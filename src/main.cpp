// Golden Sun: The Broken Seal (USA/Europe, AGSE01) — native static recompilation host.
// Windows GUI subsystem entry point: no console window, no automatic demo playback.

#include "runtime.h"
#include "runtime_arm.h"

#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#endif

namespace fs = std::filesystem;

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

int run(int argc, char** argv) {
    // Suppress debug diagnostic dumps and on-the-fly recompile cache in normal runs
    if (!std::getenv("GBARECOMP_SELFHEAL_RECOMPILE"))
        _putenv("GBARECOMP_SELFHEAL_RECOMPILE=0");
    if (!std::getenv("GBARECOMP_MISS_FRAG"))
        _putenv("GBARECOMP_MISS_FRAG=NUL");
    if (!std::getenv("GBARECOMP_COVERAGE_JSON"))
        _putenv("GBARECOMP_COVERAGE_JSON=NUL");
    if (!std::getenv("GBARECOMP_SESSION_DIAGNOSTICS"))
        _putenv("GBARECOMP_SESSION_DIAGNOSTICS=0");

    g_runtime_force_interp_hook = &gs1_force_interp_hook;

    gbarecomp::RunOptions opts{};
    opts.builtin_game_name = "Golden Sun: The Broken Seal";
    opts.builtin_rom_sha1  = "5c4695205413df7db52b9a184815a07783999971";
    opts.builtin_rom_crc32 = 0x6DAEBFBB;
    opts.freely_resizable_window = true;
    opts.expose_assist_tools = false;

    return gbarecomp::run_game(argc, argv, opts);
}

}  // namespace

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

    int rc = run(argc, argv);

    for (int i = 0; i < argc; ++i) {
        if (argv[i]) HeapFree(GetProcessHeap(), 0, argv[i]);
    }
    HeapFree(GetProcessHeap(), 0, argv);
    LocalFree(argv_w);

    return rc;
}
#else
int main(int argc, char** argv) {
    return run(argc, argv);
}
#endif
