// Golden Sun: The Broken Seal (USA/Europe, AGSE01) — native static recompilation host.
// Windows GUI subsystem entry point: no console window, player-facing recomp-ui launcher.

#include "runtime.h"
#include "runtime_arm.h"

#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#endif

int game_launcher_preboot(std::vector<std::string>&, const gbarecomp::RunOptions&);
int game_validate_inputs(std::vector<std::string>&, const gbarecomp::RunOptions&);

namespace {

// Golden Sun: The Broken Seal (AGSE01) places three kinds of code in RAM:
// 1. Fixed, immutable ARM routines from rom_770.s copied at boot to IWRAM:
//      0x03000000..0x03000658 (IRQ master handler, math, fast fill, Sqrt, 3D matrix, Div, LZ77)
//      0x03001388..0x03001400 (Fast 32-byte block copy)
//    These are statically recompiled in src/game/iwram_runtime.cpp and dispatch natively.
// 2. Self-modifying MP2K SoundMainRAM mixer at 0x03000658..0x03001388:
//    Overwrites its own instruction words at runtime. Must be interpreted from live IWRAM.
// 3. Dynamically allocated / decompressed RAM code:
//    - IWRAM dynamic heap (0x03001400..0x03008000).
//    - EWRAM dynamic overlays and heap (0x02000000..0x02040000).
extern "C" int gs1_force_interp_hook(uint32_t pc, int /*thumb*/) {
    // Self-modifying MP2K SoundMainRAM mixer
    if (pc >= 0x03000658u && pc < 0x03001388u) {
        return 1;
    }
    // Dynamic IWRAM heap/stack code region
    if (pc >= 0x03001400u && pc < 0x03008000u) {
        return 1;
    }
    // Dynamic EWRAM overlays and heap code region
    if (pc >= 0x02000000u && pc < 0x02040000u) {
        return 1;
    }
    return 0;
}

}  // namespace

int main(int argc, char** argv) {
    // Suppress debug diagnostic dumps and on-the-fly recompile cache in normal runs
#ifdef _WIN32
    if (!std::getenv("GBARECOMP_SELFHEAL_RECOMPILE"))
        _putenv("GBARECOMP_SELFHEAL_RECOMPILE=0");
    if (!std::getenv("GBARECOMP_MISS_FRAG"))
        _putenv("GBARECOMP_MISS_FRAG=NUL");
    if (!std::getenv("GBARECOMP_COVERAGE_JSON"))
        _putenv("GBARECOMP_COVERAGE_JSON=NUL");
    if (!std::getenv("GBARECOMP_SESSION_DIAGNOSTICS"))
        _putenv("GBARECOMP_SESSION_DIAGNOSTICS=0");
#else
    setenv("GBARECOMP_SELFHEAL_RECOMPILE", "0", 0);
    setenv("GBARECOMP_MISS_FRAG", "/dev/null", 0);
    setenv("GBARECOMP_COVERAGE_JSON", "/dev/null", 0);
    setenv("GBARECOMP_SESSION_DIAGNOSTICS", "0", 0);
#endif

    // Recomp runtime options for Golden Sun: The Broken Seal
    gbarecomp::RunOptions options;
    options.builtin_game_name = "Golden Sun: The Broken Seal";
    options.builtin_rom_sha1  = "5c4695205413df7db52b9a184815a07783999971";
    options.builtin_rom_crc32 = 0x6DAEBFBB;
    options.freely_resizable_window = true;
    options.expose_assist_tools = false;
    options.launcher_region = "USA/Europe";
    options.launcher_game_config = "game.toml";
    options.launcher_expose_widescreen = false;
    options.launcher_expose_adaptive_view = false;

    std::vector<std::string> args(argv, argv + argc);
    const bool player_launch = argc == 1 || (argc == 2 && args[1] == "--launcher");

    std::error_code ec;
    auto exe_path = std::filesystem::absolute(argv[0], ec);
    auto exe_dir = ec ? std::filesystem::current_path() : exe_path.parent_path();

    if (player_launch) {
        // The portable launcher, settings, and assets live beside the EXE.
        if (!ec) std::filesystem::current_path(exe_dir, ec);
    }

    // Save path resolution: preserve legacy root-level gs1.sav if already present,
    // otherwise use saves/gs1.sav cleanly without clobbering or deleting.
    std::string save_path;
    bool has_cli_save = false;
    for (std::size_t i = 1; i < args.size(); ++i) {
        if ((args[i] == "--save" || args[i] == "--save-path") && i + 1 < args.size()) {
            has_cli_save = true;
            save_path = args[i + 1];
            break;
        }
    }

    if (!has_cli_save) {
        if (std::filesystem::exists(exe_dir / "gs1.sav")) {
            save_path = (exe_dir / "gs1.sav").string();
        } else if (std::filesystem::exists("gs1.sav")) {
            save_path = "gs1.sav";
        } else {
            std::filesystem::create_directories(exe_dir / "saves", ec);
            save_path = (exe_dir / "saves" / "gs1.sav").string();
        }
    }
    options.launcher_save_path = save_path.c_str();

    // Run the recomp-ui GUI launcher preboot
    if (game_launcher_preboot(args, options)) return 0;
    // Strict ROM and BIOS gate
    if (game_validate_inputs(args, options)) return 1;

    if (player_launch) {
        if (!has_cli_save) {
            args.emplace_back("--save");
            args.emplace_back(options.launcher_save_path);
        }
        args.emplace_back("--window");
    }

    // Install MP2K & dynamic RAM interpretation hook
    g_runtime_force_interp_hook = &gs1_force_interp_hook;

    std::vector<char*> native_args;
    native_args.reserve(args.size());
    for (auto& arg : args) native_args.push_back(arg.data());

    return gbarecomp::run_game(static_cast<int>(native_args.size()), native_args.data(), options);
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    int argc = 0;
    LPWSTR* argv_w = CommandLineToArgvW(GetCommandLineW(), &argc);
    if (!argv_w) return 1;

    char** argv = static_cast<char**>(HeapAlloc(
        GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(char*) * (argc + 1)));
    if (!argv) {
        LocalFree(argv_w);
        return 1;
    }

    for (int i = 0; i < argc; ++i) {
        int n = WideCharToMultiByte(CP_UTF8, 0, argv_w[i], -1, nullptr, 0, nullptr, nullptr);
        argv[i] = static_cast<char*>(HeapAlloc(GetProcessHeap(), 0, n ? n : 1));
        if (argv[i] && n > 0) {
            WideCharToMultiByte(CP_UTF8, 0, argv_w[i], -1, argv[i], n, nullptr, nullptr);
        }
    }

    int rc = main(argc, argv);

    for (int i = 0; i < argc; ++i) {
        if (argv[i]) HeapFree(GetProcessHeap(), 0, argv[i]);
    }
    HeapFree(GetProcessHeap(), 0, argv);
    LocalFree(argv_w);

    return rc;
}
#endif
