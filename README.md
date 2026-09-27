# GoldenSunTheBrokenSealRecomp

[![Platform](https://img.shields.io/badge/platform-Windows-blue)](#prerequisites)
[![Language](https://img.shields.io/badge/language-C%2B%2B20-orange)](#what-static-recompilation-means-here)
[![License](https://img.shields.io/badge/license-PolyForm--Noncommercial--1.0.0-blue)](LICENSE)

Native static recompilation of **Golden Sun: The Broken Seal** (GBA, USA/Europe, `AGSE01`) into a standalone Windows x86_64 executable, built on the [GBARecomp](https://github.com/mstan/gbarecomp) framework.

---

## What "static recompilation" means here

The ARM7TDMI (ARM/Thumb) guest machine code from the original cartridge is statically translated into native C++ translation units in `src/game/` (19 functionally named modules), which are compiled directly into a native executable.

**The rest of the GBA is modelled hardware** in the shared GBARecomp runtime:
* **PPU**: Background tilemaps (BG0..BG3), affine/rotation transformations, OAM sprite rendering, alpha blending, and windowing.
* **APU**: Direct Sound dual FIFO PCM channels and PSG audio.
* **DMA / Timers / Interrupts**: Cycle-accurate event scheduling and IRQ dispatch.
* **Cartridge Save**: 64 KB Flash save chip protocol (`FLASH_V123` / Macronix `MX29L512` JEDEC ID `0x1CC2`).
* **BIOS**: Recompiled LLE execution path.

Architecture: **recompile the CPU, emulate the silicon**.

---

## Current Status

- [x] **BIOS boot & developer logos**: GBA intro animation, Nintendo logo, and Camelot Software Planning 3D logo.
- [x] **Title Screen & Sanctum Main Menu**: Title sequence, file selection (`Continue`, `New Game`, `Erase`, `Copy`, `Battle`).
- [x] **New Game & Character Naming**: Naming screen (`Isaac`), verified cycle- and PPU-bit-identical to the reference ARM interpreter.
- [x] **Opening Storm Prologue**: Isaac's house, Dora & Kyle cutscenes, outdoor rain and lightning effects, Mt. Aleph rolling boulder event, and Lower Vale river dock.
- [x] **Flash512 Save & Load**: Full 64 KB Flash cartridge persistence (`gs1.sav`) with valid sector checksums (`0x5008`, `0xE008`) and save word checksums (`0x503C`).
- [x] **First Battle & Combat Engine**: 3D pseudo-Mode7 Vale storm battle scene (`Wild Mushroom x2`), party & character command menus (`Attack`, `Psynergy`, `Item`, `Defend`), and combat turn execution.
- [x] **Fully Static Execution**: Zero static dispatch misses (`self_heal_coverage=FULLY_STATIC dispatch_misses=0`) across all gameplay paths.
- [x] **No console window**: Compiled as a native Windows GUI application (`-mwindows`).
- [x] **No automatic demo inputs**: The player has full direct control from boot.

---

## Quick Start (you provide the ROM)

> [!IMPORTANT]
> **Legal Notice**: This repository does **NOT** contain any copyrighted ROM data, BIOS images, game assets, or proprietary Nintendo / Camelot code. You must provide your own legally obtained ROM dump and GBA BIOS to build or play.

### Verified ROM

| Field | Value |
| :--- | :--- |
| **Game** | Golden Sun: The Broken Seal (USA/Europe) |
| **Game Code** | `AGSE` |
| **Maker Code** | `01` |
| **Header Title** | `Golden_Sun_A` |
| **File Name** | `Golden Sun(UE)(Nintendo)(64Mb).gba` |
| **Size** | `8,388,608` bytes |
| **CRC32** | `6DAEBFBB` |
| **SHA1** | `5c4695205413df7db52b9a184815a07783999971` |
| **Save Type** | Flash 64 KB / 512 Kbit (`FLASH_V123`) |

### BIOS

A retail GBA BIOS dump (`gba_bios.bin`, 16,384 bytes, SHA-1 `300c20df6731a33952ded8c436f7f186d25d3492`) is required when running the game. Place it in the project root or specify its path in `game.toml`.

---

## Building from Source

### One-click Build (PowerShell)

```powershell
.\build.ps1
```

This invokes CMake and Ninja with MinGW / MSVC, compiles the executable, and stages `SDL2.dll` and `game.toml` into `build/`.

### Manual Build

```powershell
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --target gs1 --parallel
```

Output: `build\gs1.exe`

---

## Regenerating Cartridge Code (Optional)

The recompiled C++ translation units in `src/game/` can be regenerated from your ROM at any time:

```powershell
.\scripts\generate.ps1 -Rom "path\to\Golden Sun(UE)(Nintendo)(64Mb).gba"
```

This runs `gbarecomp build` with `symbols/gs_functions.tsv` and splits the generated output into `src/game/` using `scripts/split_generated.py`.

---

## Running

```powershell
.\build\gs1.exe
```

Or pass command-line arguments explicitly:

```powershell
.\build\gs1.exe --rom "Golden Sun(UE)(Nintendo)(64Mb).gba" --bios "gba_bios.bin" --config game.toml
```

---

## Controls

| Action | Keyboard | Gamepad | GBA |
| :--- | :--- | :--- | :--- |
| **D-Pad / Movement** | Arrow Keys / WASD | D-Pad / Left Stick | D-Pad |
| **A (Confirm / Attack / Talk)** | `Z` / `X` | `A` / `B` | A |
| **B (Cancel / Dash)** | `X` / `Z` | `B` / `A` | B |
| **L (Left Trigger / Psynergy Shortcut)** | `A` / `Q` | `LB` / `L1` | L |
| **R (Right Trigger / Psynergy Shortcut)** | `S` / `E` | `RB` / `R1` | R |
| **Start (Menu / Pause)** | `Enter` | `Start` | Start |
| **Select (Map / Assist)** | `Right Shift` / `Backspace` | `Select` / `Back` | Select |
| **Fullscreen** | `F11` / `Alt+Enter` | — | — |
| **Quit** | `Esc` | — | — |

---

## Project Layout

```text
GoldenSunTheBrokenSealRecomp/
├── .gitignore
├── CMakeLists.txt
├── LICENSE                    # PolyForm Noncommercial 1.0.0
├── README.md
├── build.ps1                  # One-click native build
├── game.toml                  # ROM identity, Flash save, and code-copy configuration
├── symbols/
│   └── gs_functions.tsv       # Seed symbols with functional names
├── scripts/
│   ├── build.ps1
│   ├── generate.ps1           # One-click recompile + functional module splitting
│   ├── recompile.ps1
│   ├── setup_sdl2.ps1
│   └── split_generated.py     # Deterministic functional naming & module splitter
└── src/
    ├── main.cpp               # Windows GUI host entry point (no console, no auto-demo)
    └── game/
        ├── modules.h          # Index of functional modules
        ├── recompiled.h       # Function declarations
        ├── dispatch_table.cpp # Static dispatch table
        ├── symbol_map.cpp     # Symbol lookup map
        ├── iwram_runtime.cpp  # Master IRQ, fixed-point math, 3D matrix, LZ77, block copy
        ├── boot_system.cpp    # AgbMain, reset vector, DMA & IRQ callbacks
        ├── engine_core.cpp    # Task scheduler, heap allocator, sprite & palette manager
        ├── window_font_ui.cpp # Window framing, variable-width font, dialogue box
        ├── party_status_ui.cpp# Field menu, Psynergy, Djinn & Status screens
        ├── shop_sanctum_ui.cpp# Shops, Sanctum menu, Save/Load slot UI, Naming screen
        ├── overworld_camera.cpp   # Map loader, tileset decompression, camera scroll
        ├── overworld_entities.cpp # Game mode state machine, player & NPC controller
        ├── overworld_collision.cpp# Map collision, elevation, doors, chests & triggers
        ├── field_psynergy.cpp     # Field Psynergy (Move, Frost, Growth, Lift)
        ├── world_map_navigation.cpp # Weyard Mode-7 world map & encounters
        ├── battle_camera_scene.cpp# 3D pseudo-Mode7 battle camera & background strips
        ├── battle_command_ui.cpp  # Battle command menus & combat HUD
        ├── battle_turn_engine.cpp # Turn order, monster AI, elemental damage formulas
        ├── battle_effects_vfx.cpp # Attack animations & camera choreography
        ├── summon_djinn_vfx.cpp   # Summon sequences & Djinn unleash effects
        ├── psynergy_spell_scripts.cpp # Battle Psynergy & monster skill effect scripts
        ├── cutscene_script_vm.cpp # Event script virtual machine & story sequences
        └── audio_flash_save.cpp   # MP2K sound engine & Macronix MX29L512 Flash save driver
```

---

## Prerequisites

* **Windows 10 / 11** (x86_64)
* **CMake 3.20+**
* **MinGW-w64 (GCC 13+)** or **MSVC (Visual Studio 2022+)**
* **Ninja** or **Make**
* **SDL2** development package (placed in `third_party/` via `scripts/setup_sdl2.ps1` or system prefix)
* **GBARecomp** runtime framework checked out as sibling `../gbarecomp-main` or under `reference/gbarecomp`

---

## License

PolyForm Noncommercial License 1.0.0 — see [LICENSE](LICENSE).

This software is for personal study, research, and noncommercial recreation.

*Golden Sun* and *Game Boy Advance* are registered trademarks of Nintendo and Camelot Software Planning. This project is an unofficial fan recompilation and is not affiliated with, sponsored by, or endorsed by Nintendo or Camelot.
