# GoldenSunTheBrokenSealRecomp

[English](README.md) | [简体中文](README.zh-CN.md)

A Windows x64 native static recompilation integration for **Golden Sun: The Broken Seal (USA/Europe, Game Code: AGSE, Maker: 01, Revision 0)**, built using [GBARecomp](https://github.com/mstan/gbarecomp) and [recomp-ui](https://github.com/mstan/recomp-ui).

> **v0.1.0-preview — Experimental Preview**  
> This unofficial, non-commercial fan project is not affiliated with, endorsed by, or associated with Nintendo or Camelot Software Planning. Players must supply their own legally obtained GBA ROM and retail GBA BIOS. Full-game campaign completion has not been exhaustively verified across all optional quests and end-game dungeons.

*Golden Sun* (*Golden Sun: The Broken Seal*) is Camelot Software Planning and Nintendo's acclaimed fantasy JRPG for the Game Boy Advance. This native Windows integration translates original ARM/Thumb machine code into native x64 instructions, preserving original timing, battle animations, pseudo-3D Mode-7 camera choreography, Djinn/Psynergy systems, and cartridge save persistence while providing a modern desktop player launcher.

---

## Verified Playable Scope & Current Status

* [x] **BIOS / Cold Boot**: LLE BIOS reset sequence, official Nintendo splash, and Camelot Software Planning 3D corporate logo verified (`gba_bios.bin`).
* [x] **Title Screen & Sanctum Main Menu**: Title sequence, file management menu (`Continue`, `New Game`, `Erase`, `Copy`, `Battle`), and save slot initialization verified.
* [x] **New Game & Character Naming Screen**: Naming interface (`Isaac`), font rendering, and PPU palette transitions verified.
* [x] **Opening Storm Prologue**: Isaac's house, Dora & Kyle narrative cutscenes, outdoor rain and lightning effects, Mt. Aleph rolling boulder event, and Lower Vale river dock verified.
* [x] **First Combat & Turn-Based Engine**: 3D pseudo-Mode7 Vale storm battle scene (`Wild Mushroom x2`), party & character command menus (`Attack`, `Psynergy`, `Item`, `Defend`), and combat turn execution verified.
* [x] **Cartridge Flash512 Persistence**: Full 64 KB Flash save chip protocol (Macronix `MX29L512`, `0x1CC2`, `FLASH_V123`) verified with disk persistence round-trip (`saves/gs1.sav` and legacy `gs1.sav`).
* [x] **Native Player Launcher**: Built-in interactive GUI (`recomp-ui`) for ROM/BIOS selection, hash validation, input configuration, display options, and persistent launch.
* [x] **Windows GUI Subsystem**: Boots directly into the desktop UI without an intrusive terminal/command prompt window (`-mwindows`).

### Scope Open for Community Testing

This preview provides a solid, playable native foundation. The following chapters and features remain open for community testing and feedback:
* Full campaign progression across Weyard, Mt. Aleph Sol Sanctum, Mercury Lighthouse, Kolima Forest, Babi Lighthouse, and Venus Lighthouse.
* Late-game summon sequences (Judgement, Meteor, Thor, Eclipse), high-tier Psynergy VFX, and complex multi-target spell scripts.
* Battle mode in the Sanctum menu and link-cable party transfer/combat.
* Long-session MP2K audio stability across diverse town, dungeon, and overworld themes.

---

## Quick Start (Players)

No developer tools (CMake, Ninja, GCC, Python, or command-line shells) are required.

1. **Download**: Grab `GoldenSunTheBrokenSealRecomp-windows-x64-v0.1.0-preview.zip` from the project's Releases page.
2. **Extract**: Extract the entire archive into a writable folder on your computer. Ensure `GoldenSunTheBrokenSealRecomp.exe`, the DLLs (`SDL2.dll`, `libgcc_s_seh-1.dll`, `libstdc++-6.dll`, `libwinpthread-1.dll`), `assets/`, `game.toml`, and `licenses/` stay together.
3. **Launch**: Double-click `GoldenSunTheBrokenSealRecomp.exe`.
4. **Setup in Launcher**:
   * Click **Browse** to select your supported USA/Europe ROM (`.gba`) and retail GBA BIOS (`.bin`).
   * The launcher automatically computes SHA-1 checksums and verifies file sizes. Once valid, green checkmarks appear.
   * Customize your controller or keyboard layout, window scaling, and audio volume.
5. **Play**: Click **Play** to enter the game!

> [!TIP]
> Your selected ROM, BIOS, and settings are saved automatically (`rom.cfg`, `bios.cfg`, `config.ini`, `keybinds.ini`). If you ever check "Skip Launcher" and later want to reopen the setup GUI, run `GoldenSunTheBrokenSealRecomp.exe --launcher` from a shortcut or command prompt.

---

## Required Private Files

You must provide your own legally dumped game ROM and retail GBA BIOS. Neither file is included in this repository or any release download.

| File | Supported Identity | Expected Size | SHA-1 Hash | CRC-32 |
|---|---|---:|---|---|
| **Game ROM** | *Golden Sun* (USA/Europe, Code `AGSE`, Maker `01`) | 8,388,608 bytes | `5c4695205413df7db52b9a184815a07783999971` | `6DAEBFBB` |
| **GBA BIOS** | Retail Game Boy Advance BIOS | 16,384 bytes | `300c20df6731a33952ded8c436f7f186d25d3492` | — |

> [!WARNING]
> Other regional releases (Japanese), modified ROMs, and high-level emulation (HLE) BIOS replacements are strictly rejected by the launcher to ensure execution integrity. Renaming an unsupported file will not bypass hash verification.

---

## Controls, Display, and Audio

### Default Keyboard Mapping

| GBA Button | PC Default Key | Function |
|---|---|---|
| **D-Pad** | `W / A / S / D` or `↑ / ↓ / ← / →` | Movement / Menu Navigation |
| **A** | `Z` / `J` | Confirm / Talk / Interact / Select |
| **B** | `X` / `K` | Cancel / Dash (hold while walking) |
| **L** | `Q` / `U` | Psynergy Shortcut L / Page Left |
| **R** | `E` / `I` | Psynergy Shortcut R / Page Right |
| **START** | `Enter` | Main Party Menu (Status, Psynergy, Djinn, Items) |
| **SELECT** | `Backspace` / `Tab` | Field Map / Assist |

### Game Controller Support

Standard modern game controllers (Xbox / XInput, PlayStation DualShock 4 / DualSense, Nintendo Switch Pro Controller, and generic DirectInput gamepads) are natively supported via SDL2. Bindings can be freely customized within the launcher's **Input** tab.

### Display and Audio Settings

* **Window Scaling**: 1x through 6x integer scaling, or borderless fullscreen (`F11` / `Alt+Enter`).
* **Aspect Ratio**: Authentic 3:2 GBA aspect ratio (240 × 160 native resolution with sharp integer presentation).
* **Audio**: Master volume slider with 16-bit 44.1 kHz stereo output.

---

## Native Flash Saves and Configuration

* **Cartridge Saves**: When launched via the GUI or double-click, saves are stored beside the executable in **`saves/gs1.sav`**.
* **Backward Compatibility**: If a legacy `gs1.sav` already exists in your executable folder from prior runs, the runtime automatically detects and continues using it without modifying or deleting old progress.
* **Save Hardware Authenticity**: Emulates the Macronix `MX29L512` 64 KB Flash chip (`0x1CC2`, `FLASH_V123`) using original sector erase and program commands. Saved files are bit-identical and fully exchangeable with real GBA Flash carts and standard emulators.
* **Settings Persistence**: Launcher options, file paths, and keybindings are stored in `rom.cfg`, `bios.cfg`, `config.ini`, and `keybinds.ini` in the executable folder.

---

## Technical Architecture

* **AOT Static Recompilation**: Uses [GBARecomp](https://github.com/mstan/gbarecomp) to translate guest ARM7TDMI code into 19 functionally organized C++ modules (`src/game/`).
* **Fixed IWRAM Code Copies**: Critical low-latency routines copied to IWRAM at boot (`0x03000000–0x03000658` for IRQ dispatch, fixed-point math, 3D matrix math, LZ77 decompression; `0x03001388–0x03001400` for fast block copy) are mapped via `game.toml` `[[code_copy]]` and execute via native static dispatch (`src/game/iwram_runtime.cpp`).
* **Self-Modifying MP2K Audio Hook**: Golden Sun's MusicPlayer2000 sound driver dynamically rewrites its IWRAM mixer routines (`0x03000658–0x03001388`). The runtime routes these instructions, along with dynamic heap/overlay memory, through a dedicated execution hook (`gs1_force_interp_hook`) to the cycle-accurate interpreter, preventing code cache incoherency.
* **Silicon Emulation**: PPU tilemaps, affine transforms, sprites, interrupts, and DMA timers are cycle-accurately emulated by the shared runtime.
* **GUI Launcher**: Pinned [recomp-ui](https://github.com/mstan/recomp-ui) powered by Dear ImGui provides configuration persistence and strict SHA-1 identity gating.
* **Windows Host Subsystem**: Uses WinMain GUI entry point (`-mwindows`) with 64 MB reserved stack to guarantee zero terminal popups and stable recursion depth.

---

## Building from Source (Developers)

If you are building the project from source:

### Prerequisites

* Windows 10 / 11 64-bit
* MinGW-w64 (GCC 11+ with C++20 support)
* CMake 3.20+ and Ninja
* SDL2 MinGW development libraries (`x86_64-w64-mingw32`)
* Git

### Step-by-Step Build

1. Clone the repository:
   ```powershell
   git clone https://github.com/Zaxaerith/GoldenSunTheBrokenSealRecomp.git
   cd GoldenSunTheBrokenSealRecomp
   ```

2. Initialize submodules and dependencies:
   ```powershell
   git submodule update --init --recursive
   ```

3. Compile the native executable:
   ```powershell
   .\build.ps1
   ```
   Or explicitly via `tools/build-host.ps1`:
   ```powershell
   .\tools\build-host.ps1 -Jobs 4 -Toolchain "C:/path/to/mingw64" -SdlRoot "D:/path/to/SDL2/x86_64-w64-mingw32" -BuildContractTest
   ```

4. Output executables:
   * Game: `build\host\GoldenSunTheBrokenSealRecomp.exe`
   * Test: `build\host\launcher_contract.exe`

### Developer Command-Line Options

The native executable supports command-line arguments for development and automated testing:
* `--rom <path>`: Specify path to GBA ROM directly (bypasses launcher).
* `--bios <path>`: Specify path to GBA BIOS directly.
* `--save <path>`: Specify custom save file path.
* `--launcher`: Force open the GUI launcher even if previously skipped.
* `--frames <count>`: Run for a fixed number of frames and exit (headless testing).
* `--no-window`: Run without creating an SDL display window.

---

## Repository Structure

```text
GoldenSunTheBrokenSealRecomp/
├── .gitignore
├── CMakeLists.txt              # CMake build definitions (GoldenSunTheBrokenSealRecomp, gs1)
├── LICENSE                     # PolyForm Noncommercial 1.0.0
├── THIRD_PARTY_NOTICES.md      # Third-party notices and attributions
├── README.md                   # English player & developer documentation
├── README.zh-CN.md             # Chinese documentation
├── build.ps1                   # One-click native build wrapper
├── game.toml                   # ROM identity, Flash512, and code-copy configuration
├── docs/
│   ├── FRAMEWORK_PIN.json      # Pinned framework & dependency commit hashes
│   └── PROGRESS.md             # Development & testing log
├── tools/
│   ├── common.ps1              # Shared verification utilities
│   ├── build-host.ps1          # Host compilation script
│   └── make-release.ps1        # Release packaging & manifest generation
├── src/
│   ├── main.cpp                # Windows GUI entry, save resolution, and MP2K hook
│   ├── game_launcher_boot.cpp  # recomp-ui launcher seam & strict SHA-1 gate
│   └── game/                   # 19 functionally named recompiled modules
│       ├── iwram_runtime.cpp   # Fixed IWRAM math, matrix, and decompression
│       ├── boot_system.cpp     # Reset vector, AgbMain, IRQ callbacks
│       ├── engine_core.cpp     # Task scheduler, heap allocator, sprite manager
│       ├── window_font_ui.cpp  # Dialog box, variable-width font
│       ├── party_status_ui.cpp # Party menus, Psynergy, Djinn & Status
│       ├── shop_sanctum_ui.cpp # Shops, Sanctum, Save slot UI, Naming
│       ├── overworld_camera.cpp# Map loader, tileset, camera scroll
│       ├── overworld_entities.cpp # Game mode FSM, player & NPC controller
│       ├── overworld_collision.cpp# Elevation, doors, chests & triggers
│       ├── field_psynergy.cpp  # Field Psynergy (Move, Frost, Growth, Lift)
│       ├── world_map_navigation.cpp # Mode-7 Weyard overworld & encounters
│       ├── battle_camera_scene.cpp # 3D pseudo-Mode7 battle camera
│       ├── battle_command_ui.cpp   # Battle menus & combat HUD
│       ├── battle_turn_engine.cpp  # Turn order, AI, damage formulas
│       ├── battle_effects_vfx.cpp  # Attack animations & camera cuts
│       ├── summon_djinn_vfx.cpp    # Summon sequences & Djinn VFX
│       ├── psynergy_spell_scripts.cpp # Spell & skill effect scripts
│       ├── cutscene_script_vm.cpp  # Story sequence virtual machine
│       ├── audio_flash_save.cpp    # MP2K sound engine & Flash save driver
│       ├── dispatch_table.cpp  # Cart dispatch table
│       ├── symbol_map.cpp      # Symbol lookup map
│       ├── recompiled.h        # Forward declarations
│       └── modules.h           # Module includes
└── tests/
    └── launcher_contract.cpp   # Launcher gating and settings contract test
```

---

## Known Limitations

* Verified gameplay covers the opening chapter through the Vale storm, Lower Vale docks, and first combat. While the full game ROM code is recompiled, full-campaign edge cases remain to be validated.
* Self-modifying MP2K audio code is interpreted; on low-spec hardware, heavy sound mixing scenes may exhibit minor audio latency.
* Multiplayer battle arena via link cable is currently unsupported.

---

## Credits and Licenses

* **GBARecomp**: Developed by Matthew Stanley ([mstan/gbarecomp](https://github.com/mstan/gbarecomp)). Licensed under [PolyForm Noncommercial 1.0.0](https://polyformproject.org/licenses/noncommercial/1.0.0/).
* **recomp-ui**: Developed by Matthew Stanley ([mstan/recomp-ui](https://github.com/mstan/recomp-ui)). Licensed under MIT.
* **GoldenSunTheBrokenSealRecomp Integration**: Integration code, launcher bindings, and tooling by Zaxaerith. Licensed under [PolyForm Noncommercial License 1.0.0](LICENSE).
* **Third-Party Components**:
  * [Dear ImGui](https://github.com/ocornut/imgui) — MIT License
  * [toml++](https://github.com/marzer/tomlplusplus) — MIT License
  * [Simple DirectMedia Layer (SDL2)](https://www.libsdl.org/) — zlib License
  * [arm-recomp-core](https://github.com/mstan/arm-recomp-core) — MIT License
  * mGBA-derived BIOS HLE fallback source — MPL-2.0 (bundled in `licenses/mpl-source/`)
  * Fonts (*LatoLatin*, *OpenMoji*, *NotoSansSymbols2*) — OFL-1.1 / CC BY-SA 4.0 (see `licenses/`)
* See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for full licensing information.

---

## Legal Disclaimer

*Golden Sun*, *Golden Sun: The Broken Seal*, and all related characters, names, and assets are registered trademarks and copyrights of **Nintendo Co., Ltd.** and **Camelot Software Planning**.

This project is an independent, non-commercial software engineering and digital preservation research initiative. It is **not** affiliated with, sponsored by, or endorsed by Nintendo or Camelot Software Planning. No proprietary ROM images, BIOS dumps, or copyrighted assets are hosted or distributed in this repository.
