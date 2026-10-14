# Cleanup — 2026-10-02

Build outputs, generated `src/game/`, and the downloaded SDL2 SDK are deleted. ROM, BIOS, `gs1.sav`, handwritten host source, formal
`symbols/gs_functions.tsv`, all existing docs, and build/regeneration scripts
are preserved. No gameplay development, new cold build, or push was performed.

The retained framework checkout is upstream https://github.com/mstan/gbarecomp.git
commit `d11a36261aa1d9587a225760135d0ddea0f97344`, with the clean ARM dependency
at https://github.com/mstan/arm-recomp-core.git commit
`e372f84549b47122affa0816f9e831aa2f2bcd92`. All six handwritten framework file
modifications are preserved in `patches/gbarecomp-gs1-compat.patch`; the patch
passed a reverse-application check against the old checkout without changing it.
The changed BIOS dispatch file is generated and must be regenerated from the
user BIOS, following the existing commands recorded in `docs/PROGRESS.md`.

`scripts/setup-deps.ps1` restores the pinned framework, ARM dependency, retained
compatibility patch, and SDL2 2.30.11. Third-party license notices are preserved.
This newly saved recovery recipe was syntax checked, not fetched or cold-built
during cleanup. Dependency/BIOS compatibility remains unverified from scratch.

To build, restore dependencies, regenerate guest and BIOS sources, then run the
existing build script. Delete regenerated outputs and dependency caches again
after validation. Old Git history contains generated guest source; no history
rewrite is performed.

Blocker: automatic approval review rejected deleting reference/gbarecomp because
the ARM submodule revision and generated BIOS dispatch changes were not proven
fully recoverable. That checkout is retained intact; its six handwritten diffs
are additionally saved in the compatibility patch. The separate SDL2 download
and all project build/guest generation outputs were removed.
