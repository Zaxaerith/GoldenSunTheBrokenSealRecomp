# Third-Party Notices & Licenses

This project incorporates, links, and references software, libraries, and documentation from third-party open-source and research projects. Below are the corresponding notices, licenses, and attributions.

---

## 1. GBARecomp
- **Repository**: [https://github.com/mstan/gbarecomp](https://github.com/mstan/gbarecomp)
- **Author**: Matthew Stanley and GBARecomp Contributors
- **License**: PolyForm Noncommercial 1.0.0 / Mozilla Public License 2.0 / MIT
- **Description**: GBA static recompiler framework, ARM/Thumb recompiler core, runtime environment, PPU/APU bus emulation, and platform glue.

---

## 2. recomp-ui
- **Repository**: [https://github.com/mstan/recomp-ui](https://github.com/mstan/recomp-ui)
- **Author**: Matthew Stanley and Contributors
- **License**: MIT License
- **Description**: Portable Dear ImGui frontend launcher and in-game settings interface for recomp projects.

---

## 3. Dear ImGui
- **Repository**: [https://github.com/ocornut/imgui](https://github.com/ocornut/imgui)
- **Author**: Omar Cornut
- **License**: MIT License
- **Description**: Bloat-free immediate mode graphical user interface library for C++.

---

## 4. toml++
- **Repository**: [https://github.com/marzer/tomlplusplus](https://github.com/marzer/tomlplusplus)
- **Author**: Mark Gillard
- **License**: MIT License
- **Description**: Header-only TOML parser and serializer for C++17 and later.

---

## 5. SDL2 (Simple DirectMedia Layer)
- **Website**: [https://www.libsdl.org/](https://www.libsdl.org/)
- **License**: zlib License
- **Usage**: Cross-platform audio output, keyboard and game controller input, and window creation.

---

## 6. ArmRecompCore
- **Repository**: [https://github.com/mstan/arm-recomp-core](https://github.com/mstan/arm-recomp-core)
- **Author**: Matthew Stanley
- **License**: MIT License
- **Description**: Intermediate representation and static lowering engine for ARM/Thumb machine code.

---

## 7. MinGW-w64 Runtime
- **Website**: [https://www.mingw-w64.org/](https://www.mingw-w64.org/)
- **License**: Public Domain / MinGW-w64 Runtime Exception / ZPL-2.1
- **Usage**: C/C++ runtime support libraries (`libgcc_s_seh-1.dll`, `libstdc++-6.dll`, `libwinpthread-1.dll`).

---

## 8. Fonts and Graphical Assets
- **LatoLatin**: Lukasz Dziedzic — SIL Open Font License 1.1 (`licenses/Font-Notices.txt`)
- **OpenMoji**: OpenMoji project — Creative Commons Attribution-ShareAlike 4.0 International (`CC BY-SA 4.0`)
- **Noto Sans Symbols 2**: Google LLC — SIL Open Font License 1.1
- **GBA Gamepad & Status Icons**: Contributed by mstan / recomp-ui under MIT License (`licenses/Image-Notices.txt`)

---

## 9. Mozilla Public License 2.0 (MPL-2.0)
The GBARecomp runtime includes a fallback High-Level Emulation (HLE) BIOS implementation derived from mGBA, licensed under the Mozilla Public License 2.0. In compliance with Section 3.2 of the MPL-2.0, the corresponding source files (`bios_hle.cpp` and `bios_hle.h`) are provided in full under `licenses/mpl-source/` within the release package and repository.

---

## 10. Legal Notice, Disclaimer & Redistribution Boundaries
*Golden Sun*, *Golden Sun: The Broken Seal*, and related characters, names, graphics, and audio are trademarks and copyrights of **Nintendo Co., Ltd.** and **Camelot Software Planning**.

- **No Raw Cartridge Assets Distributed**: This repository and release archives do **NOT** contain, redistribute, or mirror any proprietary ROM cartridge binaries, BIOS images, or raw copyright-protected media assets. Players must provide their own legally obtained ROM dump and retail GBA BIOS.
- **Compiled Guest Code & Copyright Status**: The standalone executable (`GoldenSunTheBrokenSealRecomp.exe`) statically links C++ translation units derived from the original commercial game cartridge's machine code. Although this recompilation project was developed as an independent, non-commercial research and digital preservation initiative, this non-commercial research context does NOT constitute a formal legal license, exemption, or authorization from the copyright holders. All rights to the underlying game code, design, and assets remain exclusively with Nintendo and Camelot. Anyone downloading, running, or redistributing the compiled binary must exercise their own independent legal assessment regarding distribution rights.
