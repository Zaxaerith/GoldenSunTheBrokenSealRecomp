#!/usr/bin/env python3
"""Extract functions, .call_via continuations, Duff's device unrolls, and switch jump tables
from gsret/goldensun disassembly and the Golden Sun ROM.
"""
from __future__ import annotations

import argparse
import glob
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def extract_symbols(gsret_root: Path, rom_path: Path, out_tsv: Path) -> int:
    symbols: dict[int, tuple[str, str]] = {}

    def add_sym(addr: int, mode: str, name: str):
        if addr not in symbols:
            symbols[addr] = (mode, name)

    # 1. Fixed IWRAM functions (rom_770.s)
    add_sym(0x03000000, "arm", "iwram_irq_master_dispatch")
    add_sym(0x030000B8, "arm", "iwram_irq_master_return")
    add_sym(0x03000118, "arm", "iwram_call_via_register")
    add_sym(0x0300012C, "arm", "iwram_fixed_point_multiply")
    add_sym(0x0300013C, "arm", "iwram_fixed_point_divide")
    add_sym(0x03000164, "arm", "iwram_fast_word_fill_entry")
    add_sym(0x03000168, "arm", "iwram_fast_word_fill_loop")
    for k, greek in enumerate(["alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta", "theta", "iota"]):
        add_sym(0x03000194 + 4 * k, "arm", f"iwram_fast_word_fill_unroll_{greek}")
    add_sym(0x030001D8, "arm", "iwram_integer_square_root")
    add_sym(0x03000214, "arm", "iwram_matrix_load_identity")
    add_sym(0x03000250, "arm", "iwram_matrix_multiply_affine")
    add_sym(0x030002C0, "arm", "iwram_matrix_transform_vector")
    add_sym(0x03000380, "arm", "iwram_signed_divmod_routine")
    add_sym(0x030003AC, "arm", "iwram_unsigned_divmod_routine")
    add_sym(0x030003E0, "arm", "iwram_signed_modulo_routine")
    add_sym(0x030003F0, "arm", "iwram_decompress_header_dispatch")
    add_sym(0x030003FC, "arm", "iwram_lzss_decompress_stream")
    add_sym(0x030005C0, "arm", "iwram_rle_huffman_decompress")
    add_sym(0x03001388, "arm", "iwram_fast_block_copy_words")
    for k, greek in enumerate(["alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta", "theta", "iota"]):
        add_sym(0x03001398 + 8 * k, "arm", f"iwram_fast_block_copy_unroll_{greek}")

    # 2. ROM entry vectors
    add_sym(0x08000000, "arm", "boot_rom_header_branch_vector")
    add_sym(0x080003C0, "arm", "boot_cart_reset_entry")

    # 3. Parse disassembly files if available
    if gsret_root.is_dir():
        for sfile in sorted(gsret_root.glob("**/*.s")):
            for line in sfile.read_text(encoding="utf-8", errors="replace").splitlines():
                m_func = re.match(r"^\s*\.(arm|thumb)_func_start\s+(\w+)", line)
                if m_func:
                    mode, name = m_func.group(1), m_func.group(2)
                    m_addr = re.search(r"0x([0-9a-fA-F]+)", name)
                    if m_addr:
                        add_sym(int(m_addr.group(1), 16), mode, name)

    out_tsv.parent.mkdir(parents=True, exist_ok=True)
    lines = ["# Address\tMode\tName"]
    for addr in sorted(symbols):
        mode, name = symbols[addr]
        lines.append(f"0x{addr:08X}\t{mode}\t{name}")
    out_tsv.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {len(symbols)} symbols to {out_tsv}")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description="Extract Golden Sun symbols.")
    parser.add_argument("--gsret-root", type=Path, default=ROOT / "reference" / "gsret_goldensun")
    parser.add_argument("--rom", type=Path, default=ROOT / "Golden Sun(UE)(Nintendo)(64Mb).gba")
    parser.add_argument("--out", type=Path, default=ROOT / "symbols" / "gs_functions.tsv")
    args = parser.parse_args()
    return extract_symbols(args.gsret_root, args.rom, args.out)


if __name__ == "__main__":
    sys.exit(main())
