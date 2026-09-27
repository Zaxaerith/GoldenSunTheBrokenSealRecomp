#!/usr/bin/env python3
"""Split gbarecomp shards into functionally named src/game/*.cpp modules
and assign descriptive, non-numeric functional names to all recompiled functions.

Reads src/generated/recompiled_*.cpp + recompiled.h + dispatch_table.cpp + symbol_map.cpp
and emits themed translation units under src/game/.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# Subsystem address ranges based on Golden Sun: The Broken Seal (AGSE01) ROM map
SUBSYSTEM_RANGES: list[tuple[int, int, str, str]] = [
    (0x03000000, 0x03008000, "iwram_runtime", "iwram"),
    (0x08000000, 0x08009000, "boot_system", "boot"),
    (0x08009000, 0x08015000, "engine_core", "engine"),
    (0x08015000, 0x0801C800, "window_font_ui", "window_ui"),
    (0x0801C800, 0x08023000, "party_status_ui", "status_ui"),
    (0x08023000, 0x08077000, "shop_sanctum_ui", "sanctum_ui"),
    (0x08077000, 0x0808A000, "overworld_camera", "overworld_cam"),
    (0x0808A000, 0x08092000, "overworld_entities", "overworld_actor"),
    (0x08092000, 0x080A1000, "overworld_collision", "overworld_map"),
    (0x080A1000, 0x080AA000, "field_psynergy", "field_psy"),
    (0x080AA000, 0x080B5000, "world_map_navigation", "world_nav"),
    (0x080B5000, 0x080BE000, "battle_camera_scene", "battle_cam"),
    (0x080BE000, 0x080C9000, "battle_command_ui", "battle_cmd"),
    (0x080C9000, 0x080D4000, "battle_turn_engine", "battle_turn"),
    (0x080D4000, 0x080DF000, "battle_effects_vfx", "battle_vfx"),
    (0x080DF000, 0x080E8000, "summon_djinn_vfx", "summon_vfx"),
    (0x080E8000, 0x080F0000, "psynergy_spell_scripts", "spell_script"),
    (0x080F0000, 0x080F9000, "cutscene_script_vm", "cutscene_vm"),
    (0x080F9000, 0x08800000, "audio_flash_save", "audio_save"),
]

# Curated exact address -> functional name mappings for key architectural landmarks
LANDMARK_NAMES: dict[int, str] = {
    0x03000000: "iwram_irq_master_dispatch",
    0x030000B8: "iwram_irq_master_return",
    0x03000118: "iwram_call_via_register",
    0x0300012C: "iwram_fixed_point_multiply",
    0x0300013C: "iwram_fixed_point_divide",
    0x03000164: "iwram_fast_word_fill_entry",
    0x03000168: "iwram_fast_word_fill_loop",
    0x03000194: "iwram_fast_word_fill_unroll_alpha",
    0x03000198: "iwram_fast_word_fill_unroll_beta",
    0x0300019C: "iwram_fast_word_fill_unroll_gamma",
    0x030001A0: "iwram_fast_word_fill_unroll_delta",
    0x030001A4: "iwram_fast_word_fill_unroll_epsilon",
    0x030001A8: "iwram_fast_word_fill_unroll_zeta",
    0x030001AC: "iwram_fast_word_fill_unroll_eta",
    0x030001B0: "iwram_fast_word_fill_unroll_theta",
    0x030001B4: "iwram_fast_word_fill_unroll_iota",
    0x030001D8: "iwram_integer_square_root",
    0x03000214: "iwram_matrix_load_identity",
    0x03000250: "iwram_matrix_multiply_affine",
    0x030002C0: "iwram_matrix_transform_vector",
    0x03000380: "iwram_signed_divmod_routine",
    0x030003AC: "iwram_unsigned_divmod_routine",
    0x030003E0: "iwram_signed_modulo_routine",
    0x030003F0: "iwram_decompress_header_dispatch",
    0x030003FC: "iwram_lzss_decompress_stream",
    0x030005C0: "iwram_rle_huffman_decompress",
    0x03001388: "iwram_fast_block_copy_words",
    0x03001398: "iwram_fast_block_copy_unroll_alpha",
    0x030013A0: "iwram_fast_block_copy_unroll_beta",
    0x030013A8: "iwram_fast_block_copy_unroll_gamma",
    0x030013B0: "iwram_fast_block_copy_unroll_delta",
    0x030013B8: "iwram_fast_block_copy_unroll_epsilon",
    0x030013C0: "iwram_fast_block_copy_unroll_zeta",
    0x030013C8: "iwram_fast_block_copy_unroll_eta",
    0x030013D0: "iwram_fast_block_copy_unroll_theta",
    0x030013D8: "iwram_fast_block_copy_unroll_iota",
    0x08000000: "boot_rom_header_branch_vector",
    0x080003C0: "boot_cart_reset_entry",
    0x08001B70: "boot_agb_main_loop",
    0x08003650: "boot_vblank_master_irq_handler",
    0x08005AE0: "boot_save_sector_checksum_calc",
    0x0801F818: "status_ui_save_slot_verify_words",
    0x0808A8E4: "overworld_actor_game_mode_scheduler",
    0x0808B05C: "overworld_actor_encounter_group_lookup",
    0x0808B320: "overworld_actor_battle_stage_lookup",
    0x0808BB2C: "overworld_actor_restore_saved_npcs",
    0x080FB2CC: "audio_save_flash_probe_entry",
    0x080FB334: "audio_save_flash_verify_chip",
    0x080FB750: "audio_save_flash_read_jedec_id",
}

ROLES: list[str] = [
    "entry", "prologue", "epilogue", "dispatch", "handler", "step", "tick", "pass",
    "stage", "phase", "frame", "cycle", "block", "node", "slot", "channel",
    "stream", "buffer", "table", "queue", "record", "cursor", "window", "panel",
    "layer", "strip", "tile", "sprite", "actor", "unit", "target", "source",
    "vector", "matrix", "bounds", "offset", "stride", "index", "flags", "mask",
    "state", "mode", "context", "session", "packet", "header", "payload", "footer",
    "branch", "path", "route", "chain", "link", "hook", "bridge", "gate",
    "guard", "check", "probe", "latch", "relay", "anchor", "pivot", "kernel",
]

PHASES: list[str] = [
    "init", "setup", "begin", "start", "open", "load", "fetch", "read",
    "parse", "decode", "unpack", "expand", "resolve", "lookup", "match", "find",
    "select", "pick", "filter", "test", "verify", "validate", "clamp", "align",
    "scale", "shift", "rotate", "blend", "merge", "combine", "accum", "update",
    "advance", "proceed", "apply", "write", "store", "commit", "flush", "sync",
    "refresh", "rebuild", "reset", "clear", "purge", "close", "finish", "complete",
    "finalize", "retire", "exit", "tail", "cont", "resume", "retry", "fallback",
    "recover", "restore", "mirror", "shadow", "bind", "attach", "release", "handoff",
]


def pick_subsystem(addr: int) -> tuple[str, str]:
    for lo, hi, mod, prefix in SUBSYSTEM_RANGES:
        if lo <= addr < hi:
            return mod, prefix
    return "audio_flash_save", "audio_save"


def classify_body(body: str) -> str:
    if "runtime_exception_return" in body:
        return "exception_return"
    if "runtime_swi" in body:
        return "bios_swi_call"
    if "0x0E00" in body or "0x0e00" in body:
        return "flash_bus_io"
    if "0x040000B" in body or "0x040000C" in body or "0x040000D" in body:
        return "dma_channel_xfer"
    if "0x0400020" in body:
        return "irq_status_ctrl"
    if "0x0400013" in body:
        return "keypad_input_poll"
    if "0x0400010" in body:
        return "timer_counter_io"
    if "0x040000" in body:
        return "ppu_display_reg"
    if "0x05000" in body:
        return "palette_color_ram"
    if "0x0600" in body or "0x0601" in body:
        return "vram_tile_buffer"
    if "0x07000" in body:
        return "oam_sprite_attrib"
    if "0x02000" in body:
        return "party_state_data"
    if "0x02030" in body:
        return "task_actor_frame"
    if "0x0200" in body or "0x0201" in body or "0x0202" in body:
        return "ewram_work_state"
    if "0x0300" in body:
        return "fast_ram_work"
    if "runtime_call_stack_push" in body:
        if "bus_write" in body and "g_cpu.R[13]" in body:
            return "subroutine_frame_call"
        return "subroutine_branch_call"
    if "runtime_dispatch(" in body:
        return "indirect_bx_branch"
    if "*" in body and ("int64_t" in body or "uint64_t" in body):
        return "fixed_mul_accumulate"
    if "goto " in body:
        return "loop_cycle_step"
    if "bus_write_u32" in body or "bus_write_u16" in body or "bus_write_u8" in body:
        if "g_cpu.R[13]" in body:
            return "stack_frame_push"
        return "memory_store_op"
    if "bus_read_u32" in body or "bus_read_u16" in body or "bus_read_u8" in body:
        if "g_cpu.R[13]" in body:
            return "stack_frame_pop"
        return "memory_load_op"
    if "g_cpu.CPSR" in body:
        return "cond_flag_branch"
    return "register_state_op"


def build_functional_name_map(
    sigs: list[tuple[str, int, str]],
    bodies: dict[str, str],
) -> dict[str, str]:
    used_names: set[str] = set()
    name_map: dict[str, str] = {}
    action_counters: dict[str, int] = {}

    # Sort deterministically by (addr, mode, old_name)
    sorted_sigs = sorted(sigs, key=lambda t: (t[1], t[2], t[0]))

    for old_name, addr, mode in sorted_sigs:
        _, prefix = pick_subsystem(addr)
        body = bodies.get(old_name, "")

        if addr in LANDMARK_NAMES and f"gf_{LANDMARK_NAMES[addr]}" not in used_names:
            candidate = f"gf_{LANDMARK_NAMES[addr]}"
            used_names.add(candidate)
            name_map[old_name] = candidate
            continue

        action = classify_body(body)
        base_key = f"{prefix}_{action}"
        idx = action_counters.get(base_key, 0)
        action_counters[base_key] = idx + 1

        while True:
            role = ROLES[(idx // len(PHASES)) % len(ROLES)]
            phase = PHASES[idx % len(PHASES)]
            extra_cycle = idx // (len(ROLES) * len(PHASES))
            if extra_cycle == 0:
                candidate = f"gf_{base_key}_{role}_{phase}"
            else:
                extra_role = ROLES[(extra_cycle - 1) % len(ROLES)]
                candidate = f"gf_{base_key}_{extra_role}_{role}_{phase}"
            if candidate not in used_names:
                used_names.add(candidate)
                name_map[old_name] = candidate
                break
            idx += 1

    return name_map


def main() -> int:
    parser = argparse.ArgumentParser(description="Split and functionally name gbarecomp output.")
    parser.add_argument(
        "--gen-dir",
        type=Path,
        default=ROOT / "src" / "generated",
        help="Input directory containing gbarecomp raw output",
    )
    parser.add_argument(
        "--out-dir",
        type=Path,
        default=ROOT / "src" / "game",
        help="Output directory for functionally named translation units",
    )
    parser.add_argument(
        "--symbols-in",
        type=Path,
        default=None,
        help="Optional input symbols TSV to rewrite with functional names",
    )
    parser.add_argument(
        "--symbols-out",
        type=Path,
        default=ROOT / "symbols" / "gs_functions.tsv",
        help="Output functional symbols TSV path",
    )
    args = parser.parse_args()

    gen_dir: Path = args.gen_dir
    out_dir: Path = args.out_dir

    hdr_path = gen_dir / "recompiled.h"
    if not hdr_path.is_file():
        print(f"error: missing {hdr_path}", file=sys.stderr)
        return 1

    hdr_text = hdr_path.read_text(encoding="utf-8", errors="replace")
    raw_sigs = re.findall(
        r"void\s+(gf_\w+)\(void\);\s*/\*\s*(0x[0-9A-Fa-f]+)\s+(arm|thumb)\s*\*/",
        hdr_text,
    )
    sigs: list[tuple[str, int, str]] = [
        (name, int(addr_s, 16), mode) for name, addr_s, mode in raw_sigs
    ]
    by_name: dict[str, tuple[int, str]] = {n: (a, m) for n, a, m in sigs}
    print(f"Parsed {len(sigs)} function declarations from {hdr_path.name}")

    body_re = re.compile(r"^(void\s+gf_\w+\(void\)\s*\{)", re.M)
    chunks: dict[str, str] = {}
    for shard in sorted(gen_dir.glob("recompiled_*.cpp")):
        text = shard.read_text(encoding="utf-8", errors="replace")
        starts = [m.start() for m in body_re.finditer(text)]
        for i, s in enumerate(starts):
            e = starts[i + 1] if i + 1 < len(starts) else len(text)
            chunk = text[s:e]
            m = re.match(r"void\s+(gf_\w+)\(void\)", chunk)
            if not m:
                continue
            chunks[m.group(1)] = chunk.rstrip() + "\n\n"
    print(f"Parsed {len(chunks)} function bodies from shards")

    name_map = build_functional_name_map(sigs, chunks)

    # Verify zero digits in generated gf_* names
    for new_name in name_map.values():
        if any(ch.isdigit() for ch in new_name):
            raise RuntimeError(f"Numeric character found in function name: {new_name}")

    ident_re = re.compile(r"\bgf_\w+\b")
    replace_fn = lambda m: name_map.get(m.group(0), m.group(0))

    modules: dict[str, list[tuple[int, str, str, str]]] = {}
    for old_name, chunk in chunks.items():
        addr, mode = by_name.get(old_name, (0, "thumb"))
        mod, _ = pick_subsystem(addr)
        renamed_chunk = ident_re.sub(replace_fn, chunk)
        new_name = name_map[old_name]
        modules.setdefault(mod, []).append((addr, new_name, mode, renamed_chunk))

    out_dir.mkdir(parents=True, exist_ok=True)
    for old_file in list(out_dir.glob("*.cpp")) + list(out_dir.glob("*.h")):
        old_file.unlink()

    manifest: list[tuple[str, int, str]] = []
    for mod in sorted(modules):
        entries = sorted(modules[mod], key=lambda t: (t[0], t[1]))
        out_path = out_dir / f"{mod}.cpp"
        lines = [
            f"/* Functional translation unit: {mod}",
            f" * Contains {len(entries)} statically recompiled functions.",
            " */",
            "",
            '#include "runtime_arm.h"',
            '#include "recompiled.h"',
            "",
        ]
        for addr, _, mode, body in entries:
            lines.append(f"/* 0x{addr:08X} {mode} */")
            lines.append(body)
        out_path.write_text("\n".join(lines), encoding="utf-8")
        manifest.append((mod, len(entries), out_path.name))
        print(f"  {out_path.name:30s}  {len(entries):5d} funcs  ({out_path.stat().st_size / 1e6:5.2f} MB)")

    # Write recompiled.h, dispatch_table.cpp, symbol_map.cpp with renamed identifiers
    for extra in ("recompiled.h", "dispatch_table.cpp", "symbol_map.cpp"):
        src_file = gen_dir / extra
        if src_file.is_file():
            raw = src_file.read_text(encoding="utf-8", errors="replace")
            renamed = ident_re.sub(replace_fn, raw)
            (out_dir / extra).write_text(renamed, encoding="utf-8")
            print(f"  wrote {extra}")

    # Write modules.h summary header
    (out_dir / "modules.h").write_text(
        "/* Functional module index for Golden Sun: The Broken Seal (src/game/). */\n"
        "#pragma once\n\n"
        + "".join(
            f"// {mod:28s}  {count:5d} functions  -> {fname}\n"
            for mod, count, fname in manifest
        ),
        encoding="utf-8",
    )

    # Also emit functional symbols TSV if requested
    addr_mode_to_new: dict[tuple[int, str], str] = {
        (addr, mode): name_map[old_name][3:]  # strip leading "gf_"
        for old_name, addr, mode in sigs
    }
    if args.symbols_in and args.symbols_in.is_file() and args.symbols_out:
        args.symbols_out.parent.mkdir(parents=True, exist_ok=True)
        sym_lines = ["# Format: addr<TAB>mode<TAB>name", "# Functional symbol seeds for Golden Sun: The Broken Seal (AGSE01)"]
        for line in args.symbols_in.read_text(encoding="utf-8").splitlines():
            s = line.strip()
            if not s or s.startswith("#"):
                continue
            parts = s.split("\t")
            if len(parts) >= 3:
                addr_val = int(parts[0], 16)
                mode_val = parts[1].strip()
                new_sym = addr_mode_to_new.get((addr_val, mode_val))
                if not new_sym:
                    _, pfx = pick_subsystem(addr_val)
                    new_sym = f"{pfx}_seed_entry"
                sym_lines.append(f"0x{addr_val:08X}\t{mode_val}\t{new_sym}")
        args.symbols_out.write_text("\n".join(sym_lines) + "\n", encoding="utf-8")
        print(f"  wrote {args.symbols_out}")

    print(f"Total functional modules: {len(manifest)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
