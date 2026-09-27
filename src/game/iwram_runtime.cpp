/* Functional translation unit: iwram_runtime
 * Contains 62 statically recompiled functions.
 */

#include "runtime_arm.h"
#include "recompiled.h"

/* 0x03000000 arm */
void gf_iwram_irq_master_dispatch(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000000u);
    /* 03000000  03000000 A mov r3,#0x4000000 */
    g_cpu.R[15] = 0x03000000u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000000 = 1u;
    _cyc_03000000 = 1u;
    uint32_t _r_03000000;
    _r_03000000 = 0x04000000u;
    g_cpu.R[3] = _r_03000000;
    g_cpu.R[15] = 0x03000004u;
    runtime_tick(_cyc_03000000);
    /* 03000004  03000004 A ldr r2,[r3,#0x200]! */
    g_cpu.R[15] = 0x03000004u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000004 = 1u;
    _cyc_03000004 = 2u;
    uint32_t _base_03000004 = g_cpu.R[3];
    uint32_t _off_03000004;
    _off_03000004 = 0x00000200u;
    uint32_t _ea_03000004 = _base_03000004 + _off_03000004;
    uint32_t _post_03000004 = _base_03000004 + _off_03000004;
    _cyc_03000004 += runtime_mem_cycles(_ea_03000004, 4u, 0u);
    uint32_t _v_03000004;
    { uint32_t _w = bus_read_u32(_ea_03000004 & ~3u); uint32_t _rot = (_ea_03000004 & 3u) * 8u; _v_03000004 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
    if (3u != 2u) g_cpu.R[3] = _ea_03000004;
    g_cpu.R[2] = _v_03000004;
    g_cpu.R[15] = 0x03000008u;
    runtime_tick(_cyc_03000004);
    /* 03000008  03000008 A ldrh r1,[r3,#0x8] */
    g_cpu.R[15] = 0x03000008u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000008 = 1u;
    _cyc_03000008 = 2u;
    uint32_t _base_03000008 = g_cpu.R[3];
    uint32_t _off_03000008;
    _off_03000008 = 0x00000008u;
    uint32_t _ea_03000008 = _base_03000008 + _off_03000008;
    uint32_t _post_03000008 = _base_03000008 + _off_03000008;
    _cyc_03000008 += runtime_mem_cycles(_ea_03000008, 2u, 0u);
    uint32_t _v_03000008;
    { uint32_t _h = bus_read_u16(_ea_03000008 & ~1u); if (_ea_03000008 & 1u) _v_03000008 = ((_h >> 8) | (_h << 24)); else _v_03000008 = _h; }
    g_cpu.R[1] = _v_03000008;
    g_cpu.R[15] = 0x0300000Cu;
    runtime_tick(_cyc_03000008);
    /* 0300000C  0300000c A mrs r0,spsr */
    g_cpu.R[15] = 0x0300000Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300000C = 1u;
    _cyc_0300000C = 1u;
    g_cpu.R[0] = runtime_mrs_spsr();
    g_cpu.R[15] = 0x03000010u;
    runtime_tick(_cyc_0300000C);
    /* 03000010  03000010 A stm r13!,{r0,r1,r2,r3,r4,r5,r14} */
    g_cpu.R[15] = 0x03000010u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000010 = 1u;
    _cyc_03000010 = 1u;
    uint32_t _b_03000010 = g_cpu.R[13];
    uint32_t _a_03000010 = _b_03000010 - 28u;
    uint32_t _fb_03000010 = _b_03000010 - 28u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[0], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[0]);
    _a_03000010 += 4u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[1], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[1]);
    _a_03000010 += 4u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[2]);
    _a_03000010 += 4u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[3]);
    _a_03000010 += 4u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[4]);
    _a_03000010 += 4u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[5]);
    _a_03000010 += 4u;
    _cyc_03000010 += runtime_mem_cycles(_a_03000010 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000010u, _a_03000010 & ~3u, g_cpu.R[14], 4u);
    bus_write_u32(_a_03000010 & ~3u, g_cpu.R[14]);
    _a_03000010 += 4u;
    g_cpu.R[13] = _fb_03000010;
    g_cpu.R[15] = 0x03000014u;
    runtime_tick(_cyc_03000010);
    /* 03000014  03000014 A mov r0,#0x1 */
    g_cpu.R[15] = 0x03000014u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000014 = 1u;
    _cyc_03000014 = 1u;
    uint32_t _r_03000014;
    _r_03000014 = 0x00000001u;
    g_cpu.R[0] = _r_03000014;
    g_cpu.R[15] = 0x03000018u;
    runtime_tick(_cyc_03000014);
    /* 03000018  03000018 A strh r0,[r3,#0x8] */
    g_cpu.R[15] = 0x03000018u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000018 = 1u;
    _cyc_03000018 = 1u;
    uint32_t _base_03000018 = g_cpu.R[3];
    uint32_t _off_03000018;
    _off_03000018 = 0x00000008u;
    uint32_t _ea_03000018 = _base_03000018 + _off_03000018;
    uint32_t _post_03000018 = _base_03000018 + _off_03000018;
    _cyc_03000018 += runtime_mem_cycles(_ea_03000018, 2u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000018u, _ea_03000018 & ~1u, (uint32_t)(g_cpu.R[0] & 0xFFFFu), 2u);
    bus_write_u16(_ea_03000018 & ~1u, (uint16_t)(g_cpu.R[0] & 0xFFFFu));
    g_cpu.R[15] = 0x0300001Cu;
    runtime_tick(_cyc_03000018);
    /* 0300001C  0300001c A and r1,r2,r2,lsr #16 */
    g_cpu.R[15] = 0x0300001Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300001C = 1u;
    _cyc_0300001C = 1u;
    uint32_t _rm_0300001C = g_cpu.R[2];
    uint32_t _op2_0300001C;
    uint32_t _co_0300001C;
    _op2_0300001C = _rm_0300001C >> 16;
    _co_0300001C = (_rm_0300001C >> 15) & 1u;
    uint32_t _rn_0300001C = g_cpu.R[2];
    uint32_t _r_0300001C;
    _r_0300001C = _rn_0300001C & _op2_0300001C;
    g_cpu.R[1] = _r_0300001C;
    g_cpu.R[15] = 0x03000020u;
    runtime_tick(_cyc_0300001C);
    /* 03000020  03000020 A ands r0,r1,#0x2 */
    g_cpu.R[15] = 0x03000020u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000020 = 1u;
    _cyc_03000020 = 1u;
    uint32_t _rn_03000020 = g_cpu.R[1];
    uint32_t _r_03000020;
    _r_03000020 = _rn_03000020 & 0x00000002u;
    arm_set_nzc_logic(_r_03000020, cpsr_c());
    g_cpu.R[0] = _r_03000020;
    g_cpu.R[15] = 0x03000024u;
    runtime_tick(_cyc_03000020);
    /* 03000024  03000024 A ldrne r12,[r15,#0xb8] */
    g_cpu.R[15] = 0x03000024u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000024 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000024 = 2u;
        uint32_t _base_03000024 = 0x0300002Cu;
        uint32_t _off_03000024;
        _off_03000024 = 0x000000B8u;
        uint32_t _ea_03000024 = _base_03000024 + _off_03000024;
        uint32_t _post_03000024 = _base_03000024 + _off_03000024;
        _cyc_03000024 += runtime_mem_cycles(_ea_03000024, 4u, 0u);
        uint32_t _v_03000024;
        { uint32_t _w = bus_read_u32(_ea_03000024 & ~3u); uint32_t _rot = (_ea_03000024 & 3u) * 8u; _v_03000024 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_03000024;
    }
    g_cpu.R[15] = 0x03000028u;
    runtime_tick(_cyc_03000024);
    /* 03000028  03000028 A bne 0x03000088 */
    g_cpu.R[15] = 0x03000028u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000028 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000028 = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_03000028);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x0300002Cu;
    runtime_tick(_cyc_03000028);
    /* 0300002C  0300002c A ands r0,r1,#0x1 */
    g_cpu.R[15] = 0x0300002Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300002C = 1u;
    _cyc_0300002C = 1u;
    uint32_t _rn_0300002C = g_cpu.R[1];
    uint32_t _r_0300002C;
    _r_0300002C = _rn_0300002C & 0x00000001u;
    arm_set_nzc_logic(_r_0300002C, cpsr_c());
    g_cpu.R[0] = _r_0300002C;
    g_cpu.R[15] = 0x03000030u;
    runtime_tick(_cyc_0300002C);
    /* 03000030  03000030 A ldrne r12,[r15,#0xa8] */
    g_cpu.R[15] = 0x03000030u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000030 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000030 = 2u;
        uint32_t _base_03000030 = 0x03000038u;
        uint32_t _off_03000030;
        _off_03000030 = 0x000000A8u;
        uint32_t _ea_03000030 = _base_03000030 + _off_03000030;
        uint32_t _post_03000030 = _base_03000030 + _off_03000030;
        _cyc_03000030 += runtime_mem_cycles(_ea_03000030, 4u, 0u);
        uint32_t _v_03000030;
        { uint32_t _w = bus_read_u32(_ea_03000030 & ~3u); uint32_t _rot = (_ea_03000030 & 3u) * 8u; _v_03000030 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_03000030;
    }
    g_cpu.R[15] = 0x03000034u;
    runtime_tick(_cyc_03000030);
    /* 03000034  03000034 A bne 0x03000088 */
    g_cpu.R[15] = 0x03000034u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000034 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000034 = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_03000034);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000038u;
    runtime_tick(_cyc_03000034);
    /* 03000038  03000038 A ands r0,r1,#0x4 */
    g_cpu.R[15] = 0x03000038u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000038 = 1u;
    _cyc_03000038 = 1u;
    uint32_t _rn_03000038 = g_cpu.R[1];
    uint32_t _r_03000038;
    _r_03000038 = _rn_03000038 & 0x00000004u;
    arm_set_nzc_logic(_r_03000038, cpsr_c());
    g_cpu.R[0] = _r_03000038;
    g_cpu.R[15] = 0x0300003Cu;
    runtime_tick(_cyc_03000038);
    /* 0300003C  0300003c A ldrne r12,[r15,#0xa4] */
    g_cpu.R[15] = 0x0300003Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300003C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300003C = 2u;
        uint32_t _base_0300003C = 0x03000044u;
        uint32_t _off_0300003C;
        _off_0300003C = 0x000000A4u;
        uint32_t _ea_0300003C = _base_0300003C + _off_0300003C;
        uint32_t _post_0300003C = _base_0300003C + _off_0300003C;
        _cyc_0300003C += runtime_mem_cycles(_ea_0300003C, 4u, 0u);
        uint32_t _v_0300003C;
        { uint32_t _w = bus_read_u32(_ea_0300003C & ~3u); uint32_t _rot = (_ea_0300003C & 3u) * 8u; _v_0300003C = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_0300003C;
    }
    g_cpu.R[15] = 0x03000040u;
    runtime_tick(_cyc_0300003C);
    /* 03000040  03000040 A bne 0x03000088 */
    g_cpu.R[15] = 0x03000040u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000040 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000040 = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_03000040);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000044u;
    runtime_tick(_cyc_03000040);
    /* 03000044  03000044 A ands r0,r1,#0x40 */
    g_cpu.R[15] = 0x03000044u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000044 = 1u;
    _cyc_03000044 = 1u;
    uint32_t _rn_03000044 = g_cpu.R[1];
    uint32_t _r_03000044;
    _r_03000044 = _rn_03000044 & 0x00000040u;
    arm_set_nzc_logic(_r_03000044, cpsr_c());
    g_cpu.R[0] = _r_03000044;
    g_cpu.R[15] = 0x03000048u;
    runtime_tick(_cyc_03000044);
    /* 03000048  03000048 A ldrne r12,[r15,#0xa8] */
    g_cpu.R[15] = 0x03000048u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000048 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000048 = 2u;
        uint32_t _base_03000048 = 0x03000050u;
        uint32_t _off_03000048;
        _off_03000048 = 0x000000A8u;
        uint32_t _ea_03000048 = _base_03000048 + _off_03000048;
        uint32_t _post_03000048 = _base_03000048 + _off_03000048;
        _cyc_03000048 += runtime_mem_cycles(_ea_03000048, 4u, 0u);
        uint32_t _v_03000048;
        { uint32_t _w = bus_read_u32(_ea_03000048 & ~3u); uint32_t _rot = (_ea_03000048 & 3u) * 8u; _v_03000048 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_03000048;
    }
    g_cpu.R[15] = 0x0300004Cu;
    runtime_tick(_cyc_03000048);
    /* 0300004C  0300004c A bne 0x03000088 */
    g_cpu.R[15] = 0x0300004Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300004C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300004C = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_0300004C);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000050u;
    runtime_tick(_cyc_0300004C);
    /* 03000050  03000050 A ands r0,r1,#0x80 */
    g_cpu.R[15] = 0x03000050u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000050 = 1u;
    _cyc_03000050 = 1u;
    uint32_t _rn_03000050 = g_cpu.R[1];
    uint32_t _r_03000050;
    _r_03000050 = _rn_03000050 & 0x00000080u;
    arm_set_nzc_logic(_r_03000050, cpsr_c());
    g_cpu.R[0] = _r_03000050;
    g_cpu.R[15] = 0x03000054u;
    runtime_tick(_cyc_03000050);
    /* 03000054  03000054 A ldrne r12,[r15,#0xa0] */
    g_cpu.R[15] = 0x03000054u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000054 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000054 = 2u;
        uint32_t _base_03000054 = 0x0300005Cu;
        uint32_t _off_03000054;
        _off_03000054 = 0x000000A0u;
        uint32_t _ea_03000054 = _base_03000054 + _off_03000054;
        uint32_t _post_03000054 = _base_03000054 + _off_03000054;
        _cyc_03000054 += runtime_mem_cycles(_ea_03000054, 4u, 0u);
        uint32_t _v_03000054;
        { uint32_t _w = bus_read_u32(_ea_03000054 & ~3u); uint32_t _rot = (_ea_03000054 & 3u) * 8u; _v_03000054 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_03000054;
    }
    g_cpu.R[15] = 0x03000058u;
    runtime_tick(_cyc_03000054);
    /* 03000058  03000058 A bne 0x03000088 */
    g_cpu.R[15] = 0x03000058u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000058 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000058 = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_03000058);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x0300005Cu;
    runtime_tick(_cyc_03000058);
    /* 0300005C  0300005c A ands r0,r1,#0x10 */
    g_cpu.R[15] = 0x0300005Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300005C = 1u;
    _cyc_0300005C = 1u;
    uint32_t _rn_0300005C = g_cpu.R[1];
    uint32_t _r_0300005C;
    _r_0300005C = _rn_0300005C & 0x00000010u;
    arm_set_nzc_logic(_r_0300005C, cpsr_c());
    g_cpu.R[0] = _r_0300005C;
    g_cpu.R[15] = 0x03000060u;
    runtime_tick(_cyc_0300005C);
    /* 03000060  03000060 A ldrne r12,[r15,#0x88] */
    g_cpu.R[15] = 0x03000060u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000060 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000060 = 2u;
        uint32_t _base_03000060 = 0x03000068u;
        uint32_t _off_03000060;
        _off_03000060 = 0x00000088u;
        uint32_t _ea_03000060 = _base_03000060 + _off_03000060;
        uint32_t _post_03000060 = _base_03000060 + _off_03000060;
        _cyc_03000060 += runtime_mem_cycles(_ea_03000060, 4u, 0u);
        uint32_t _v_03000060;
        { uint32_t _w = bus_read_u32(_ea_03000060 & ~3u); uint32_t _rot = (_ea_03000060 & 3u) * 8u; _v_03000060 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_03000060;
    }
    g_cpu.R[15] = 0x03000064u;
    runtime_tick(_cyc_03000060);
    /* 03000064  03000064 A bne 0x03000088 */
    g_cpu.R[15] = 0x03000064u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000064 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000064 = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_03000064);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000068u;
    runtime_tick(_cyc_03000064);
    /* 03000068  03000068 A ands r0,r1,#0x20 */
    g_cpu.R[15] = 0x03000068u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000068 = 1u;
    _cyc_03000068 = 1u;
    uint32_t _rn_03000068 = g_cpu.R[1];
    uint32_t _r_03000068;
    _r_03000068 = _rn_03000068 & 0x00000020u;
    arm_set_nzc_logic(_r_03000068, cpsr_c());
    g_cpu.R[0] = _r_03000068;
    g_cpu.R[15] = 0x0300006Cu;
    runtime_tick(_cyc_03000068);
    /* 0300006C  0300006c A ldrne r12,[r15,#0x80] */
    g_cpu.R[15] = 0x0300006Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300006C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300006C = 2u;
        uint32_t _base_0300006C = 0x03000074u;
        uint32_t _off_0300006C;
        _off_0300006C = 0x00000080u;
        uint32_t _ea_0300006C = _base_0300006C + _off_0300006C;
        uint32_t _post_0300006C = _base_0300006C + _off_0300006C;
        _cyc_0300006C += runtime_mem_cycles(_ea_0300006C, 4u, 0u);
        uint32_t _v_0300006C;
        { uint32_t _w = bus_read_u32(_ea_0300006C & ~3u); uint32_t _rot = (_ea_0300006C & 3u) * 8u; _v_0300006C = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_0300006C;
    }
    g_cpu.R[15] = 0x03000070u;
    runtime_tick(_cyc_0300006C);
    /* 03000070  03000070 A bne 0x03000088 */
    g_cpu.R[15] = 0x03000070u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000070 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000070 = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_03000070);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000074u;
    runtime_tick(_cyc_03000070);
    /* 03000074  03000074 A ands r0,r1,#0x1000 */
    g_cpu.R[15] = 0x03000074u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000074 = 1u;
    _cyc_03000074 = 1u;
    uint32_t _rn_03000074 = g_cpu.R[1];
    uint32_t _r_03000074;
    _r_03000074 = _rn_03000074 & 0x00001000u;
    arm_set_nzc_logic(_r_03000074, 0u);
    g_cpu.R[0] = _r_03000074;
    g_cpu.R[15] = 0x03000078u;
    runtime_tick(_cyc_03000074);
    /* 03000078  03000078 A ldrne r12,[r15,#0x90] */
    g_cpu.R[15] = 0x03000078u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000078 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000078 = 2u;
        uint32_t _base_03000078 = 0x03000080u;
        uint32_t _off_03000078;
        _off_03000078 = 0x00000090u;
        uint32_t _ea_03000078 = _base_03000078 + _off_03000078;
        uint32_t _post_03000078 = _base_03000078 + _off_03000078;
        _cyc_03000078 += runtime_mem_cycles(_ea_03000078, 4u, 0u);
        uint32_t _v_03000078;
        { uint32_t _w = bus_read_u32(_ea_03000078 & ~3u); uint32_t _rot = (_ea_03000078 & 3u) * 8u; _v_03000078 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
        g_cpu.R[12] = _v_03000078;
    }
    g_cpu.R[15] = 0x0300007Cu;
    runtime_tick(_cyc_03000078);
    /* 0300007C  0300007c A bne 0x03000088 */
    g_cpu.R[15] = 0x0300007Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300007C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300007C = 3u;
        g_cpu.R[15] = 0x03000088u;
        runtime_tick(_cyc_0300007C);
        gf_iwram_fast_ram_work_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000080u;
    runtime_tick(_cyc_0300007C);
    /* 03000080  03000080 A ands r0,r1,#0x2000 */
    g_cpu.R[15] = 0x03000080u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000080 = 1u;
    _cyc_03000080 = 1u;
    uint32_t _rn_03000080 = g_cpu.R[1];
    uint32_t _r_03000080;
    _r_03000080 = _rn_03000080 & 0x00002000u;
    arm_set_nzc_logic(_r_03000080, 0u);
    g_cpu.R[0] = _r_03000080;
    g_cpu.R[15] = 0x03000084u;
    runtime_tick(_cyc_03000080);
    /* 03000084  03000084 A ldr r12,[r15,#0x88] */
    g_cpu.R[15] = 0x03000084u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000084 = 1u;
    _cyc_03000084 = 2u;
    uint32_t _base_03000084 = 0x0300008Cu;
    uint32_t _off_03000084;
    _off_03000084 = 0x00000088u;
    uint32_t _ea_03000084 = _base_03000084 + _off_03000084;
    uint32_t _post_03000084 = _base_03000084 + _off_03000084;
    _cyc_03000084 += runtime_mem_cycles(_ea_03000084, 4u, 0u);
    uint32_t _v_03000084;
    { uint32_t _w = bus_read_u32(_ea_03000084 & ~3u); uint32_t _rot = (_ea_03000084 & 3u) * 8u; _v_03000084 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
    g_cpu.R[12] = _v_03000084;
    g_cpu.R[15] = 0x03000088u;
    runtime_tick(_cyc_03000084);
    /* fall-through to 0x03000088 */
    g_cpu.R[15] = 0x03000088u;
    runtime_dispatch(0x03000088u);
    return;
}

/* 0x03000198  mode=arm  end=0x0300019C  branches=3  indirect */


/* 0x03000088 arm */
void gf_iwram_fast_ram_work_entry_init(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000088u);
    /* 03000088  03000088 A strh r0,[r3,#0x2] */
    g_cpu.R[15] = 0x03000088u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000088 = 1u;
    _cyc_03000088 = 1u;
    uint32_t _base_03000088 = g_cpu.R[3];
    uint32_t _off_03000088;
    _off_03000088 = 0x00000002u;
    uint32_t _ea_03000088 = _base_03000088 + _off_03000088;
    uint32_t _post_03000088 = _base_03000088 + _off_03000088;
    _cyc_03000088 += runtime_mem_cycles(_ea_03000088, 2u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000088u, _ea_03000088 & ~1u, (uint32_t)(g_cpu.R[0] & 0xFFFFu), 2u);
    bus_write_u16(_ea_03000088 & ~1u, (uint16_t)(g_cpu.R[0] & 0xFFFFu));
    g_cpu.R[15] = 0x0300008Cu;
    runtime_tick(_cyc_03000088);
    /* 0300008C  0300008c A mov r1,#0x20c0 */
    g_cpu.R[15] = 0x0300008Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300008C = 1u;
    _cyc_0300008C = 1u;
    uint32_t _r_0300008C;
    _r_0300008C = 0x000020C0u;
    g_cpu.R[1] = _r_0300008C;
    g_cpu.R[15] = 0x03000090u;
    runtime_tick(_cyc_0300008C);
    /* 03000090  03000090 A bic r2,r2,r0 */
    g_cpu.R[15] = 0x03000090u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000090 = 1u;
    _cyc_03000090 = 1u;
    uint32_t _rm_03000090 = g_cpu.R[0];
    uint32_t _op2_03000090;
    uint32_t _co_03000090;
    _op2_03000090 = _rm_03000090;
    _co_03000090 = cpsr_c();
    uint32_t _rn_03000090 = g_cpu.R[2];
    uint32_t _r_03000090;
    _r_03000090 = _rn_03000090 & ~(_op2_03000090);
    g_cpu.R[2] = _r_03000090;
    g_cpu.R[15] = 0x03000094u;
    runtime_tick(_cyc_03000090);
    /* 03000094  03000094 A and r1,r1,r2 */
    g_cpu.R[15] = 0x03000094u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000094 = 1u;
    _cyc_03000094 = 1u;
    uint32_t _rm_03000094 = g_cpu.R[2];
    uint32_t _op2_03000094;
    uint32_t _co_03000094;
    _op2_03000094 = _rm_03000094;
    _co_03000094 = cpsr_c();
    uint32_t _rn_03000094 = g_cpu.R[1];
    uint32_t _r_03000094;
    _r_03000094 = _rn_03000094 & _op2_03000094;
    g_cpu.R[1] = _r_03000094;
    g_cpu.R[15] = 0x03000098u;
    runtime_tick(_cyc_03000094);
    /* 03000098  03000098 A strh r1,[r3] */
    g_cpu.R[15] = 0x03000098u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000098 = 1u;
    _cyc_03000098 = 1u;
    uint32_t _base_03000098 = g_cpu.R[3];
    uint32_t _off_03000098;
    _off_03000098 = 0x00000000u;
    uint32_t _ea_03000098 = _base_03000098 + _off_03000098;
    uint32_t _post_03000098 = _base_03000098 + _off_03000098;
    _cyc_03000098 += runtime_mem_cycles(_ea_03000098, 2u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000098u, _ea_03000098 & ~1u, (uint32_t)(g_cpu.R[1] & 0xFFFFu), 2u);
    bus_write_u16(_ea_03000098 & ~1u, (uint16_t)(g_cpu.R[1] & 0xFFFFu));
    g_cpu.R[15] = 0x0300009Cu;
    runtime_tick(_cyc_03000098);
    /* 0300009C  0300009c A mrs r3,cpsr */
    g_cpu.R[15] = 0x0300009Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300009C = 1u;
    _cyc_0300009C = 1u;
    g_cpu.R[3] = runtime_mrs_cpsr();
    g_cpu.R[15] = 0x030000A0u;
    runtime_tick(_cyc_0300009C);
    /* 030000A0  030000a0 A bic r3,r3,#0xdf */
    g_cpu.R[15] = 0x030000A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000A0 = 1u;
    _cyc_030000A0 = 1u;
    uint32_t _rn_030000A0 = g_cpu.R[3];
    uint32_t _r_030000A0;
    _r_030000A0 = _rn_030000A0 & ~(0x000000DFu);
    g_cpu.R[3] = _r_030000A0;
    g_cpu.R[15] = 0x030000A4u;
    runtime_tick(_cyc_030000A0);
    /* 030000A4  030000a4 A orr r3,r3,#0x1f */
    g_cpu.R[15] = 0x030000A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000A4 = 1u;
    _cyc_030000A4 = 1u;
    uint32_t _rn_030000A4 = g_cpu.R[3];
    uint32_t _r_030000A4;
    _r_030000A4 = _rn_030000A4 | 0x0000001Fu;
    g_cpu.R[3] = _r_030000A4;
    g_cpu.R[15] = 0x030000A8u;
    runtime_tick(_cyc_030000A4);
    /* 030000A8  030000a8 A msr cpsr_cf,r3 */
    g_cpu.R[15] = 0x030000A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000A8 = 1u;
    _cyc_030000A8 = 1u;
    uint32_t _msrv_030000A8;
    _msrv_030000A8 = g_cpu.R[3];
    runtime_msr_cpsr(_msrv_030000A8, 9u);
    g_cpu.R[15] = 0x030000ACu;
    runtime_tick(_cyc_030000A8);
    /* 030000AC  030000ac A mov r5,r14 */
    g_cpu.R[15] = 0x030000ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000AC = 1u;
    _cyc_030000AC = 1u;
    uint32_t _rm_030000AC = g_cpu.R[14];
    uint32_t _op2_030000AC;
    uint32_t _co_030000AC;
    _op2_030000AC = _rm_030000AC;
    _co_030000AC = cpsr_c();
    uint32_t _r_030000AC;
    _r_030000AC = _op2_030000AC;
    g_cpu.R[5] = _r_030000AC;
    g_cpu.R[15] = 0x030000B0u;
    runtime_tick(_cyc_030000AC);
    /* 030000B0  030000b0 A add r14,r15,#0x0 */
    g_cpu.R[15] = 0x030000B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000B0 = 1u;
    _cyc_030000B0 = 1u;
    uint32_t _rn_030000B0 = 0x030000B8u;
    uint32_t _r_030000B0;
    _r_030000B0 = _rn_030000B0 + 0x00000000u;
    g_cpu.R[14] = _r_030000B0;
    g_cpu.R[15] = 0x030000B4u;
    runtime_tick(_cyc_030000B0);
    /* 030000B4  030000b4 A bx r12 */
    g_cpu.R[15] = 0x030000B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000B4 = 1u;
    _cyc_030000B4 = 3u;
    uint32_t _bxt_030000B4 = g_cpu.R[12];
    g_cpu.R[15] = _bxt_030000B4 & ~1u;
    runtime_tick(_cyc_030000B4);
    runtime_dispatch_with_exchange(_bxt_030000B4);
    return;
    g_cpu.R[15] = 0x030000B8u;
    runtime_tick(_cyc_030000B4);
    /* fall-through to 0x030000B8 */
    g_cpu.R[15] = 0x030000B8u;
    runtime_dispatch(0x030000B8u);
    return;
}

/* 0x03000194  mode=arm  end=0x03000198  branches=3  indirect */


/* 0x030000B8 arm */
void gf_iwram_irq_master_return(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030000B8u);
    /* 030000B8  030000b8 A mov r14,r5 */
    g_cpu.R[15] = 0x030000B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000B8 = 1u;
    _cyc_030000B8 = 1u;
    uint32_t _rm_030000B8 = g_cpu.R[5];
    uint32_t _op2_030000B8;
    uint32_t _co_030000B8;
    _op2_030000B8 = _rm_030000B8;
    _co_030000B8 = cpsr_c();
    uint32_t _r_030000B8;
    _r_030000B8 = _op2_030000B8;
    g_cpu.R[14] = _r_030000B8;
    g_cpu.R[15] = 0x030000BCu;
    runtime_tick(_cyc_030000B8);
    /* 030000BC  030000bc A mrs r3,cpsr */
    g_cpu.R[15] = 0x030000BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000BC = 1u;
    _cyc_030000BC = 1u;
    g_cpu.R[3] = runtime_mrs_cpsr();
    g_cpu.R[15] = 0x030000C0u;
    runtime_tick(_cyc_030000BC);
    /* 030000C0  030000c0 A bic r3,r3,#0xdf */
    g_cpu.R[15] = 0x030000C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000C0 = 1u;
    _cyc_030000C0 = 1u;
    uint32_t _rn_030000C0 = g_cpu.R[3];
    uint32_t _r_030000C0;
    _r_030000C0 = _rn_030000C0 & ~(0x000000DFu);
    g_cpu.R[3] = _r_030000C0;
    g_cpu.R[15] = 0x030000C4u;
    runtime_tick(_cyc_030000C0);
    /* 030000C4  030000c4 A orr r3,r3,#0x92 */
    g_cpu.R[15] = 0x030000C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000C4 = 1u;
    _cyc_030000C4 = 1u;
    uint32_t _rn_030000C4 = g_cpu.R[3];
    uint32_t _r_030000C4;
    _r_030000C4 = _rn_030000C4 | 0x00000092u;
    g_cpu.R[3] = _r_030000C4;
    g_cpu.R[15] = 0x030000C8u;
    runtime_tick(_cyc_030000C4);
    /* 030000C8  030000c8 A msr cpsr_cf,r3 */
    g_cpu.R[15] = 0x030000C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000C8 = 1u;
    _cyc_030000C8 = 1u;
    uint32_t _msrv_030000C8;
    _msrv_030000C8 = g_cpu.R[3];
    runtime_msr_cpsr(_msrv_030000C8, 9u);
    g_cpu.R[15] = 0x030000CCu;
    runtime_tick(_cyc_030000C8);
    /* 030000CC  030000cc A ldm r13!,{r0,r1,r2,r3,r4,r5,r14} */
    g_cpu.R[15] = 0x030000CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000CC = 1u;
    _cyc_030000CC = 2u;
    uint32_t _b_030000CC = g_cpu.R[13];
    uint32_t _a_030000CC = _b_030000CC;
    uint32_t _fb_030000CC = _b_030000CC + 28u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 0u);
    g_cpu.R[0] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 1u);
    g_cpu.R[1] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 1u);
    g_cpu.R[2] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 1u);
    g_cpu.R[3] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    _cyc_030000CC += runtime_mem_cycles(_a_030000CC & ~3u, 4u, 1u);
    g_cpu.R[14] = bus_read_u32(_a_030000CC & ~3u);
    _a_030000CC += 4u;
    g_cpu.R[13] = _fb_030000CC;
    g_cpu.R[15] = 0x030000D0u;
    runtime_tick(_cyc_030000CC);
    /* 030000D0  030000d0 A strh r2,[r3] */
    g_cpu.R[15] = 0x030000D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000D0 = 1u;
    _cyc_030000D0 = 1u;
    uint32_t _base_030000D0 = g_cpu.R[3];
    uint32_t _off_030000D0;
    _off_030000D0 = 0x00000000u;
    uint32_t _ea_030000D0 = _base_030000D0 + _off_030000D0;
    uint32_t _post_030000D0 = _base_030000D0 + _off_030000D0;
    _cyc_030000D0 += runtime_mem_cycles(_ea_030000D0, 2u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030000D0u, _ea_030000D0 & ~1u, (uint32_t)(g_cpu.R[2] & 0xFFFFu), 2u);
    bus_write_u16(_ea_030000D0 & ~1u, (uint16_t)(g_cpu.R[2] & 0xFFFFu));
    g_cpu.R[15] = 0x030000D4u;
    runtime_tick(_cyc_030000D0);
    /* 030000D4  030000d4 A strh r1,[r3,#0x8] */
    g_cpu.R[15] = 0x030000D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000D4 = 1u;
    _cyc_030000D4 = 1u;
    uint32_t _base_030000D4 = g_cpu.R[3];
    uint32_t _off_030000D4;
    _off_030000D4 = 0x00000008u;
    uint32_t _ea_030000D4 = _base_030000D4 + _off_030000D4;
    uint32_t _post_030000D4 = _base_030000D4 + _off_030000D4;
    _cyc_030000D4 += runtime_mem_cycles(_ea_030000D4, 2u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030000D4u, _ea_030000D4 & ~1u, (uint32_t)(g_cpu.R[1] & 0xFFFFu), 2u);
    bus_write_u16(_ea_030000D4 & ~1u, (uint16_t)(g_cpu.R[1] & 0xFFFFu));
    g_cpu.R[15] = 0x030000D8u;
    runtime_tick(_cyc_030000D4);
    /* 030000D8  030000d8 A msr spsr_cf,r0 */
    g_cpu.R[15] = 0x030000D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000D8 = 1u;
    _cyc_030000D8 = 1u;
    uint32_t _msrv_030000D8;
    _msrv_030000D8 = g_cpu.R[0];
    runtime_msr_spsr(_msrv_030000D8, 9u);
    g_cpu.R[15] = 0x030000DCu;
    runtime_tick(_cyc_030000D8);
    /* 030000DC  030000dc A bx r14 */
    g_cpu.R[15] = 0x030000DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030000DC = 1u;
    _cyc_030000DC = 3u;
    uint32_t _bxt_030000DC = g_cpu.R[14];
    g_cpu.R[15] = _bxt_030000DC & ~1u;
    runtime_tick(_cyc_030000DC);
    if (_bxt_030000DC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030000DC);
    return;
    g_cpu.R[15] = 0x030000E0u;
    runtime_tick(_cyc_030000DC);
    /* fall-through to 0x030000E0 */
    g_cpu.R[15] = 0x030000E0u;
    runtime_dispatch(0x030000E0u);
    return;
}

/* 0x0300019C  mode=arm  end=0x030001A0  branches=3  indirect */


/* 0x03000118 arm */
void gf_iwram_call_via_register(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000118u);
    /* 03000118  03000118 A smull raw=0xe0c02091 */
    g_cpu.R[15] = 0x03000118u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000118 = 1u;
    _cyc_03000118 = 1u;
    _cyc_03000118 += runtime_mul_cycles(g_cpu.R[0], 1u, 1u);
    int64_t _p_03000118 = (int64_t)(int32_t)g_cpu.R[1] * (int64_t)(int32_t)g_cpu.R[0];
    g_cpu.R[2] = (uint32_t)((uint64_t)_p_03000118 & 0xFFFFFFFFu);
    g_cpu.R[0] = (uint32_t)((uint64_t)_p_03000118 >> 32);
    g_cpu.R[15] = 0x0300011Cu;
    runtime_tick(_cyc_03000118);
    /* 0300011C  0300011c A mov r0,r0,lsl #16 */
    g_cpu.R[15] = 0x0300011Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300011C = 1u;
    _cyc_0300011C = 1u;
    uint32_t _rm_0300011C = g_cpu.R[0];
    uint32_t _op2_0300011C;
    uint32_t _co_0300011C;
    _op2_0300011C = _rm_0300011C << 16;
    _co_0300011C = (_rm_0300011C >> 16) & 1u;
    uint32_t _r_0300011C;
    _r_0300011C = _op2_0300011C;
    g_cpu.R[0] = _r_0300011C;
    g_cpu.R[15] = 0x03000120u;
    runtime_tick(_cyc_0300011C);
    /* 03000120  03000120 A orr r0,r0,r2,lsr #16 */
    g_cpu.R[15] = 0x03000120u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000120 = 1u;
    _cyc_03000120 = 1u;
    uint32_t _rm_03000120 = g_cpu.R[2];
    uint32_t _op2_03000120;
    uint32_t _co_03000120;
    _op2_03000120 = _rm_03000120 >> 16;
    _co_03000120 = (_rm_03000120 >> 15) & 1u;
    uint32_t _rn_03000120 = g_cpu.R[0];
    uint32_t _r_03000120;
    _r_03000120 = _rn_03000120 | _op2_03000120;
    g_cpu.R[0] = _r_03000120;
    g_cpu.R[15] = 0x03000124u;
    runtime_tick(_cyc_03000120);
    /* 03000124  03000124 A add r12,r12,#0x1 */
    g_cpu.R[15] = 0x03000124u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000124 = 1u;
    _cyc_03000124 = 1u;
    uint32_t _rn_03000124 = g_cpu.R[12];
    uint32_t _r_03000124;
    _r_03000124 = _rn_03000124 + 0x00000001u;
    g_cpu.R[12] = _r_03000124;
    g_cpu.R[15] = 0x03000128u;
    runtime_tick(_cyc_03000124);
    /* 03000128  03000128 A bx r12 */
    g_cpu.R[15] = 0x03000128u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000128 = 1u;
    _cyc_03000128 = 3u;
    uint32_t _bxt_03000128 = g_cpu.R[12];
    g_cpu.R[15] = _bxt_03000128 & ~1u;
    runtime_tick(_cyc_03000128);
    runtime_dispatch_with_exchange(_bxt_03000128);
    return;
    g_cpu.R[15] = 0x0300012Cu;
    runtime_tick(_cyc_03000128);
    /* fall-through to 0x0300012C */
    g_cpu.R[15] = 0x0300012Cu;
    runtime_dispatch(0x0300012Cu);
    return;
}

/* 0x0300013C  mode=arm  end=0x03000164  branches=1  indirect */


/* 0x0300012C arm */
void gf_iwram_fixed_point_multiply(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300012Cu);
    /* 0300012C  0300012c A smull raw=0xe0c02091 */
    g_cpu.R[15] = 0x0300012Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300012C = 1u;
    _cyc_0300012C = 1u;
    _cyc_0300012C += runtime_mul_cycles(g_cpu.R[0], 1u, 1u);
    int64_t _p_0300012C = (int64_t)(int32_t)g_cpu.R[1] * (int64_t)(int32_t)g_cpu.R[0];
    g_cpu.R[2] = (uint32_t)((uint64_t)_p_0300012C & 0xFFFFFFFFu);
    g_cpu.R[0] = (uint32_t)((uint64_t)_p_0300012C >> 32);
    g_cpu.R[15] = 0x03000130u;
    runtime_tick(_cyc_0300012C);
    /* 03000130  03000130 A mov r0,r0,lsl #16 */
    g_cpu.R[15] = 0x03000130u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000130 = 1u;
    _cyc_03000130 = 1u;
    uint32_t _rm_03000130 = g_cpu.R[0];
    uint32_t _op2_03000130;
    uint32_t _co_03000130;
    _op2_03000130 = _rm_03000130 << 16;
    _co_03000130 = (_rm_03000130 >> 16) & 1u;
    uint32_t _r_03000130;
    _r_03000130 = _op2_03000130;
    g_cpu.R[0] = _r_03000130;
    g_cpu.R[15] = 0x03000134u;
    runtime_tick(_cyc_03000130);
    /* 03000134  03000134 A orr r0,r0,r2,lsr #16 */
    g_cpu.R[15] = 0x03000134u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000134 = 1u;
    _cyc_03000134 = 1u;
    uint32_t _rm_03000134 = g_cpu.R[2];
    uint32_t _op2_03000134;
    uint32_t _co_03000134;
    _op2_03000134 = _rm_03000134 >> 16;
    _co_03000134 = (_rm_03000134 >> 15) & 1u;
    uint32_t _rn_03000134 = g_cpu.R[0];
    uint32_t _r_03000134;
    _r_03000134 = _rn_03000134 | _op2_03000134;
    g_cpu.R[0] = _r_03000134;
    g_cpu.R[15] = 0x03000138u;
    runtime_tick(_cyc_03000134);
    /* 03000138  03000138 A bx r14 */
    g_cpu.R[15] = 0x03000138u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000138 = 1u;
    _cyc_03000138 = 3u;
    uint32_t _bxt_03000138 = g_cpu.R[14];
    g_cpu.R[15] = _bxt_03000138 & ~1u;
    runtime_tick(_cyc_03000138);
    if (_bxt_03000138 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_03000138);
    return;
    g_cpu.R[15] = 0x0300013Cu;
    runtime_tick(_cyc_03000138);
    /* fall-through to 0x0300013C */
    g_cpu.R[15] = 0x0300013Cu;
    runtime_dispatch(0x0300013Cu);
    return;
}

/* 0x03000164  mode=arm  end=0x03000168  branches=0  indirect */


/* 0x0300013C arm */
void gf_iwram_fixed_point_divide(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300013Cu);
    /* 0300013C  0300013c A stm r13!,{r14} */
    g_cpu.R[15] = 0x0300013Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300013C = 1u;
    _cyc_0300013C = 1u;
    uint32_t _b_0300013C = g_cpu.R[13];
    uint32_t _a_0300013C = _b_0300013C - 4u;
    uint32_t _fb_0300013C = _b_0300013C - 4u;
    _cyc_0300013C += runtime_mem_cycles(_a_0300013C & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300013Cu, _a_0300013C & ~3u, g_cpu.R[14], 4u);
    bus_write_u32(_a_0300013C & ~3u, g_cpu.R[14]);
    _a_0300013C += 4u;
    g_cpu.R[13] = _fb_0300013C;
    g_cpu.R[15] = 0x03000140u;
    runtime_tick(_cyc_0300013C);
    /* 03000140  03000140 A mov r4,r1 */
    g_cpu.R[15] = 0x03000140u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000140 = 1u;
    _cyc_03000140 = 1u;
    uint32_t _rm_03000140 = g_cpu.R[1];
    uint32_t _op2_03000140;
    uint32_t _co_03000140;
    _op2_03000140 = _rm_03000140;
    _co_03000140 = cpsr_c();
    uint32_t _r_03000140;
    _r_03000140 = _op2_03000140;
    g_cpu.R[4] = _r_03000140;
    g_cpu.R[15] = 0x03000144u;
    runtime_tick(_cyc_03000140);
    /* 03000144  03000144 A mov r1,r0 */
    g_cpu.R[15] = 0x03000144u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000144 = 1u;
    _cyc_03000144 = 1u;
    uint32_t _rm_03000144 = g_cpu.R[0];
    uint32_t _op2_03000144;
    uint32_t _co_03000144;
    _op2_03000144 = _rm_03000144;
    _co_03000144 = cpsr_c();
    uint32_t _r_03000144;
    _r_03000144 = _op2_03000144;
    g_cpu.R[1] = _r_03000144;
    g_cpu.R[15] = 0x03000148u;
    runtime_tick(_cyc_03000144);
    /* 03000148  03000148 A mov r0,#0x40000000 */
    g_cpu.R[15] = 0x03000148u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000148 = 1u;
    _cyc_03000148 = 1u;
    uint32_t _r_03000148;
    _r_03000148 = 0x40000000u;
    g_cpu.R[0] = _r_03000148;
    g_cpu.R[15] = 0x0300014Cu;
    runtime_tick(_cyc_03000148);
    /* 0300014C  0300014c A bl 0x03000380 */
    g_cpu.R[15] = 0x0300014Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300014C = 1u;
    _cyc_0300014C = 3u;
    g_cpu.R[14] = 0x03000150u;
    g_cpu.R[15] = 0x03000380u;
    runtime_call_push_return(0x03000150u);
    runtime_tick(_cyc_0300014C);
    _cyc_0300014C = 0u;
    gf_iwram_signed_divmod_routine();
    if (g_cpu.R[15] != 0x03000150u) { runtime_call_cancel_return(0x03000150u); return; }
    g_cpu.R[15] = 0x03000150u;
    runtime_tick(_cyc_0300014C);
    /* 03000150  03000150 A smull raw=0xe0c03094 */
    g_cpu.R[15] = 0x03000150u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000150 = 1u;
    _cyc_03000150 = 1u;
    _cyc_03000150 += runtime_mul_cycles(g_cpu.R[0], 1u, 1u);
    int64_t _p_03000150 = (int64_t)(int32_t)g_cpu.R[4] * (int64_t)(int32_t)g_cpu.R[0];
    g_cpu.R[3] = (uint32_t)((uint64_t)_p_03000150 & 0xFFFFFFFFu);
    g_cpu.R[0] = (uint32_t)((uint64_t)_p_03000150 >> 32);
    g_cpu.R[15] = 0x03000154u;
    runtime_tick(_cyc_03000150);
    /* 03000154  03000154 A ldm r13!,{r14} */
    g_cpu.R[15] = 0x03000154u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000154 = 1u;
    _cyc_03000154 = 2u;
    uint32_t _b_03000154 = g_cpu.R[13];
    uint32_t _a_03000154 = _b_03000154;
    uint32_t _fb_03000154 = _b_03000154 + 4u;
    _cyc_03000154 += runtime_mem_cycles(_a_03000154 & ~3u, 4u, 0u);
    g_cpu.R[14] = bus_read_u32(_a_03000154 & ~3u);
    _a_03000154 += 4u;
    g_cpu.R[13] = _fb_03000154;
    g_cpu.R[15] = 0x03000158u;
    runtime_tick(_cyc_03000154);
    /* 03000158  03000158 A mov r0,r0,lsl #18 */
    g_cpu.R[15] = 0x03000158u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000158 = 1u;
    _cyc_03000158 = 1u;
    uint32_t _rm_03000158 = g_cpu.R[0];
    uint32_t _op2_03000158;
    uint32_t _co_03000158;
    _op2_03000158 = _rm_03000158 << 18;
    _co_03000158 = (_rm_03000158 >> 14) & 1u;
    uint32_t _r_03000158;
    _r_03000158 = _op2_03000158;
    g_cpu.R[0] = _r_03000158;
    g_cpu.R[15] = 0x0300015Cu;
    runtime_tick(_cyc_03000158);
    /* 0300015C  0300015c A orr r0,r0,r3,lsr #14 */
    g_cpu.R[15] = 0x0300015Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300015C = 1u;
    _cyc_0300015C = 1u;
    uint32_t _rm_0300015C = g_cpu.R[3];
    uint32_t _op2_0300015C;
    uint32_t _co_0300015C;
    _op2_0300015C = _rm_0300015C >> 14;
    _co_0300015C = (_rm_0300015C >> 13) & 1u;
    uint32_t _rn_0300015C = g_cpu.R[0];
    uint32_t _r_0300015C;
    _r_0300015C = _rn_0300015C | _op2_0300015C;
    g_cpu.R[0] = _r_0300015C;
    g_cpu.R[15] = 0x03000160u;
    runtime_tick(_cyc_0300015C);
    /* 03000160  03000160 A bx r14 */
    g_cpu.R[15] = 0x03000160u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000160 = 1u;
    _cyc_03000160 = 3u;
    uint32_t _bxt_03000160 = g_cpu.R[14];
    g_cpu.R[15] = _bxt_03000160 & ~1u;
    runtime_tick(_cyc_03000160);
    if (_bxt_03000160 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_03000160);
    return;
    g_cpu.R[15] = 0x03000164u;
    runtime_tick(_cyc_03000160);
    /* fall-through to 0x03000164 */
    g_cpu.R[15] = 0x03000164u;
    runtime_dispatch(0x03000164u);
    return;
}

/* 0x03000250  mode=arm  end=0x030002C0  branches=0  indirect */


/* 0x03000164 arm */
void gf_iwram_fast_word_fill_entry(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000164u);
    /* 03000164  03000164 A mov r2,#0x0 */
    g_cpu.R[15] = 0x03000164u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000164 = 1u;
    _cyc_03000164 = 1u;
    uint32_t _r_03000164;
    _r_03000164 = 0x00000000u;
    g_cpu.R[2] = _r_03000164;
    g_cpu.R[15] = 0x03000168u;
    runtime_tick(_cyc_03000164);
    /* fall-through to 0x03000168 */
    g_cpu.R[15] = 0x03000168u;
    runtime_dispatch(0x03000168u);
    return;
}

/* 0x03000630  mode=arm  end=0x0300064C  branches=2 */


/* 0x03000168 arm */
void gf_iwram_fast_word_fill_loop(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000168u);
    /* 03000168  03000168 A stm r13!,{r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x03000168u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000168 = 1u;
    _cyc_03000168 = 1u;
    uint32_t _b_03000168 = g_cpu.R[13];
    uint32_t _a_03000168 = _b_03000168 - 20u;
    uint32_t _fb_03000168 = _b_03000168 - 20u;
    _cyc_03000168 += runtime_mem_cycles(_a_03000168 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000168u, _a_03000168 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03000168 & ~3u, g_cpu.R[5]);
    _a_03000168 += 4u;
    _cyc_03000168 += runtime_mem_cycles(_a_03000168 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000168u, _a_03000168 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_03000168 & ~3u, g_cpu.R[6]);
    _a_03000168 += 4u;
    _cyc_03000168 += runtime_mem_cycles(_a_03000168 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000168u, _a_03000168 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_03000168 & ~3u, g_cpu.R[7]);
    _a_03000168 += 4u;
    _cyc_03000168 += runtime_mem_cycles(_a_03000168 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000168u, _a_03000168 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_03000168 & ~3u, g_cpu.R[8]);
    _a_03000168 += 4u;
    _cyc_03000168 += runtime_mem_cycles(_a_03000168 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000168u, _a_03000168 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_03000168 & ~3u, g_cpu.R[9]);
    _a_03000168 += 4u;
    g_cpu.R[13] = _fb_03000168;
    g_cpu.R[15] = 0x0300016Cu;
    runtime_tick(_cyc_03000168);
    /* 0300016C  0300016c A mov r3,r2 */
    g_cpu.R[15] = 0x0300016Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300016C = 1u;
    _cyc_0300016C = 1u;
    uint32_t _rm_0300016C = g_cpu.R[2];
    uint32_t _op2_0300016C;
    uint32_t _co_0300016C;
    _op2_0300016C = _rm_0300016C;
    _co_0300016C = cpsr_c();
    uint32_t _r_0300016C;
    _r_0300016C = _op2_0300016C;
    g_cpu.R[3] = _r_0300016C;
    g_cpu.R[15] = 0x03000170u;
    runtime_tick(_cyc_0300016C);
    /* 03000170  03000170 A mov r4,r2 */
    g_cpu.R[15] = 0x03000170u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000170 = 1u;
    _cyc_03000170 = 1u;
    uint32_t _rm_03000170 = g_cpu.R[2];
    uint32_t _op2_03000170;
    uint32_t _co_03000170;
    _op2_03000170 = _rm_03000170;
    _co_03000170 = cpsr_c();
    uint32_t _r_03000170;
    _r_03000170 = _op2_03000170;
    g_cpu.R[4] = _r_03000170;
    g_cpu.R[15] = 0x03000174u;
    runtime_tick(_cyc_03000170);
    /* 03000174  03000174 A mov r5,r2 */
    g_cpu.R[15] = 0x03000174u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000174 = 1u;
    _cyc_03000174 = 1u;
    uint32_t _rm_03000174 = g_cpu.R[2];
    uint32_t _op2_03000174;
    uint32_t _co_03000174;
    _op2_03000174 = _rm_03000174;
    _co_03000174 = cpsr_c();
    uint32_t _r_03000174;
    _r_03000174 = _op2_03000174;
    g_cpu.R[5] = _r_03000174;
    g_cpu.R[15] = 0x03000178u;
    runtime_tick(_cyc_03000174);
    /* 03000178  03000178 A mov r6,r2 */
    g_cpu.R[15] = 0x03000178u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000178 = 1u;
    _cyc_03000178 = 1u;
    uint32_t _rm_03000178 = g_cpu.R[2];
    uint32_t _op2_03000178;
    uint32_t _co_03000178;
    _op2_03000178 = _rm_03000178;
    _co_03000178 = cpsr_c();
    uint32_t _r_03000178;
    _r_03000178 = _op2_03000178;
    g_cpu.R[6] = _r_03000178;
    g_cpu.R[15] = 0x0300017Cu;
    runtime_tick(_cyc_03000178);
    /* 0300017C  0300017c A mov r7,r2 */
    g_cpu.R[15] = 0x0300017Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300017C = 1u;
    _cyc_0300017C = 1u;
    uint32_t _rm_0300017C = g_cpu.R[2];
    uint32_t _op2_0300017C;
    uint32_t _co_0300017C;
    _op2_0300017C = _rm_0300017C;
    _co_0300017C = cpsr_c();
    uint32_t _r_0300017C;
    _r_0300017C = _op2_0300017C;
    g_cpu.R[7] = _r_0300017C;
    g_cpu.R[15] = 0x03000180u;
    runtime_tick(_cyc_0300017C);
    /* 03000180  03000180 A mov r8,r2 */
    g_cpu.R[15] = 0x03000180u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000180 = 1u;
    _cyc_03000180 = 1u;
    uint32_t _rm_03000180 = g_cpu.R[2];
    uint32_t _op2_03000180;
    uint32_t _co_03000180;
    _op2_03000180 = _rm_03000180;
    _co_03000180 = cpsr_c();
    uint32_t _r_03000180;
    _r_03000180 = _op2_03000180;
    g_cpu.R[8] = _r_03000180;
    g_cpu.R[15] = 0x03000184u;
    runtime_tick(_cyc_03000180);
    /* 03000184  03000184 A mov r9,r2 */
    g_cpu.R[15] = 0x03000184u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000184 = 1u;
    _cyc_03000184 = 1u;
    uint32_t _rm_03000184 = g_cpu.R[2];
    uint32_t _op2_03000184;
    uint32_t _co_03000184;
    _op2_03000184 = _rm_03000184;
    _co_03000184 = cpsr_c();
    uint32_t _r_03000184;
    _r_03000184 = _op2_03000184;
    g_cpu.R[9] = _r_03000184;
    g_cpu.R[15] = 0x03000188u;
    runtime_tick(_cyc_03000184);
    /* 03000188  03000188 A ands r12,r1,#0xe0 */
    g_cpu.R[15] = 0x03000188u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000188 = 1u;
    _cyc_03000188 = 1u;
    uint32_t _rn_03000188 = g_cpu.R[1];
    uint32_t _r_03000188;
    _r_03000188 = _rn_03000188 & 0x000000E0u;
    arm_set_nzc_logic(_r_03000188, cpsr_c());
    g_cpu.R[12] = _r_03000188;
    g_cpu.R[15] = 0x0300018Cu;
    runtime_tick(_cyc_03000188);
    /* 0300018C  0300018c A rsb r12,r12,#0xe0 */
    g_cpu.R[15] = 0x0300018Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300018C = 1u;
    _cyc_0300018C = 1u;
    uint32_t _rn_0300018C = g_cpu.R[12];
    uint32_t _r_0300018C;
    _r_0300018C = 0x000000E0u - _rn_0300018C;
    g_cpu.R[12] = _r_0300018C;
    g_cpu.R[15] = 0x03000190u;
    runtime_tick(_cyc_0300018C);
    /* 03000190  03000190 A add r15,r15,r12,lsr #3 */
    g_cpu.R[15] = 0x03000190u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000190 = 1u;
    _cyc_03000190 = 3u;
    uint32_t _rm_03000190 = g_cpu.R[12];
    uint32_t _op2_03000190;
    uint32_t _co_03000190;
    _op2_03000190 = _rm_03000190 >> 3;
    _co_03000190 = (_rm_03000190 >> 2) & 1u;
    uint32_t _rn_03000190 = 0x03000198u;
    uint32_t _r_03000190;
    _r_03000190 = _rn_03000190 + _op2_03000190;
    uint32_t _pc_03000190 = _r_03000190 & ~3u;
    g_cpu.R[15] = _pc_03000190;
    runtime_tick(_cyc_03000190);
    runtime_dispatch(_pc_03000190);
    return;
    g_cpu.R[15] = 0x03000194u;
    runtime_tick(_cyc_03000190);
    /* fall-through to 0x03000194 */
    g_cpu.R[15] = 0x03000194u;
    runtime_dispatch(0x03000194u);
    return;
}

/* 0x08000168  mode=thumb  end=0x0800016C  branches=1  indirect */


/* 0x03000194 arm */
void gf_iwram_fast_word_fill_unroll_alpha(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000194u);
    /* 03000194  03000194 A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x03000194u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000194 = 1u;
    _cyc_03000194 = 1u;
    uint32_t _b_03000194 = g_cpu.R[0];
    uint32_t _a_03000194 = _b_03000194;
    uint32_t _fb_03000194 = _b_03000194 + 32u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[2]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[3]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[4]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[5]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[6]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[7]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[8]);
    _a_03000194 += 4u;
    _cyc_03000194 += runtime_mem_cycles(_a_03000194 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000194u, _a_03000194 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_03000194 & ~3u, g_cpu.R[9]);
    _a_03000194 += 4u;
    g_cpu.R[0] = _fb_03000194;
    g_cpu.R[15] = 0x03000198u;
    runtime_tick(_cyc_03000194);
    /* fall-through to 0x03000198 */
    g_cpu.R[15] = 0x03000198u;
    runtime_dispatch(0x03000198u);
    return;
}

/* 0x03000218  mode=arm  end=0x0300022C  branches=4  indirect */


/* 0x03000198 arm */
void gf_iwram_fast_word_fill_unroll_beta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000198u);
    /* 03000198  03000198 A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x03000198u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000198 = 1u;
    _cyc_03000198 = 1u;
    uint32_t _b_03000198 = g_cpu.R[0];
    uint32_t _a_03000198 = _b_03000198;
    uint32_t _fb_03000198 = _b_03000198 + 32u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[2]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[3]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[4]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[5]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[6]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[7]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[8]);
    _a_03000198 += 4u;
    _cyc_03000198 += runtime_mem_cycles(_a_03000198 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000198u, _a_03000198 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_03000198 & ~3u, g_cpu.R[9]);
    _a_03000198 += 4u;
    g_cpu.R[0] = _fb_03000198;
    g_cpu.R[15] = 0x0300019Cu;
    runtime_tick(_cyc_03000198);
    /* fall-through to 0x0300019C */
    g_cpu.R[15] = 0x0300019Cu;
    runtime_dispatch(0x0300019Cu);
    return;
}

/* 0x030001D0  mode=arm  end=0x030001D8  branches=0  indirect */


/* 0x0300019C arm */
void gf_iwram_fast_word_fill_unroll_gamma(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300019Cu);
    /* 0300019C  0300019c A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x0300019Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300019C = 1u;
    _cyc_0300019C = 1u;
    uint32_t _b_0300019C = g_cpu.R[0];
    uint32_t _a_0300019C = _b_0300019C;
    uint32_t _fb_0300019C = _b_0300019C + 32u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[2]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[3]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[4]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[5]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[6]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[7]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[8]);
    _a_0300019C += 4u;
    _cyc_0300019C += runtime_mem_cycles(_a_0300019C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300019Cu, _a_0300019C & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_0300019C & ~3u, g_cpu.R[9]);
    _a_0300019C += 4u;
    g_cpu.R[0] = _fb_0300019C;
    g_cpu.R[15] = 0x030001A0u;
    runtime_tick(_cyc_0300019C);
    /* fall-through to 0x030001A0 */
    g_cpu.R[15] = 0x030001A0u;
    runtime_dispatch(0x030001A0u);
    return;
}

/* 0x030001B0  mode=arm  end=0x030001B4  branches=3  indirect */


/* 0x030001A0 arm */
void gf_iwram_fast_word_fill_unroll_delta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001A0u);
    /* 030001A0  030001a0 A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030001A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001A0 = 1u;
    _cyc_030001A0 = 1u;
    uint32_t _b_030001A0 = g_cpu.R[0];
    uint32_t _a_030001A0 = _b_030001A0;
    uint32_t _fb_030001A0 = _b_030001A0 + 32u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[2]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[3]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[4]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[5]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[6]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[7]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[8]);
    _a_030001A0 += 4u;
    _cyc_030001A0 += runtime_mem_cycles(_a_030001A0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A0u, _a_030001A0 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030001A0 & ~3u, g_cpu.R[9]);
    _a_030001A0 += 4u;
    g_cpu.R[0] = _fb_030001A0;
    g_cpu.R[15] = 0x030001A4u;
    runtime_tick(_cyc_030001A0);
    /* fall-through to 0x030001A4 */
    g_cpu.R[15] = 0x030001A4u;
    runtime_dispatch(0x030001A4u);
    return;
}

/* 0x030002CC  mode=arm  end=0x03000350  branches=1  indirect */


/* 0x030001A4 arm */
void gf_iwram_fast_word_fill_unroll_epsilon(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001A4u);
    /* 030001A4  030001a4 A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030001A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001A4 = 1u;
    _cyc_030001A4 = 1u;
    uint32_t _b_030001A4 = g_cpu.R[0];
    uint32_t _a_030001A4 = _b_030001A4;
    uint32_t _fb_030001A4 = _b_030001A4 + 32u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[2]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[3]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[4]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[5]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[6]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[7]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[8]);
    _a_030001A4 += 4u;
    _cyc_030001A4 += runtime_mem_cycles(_a_030001A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A4u, _a_030001A4 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030001A4 & ~3u, g_cpu.R[9]);
    _a_030001A4 += 4u;
    g_cpu.R[0] = _fb_030001A4;
    g_cpu.R[15] = 0x030001A8u;
    runtime_tick(_cyc_030001A4);
    /* fall-through to 0x030001A8 */
    g_cpu.R[15] = 0x030001A8u;
    runtime_dispatch(0x030001A8u);
    return;
}

/* 0x0300046C  mode=arm  end=0x030004A4  branches=6  indirect */


/* 0x030001A8 arm */
void gf_iwram_fast_word_fill_unroll_zeta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001A8u);
    /* 030001A8  030001a8 A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030001A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001A8 = 1u;
    _cyc_030001A8 = 1u;
    uint32_t _b_030001A8 = g_cpu.R[0];
    uint32_t _a_030001A8 = _b_030001A8;
    uint32_t _fb_030001A8 = _b_030001A8 + 32u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[2]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[3]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[4]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[5]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[6]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[7]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[8]);
    _a_030001A8 += 4u;
    _cyc_030001A8 += runtime_mem_cycles(_a_030001A8 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001A8u, _a_030001A8 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030001A8 & ~3u, g_cpu.R[9]);
    _a_030001A8 += 4u;
    g_cpu.R[0] = _fb_030001A8;
    g_cpu.R[15] = 0x030001ACu;
    runtime_tick(_cyc_030001A8);
    /* fall-through to 0x030001AC */
    g_cpu.R[15] = 0x030001ACu;
    runtime_dispatch(0x030001ACu);
    return;
}

/* 0x080000E8  mode=thumb  end=0x080000EC  branches=1  indirect */


/* 0x030001AC arm */
void gf_iwram_fast_word_fill_unroll_eta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001ACu);
    /* 030001AC  030001ac A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030001ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001AC = 1u;
    _cyc_030001AC = 1u;
    uint32_t _b_030001AC = g_cpu.R[0];
    uint32_t _a_030001AC = _b_030001AC;
    uint32_t _fb_030001AC = _b_030001AC + 32u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[2]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[3]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[4]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[5]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[6]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[7]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[8]);
    _a_030001AC += 4u;
    _cyc_030001AC += runtime_mem_cycles(_a_030001AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001ACu, _a_030001AC & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030001AC & ~3u, g_cpu.R[9]);
    _a_030001AC += 4u;
    g_cpu.R[0] = _fb_030001AC;
    g_cpu.R[15] = 0x030001B0u;
    runtime_tick(_cyc_030001AC);
    /* fall-through to 0x030001B0 */
    g_cpu.R[15] = 0x030001B0u;
    runtime_dispatch(0x030001B0u);
    return;
}

/* 0x030005E0  mode=arm  end=0x030005E8  branches=3 */


/* 0x030001B0 arm */
void gf_iwram_fast_word_fill_unroll_theta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001B0u);
    /* 030001B0  030001b0 A stm r0!,{r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030001B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001B0 = 1u;
    _cyc_030001B0 = 1u;
    uint32_t _b_030001B0 = g_cpu.R[0];
    uint32_t _a_030001B0 = _b_030001B0;
    uint32_t _fb_030001B0 = _b_030001B0 + 32u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[2]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[3]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[4]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[5]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[6]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[7]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[8]);
    _a_030001B0 += 4u;
    _cyc_030001B0 += runtime_mem_cycles(_a_030001B0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001B0u, _a_030001B0 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030001B0 & ~3u, g_cpu.R[9]);
    _a_030001B0 += 4u;
    g_cpu.R[0] = _fb_030001B0;
    g_cpu.R[15] = 0x030001B4u;
    runtime_tick(_cyc_030001B0);
    /* fall-through to 0x030001B4 */
    g_cpu.R[15] = 0x030001B4u;
    runtime_dispatch(0x030001B4u);
    return;
}

/* 0x0300022C  mode=arm  end=0x03000230  branches=3  indirect */


/* 0x030001B4 arm */
void gf_iwram_fast_word_fill_unroll_iota(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001B4u);
    /* 030001B4  030001b4 A subs r1,r1,#0x100 */
    g_cpu.R[15] = 0x030001B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001B4 = 1u;
    _cyc_030001B4 = 1u;
    uint32_t _rn_030001B4 = g_cpu.R[1];
    uint32_t _r_030001B4;
    _r_030001B4 = _rn_030001B4 - 0x00000100u;
    arm_set_nzcv_sub(_rn_030001B4, 0x00000100u, _r_030001B4);
    g_cpu.R[1] = _r_030001B4;
    g_cpu.R[15] = 0x030001B8u;
    runtime_tick(_cyc_030001B4);
    /* 030001B8  030001b8 A bpl 0x03000194 */
    g_cpu.R[15] = 0x030001B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001B8 = 1u;
    if (arm_cond_passes(0x5u)) {
        _cyc_030001B8 = 3u;
        g_cpu.R[15] = 0x03000194u;
        runtime_tick(_cyc_030001B8);
        gf_iwram_fast_word_fill_unroll_alpha();
        return;
    }
    g_cpu.R[15] = 0x030001BCu;
    runtime_tick(_cyc_030001B8);
    /* 030001BC  030001bc A ands r1,r1,#0x1c */
    g_cpu.R[15] = 0x030001BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001BC = 1u;
    _cyc_030001BC = 1u;
    uint32_t _rn_030001BC = g_cpu.R[1];
    uint32_t _r_030001BC;
    _r_030001BC = _rn_030001BC & 0x0000001Cu;
    arm_set_nzc_logic(_r_030001BC, cpsr_c());
    g_cpu.R[1] = _r_030001BC;
    g_cpu.R[15] = 0x030001C0u;
    runtime_tick(_cyc_030001BC);
    /* 030001C0  030001c0 A beq 0x030001d0 */
    g_cpu.R[15] = 0x030001C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001C0 = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_030001C0 = 3u;
        g_cpu.R[15] = 0x030001D0u;
        runtime_tick(_cyc_030001C0);
        gf_iwram_fast_ram_work_entry_begin();
        return;
    }
    g_cpu.R[15] = 0x030001C4u;
    runtime_tick(_cyc_030001C0);
    /* fall-through to 0x030001C4 */
    g_cpu.R[15] = 0x030001C4u;
    runtime_dispatch(0x030001C4u);
    return;
}

/* 0x030001C4  mode=arm  end=0x030001D0  branches=1  indirect */


/* 0x030001C4 arm */
void gf_iwram_fast_ram_work_entry_setup(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001C4u);
L_030001C4:
    /* 030001C4  030001c4 A stm r0!,{r2} */
    g_cpu.R[15] = 0x030001C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001C4 = 1u;
    _cyc_030001C4 = 1u;
    uint32_t _b_030001C4 = g_cpu.R[0];
    uint32_t _a_030001C4 = _b_030001C4;
    uint32_t _fb_030001C4 = _b_030001C4 + 4u;
    _cyc_030001C4 += runtime_mem_cycles(_a_030001C4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030001C4u, _a_030001C4 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_030001C4 & ~3u, g_cpu.R[2]);
    _a_030001C4 += 4u;
    g_cpu.R[0] = _fb_030001C4;
    g_cpu.R[15] = 0x030001C8u;
    runtime_tick(_cyc_030001C4);
    /* 030001C8  030001c8 A subs r1,r1,#0x4 */
    g_cpu.R[15] = 0x030001C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001C8 = 1u;
    _cyc_030001C8 = 1u;
    uint32_t _rn_030001C8 = g_cpu.R[1];
    uint32_t _r_030001C8;
    _r_030001C8 = _rn_030001C8 - 0x00000004u;
    arm_set_nzcv_sub(_rn_030001C8, 0x00000004u, _r_030001C8);
    g_cpu.R[1] = _r_030001C8;
    g_cpu.R[15] = 0x030001CCu;
    runtime_tick(_cyc_030001C8);
    /* 030001CC  030001cc A bgt 0x030001c4 */
    g_cpu.R[15] = 0x030001CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001CC = 1u;
    if (arm_cond_passes(0xcu)) {
        _cyc_030001CC = 3u;
        g_cpu.R[15] = 0x030001C4u;
        runtime_trace_event(RUNTIME_TRACE_BRANCH, 0x030001CCu, 0x030001C4u, 0u, 0u);
        runtime_tick(_cyc_030001CC);
        goto L_030001C4;
    }
    g_cpu.R[15] = 0x030001D0u;
    runtime_tick(_cyc_030001CC);
    /* fall-through to 0x030001D0 */
    g_cpu.R[15] = 0x030001D0u;
    runtime_dispatch(0x030001D0u);
    return;
}

/* 0x08000120  mode=thumb  end=0x08000124  branches=1  indirect */


/* 0x030001D0 arm */
void gf_iwram_fast_ram_work_entry_begin(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001D0u);
    /* 030001D0  030001d0 A ldm r13!,{r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030001D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001D0 = 1u;
    _cyc_030001D0 = 2u;
    uint32_t _b_030001D0 = g_cpu.R[13];
    uint32_t _a_030001D0 = _b_030001D0;
    uint32_t _fb_030001D0 = _b_030001D0 + 20u;
    _cyc_030001D0 += runtime_mem_cycles(_a_030001D0 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030001D0 & ~3u);
    _a_030001D0 += 4u;
    _cyc_030001D0 += runtime_mem_cycles(_a_030001D0 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030001D0 & ~3u);
    _a_030001D0 += 4u;
    _cyc_030001D0 += runtime_mem_cycles(_a_030001D0 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030001D0 & ~3u);
    _a_030001D0 += 4u;
    _cyc_030001D0 += runtime_mem_cycles(_a_030001D0 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030001D0 & ~3u);
    _a_030001D0 += 4u;
    _cyc_030001D0 += runtime_mem_cycles(_a_030001D0 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030001D0 & ~3u);
    _a_030001D0 += 4u;
    g_cpu.R[13] = _fb_030001D0;
    g_cpu.R[15] = 0x030001D4u;
    runtime_tick(_cyc_030001D0);
    /* 030001D4  030001d4 A bx r14 */
    g_cpu.R[15] = 0x030001D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001D4 = 1u;
    _cyc_030001D4 = 3u;
    uint32_t _bxt_030001D4 = g_cpu.R[14];
    g_cpu.R[15] = _bxt_030001D4 & ~1u;
    runtime_tick(_cyc_030001D4);
    if (_bxt_030001D4 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030001D4);
    return;
    g_cpu.R[15] = 0x030001D8u;
    runtime_tick(_cyc_030001D4);
    /* fall-through to 0x030001D8 */
    g_cpu.R[15] = 0x030001D8u;
    runtime_dispatch(0x030001D8u);
    return;
}

/* 0x030001E4  mode=arm  end=0x030001E8  branches=1  indirect */


/* 0x030001D8 arm */
void gf_iwram_integer_square_root(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001D8u);
    /* 030001D8  030001d8 A movs r1,r0 */
    g_cpu.R[15] = 0x030001D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001D8 = 1u;
    _cyc_030001D8 = 1u;
    uint32_t _rm_030001D8 = g_cpu.R[0];
    uint32_t _op2_030001D8;
    uint32_t _co_030001D8;
    _op2_030001D8 = _rm_030001D8;
    _co_030001D8 = cpsr_c();
    uint32_t _r_030001D8;
    _r_030001D8 = _op2_030001D8;
    arm_set_nzc_logic(_r_030001D8, _co_030001D8);
    g_cpu.R[1] = _r_030001D8;
    g_cpu.R[15] = 0x030001DCu;
    runtime_tick(_cyc_030001D8);
    /* 030001DC  030001dc A mov r0,#0x0 */
    g_cpu.R[15] = 0x030001DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001DC = 1u;
    _cyc_030001DC = 1u;
    uint32_t _r_030001DC;
    _r_030001DC = 0x00000000u;
    g_cpu.R[0] = _r_030001DC;
    g_cpu.R[15] = 0x030001E0u;
    runtime_tick(_cyc_030001DC);
    /* 030001E0  030001e0 A bxmi r14 */
    g_cpu.R[15] = 0x030001E0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001E0 = 1u;
    if (arm_cond_passes(0x4u)) {
        _cyc_030001E0 = 3u;
        uint32_t _bxt_030001E0 = g_cpu.R[14];
        g_cpu.R[15] = _bxt_030001E0 & ~1u;
        runtime_tick(_cyc_030001E0);
        if (_bxt_030001E0 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
        if (runtime_call_should_return(g_cpu.R[15])) return;
        runtime_dispatch_with_exchange(_bxt_030001E0);
        return;
    }
    g_cpu.R[15] = 0x030001E4u;
    runtime_tick(_cyc_030001E0);
    /* fall-through to 0x030001E4 */
    g_cpu.R[15] = 0x030001E4u;
    runtime_dispatch(0x030001E4u);
    return;
}

/* 0x03000238  mode=arm  end=0x03000250  branches=2  indirect */


/* 0x030001E4 arm */
void gf_iwram_fast_ram_work_entry_start(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001E4u);
    /* 030001E4  030001e4 A mov r2,#0x8000 */
    g_cpu.R[15] = 0x030001E4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001E4 = 1u;
    _cyc_030001E4 = 1u;
    uint32_t _r_030001E4;
    _r_030001E4 = 0x00008000u;
    g_cpu.R[2] = _r_030001E4;
    g_cpu.R[15] = 0x030001E8u;
    runtime_tick(_cyc_030001E4);
    /* fall-through to 0x030001E8 */
    g_cpu.R[15] = 0x030001E8u;
    runtime_dispatch(0x030001E8u);
    return;
}

/* 0x03000214  mode=arm  end=0x03000218  branches=4  indirect */


/* 0x030001E8 arm */
void gf_iwram_fast_ram_work_entry_open(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030001E8u);
L_030001E8:
    /* 030001E8  030001e8 A add r0,r0,r2 */
    g_cpu.R[15] = 0x030001E8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001E8 = 1u;
    _cyc_030001E8 = 1u;
    uint32_t _rm_030001E8 = g_cpu.R[2];
    uint32_t _op2_030001E8;
    uint32_t _co_030001E8;
    _op2_030001E8 = _rm_030001E8;
    _co_030001E8 = cpsr_c();
    uint32_t _rn_030001E8 = g_cpu.R[0];
    uint32_t _r_030001E8;
    _r_030001E8 = _rn_030001E8 + _op2_030001E8;
    g_cpu.R[0] = _r_030001E8;
    g_cpu.R[15] = 0x030001ECu;
    runtime_tick(_cyc_030001E8);
    /* 030001EC  030001ec A mul r3,r0,r0 */
    g_cpu.R[15] = 0x030001ECu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001EC = 1u;
    _cyc_030001EC = 1u;
    _cyc_030001EC += runtime_mul_cycles(g_cpu.R[0], 1u, 0u);
    uint32_t _r_030001EC = g_cpu.R[0] * g_cpu.R[0];
    g_cpu.R[3] = _r_030001EC;
    g_cpu.R[15] = 0x030001F0u;
    runtime_tick(_cyc_030001EC);
    /* 030001F0  030001f0 A cmps r3,r1 */
    g_cpu.R[15] = 0x030001F0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001F0 = 1u;
    _cyc_030001F0 = 1u;
    uint32_t _rm_030001F0 = g_cpu.R[1];
    uint32_t _op2_030001F0;
    uint32_t _co_030001F0;
    _op2_030001F0 = _rm_030001F0;
    _co_030001F0 = cpsr_c();
    uint32_t _rn_030001F0 = g_cpu.R[3];
    uint32_t _r_030001F0;
    _r_030001F0 = _rn_030001F0 - _op2_030001F0;
    arm_set_nzcv_sub(_rn_030001F0, _op2_030001F0, _r_030001F0);
    g_cpu.R[15] = 0x030001F4u;
    runtime_tick(_cyc_030001F0);
    /* 030001F4  030001f4 A subhi r0,r0,r2 */
    g_cpu.R[15] = 0x030001F4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001F4 = 1u;
    if (arm_cond_passes(0x8u)) {
        _cyc_030001F4 = 1u;
        uint32_t _rm_030001F4 = g_cpu.R[2];
        uint32_t _op2_030001F4;
        uint32_t _co_030001F4;
        _op2_030001F4 = _rm_030001F4;
        _co_030001F4 = cpsr_c();
        uint32_t _rn_030001F4 = g_cpu.R[0];
        uint32_t _r_030001F4;
        _r_030001F4 = _rn_030001F4 - _op2_030001F4;
        g_cpu.R[0] = _r_030001F4;
    }
    g_cpu.R[15] = 0x030001F8u;
    runtime_tick(_cyc_030001F4);
    /* 030001F8  030001f8 A add r0,r0,r2,lsr #1 */
    g_cpu.R[15] = 0x030001F8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001F8 = 1u;
    _cyc_030001F8 = 1u;
    uint32_t _rm_030001F8 = g_cpu.R[2];
    uint32_t _op2_030001F8;
    uint32_t _co_030001F8;
    _op2_030001F8 = _rm_030001F8 >> 1;
    _co_030001F8 = (_rm_030001F8 >> 0) & 1u;
    uint32_t _rn_030001F8 = g_cpu.R[0];
    uint32_t _r_030001F8;
    _r_030001F8 = _rn_030001F8 + _op2_030001F8;
    g_cpu.R[0] = _r_030001F8;
    g_cpu.R[15] = 0x030001FCu;
    runtime_tick(_cyc_030001F8);
    /* 030001FC  030001fc A mul r3,r0,r0 */
    g_cpu.R[15] = 0x030001FCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030001FC = 1u;
    _cyc_030001FC = 1u;
    _cyc_030001FC += runtime_mul_cycles(g_cpu.R[0], 1u, 0u);
    uint32_t _r_030001FC = g_cpu.R[0] * g_cpu.R[0];
    g_cpu.R[3] = _r_030001FC;
    g_cpu.R[15] = 0x03000200u;
    runtime_tick(_cyc_030001FC);
    /* 03000200  03000200 A cmps r3,r1 */
    g_cpu.R[15] = 0x03000200u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000200 = 1u;
    _cyc_03000200 = 1u;
    uint32_t _rm_03000200 = g_cpu.R[1];
    uint32_t _op2_03000200;
    uint32_t _co_03000200;
    _op2_03000200 = _rm_03000200;
    _co_03000200 = cpsr_c();
    uint32_t _rn_03000200 = g_cpu.R[3];
    uint32_t _r_03000200;
    _r_03000200 = _rn_03000200 - _op2_03000200;
    arm_set_nzcv_sub(_rn_03000200, _op2_03000200, _r_03000200);
    g_cpu.R[15] = 0x03000204u;
    runtime_tick(_cyc_03000200);
    /* 03000204  03000204 A subhi r0,r0,r2,lsr #1 */
    g_cpu.R[15] = 0x03000204u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000204 = 1u;
    if (arm_cond_passes(0x8u)) {
        _cyc_03000204 = 1u;
        uint32_t _rm_03000204 = g_cpu.R[2];
        uint32_t _op2_03000204;
        uint32_t _co_03000204;
        _op2_03000204 = _rm_03000204 >> 1;
        _co_03000204 = (_rm_03000204 >> 0) & 1u;
        uint32_t _rn_03000204 = g_cpu.R[0];
        uint32_t _r_03000204;
        _r_03000204 = _rn_03000204 - _op2_03000204;
        g_cpu.R[0] = _r_03000204;
    }
    g_cpu.R[15] = 0x03000208u;
    runtime_tick(_cyc_03000204);
    /* 03000208  03000208 A movs r2,r2,lsr #2 */
    g_cpu.R[15] = 0x03000208u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000208 = 1u;
    _cyc_03000208 = 1u;
    uint32_t _rm_03000208 = g_cpu.R[2];
    uint32_t _op2_03000208;
    uint32_t _co_03000208;
    _op2_03000208 = _rm_03000208 >> 2;
    _co_03000208 = (_rm_03000208 >> 1) & 1u;
    uint32_t _r_03000208;
    _r_03000208 = _op2_03000208;
    arm_set_nzc_logic(_r_03000208, _co_03000208);
    g_cpu.R[2] = _r_03000208;
    g_cpu.R[15] = 0x0300020Cu;
    runtime_tick(_cyc_03000208);
    /* 0300020C  0300020c A bne 0x030001e8 */
    g_cpu.R[15] = 0x0300020Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300020C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300020C = 3u;
        g_cpu.R[15] = 0x030001E8u;
        runtime_trace_event(RUNTIME_TRACE_BRANCH, 0x0300020Cu, 0x030001E8u, 0u, 0u);
        runtime_tick(_cyc_0300020C);
        runtime_idle_backedge(0x030001E8u);
        goto L_030001E8;
    }
    g_cpu.R[15] = 0x03000210u;
    runtime_tick(_cyc_0300020C);
    /* 03000210  03000210 A bx r14 */
    g_cpu.R[15] = 0x03000210u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000210 = 1u;
    _cyc_03000210 = 3u;
    uint32_t _bxt_03000210 = g_cpu.R[14];
    g_cpu.R[15] = _bxt_03000210 & ~1u;
    runtime_tick(_cyc_03000210);
    if (_bxt_03000210 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_03000210);
    return;
    g_cpu.R[15] = 0x03000214u;
    runtime_tick(_cyc_03000210);
    /* fall-through to 0x03000214 */
    g_cpu.R[15] = 0x03000214u;
    runtime_dispatch(0x03000214u);
    return;
}

/* 0x03000380  mode=arm  end=0x030003AC  branches=2  indirect */


/* 0x03000214 arm */
void gf_iwram_matrix_load_identity(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000214u);
    /* 03000214  03000214 A add r12,r0,#0x1c */
    g_cpu.R[15] = 0x03000214u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000214 = 1u;
    _cyc_03000214 = 1u;
    uint32_t _rn_03000214 = g_cpu.R[0];
    uint32_t _r_03000214;
    _r_03000214 = _rn_03000214 + 0x0000001Cu;
    g_cpu.R[12] = _r_03000214;
    g_cpu.R[15] = 0x03000218u;
    runtime_tick(_cyc_03000214);
    /* fall-through to 0x03000218 */
    g_cpu.R[15] = 0x03000218u;
    runtime_dispatch(0x03000218u);
    return;
}

/* 0x030013A0  mode=arm  end=0x030013A8  branches=3  indirect */


/* 0x03000218 arm */
void gf_iwram_fast_ram_work_entry_load(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000218u);
    /* 03000218  03000218 A mov r4,r1 */
    g_cpu.R[15] = 0x03000218u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000218 = 1u;
    _cyc_03000218 = 1u;
    uint32_t _rm_03000218 = g_cpu.R[1];
    uint32_t _op2_03000218;
    uint32_t _co_03000218;
    _op2_03000218 = _rm_03000218;
    _co_03000218 = cpsr_c();
    uint32_t _r_03000218;
    _r_03000218 = _op2_03000218;
    g_cpu.R[4] = _r_03000218;
    g_cpu.R[15] = 0x0300021Cu;
    runtime_tick(_cyc_03000218);
    /* 0300021C  0300021c A ldrh r3,[r0],#0x2 */
    g_cpu.R[15] = 0x0300021Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300021C = 1u;
    _cyc_0300021C = 2u;
    uint32_t _base_0300021C = g_cpu.R[0];
    uint32_t _off_0300021C;
    _off_0300021C = 0x00000002u;
    uint32_t _ea_0300021C = _base_0300021C;
    uint32_t _post_0300021C = _base_0300021C + _off_0300021C;
    _cyc_0300021C += runtime_mem_cycles(_ea_0300021C, 2u, 0u);
    uint32_t _v_0300021C;
    { uint32_t _h = bus_read_u16(_ea_0300021C & ~1u); if (_ea_0300021C & 1u) _v_0300021C = ((_h >> 8) | (_h << 24)); else _v_0300021C = _h; }
    if (0u != 3u) g_cpu.R[0] = _post_0300021C;
    g_cpu.R[3] = _v_0300021C;
    g_cpu.R[15] = 0x03000220u;
    runtime_tick(_cyc_0300021C);
    /* 03000220  03000220 A bic r3,r3,#0x3 */
    g_cpu.R[15] = 0x03000220u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000220 = 1u;
    _cyc_03000220 = 1u;
    uint32_t _rn_03000220 = g_cpu.R[3];
    uint32_t _r_03000220;
    _r_03000220 = _rn_03000220 & ~(0x00000003u);
    g_cpu.R[3] = _r_03000220;
    g_cpu.R[15] = 0x03000224u;
    runtime_tick(_cyc_03000220);
    /* 03000224  03000224 A movs r3,r3,lsl #17 */
    g_cpu.R[15] = 0x03000224u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000224 = 1u;
    _cyc_03000224 = 1u;
    uint32_t _rm_03000224 = g_cpu.R[3];
    uint32_t _op2_03000224;
    uint32_t _co_03000224;
    _op2_03000224 = _rm_03000224 << 17;
    _co_03000224 = (_rm_03000224 >> 15) & 1u;
    uint32_t _r_03000224;
    _r_03000224 = _op2_03000224;
    arm_set_nzc_logic(_r_03000224, _co_03000224);
    g_cpu.R[3] = _r_03000224;
    g_cpu.R[15] = 0x03000228u;
    runtime_tick(_cyc_03000224);
    /* 03000228  03000228 A bcc 0x03000238 */
    g_cpu.R[15] = 0x03000228u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000228 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000228 = 3u;
        g_cpu.R[15] = 0x03000238u;
        runtime_tick(_cyc_03000228);
        gf_iwram_fast_ram_work_entry_parse();
        return;
    }
    g_cpu.R[15] = 0x0300022Cu;
    runtime_tick(_cyc_03000228);
    /* fall-through to 0x0300022C */
    g_cpu.R[15] = 0x0300022Cu;
    runtime_dispatch(0x0300022Cu);
    return;
}

/* 0x03000230  mode=arm  end=0x03000238  branches=3  indirect */


/* 0x0300022C arm */
void gf_iwram_fast_ram_work_entry_fetch(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300022Cu);
    /* 0300022C  0300022c A strb r2,[r4],#0x1 */
    g_cpu.R[15] = 0x0300022Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300022C = 1u;
    _cyc_0300022C = 1u;
    uint32_t _base_0300022C = g_cpu.R[4];
    uint32_t _off_0300022C;
    _off_0300022C = 0x00000001u;
    uint32_t _ea_0300022C = _base_0300022C;
    uint32_t _post_0300022C = _base_0300022C + _off_0300022C;
    _cyc_0300022C += runtime_mem_cycles(_ea_0300022C, 1u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300022Cu, _ea_0300022C, (uint32_t)(g_cpu.R[2] & 0xFFu), 1u);
    bus_write_u8(_ea_0300022C, (uint8_t)(g_cpu.R[2] & 0xFFu));
    g_cpu.R[4] = _post_0300022C;
    g_cpu.R[15] = 0x03000230u;
    runtime_tick(_cyc_0300022C);
    /* fall-through to 0x03000230 */
    g_cpu.R[15] = 0x03000230u;
    runtime_dispatch(0x03000230u);
    return;
}

/* 0x03001398  mode=arm  end=0x030013A0  branches=3  indirect */


/* 0x03000230 arm */
void gf_iwram_fast_ram_work_entry_read(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000230u);
    /* 03000230  03000230 A movs r3,r3,lsl #1 */
    g_cpu.R[15] = 0x03000230u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000230 = 1u;
    _cyc_03000230 = 1u;
    uint32_t _rm_03000230 = g_cpu.R[3];
    uint32_t _op2_03000230;
    uint32_t _co_03000230;
    _op2_03000230 = _rm_03000230 << 1;
    _co_03000230 = (_rm_03000230 >> 31) & 1u;
    uint32_t _r_03000230;
    _r_03000230 = _op2_03000230;
    arm_set_nzc_logic(_r_03000230, _co_03000230);
    g_cpu.R[3] = _r_03000230;
    g_cpu.R[15] = 0x03000234u;
    runtime_tick(_cyc_03000230);
    /* 03000234  03000234 A bcs 0x0300022c */
    g_cpu.R[15] = 0x03000234u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000234 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000234 = 3u;
        g_cpu.R[15] = 0x0300022Cu;
        runtime_tick(_cyc_03000234);
        gf_iwram_fast_ram_work_entry_fetch();
        return;
    }
    g_cpu.R[15] = 0x03000238u;
    runtime_tick(_cyc_03000234);
    /* fall-through to 0x03000238 */
    g_cpu.R[15] = 0x03000238u;
    runtime_dispatch(0x03000238u);
    return;
}

/* 0x030002C0  mode=arm  end=0x030002CC  branches=1  indirect */


/* 0x03000238 arm */
void gf_iwram_fast_ram_work_entry_parse(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000238u);
    /* 03000238  03000238 A add r4,r4,#0x1 */
    g_cpu.R[15] = 0x03000238u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000238 = 1u;
    _cyc_03000238 = 1u;
    uint32_t _rn_03000238 = g_cpu.R[4];
    uint32_t _r_03000238;
    _r_03000238 = _rn_03000238 + 0x00000001u;
    g_cpu.R[4] = _r_03000238;
    g_cpu.R[15] = 0x0300023Cu;
    runtime_tick(_cyc_03000238);
    /* 0300023C  0300023c A bne 0x03000230 */
    g_cpu.R[15] = 0x0300023Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300023C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300023C = 3u;
        g_cpu.R[15] = 0x03000230u;
        runtime_tick(_cyc_0300023C);
        gf_iwram_fast_ram_work_entry_read();
        return;
    }
    g_cpu.R[15] = 0x03000240u;
    runtime_tick(_cyc_0300023C);
    /* 03000240  03000240 A add r1,r1,#0x10 */
    g_cpu.R[15] = 0x03000240u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000240 = 1u;
    _cyc_03000240 = 1u;
    uint32_t _rn_03000240 = g_cpu.R[1];
    uint32_t _r_03000240;
    _r_03000240 = _rn_03000240 + 0x00000010u;
    g_cpu.R[1] = _r_03000240;
    g_cpu.R[15] = 0x03000244u;
    runtime_tick(_cyc_03000240);
    /* 03000244  03000244 A cmps r0,r12 */
    g_cpu.R[15] = 0x03000244u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000244 = 1u;
    _cyc_03000244 = 1u;
    uint32_t _rm_03000244 = g_cpu.R[12];
    uint32_t _op2_03000244;
    uint32_t _co_03000244;
    _op2_03000244 = _rm_03000244;
    _co_03000244 = cpsr_c();
    uint32_t _rn_03000244 = g_cpu.R[0];
    uint32_t _r_03000244;
    _r_03000244 = _rn_03000244 - _op2_03000244;
    arm_set_nzcv_sub(_rn_03000244, _op2_03000244, _r_03000244);
    g_cpu.R[15] = 0x03000248u;
    runtime_tick(_cyc_03000244);
    /* 03000248  03000248 A bne 0x03000218 */
    g_cpu.R[15] = 0x03000248u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000248 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000248 = 3u;
        g_cpu.R[15] = 0x03000218u;
        runtime_tick(_cyc_03000248);
        gf_iwram_fast_ram_work_entry_load();
        return;
    }
    g_cpu.R[15] = 0x0300024Cu;
    runtime_tick(_cyc_03000248);
    /* 0300024C  0300024c A bx r14 */
    g_cpu.R[15] = 0x0300024Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300024C = 1u;
    _cyc_0300024C = 3u;
    uint32_t _bxt_0300024C = g_cpu.R[14];
    g_cpu.R[15] = _bxt_0300024C & ~1u;
    runtime_tick(_cyc_0300024C);
    if (_bxt_0300024C & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_0300024C);
    return;
    g_cpu.R[15] = 0x03000250u;
    runtime_tick(_cyc_0300024C);
    /* fall-through to 0x03000250 */
    g_cpu.R[15] = 0x03000250u;
    runtime_dispatch(0x03000250u);
    return;
}

/* 0x03000514  mode=arm  end=0x0300054C  branches=3  indirect */


/* 0x03000250 arm */
void gf_iwram_matrix_multiply_affine(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000250u);
    /* 03000250  03000250 A stm r13!,{r5,r6,r7,r8,r9,r10,r11,r14} */
    g_cpu.R[15] = 0x03000250u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000250 = 1u;
    _cyc_03000250 = 1u;
    uint32_t _b_03000250 = g_cpu.R[13];
    uint32_t _a_03000250 = _b_03000250 - 32u;
    uint32_t _fb_03000250 = _b_03000250 - 32u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[5]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[6]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[7]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[8]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[9]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[10], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[10]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[11], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[11]);
    _a_03000250 += 4u;
    _cyc_03000250 += runtime_mem_cycles(_a_03000250 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000250u, _a_03000250 & ~3u, g_cpu.R[14], 4u);
    bus_write_u32(_a_03000250 & ~3u, g_cpu.R[14]);
    _a_03000250 += 4u;
    g_cpu.R[13] = _fb_03000250;
    g_cpu.R[15] = 0x03000254u;
    runtime_tick(_cyc_03000250);
    /* 03000254  03000254 A ldm r0,{r2,r3,r4} */
    g_cpu.R[15] = 0x03000254u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000254 = 1u;
    _cyc_03000254 = 2u;
    uint32_t _b_03000254 = g_cpu.R[0];
    uint32_t _a_03000254 = _b_03000254;
    uint32_t _fb_03000254 = _b_03000254 + 12u;
    _cyc_03000254 += runtime_mem_cycles(_a_03000254 & ~3u, 4u, 0u);
    g_cpu.R[2] = bus_read_u32(_a_03000254 & ~3u);
    _a_03000254 += 4u;
    _cyc_03000254 += runtime_mem_cycles(_a_03000254 & ~3u, 4u, 1u);
    g_cpu.R[3] = bus_read_u32(_a_03000254 & ~3u);
    _a_03000254 += 4u;
    _cyc_03000254 += runtime_mem_cycles(_a_03000254 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_03000254 & ~3u);
    _a_03000254 += 4u;
    g_cpu.R[15] = 0x03000258u;
    runtime_tick(_cyc_03000254);
    /* 03000258  03000258 A add r0,r15,#0xf0 */
    g_cpu.R[15] = 0x03000258u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000258 = 1u;
    _cyc_03000258 = 1u;
    uint32_t _rn_03000258 = 0x03000260u;
    uint32_t _r_03000258;
    _r_03000258 = _rn_03000258 + 0x000000F0u;
    g_cpu.R[0] = _r_03000258;
    g_cpu.R[15] = 0x0300025Cu;
    runtime_tick(_cyc_03000258);
    /* 0300025C  0300025c A ldm r0!,{r5,r6,r7} */
    g_cpu.R[15] = 0x0300025Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300025C = 1u;
    _cyc_0300025C = 2u;
    uint32_t _b_0300025C = g_cpu.R[0];
    uint32_t _a_0300025C = _b_0300025C;
    uint32_t _fb_0300025C = _b_0300025C + 12u;
    _cyc_0300025C += runtime_mem_cycles(_a_0300025C & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_0300025C & ~3u);
    _a_0300025C += 4u;
    _cyc_0300025C += runtime_mem_cycles(_a_0300025C & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_0300025C & ~3u);
    _a_0300025C += 4u;
    _cyc_0300025C += runtime_mem_cycles(_a_0300025C & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_0300025C & ~3u);
    _a_0300025C += 4u;
    g_cpu.R[0] = _fb_0300025C;
    g_cpu.R[15] = 0x03000260u;
    runtime_tick(_cyc_0300025C);
    /* 03000260  03000260 A smull raw=0xe0c98592 */
    g_cpu.R[15] = 0x03000260u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000260 = 1u;
    _cyc_03000260 = 1u;
    _cyc_03000260 += runtime_mul_cycles(g_cpu.R[5], 1u, 1u);
    int64_t _p_03000260 = (int64_t)(int32_t)g_cpu.R[2] * (int64_t)(int32_t)g_cpu.R[5];
    g_cpu.R[8] = (uint32_t)((uint64_t)_p_03000260 & 0xFFFFFFFFu);
    g_cpu.R[9] = (uint32_t)((uint64_t)_p_03000260 >> 32);
    g_cpu.R[15] = 0x03000264u;
    runtime_tick(_cyc_03000260);
    /* 03000264  03000264 A smull raw=0xe0cba692 */
    g_cpu.R[15] = 0x03000264u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000264 = 1u;
    _cyc_03000264 = 1u;
    _cyc_03000264 += runtime_mul_cycles(g_cpu.R[6], 1u, 1u);
    int64_t _p_03000264 = (int64_t)(int32_t)g_cpu.R[2] * (int64_t)(int32_t)g_cpu.R[6];
    g_cpu.R[10] = (uint32_t)((uint64_t)_p_03000264 & 0xFFFFFFFFu);
    g_cpu.R[11] = (uint32_t)((uint64_t)_p_03000264 >> 32);
    g_cpu.R[15] = 0x03000268u;
    runtime_tick(_cyc_03000264);
    /* 03000268  03000268 A smull raw=0xe0cec792 */
    g_cpu.R[15] = 0x03000268u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000268 = 1u;
    _cyc_03000268 = 1u;
    _cyc_03000268 += runtime_mul_cycles(g_cpu.R[7], 1u, 1u);
    int64_t _p_03000268 = (int64_t)(int32_t)g_cpu.R[2] * (int64_t)(int32_t)g_cpu.R[7];
    g_cpu.R[12] = (uint32_t)((uint64_t)_p_03000268 & 0xFFFFFFFFu);
    g_cpu.R[14] = (uint32_t)((uint64_t)_p_03000268 >> 32);
    g_cpu.R[15] = 0x0300026Cu;
    runtime_tick(_cyc_03000268);
    /* 0300026C  0300026c A ldm r0!,{r5,r6,r7} */
    g_cpu.R[15] = 0x0300026Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300026C = 1u;
    _cyc_0300026C = 2u;
    uint32_t _b_0300026C = g_cpu.R[0];
    uint32_t _a_0300026C = _b_0300026C;
    uint32_t _fb_0300026C = _b_0300026C + 12u;
    _cyc_0300026C += runtime_mem_cycles(_a_0300026C & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_0300026C & ~3u);
    _a_0300026C += 4u;
    _cyc_0300026C += runtime_mem_cycles(_a_0300026C & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_0300026C & ~3u);
    _a_0300026C += 4u;
    _cyc_0300026C += runtime_mem_cycles(_a_0300026C & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_0300026C & ~3u);
    _a_0300026C += 4u;
    g_cpu.R[0] = _fb_0300026C;
    g_cpu.R[15] = 0x03000270u;
    runtime_tick(_cyc_0300026C);
    /* 03000270  03000270 A smlal raw=0xe0e98593 */
    g_cpu.R[15] = 0x03000270u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000270 = 1u;
    _cyc_03000270 = 1u;
    _cyc_03000270 += runtime_mul_cycles(g_cpu.R[5], 1u, 2u);
    int64_t _p_03000270 = (int64_t)(int32_t)g_cpu.R[3] * (int64_t)(int32_t)g_cpu.R[5];
    uint64_t _acc_03000270 = ((uint64_t)g_cpu.R[9] << 32) | g_cpu.R[8];
    uint64_t _sum_03000270 = _acc_03000270 + (uint64_t)_p_03000270;
    g_cpu.R[8] = (uint32_t)(_sum_03000270 & 0xFFFFFFFFu);
    g_cpu.R[9] = (uint32_t)(_sum_03000270 >> 32);
    g_cpu.R[15] = 0x03000274u;
    runtime_tick(_cyc_03000270);
    /* 03000274  03000274 A smlal raw=0xe0eba693 */
    g_cpu.R[15] = 0x03000274u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000274 = 1u;
    _cyc_03000274 = 1u;
    _cyc_03000274 += runtime_mul_cycles(g_cpu.R[6], 1u, 2u);
    int64_t _p_03000274 = (int64_t)(int32_t)g_cpu.R[3] * (int64_t)(int32_t)g_cpu.R[6];
    uint64_t _acc_03000274 = ((uint64_t)g_cpu.R[11] << 32) | g_cpu.R[10];
    uint64_t _sum_03000274 = _acc_03000274 + (uint64_t)_p_03000274;
    g_cpu.R[10] = (uint32_t)(_sum_03000274 & 0xFFFFFFFFu);
    g_cpu.R[11] = (uint32_t)(_sum_03000274 >> 32);
    g_cpu.R[15] = 0x03000278u;
    runtime_tick(_cyc_03000274);
    /* 03000278  03000278 A smlal raw=0xe0eec793 */
    g_cpu.R[15] = 0x03000278u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000278 = 1u;
    _cyc_03000278 = 1u;
    _cyc_03000278 += runtime_mul_cycles(g_cpu.R[7], 1u, 2u);
    int64_t _p_03000278 = (int64_t)(int32_t)g_cpu.R[3] * (int64_t)(int32_t)g_cpu.R[7];
    uint64_t _acc_03000278 = ((uint64_t)g_cpu.R[14] << 32) | g_cpu.R[12];
    uint64_t _sum_03000278 = _acc_03000278 + (uint64_t)_p_03000278;
    g_cpu.R[12] = (uint32_t)(_sum_03000278 & 0xFFFFFFFFu);
    g_cpu.R[14] = (uint32_t)(_sum_03000278 >> 32);
    g_cpu.R[15] = 0x0300027Cu;
    runtime_tick(_cyc_03000278);
    /* 0300027C  0300027c A ldm r0!,{r5,r6,r7} */
    g_cpu.R[15] = 0x0300027Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300027C = 1u;
    _cyc_0300027C = 2u;
    uint32_t _b_0300027C = g_cpu.R[0];
    uint32_t _a_0300027C = _b_0300027C;
    uint32_t _fb_0300027C = _b_0300027C + 12u;
    _cyc_0300027C += runtime_mem_cycles(_a_0300027C & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_0300027C & ~3u);
    _a_0300027C += 4u;
    _cyc_0300027C += runtime_mem_cycles(_a_0300027C & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_0300027C & ~3u);
    _a_0300027C += 4u;
    _cyc_0300027C += runtime_mem_cycles(_a_0300027C & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_0300027C & ~3u);
    _a_0300027C += 4u;
    g_cpu.R[0] = _fb_0300027C;
    g_cpu.R[15] = 0x03000280u;
    runtime_tick(_cyc_0300027C);
    /* 03000280  03000280 A smlal raw=0xe0e98594 */
    g_cpu.R[15] = 0x03000280u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000280 = 1u;
    _cyc_03000280 = 1u;
    _cyc_03000280 += runtime_mul_cycles(g_cpu.R[5], 1u, 2u);
    int64_t _p_03000280 = (int64_t)(int32_t)g_cpu.R[4] * (int64_t)(int32_t)g_cpu.R[5];
    uint64_t _acc_03000280 = ((uint64_t)g_cpu.R[9] << 32) | g_cpu.R[8];
    uint64_t _sum_03000280 = _acc_03000280 + (uint64_t)_p_03000280;
    g_cpu.R[8] = (uint32_t)(_sum_03000280 & 0xFFFFFFFFu);
    g_cpu.R[9] = (uint32_t)(_sum_03000280 >> 32);
    g_cpu.R[15] = 0x03000284u;
    runtime_tick(_cyc_03000280);
    /* 03000284  03000284 A smlal raw=0xe0eba694 */
    g_cpu.R[15] = 0x03000284u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000284 = 1u;
    _cyc_03000284 = 1u;
    _cyc_03000284 += runtime_mul_cycles(g_cpu.R[6], 1u, 2u);
    int64_t _p_03000284 = (int64_t)(int32_t)g_cpu.R[4] * (int64_t)(int32_t)g_cpu.R[6];
    uint64_t _acc_03000284 = ((uint64_t)g_cpu.R[11] << 32) | g_cpu.R[10];
    uint64_t _sum_03000284 = _acc_03000284 + (uint64_t)_p_03000284;
    g_cpu.R[10] = (uint32_t)(_sum_03000284 & 0xFFFFFFFFu);
    g_cpu.R[11] = (uint32_t)(_sum_03000284 >> 32);
    g_cpu.R[15] = 0x03000288u;
    runtime_tick(_cyc_03000284);
    /* 03000288  03000288 A smlal raw=0xe0eec794 */
    g_cpu.R[15] = 0x03000288u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000288 = 1u;
    _cyc_03000288 = 1u;
    _cyc_03000288 += runtime_mul_cycles(g_cpu.R[7], 1u, 2u);
    int64_t _p_03000288 = (int64_t)(int32_t)g_cpu.R[4] * (int64_t)(int32_t)g_cpu.R[7];
    uint64_t _acc_03000288 = ((uint64_t)g_cpu.R[14] << 32) | g_cpu.R[12];
    uint64_t _sum_03000288 = _acc_03000288 + (uint64_t)_p_03000288;
    g_cpu.R[12] = (uint32_t)(_sum_03000288 & 0xFFFFFFFFu);
    g_cpu.R[14] = (uint32_t)(_sum_03000288 >> 32);
    g_cpu.R[15] = 0x0300028Cu;
    runtime_tick(_cyc_03000288);
    /* 0300028C  0300028c A mov r8,r8,lsr #16 */
    g_cpu.R[15] = 0x0300028Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300028C = 1u;
    _cyc_0300028C = 1u;
    uint32_t _rm_0300028C = g_cpu.R[8];
    uint32_t _op2_0300028C;
    uint32_t _co_0300028C;
    _op2_0300028C = _rm_0300028C >> 16;
    _co_0300028C = (_rm_0300028C >> 15) & 1u;
    uint32_t _r_0300028C;
    _r_0300028C = _op2_0300028C;
    g_cpu.R[8] = _r_0300028C;
    g_cpu.R[15] = 0x03000290u;
    runtime_tick(_cyc_0300028C);
    /* 03000290  03000290 A orr r8,r8,r9,lsl #16 */
    g_cpu.R[15] = 0x03000290u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000290 = 1u;
    _cyc_03000290 = 1u;
    uint32_t _rm_03000290 = g_cpu.R[9];
    uint32_t _op2_03000290;
    uint32_t _co_03000290;
    _op2_03000290 = _rm_03000290 << 16;
    _co_03000290 = (_rm_03000290 >> 16) & 1u;
    uint32_t _rn_03000290 = g_cpu.R[8];
    uint32_t _r_03000290;
    _r_03000290 = _rn_03000290 | _op2_03000290;
    g_cpu.R[8] = _r_03000290;
    g_cpu.R[15] = 0x03000294u;
    runtime_tick(_cyc_03000290);
    /* 03000294  03000294 A mov r10,r10,lsr #16 */
    g_cpu.R[15] = 0x03000294u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000294 = 1u;
    _cyc_03000294 = 1u;
    uint32_t _rm_03000294 = g_cpu.R[10];
    uint32_t _op2_03000294;
    uint32_t _co_03000294;
    _op2_03000294 = _rm_03000294 >> 16;
    _co_03000294 = (_rm_03000294 >> 15) & 1u;
    uint32_t _r_03000294;
    _r_03000294 = _op2_03000294;
    g_cpu.R[10] = _r_03000294;
    g_cpu.R[15] = 0x03000298u;
    runtime_tick(_cyc_03000294);
    /* 03000298  03000298 A orr r10,r10,r11,lsl #16 */
    g_cpu.R[15] = 0x03000298u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000298 = 1u;
    _cyc_03000298 = 1u;
    uint32_t _rm_03000298 = g_cpu.R[11];
    uint32_t _op2_03000298;
    uint32_t _co_03000298;
    _op2_03000298 = _rm_03000298 << 16;
    _co_03000298 = (_rm_03000298 >> 16) & 1u;
    uint32_t _rn_03000298 = g_cpu.R[10];
    uint32_t _r_03000298;
    _r_03000298 = _rn_03000298 | _op2_03000298;
    g_cpu.R[10] = _r_03000298;
    g_cpu.R[15] = 0x0300029Cu;
    runtime_tick(_cyc_03000298);
    /* 0300029C  0300029c A mov r12,r12,lsr #16 */
    g_cpu.R[15] = 0x0300029Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300029C = 1u;
    _cyc_0300029C = 1u;
    uint32_t _rm_0300029C = g_cpu.R[12];
    uint32_t _op2_0300029C;
    uint32_t _co_0300029C;
    _op2_0300029C = _rm_0300029C >> 16;
    _co_0300029C = (_rm_0300029C >> 15) & 1u;
    uint32_t _r_0300029C;
    _r_0300029C = _op2_0300029C;
    g_cpu.R[12] = _r_0300029C;
    g_cpu.R[15] = 0x030002A0u;
    runtime_tick(_cyc_0300029C);
    /* 030002A0  030002a0 A orr r12,r12,r14,lsl #16 */
    g_cpu.R[15] = 0x030002A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002A0 = 1u;
    _cyc_030002A0 = 1u;
    uint32_t _rm_030002A0 = g_cpu.R[14];
    uint32_t _op2_030002A0;
    uint32_t _co_030002A0;
    _op2_030002A0 = _rm_030002A0 << 16;
    _co_030002A0 = (_rm_030002A0 >> 16) & 1u;
    uint32_t _rn_030002A0 = g_cpu.R[12];
    uint32_t _r_030002A0;
    _r_030002A0 = _rn_030002A0 | _op2_030002A0;
    g_cpu.R[12] = _r_030002A0;
    g_cpu.R[15] = 0x030002A4u;
    runtime_tick(_cyc_030002A0);
    /* 030002A4  030002a4 A ldm r0!,{r5,r6,r7} */
    g_cpu.R[15] = 0x030002A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002A4 = 1u;
    _cyc_030002A4 = 2u;
    uint32_t _b_030002A4 = g_cpu.R[0];
    uint32_t _a_030002A4 = _b_030002A4;
    uint32_t _fb_030002A4 = _b_030002A4 + 12u;
    _cyc_030002A4 += runtime_mem_cycles(_a_030002A4 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030002A4 & ~3u);
    _a_030002A4 += 4u;
    _cyc_030002A4 += runtime_mem_cycles(_a_030002A4 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030002A4 & ~3u);
    _a_030002A4 += 4u;
    _cyc_030002A4 += runtime_mem_cycles(_a_030002A4 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030002A4 & ~3u);
    _a_030002A4 += 4u;
    g_cpu.R[0] = _fb_030002A4;
    g_cpu.R[15] = 0x030002A8u;
    runtime_tick(_cyc_030002A4);
    /* 030002A8  030002a8 A add r5,r5,r8 */
    g_cpu.R[15] = 0x030002A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002A8 = 1u;
    _cyc_030002A8 = 1u;
    uint32_t _rm_030002A8 = g_cpu.R[8];
    uint32_t _op2_030002A8;
    uint32_t _co_030002A8;
    _op2_030002A8 = _rm_030002A8;
    _co_030002A8 = cpsr_c();
    uint32_t _rn_030002A8 = g_cpu.R[5];
    uint32_t _r_030002A8;
    _r_030002A8 = _rn_030002A8 + _op2_030002A8;
    g_cpu.R[5] = _r_030002A8;
    g_cpu.R[15] = 0x030002ACu;
    runtime_tick(_cyc_030002A8);
    /* 030002AC  030002ac A add r6,r6,r10 */
    g_cpu.R[15] = 0x030002ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002AC = 1u;
    _cyc_030002AC = 1u;
    uint32_t _rm_030002AC = g_cpu.R[10];
    uint32_t _op2_030002AC;
    uint32_t _co_030002AC;
    _op2_030002AC = _rm_030002AC;
    _co_030002AC = cpsr_c();
    uint32_t _rn_030002AC = g_cpu.R[6];
    uint32_t _r_030002AC;
    _r_030002AC = _rn_030002AC + _op2_030002AC;
    g_cpu.R[6] = _r_030002AC;
    g_cpu.R[15] = 0x030002B0u;
    runtime_tick(_cyc_030002AC);
    /* 030002B0  030002b0 A add r7,r7,r12 */
    g_cpu.R[15] = 0x030002B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002B0 = 1u;
    _cyc_030002B0 = 1u;
    uint32_t _rm_030002B0 = g_cpu.R[12];
    uint32_t _op2_030002B0;
    uint32_t _co_030002B0;
    _op2_030002B0 = _rm_030002B0;
    _co_030002B0 = cpsr_c();
    uint32_t _rn_030002B0 = g_cpu.R[7];
    uint32_t _r_030002B0;
    _r_030002B0 = _rn_030002B0 + _op2_030002B0;
    g_cpu.R[7] = _r_030002B0;
    g_cpu.R[15] = 0x030002B4u;
    runtime_tick(_cyc_030002B0);
    /* 030002B4  030002b4 A stm r1!,{r5,r6,r7} */
    g_cpu.R[15] = 0x030002B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002B4 = 1u;
    _cyc_030002B4 = 1u;
    uint32_t _b_030002B4 = g_cpu.R[1];
    uint32_t _a_030002B4 = _b_030002B4;
    uint32_t _fb_030002B4 = _b_030002B4 + 12u;
    _cyc_030002B4 += runtime_mem_cycles(_a_030002B4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002B4u, _a_030002B4 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030002B4 & ~3u, g_cpu.R[5]);
    _a_030002B4 += 4u;
    _cyc_030002B4 += runtime_mem_cycles(_a_030002B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002B4u, _a_030002B4 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030002B4 & ~3u, g_cpu.R[6]);
    _a_030002B4 += 4u;
    _cyc_030002B4 += runtime_mem_cycles(_a_030002B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002B4u, _a_030002B4 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030002B4 & ~3u, g_cpu.R[7]);
    _a_030002B4 += 4u;
    g_cpu.R[1] = _fb_030002B4;
    g_cpu.R[15] = 0x030002B8u;
    runtime_tick(_cyc_030002B4);
    /* 030002B8  030002b8 A ldm r13!,{r5,r6,r7,r8,r9,r10,r11,r14} */
    g_cpu.R[15] = 0x030002B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002B8 = 1u;
    _cyc_030002B8 = 2u;
    uint32_t _b_030002B8 = g_cpu.R[13];
    uint32_t _a_030002B8 = _b_030002B8;
    uint32_t _fb_030002B8 = _b_030002B8 + 32u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[10] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[11] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    _cyc_030002B8 += runtime_mem_cycles(_a_030002B8 & ~3u, 4u, 1u);
    g_cpu.R[14] = bus_read_u32(_a_030002B8 & ~3u);
    _a_030002B8 += 4u;
    g_cpu.R[13] = _fb_030002B8;
    g_cpu.R[15] = 0x030002BCu;
    runtime_tick(_cyc_030002B8);
    /* 030002BC  030002bc A bx r14 */
    g_cpu.R[15] = 0x030002BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002BC = 1u;
    _cyc_030002BC = 3u;
    uint32_t _bxt_030002BC = g_cpu.R[14];
    g_cpu.R[15] = _bxt_030002BC & ~1u;
    runtime_tick(_cyc_030002BC);
    if (_bxt_030002BC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030002BC);
    return;
    g_cpu.R[15] = 0x030002C0u;
    runtime_tick(_cyc_030002BC);
    /* fall-through to 0x030002C0 */
    g_cpu.R[15] = 0x030002C0u;
    runtime_dispatch(0x030002C0u);
    return;
}

/* 0x030003FC  mode=arm  end=0x03000434  branches=8  indirect */


/* 0x030002C0 arm */
void gf_iwram_matrix_transform_vector(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030002C0u);
    /* 030002C0  030002c0 A stm r13!,{r5,r6,r7,r8,r9,r10,r11,r14} */
    g_cpu.R[15] = 0x030002C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002C0 = 1u;
    _cyc_030002C0 = 1u;
    uint32_t _b_030002C0 = g_cpu.R[13];
    uint32_t _a_030002C0 = _b_030002C0 - 32u;
    uint32_t _fb_030002C0 = _b_030002C0 - 32u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[5]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[6]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[7]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[8]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[9]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[10], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[10]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[11], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[11]);
    _a_030002C0 += 4u;
    _cyc_030002C0 += runtime_mem_cycles(_a_030002C0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030002C0u, _a_030002C0 & ~3u, g_cpu.R[14], 4u);
    bus_write_u32(_a_030002C0 & ~3u, g_cpu.R[14]);
    _a_030002C0 += 4u;
    g_cpu.R[13] = _fb_030002C0;
    g_cpu.R[15] = 0x030002C4u;
    runtime_tick(_cyc_030002C0);
    /* 030002C4  030002c4 A sub r13,r13,#0x24 */
    g_cpu.R[15] = 0x030002C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002C4 = 1u;
    _cyc_030002C4 = 1u;
    uint32_t _rn_030002C4 = g_cpu.R[13];
    uint32_t _r_030002C4;
    _r_030002C4 = _rn_030002C4 - 0x00000024u;
    g_cpu.R[13] = _r_030002C4;
    g_cpu.R[15] = 0x030002C8u;
    runtime_tick(_cyc_030002C4);
    /* 030002C8  030002c8 A mov r4,r13 */
    g_cpu.R[15] = 0x030002C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002C8 = 1u;
    _cyc_030002C8 = 1u;
    uint32_t _rm_030002C8 = g_cpu.R[13];
    uint32_t _op2_030002C8;
    uint32_t _co_030002C8;
    _op2_030002C8 = _rm_030002C8;
    _co_030002C8 = cpsr_c();
    uint32_t _r_030002C8;
    _r_030002C8 = _op2_030002C8;
    g_cpu.R[4] = _r_030002C8;
    g_cpu.R[15] = 0x030002CCu;
    runtime_tick(_cyc_030002C8);
    /* fall-through to 0x030002CC */
    g_cpu.R[15] = 0x030002CCu;
    runtime_dispatch(0x030002CCu);
    return;
}

/* 0x030003E0  mode=arm  end=0x030003F0  branches=1  indirect */


/* 0x030002CC arm */
void gf_iwram_fast_ram_work_entry_decode(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030002CCu);
L_030002CC:
    /* 030002CC  030002cc A add r1,r15,#0x7c */
    g_cpu.R[15] = 0x030002CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002CC = 1u;
    _cyc_030002CC = 1u;
    uint32_t _rn_030002CC = 0x030002D4u;
    uint32_t _r_030002CC;
    _r_030002CC = _rn_030002CC + 0x0000007Cu;
    g_cpu.R[1] = _r_030002CC;
    g_cpu.R[15] = 0x030002D0u;
    runtime_tick(_cyc_030002CC);
    /* 030002D0  030002d0 A ldm r0!,{r2,r3} */
    g_cpu.R[15] = 0x030002D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002D0 = 1u;
    _cyc_030002D0 = 2u;
    uint32_t _b_030002D0 = g_cpu.R[0];
    uint32_t _a_030002D0 = _b_030002D0;
    uint32_t _fb_030002D0 = _b_030002D0 + 8u;
    _cyc_030002D0 += runtime_mem_cycles(_a_030002D0 & ~3u, 4u, 0u);
    g_cpu.R[2] = bus_read_u32(_a_030002D0 & ~3u);
    _a_030002D0 += 4u;
    _cyc_030002D0 += runtime_mem_cycles(_a_030002D0 & ~3u, 4u, 1u);
    g_cpu.R[3] = bus_read_u32(_a_030002D0 & ~3u);
    _a_030002D0 += 4u;
    g_cpu.R[0] = _fb_030002D0;
    g_cpu.R[15] = 0x030002D4u;
    runtime_tick(_cyc_030002D0);
    /* 030002D4  030002d4 A ldm r1!,{r5,r6,r7} */
    g_cpu.R[15] = 0x030002D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002D4 = 1u;
    _cyc_030002D4 = 2u;
    uint32_t _b_030002D4 = g_cpu.R[1];
    uint32_t _a_030002D4 = _b_030002D4;
    uint32_t _fb_030002D4 = _b_030002D4 + 12u;
    _cyc_030002D4 += runtime_mem_cycles(_a_030002D4 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030002D4 & ~3u);
    _a_030002D4 += 4u;
    _cyc_030002D4 += runtime_mem_cycles(_a_030002D4 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030002D4 & ~3u);
    _a_030002D4 += 4u;
    _cyc_030002D4 += runtime_mem_cycles(_a_030002D4 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030002D4 & ~3u);
    _a_030002D4 += 4u;
    g_cpu.R[1] = _fb_030002D4;
    g_cpu.R[15] = 0x030002D8u;
    runtime_tick(_cyc_030002D4);
    /* 030002D8  030002d8 A smull raw=0xe0c98295 */
    g_cpu.R[15] = 0x030002D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002D8 = 1u;
    _cyc_030002D8 = 1u;
    _cyc_030002D8 += runtime_mul_cycles(g_cpu.R[2], 1u, 1u);
    int64_t _p_030002D8 = (int64_t)(int32_t)g_cpu.R[5] * (int64_t)(int32_t)g_cpu.R[2];
    g_cpu.R[8] = (uint32_t)((uint64_t)_p_030002D8 & 0xFFFFFFFFu);
    g_cpu.R[9] = (uint32_t)((uint64_t)_p_030002D8 >> 32);
    g_cpu.R[15] = 0x030002DCu;
    runtime_tick(_cyc_030002D8);
    /* 030002DC  030002dc A smull raw=0xe0cba296 */
    g_cpu.R[15] = 0x030002DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002DC = 1u;
    _cyc_030002DC = 1u;
    _cyc_030002DC += runtime_mul_cycles(g_cpu.R[2], 1u, 1u);
    int64_t _p_030002DC = (int64_t)(int32_t)g_cpu.R[6] * (int64_t)(int32_t)g_cpu.R[2];
    g_cpu.R[10] = (uint32_t)((uint64_t)_p_030002DC & 0xFFFFFFFFu);
    g_cpu.R[11] = (uint32_t)((uint64_t)_p_030002DC >> 32);
    g_cpu.R[15] = 0x030002E0u;
    runtime_tick(_cyc_030002DC);
    /* 030002E0  030002e0 A smull raw=0xe0cec297 */
    g_cpu.R[15] = 0x030002E0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002E0 = 1u;
    _cyc_030002E0 = 1u;
    _cyc_030002E0 += runtime_mul_cycles(g_cpu.R[2], 1u, 1u);
    int64_t _p_030002E0 = (int64_t)(int32_t)g_cpu.R[7] * (int64_t)(int32_t)g_cpu.R[2];
    g_cpu.R[12] = (uint32_t)((uint64_t)_p_030002E0 & 0xFFFFFFFFu);
    g_cpu.R[14] = (uint32_t)((uint64_t)_p_030002E0 >> 32);
    g_cpu.R[15] = 0x030002E4u;
    runtime_tick(_cyc_030002E0);
    /* 030002E4  030002e4 A ldm r1!,{r5,r6,r7} */
    g_cpu.R[15] = 0x030002E4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002E4 = 1u;
    _cyc_030002E4 = 2u;
    uint32_t _b_030002E4 = g_cpu.R[1];
    uint32_t _a_030002E4 = _b_030002E4;
    uint32_t _fb_030002E4 = _b_030002E4 + 12u;
    _cyc_030002E4 += runtime_mem_cycles(_a_030002E4 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030002E4 & ~3u);
    _a_030002E4 += 4u;
    _cyc_030002E4 += runtime_mem_cycles(_a_030002E4 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030002E4 & ~3u);
    _a_030002E4 += 4u;
    _cyc_030002E4 += runtime_mem_cycles(_a_030002E4 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030002E4 & ~3u);
    _a_030002E4 += 4u;
    g_cpu.R[1] = _fb_030002E4;
    g_cpu.R[15] = 0x030002E8u;
    runtime_tick(_cyc_030002E4);
    /* 030002E8  030002e8 A smlal raw=0xe0e98395 */
    g_cpu.R[15] = 0x030002E8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002E8 = 1u;
    _cyc_030002E8 = 1u;
    _cyc_030002E8 += runtime_mul_cycles(g_cpu.R[3], 1u, 2u);
    int64_t _p_030002E8 = (int64_t)(int32_t)g_cpu.R[5] * (int64_t)(int32_t)g_cpu.R[3];
    uint64_t _acc_030002E8 = ((uint64_t)g_cpu.R[9] << 32) | g_cpu.R[8];
    uint64_t _sum_030002E8 = _acc_030002E8 + (uint64_t)_p_030002E8;
    g_cpu.R[8] = (uint32_t)(_sum_030002E8 & 0xFFFFFFFFu);
    g_cpu.R[9] = (uint32_t)(_sum_030002E8 >> 32);
    g_cpu.R[15] = 0x030002ECu;
    runtime_tick(_cyc_030002E8);
    /* 030002EC  030002ec A smlal raw=0xe0eba396 */
    g_cpu.R[15] = 0x030002ECu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002EC = 1u;
    _cyc_030002EC = 1u;
    _cyc_030002EC += runtime_mul_cycles(g_cpu.R[3], 1u, 2u);
    int64_t _p_030002EC = (int64_t)(int32_t)g_cpu.R[6] * (int64_t)(int32_t)g_cpu.R[3];
    uint64_t _acc_030002EC = ((uint64_t)g_cpu.R[11] << 32) | g_cpu.R[10];
    uint64_t _sum_030002EC = _acc_030002EC + (uint64_t)_p_030002EC;
    g_cpu.R[10] = (uint32_t)(_sum_030002EC & 0xFFFFFFFFu);
    g_cpu.R[11] = (uint32_t)(_sum_030002EC >> 32);
    g_cpu.R[15] = 0x030002F0u;
    runtime_tick(_cyc_030002EC);
    /* 030002F0  030002f0 A smlal raw=0xe0eec397 */
    g_cpu.R[15] = 0x030002F0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002F0 = 1u;
    _cyc_030002F0 = 1u;
    _cyc_030002F0 += runtime_mul_cycles(g_cpu.R[3], 1u, 2u);
    int64_t _p_030002F0 = (int64_t)(int32_t)g_cpu.R[7] * (int64_t)(int32_t)g_cpu.R[3];
    uint64_t _acc_030002F0 = ((uint64_t)g_cpu.R[14] << 32) | g_cpu.R[12];
    uint64_t _sum_030002F0 = _acc_030002F0 + (uint64_t)_p_030002F0;
    g_cpu.R[12] = (uint32_t)(_sum_030002F0 & 0xFFFFFFFFu);
    g_cpu.R[14] = (uint32_t)(_sum_030002F0 >> 32);
    g_cpu.R[15] = 0x030002F4u;
    runtime_tick(_cyc_030002F0);
    /* 030002F4  030002f4 A ldm r1!,{r5,r6,r7} */
    g_cpu.R[15] = 0x030002F4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002F4 = 1u;
    _cyc_030002F4 = 2u;
    uint32_t _b_030002F4 = g_cpu.R[1];
    uint32_t _a_030002F4 = _b_030002F4;
    uint32_t _fb_030002F4 = _b_030002F4 + 12u;
    _cyc_030002F4 += runtime_mem_cycles(_a_030002F4 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030002F4 & ~3u);
    _a_030002F4 += 4u;
    _cyc_030002F4 += runtime_mem_cycles(_a_030002F4 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030002F4 & ~3u);
    _a_030002F4 += 4u;
    _cyc_030002F4 += runtime_mem_cycles(_a_030002F4 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030002F4 & ~3u);
    _a_030002F4 += 4u;
    g_cpu.R[1] = _fb_030002F4;
    g_cpu.R[15] = 0x030002F8u;
    runtime_tick(_cyc_030002F4);
    /* 030002F8  030002f8 A ldr r2,[r0],#0x4 */
    g_cpu.R[15] = 0x030002F8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002F8 = 1u;
    _cyc_030002F8 = 2u;
    uint32_t _base_030002F8 = g_cpu.R[0];
    uint32_t _off_030002F8;
    _off_030002F8 = 0x00000004u;
    uint32_t _ea_030002F8 = _base_030002F8;
    uint32_t _post_030002F8 = _base_030002F8 + _off_030002F8;
    _cyc_030002F8 += runtime_mem_cycles(_ea_030002F8, 4u, 0u);
    uint32_t _v_030002F8;
    { uint32_t _w = bus_read_u32(_ea_030002F8 & ~3u); uint32_t _rot = (_ea_030002F8 & 3u) * 8u; _v_030002F8 = (_rot == 0u) ? _w : ((_w >> _rot) | (_w << (32u - _rot))); }
    if (0u != 2u) g_cpu.R[0] = _post_030002F8;
    g_cpu.R[2] = _v_030002F8;
    g_cpu.R[15] = 0x030002FCu;
    runtime_tick(_cyc_030002F8);
    /* 030002FC  030002fc A smlal raw=0xe0e98295 */
    g_cpu.R[15] = 0x030002FCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030002FC = 1u;
    _cyc_030002FC = 1u;
    _cyc_030002FC += runtime_mul_cycles(g_cpu.R[2], 1u, 2u);
    int64_t _p_030002FC = (int64_t)(int32_t)g_cpu.R[5] * (int64_t)(int32_t)g_cpu.R[2];
    uint64_t _acc_030002FC = ((uint64_t)g_cpu.R[9] << 32) | g_cpu.R[8];
    uint64_t _sum_030002FC = _acc_030002FC + (uint64_t)_p_030002FC;
    g_cpu.R[8] = (uint32_t)(_sum_030002FC & 0xFFFFFFFFu);
    g_cpu.R[9] = (uint32_t)(_sum_030002FC >> 32);
    g_cpu.R[15] = 0x03000300u;
    runtime_tick(_cyc_030002FC);
    /* 03000300  03000300 A smlal raw=0xe0eba296 */
    g_cpu.R[15] = 0x03000300u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000300 = 1u;
    _cyc_03000300 = 1u;
    _cyc_03000300 += runtime_mul_cycles(g_cpu.R[2], 1u, 2u);
    int64_t _p_03000300 = (int64_t)(int32_t)g_cpu.R[6] * (int64_t)(int32_t)g_cpu.R[2];
    uint64_t _acc_03000300 = ((uint64_t)g_cpu.R[11] << 32) | g_cpu.R[10];
    uint64_t _sum_03000300 = _acc_03000300 + (uint64_t)_p_03000300;
    g_cpu.R[10] = (uint32_t)(_sum_03000300 & 0xFFFFFFFFu);
    g_cpu.R[11] = (uint32_t)(_sum_03000300 >> 32);
    g_cpu.R[15] = 0x03000304u;
    runtime_tick(_cyc_03000300);
    /* 03000304  03000304 A smlal raw=0xe0eec297 */
    g_cpu.R[15] = 0x03000304u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000304 = 1u;
    _cyc_03000304 = 1u;
    _cyc_03000304 += runtime_mul_cycles(g_cpu.R[2], 1u, 2u);
    int64_t _p_03000304 = (int64_t)(int32_t)g_cpu.R[7] * (int64_t)(int32_t)g_cpu.R[2];
    uint64_t _acc_03000304 = ((uint64_t)g_cpu.R[14] << 32) | g_cpu.R[12];
    uint64_t _sum_03000304 = _acc_03000304 + (uint64_t)_p_03000304;
    g_cpu.R[12] = (uint32_t)(_sum_03000304 & 0xFFFFFFFFu);
    g_cpu.R[14] = (uint32_t)(_sum_03000304 >> 32);
    g_cpu.R[15] = 0x03000308u;
    runtime_tick(_cyc_03000304);
    /* 03000308  03000308 A mov r8,r8,lsr #16 */
    g_cpu.R[15] = 0x03000308u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000308 = 1u;
    _cyc_03000308 = 1u;
    uint32_t _rm_03000308 = g_cpu.R[8];
    uint32_t _op2_03000308;
    uint32_t _co_03000308;
    _op2_03000308 = _rm_03000308 >> 16;
    _co_03000308 = (_rm_03000308 >> 15) & 1u;
    uint32_t _r_03000308;
    _r_03000308 = _op2_03000308;
    g_cpu.R[8] = _r_03000308;
    g_cpu.R[15] = 0x0300030Cu;
    runtime_tick(_cyc_03000308);
    /* 0300030C  0300030c A orr r8,r8,r9,lsl #16 */
    g_cpu.R[15] = 0x0300030Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300030C = 1u;
    _cyc_0300030C = 1u;
    uint32_t _rm_0300030C = g_cpu.R[9];
    uint32_t _op2_0300030C;
    uint32_t _co_0300030C;
    _op2_0300030C = _rm_0300030C << 16;
    _co_0300030C = (_rm_0300030C >> 16) & 1u;
    uint32_t _rn_0300030C = g_cpu.R[8];
    uint32_t _r_0300030C;
    _r_0300030C = _rn_0300030C | _op2_0300030C;
    g_cpu.R[8] = _r_0300030C;
    g_cpu.R[15] = 0x03000310u;
    runtime_tick(_cyc_0300030C);
    /* 03000310  03000310 A mov r10,r10,lsr #16 */
    g_cpu.R[15] = 0x03000310u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000310 = 1u;
    _cyc_03000310 = 1u;
    uint32_t _rm_03000310 = g_cpu.R[10];
    uint32_t _op2_03000310;
    uint32_t _co_03000310;
    _op2_03000310 = _rm_03000310 >> 16;
    _co_03000310 = (_rm_03000310 >> 15) & 1u;
    uint32_t _r_03000310;
    _r_03000310 = _op2_03000310;
    g_cpu.R[10] = _r_03000310;
    g_cpu.R[15] = 0x03000314u;
    runtime_tick(_cyc_03000310);
    /* 03000314  03000314 A orr r10,r10,r11,lsl #16 */
    g_cpu.R[15] = 0x03000314u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000314 = 1u;
    _cyc_03000314 = 1u;
    uint32_t _rm_03000314 = g_cpu.R[11];
    uint32_t _op2_03000314;
    uint32_t _co_03000314;
    _op2_03000314 = _rm_03000314 << 16;
    _co_03000314 = (_rm_03000314 >> 16) & 1u;
    uint32_t _rn_03000314 = g_cpu.R[10];
    uint32_t _r_03000314;
    _r_03000314 = _rn_03000314 | _op2_03000314;
    g_cpu.R[10] = _r_03000314;
    g_cpu.R[15] = 0x03000318u;
    runtime_tick(_cyc_03000314);
    /* 03000318  03000318 A mov r12,r12,lsr #16 */
    g_cpu.R[15] = 0x03000318u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000318 = 1u;
    _cyc_03000318 = 1u;
    uint32_t _rm_03000318 = g_cpu.R[12];
    uint32_t _op2_03000318;
    uint32_t _co_03000318;
    _op2_03000318 = _rm_03000318 >> 16;
    _co_03000318 = (_rm_03000318 >> 15) & 1u;
    uint32_t _r_03000318;
    _r_03000318 = _op2_03000318;
    g_cpu.R[12] = _r_03000318;
    g_cpu.R[15] = 0x0300031Cu;
    runtime_tick(_cyc_03000318);
    /* 0300031C  0300031c A orr r12,r12,r14,lsl #16 */
    g_cpu.R[15] = 0x0300031Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300031C = 1u;
    _cyc_0300031C = 1u;
    uint32_t _rm_0300031C = g_cpu.R[14];
    uint32_t _op2_0300031C;
    uint32_t _co_0300031C;
    _op2_0300031C = _rm_0300031C << 16;
    _co_0300031C = (_rm_0300031C >> 16) & 1u;
    uint32_t _rn_0300031C = g_cpu.R[12];
    uint32_t _r_0300031C;
    _r_0300031C = _rn_0300031C | _op2_0300031C;
    g_cpu.R[12] = _r_0300031C;
    g_cpu.R[15] = 0x03000320u;
    runtime_tick(_cyc_0300031C);
    /* 03000320  03000320 A sub r2,r4,r13 */
    g_cpu.R[15] = 0x03000320u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000320 = 1u;
    _cyc_03000320 = 1u;
    uint32_t _rm_03000320 = g_cpu.R[13];
    uint32_t _op2_03000320;
    uint32_t _co_03000320;
    _op2_03000320 = _rm_03000320;
    _co_03000320 = cpsr_c();
    uint32_t _rn_03000320 = g_cpu.R[4];
    uint32_t _r_03000320;
    _r_03000320 = _rn_03000320 - _op2_03000320;
    g_cpu.R[2] = _r_03000320;
    g_cpu.R[15] = 0x03000324u;
    runtime_tick(_cyc_03000320);
    /* 03000324  03000324 A cmps r2,#0x24 */
    g_cpu.R[15] = 0x03000324u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000324 = 1u;
    _cyc_03000324 = 1u;
    uint32_t _rn_03000324 = g_cpu.R[2];
    uint32_t _r_03000324;
    _r_03000324 = _rn_03000324 - 0x00000024u;
    arm_set_nzcv_sub(_rn_03000324, 0x00000024u, _r_03000324);
    g_cpu.R[15] = 0x03000328u;
    runtime_tick(_cyc_03000324);
    /* 03000328  03000328 A stmne r4!,{r8,r10,r12} */
    g_cpu.R[15] = 0x03000328u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000328 = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_03000328 = 1u;
        uint32_t _b_03000328 = g_cpu.R[4];
        uint32_t _a_03000328 = _b_03000328;
        uint32_t _fb_03000328 = _b_03000328 + 12u;
        _cyc_03000328 += runtime_mem_cycles(_a_03000328 & ~3u, 4u, 0u);
        runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000328u, _a_03000328 & ~3u, g_cpu.R[8], 4u);
        bus_write_u32(_a_03000328 & ~3u, g_cpu.R[8]);
        _a_03000328 += 4u;
        _cyc_03000328 += runtime_mem_cycles(_a_03000328 & ~3u, 4u, 1u);
        runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000328u, _a_03000328 & ~3u, g_cpu.R[10], 4u);
        bus_write_u32(_a_03000328 & ~3u, g_cpu.R[10]);
        _a_03000328 += 4u;
        _cyc_03000328 += runtime_mem_cycles(_a_03000328 & ~3u, 4u, 1u);
        runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000328u, _a_03000328 & ~3u, g_cpu.R[12], 4u);
        bus_write_u32(_a_03000328 & ~3u, g_cpu.R[12]);
        _a_03000328 += 4u;
        g_cpu.R[4] = _fb_03000328;
    }
    g_cpu.R[15] = 0x0300032Cu;
    runtime_tick(_cyc_03000328);
    /* 0300032C  0300032c A bne 0x030002cc */
    g_cpu.R[15] = 0x0300032Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300032C = 1u;
    if (arm_cond_passes(0x1u)) {
        _cyc_0300032C = 3u;
        g_cpu.R[15] = 0x030002CCu;
        runtime_trace_event(RUNTIME_TRACE_BRANCH, 0x0300032Cu, 0x030002CCu, 0u, 0u);
        runtime_tick(_cyc_0300032C);
        goto L_030002CC;
    }
    g_cpu.R[15] = 0x03000330u;
    runtime_tick(_cyc_0300032C);
    /* 03000330  03000330 A ldm r1!,{r5,r6,r7} */
    g_cpu.R[15] = 0x03000330u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000330 = 1u;
    _cyc_03000330 = 2u;
    uint32_t _b_03000330 = g_cpu.R[1];
    uint32_t _a_03000330 = _b_03000330;
    uint32_t _fb_03000330 = _b_03000330 + 12u;
    _cyc_03000330 += runtime_mem_cycles(_a_03000330 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_03000330 & ~3u);
    _a_03000330 += 4u;
    _cyc_03000330 += runtime_mem_cycles(_a_03000330 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_03000330 & ~3u);
    _a_03000330 += 4u;
    _cyc_03000330 += runtime_mem_cycles(_a_03000330 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_03000330 & ~3u);
    _a_03000330 += 4u;
    g_cpu.R[1] = _fb_03000330;
    g_cpu.R[15] = 0x03000334u;
    runtime_tick(_cyc_03000330);
    /* 03000334  03000334 A add r12,r12,r7 */
    g_cpu.R[15] = 0x03000334u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000334 = 1u;
    _cyc_03000334 = 1u;
    uint32_t _rm_03000334 = g_cpu.R[7];
    uint32_t _op2_03000334;
    uint32_t _co_03000334;
    _op2_03000334 = _rm_03000334;
    _co_03000334 = cpsr_c();
    uint32_t _rn_03000334 = g_cpu.R[12];
    uint32_t _r_03000334;
    _r_03000334 = _rn_03000334 + _op2_03000334;
    g_cpu.R[12] = _r_03000334;
    g_cpu.R[15] = 0x03000338u;
    runtime_tick(_cyc_03000334);
    /* 03000338  03000338 A add r11,r10,r6 */
    g_cpu.R[15] = 0x03000338u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000338 = 1u;
    _cyc_03000338 = 1u;
    uint32_t _rm_03000338 = g_cpu.R[6];
    uint32_t _op2_03000338;
    uint32_t _co_03000338;
    _op2_03000338 = _rm_03000338;
    _co_03000338 = cpsr_c();
    uint32_t _rn_03000338 = g_cpu.R[10];
    uint32_t _r_03000338;
    _r_03000338 = _rn_03000338 + _op2_03000338;
    g_cpu.R[11] = _r_03000338;
    g_cpu.R[15] = 0x0300033Cu;
    runtime_tick(_cyc_03000338);
    /* 0300033C  0300033c A add r10,r8,r5 */
    g_cpu.R[15] = 0x0300033Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300033C = 1u;
    _cyc_0300033C = 1u;
    uint32_t _rm_0300033C = g_cpu.R[5];
    uint32_t _op2_0300033C;
    uint32_t _co_0300033C;
    _op2_0300033C = _rm_0300033C;
    _co_0300033C = cpsr_c();
    uint32_t _rn_0300033C = g_cpu.R[8];
    uint32_t _r_0300033C;
    _r_0300033C = _rn_0300033C + _op2_0300033C;
    g_cpu.R[10] = _r_0300033C;
    g_cpu.R[15] = 0x03000340u;
    runtime_tick(_cyc_0300033C);
    /* 03000340  03000340 A ldm r13!,{r0,r2,r3,r4,r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x03000340u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000340 = 1u;
    _cyc_03000340 = 2u;
    uint32_t _b_03000340 = g_cpu.R[13];
    uint32_t _a_03000340 = _b_03000340;
    uint32_t _fb_03000340 = _b_03000340 + 36u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 0u);
    g_cpu.R[0] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[2] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[3] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    _cyc_03000340 += runtime_mem_cycles(_a_03000340 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_03000340 & ~3u);
    _a_03000340 += 4u;
    g_cpu.R[13] = _fb_03000340;
    g_cpu.R[15] = 0x03000344u;
    runtime_tick(_cyc_03000340);
    /* 03000344  03000344 A stm r1,{r0,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12} */
    g_cpu.R[15] = 0x03000344u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000344 = 1u;
    _cyc_03000344 = 1u;
    uint32_t _b_03000344 = g_cpu.R[1];
    uint32_t _a_03000344 = _b_03000344 - 48u;
    uint32_t _fb_03000344 = _b_03000344 - 48u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[0], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[0]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[2], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[2]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[3]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[4]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[5]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[6]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[7]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[8]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[9]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[10], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[10]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[11], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[11]);
    _a_03000344 += 4u;
    _cyc_03000344 += runtime_mem_cycles(_a_03000344 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000344u, _a_03000344 & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_03000344 & ~3u, g_cpu.R[12]);
    _a_03000344 += 4u;
    g_cpu.R[15] = 0x03000348u;
    runtime_tick(_cyc_03000344);
    /* 03000348  03000348 A ldm r13!,{r5,r6,r7,r8,r9,r10,r11,r14} */
    g_cpu.R[15] = 0x03000348u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000348 = 1u;
    _cyc_03000348 = 2u;
    uint32_t _b_03000348 = g_cpu.R[13];
    uint32_t _a_03000348 = _b_03000348;
    uint32_t _fb_03000348 = _b_03000348 + 32u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[10] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[11] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    _cyc_03000348 += runtime_mem_cycles(_a_03000348 & ~3u, 4u, 1u);
    g_cpu.R[14] = bus_read_u32(_a_03000348 & ~3u);
    _a_03000348 += 4u;
    g_cpu.R[13] = _fb_03000348;
    g_cpu.R[15] = 0x0300034Cu;
    runtime_tick(_cyc_03000348);
    /* 0300034C  0300034c A bx r14 */
    g_cpu.R[15] = 0x0300034Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300034C = 1u;
    _cyc_0300034C = 3u;
    uint32_t _bxt_0300034C = g_cpu.R[14];
    g_cpu.R[15] = _bxt_0300034C & ~1u;
    runtime_tick(_cyc_0300034C);
    if (_bxt_0300034C & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_0300034C);
    return;
    g_cpu.R[15] = 0x03000350u;
    runtime_tick(_cyc_0300034C);
    /* fall-through to 0x03000350 */
    g_cpu.R[15] = 0x03000350u;
    runtime_dispatch(0x03000350u);
    return;
}

/* 0x030013F8  mode=arm  end=0x03001400  branches=0  indirect */


/* 0x03000380 arm */
void gf_iwram_signed_divmod_routine(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000380u);
    /* 03000380  03000380 A eor r12,r0,r1 */
    g_cpu.R[15] = 0x03000380u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000380 = 1u;
    _cyc_03000380 = 1u;
    uint32_t _rm_03000380 = g_cpu.R[1];
    uint32_t _op2_03000380;
    uint32_t _co_03000380;
    _op2_03000380 = _rm_03000380;
    _co_03000380 = cpsr_c();
    uint32_t _rn_03000380 = g_cpu.R[0];
    uint32_t _r_03000380;
    _r_03000380 = _rn_03000380 ^ _op2_03000380;
    g_cpu.R[12] = _r_03000380;
    g_cpu.R[15] = 0x03000384u;
    runtime_tick(_cyc_03000380);
    /* 03000384  03000384 A movs r2,r1 */
    g_cpu.R[15] = 0x03000384u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000384 = 1u;
    _cyc_03000384 = 1u;
    uint32_t _rm_03000384 = g_cpu.R[1];
    uint32_t _op2_03000384;
    uint32_t _co_03000384;
    _op2_03000384 = _rm_03000384;
    _co_03000384 = cpsr_c();
    uint32_t _r_03000384;
    _r_03000384 = _op2_03000384;
    arm_set_nzc_logic(_r_03000384, _co_03000384);
    g_cpu.R[2] = _r_03000384;
    g_cpu.R[15] = 0x03000388u;
    runtime_tick(_cyc_03000384);
    /* 03000388  03000388 A rsbmi r2,r2,#0x0 */
    g_cpu.R[15] = 0x03000388u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000388 = 1u;
    if (arm_cond_passes(0x4u)) {
        _cyc_03000388 = 1u;
        uint32_t _rn_03000388 = g_cpu.R[2];
        uint32_t _r_03000388;
        _r_03000388 = 0x00000000u - _rn_03000388;
        g_cpu.R[2] = _r_03000388;
    }
    g_cpu.R[15] = 0x0300038Cu;
    runtime_tick(_cyc_03000388);
    /* 0300038C  0300038c A movs r1,r0 */
    g_cpu.R[15] = 0x0300038Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300038C = 1u;
    _cyc_0300038C = 1u;
    uint32_t _rm_0300038C = g_cpu.R[0];
    uint32_t _op2_0300038C;
    uint32_t _co_0300038C;
    _op2_0300038C = _rm_0300038C;
    _co_0300038C = cpsr_c();
    uint32_t _r_0300038C;
    _r_0300038C = _op2_0300038C;
    arm_set_nzc_logic(_r_0300038C, _co_0300038C);
    g_cpu.R[1] = _r_0300038C;
    g_cpu.R[15] = 0x03000390u;
    runtime_tick(_cyc_0300038C);
    /* 03000390  03000390 A rsbmi r1,r1,#0x0 */
    g_cpu.R[15] = 0x03000390u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000390 = 1u;
    if (arm_cond_passes(0x4u)) {
        _cyc_03000390 = 1u;
        uint32_t _rn_03000390 = g_cpu.R[1];
        uint32_t _r_03000390;
        _r_03000390 = 0x00000000u - _rn_03000390;
        g_cpu.R[1] = _r_03000390;
    }
    g_cpu.R[15] = 0x03000394u;
    runtime_tick(_cyc_03000390);
    /* 03000394  03000394 A movs r0,r12,lsr #0 */
    g_cpu.R[15] = 0x03000394u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000394 = 1u;
    _cyc_03000394 = 1u;
    uint32_t _rm_03000394 = g_cpu.R[12];
    uint32_t _op2_03000394;
    uint32_t _co_03000394;
    _op2_03000394 = 0u;
    _co_03000394 = (_rm_03000394 >> 31) & 1u;
    uint32_t _r_03000394;
    _r_03000394 = _op2_03000394;
    arm_set_nzc_logic(_r_03000394, _co_03000394);
    g_cpu.R[0] = _r_03000394;
    g_cpu.R[15] = 0x03000398u;
    runtime_tick(_cyc_03000394);
    /* 03000398  03000398 A bcc 0x030003fc */
    g_cpu.R[15] = 0x03000398u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000398 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000398 = 3u;
        g_cpu.R[15] = 0x030003FCu;
        runtime_tick(_cyc_03000398);
        gf_iwram_lzss_decompress_stream();
        return;
    }
    g_cpu.R[15] = 0x0300039Cu;
    runtime_tick(_cyc_03000398);
    /* 0300039C  0300039c A mov r12,r14 */
    g_cpu.R[15] = 0x0300039Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300039C = 1u;
    _cyc_0300039C = 1u;
    uint32_t _rm_0300039C = g_cpu.R[14];
    uint32_t _op2_0300039C;
    uint32_t _co_0300039C;
    _op2_0300039C = _rm_0300039C;
    _co_0300039C = cpsr_c();
    uint32_t _r_0300039C;
    _r_0300039C = _op2_0300039C;
    g_cpu.R[12] = _r_0300039C;
    g_cpu.R[15] = 0x030003A0u;
    runtime_tick(_cyc_0300039C);
    /* 030003A0  030003a0 A bl 0x030003fc */
    g_cpu.R[15] = 0x030003A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003A0 = 1u;
    _cyc_030003A0 = 3u;
    g_cpu.R[14] = 0x030003A4u;
    g_cpu.R[15] = 0x030003FCu;
    runtime_call_push_return(0x030003A4u);
    runtime_tick(_cyc_030003A0);
    _cyc_030003A0 = 0u;
    gf_iwram_lzss_decompress_stream();
    if (g_cpu.R[15] != 0x030003A4u) { runtime_call_cancel_return(0x030003A4u); return; }
    g_cpu.R[15] = 0x030003A4u;
    runtime_tick(_cyc_030003A0);
    /* 030003A4  030003a4 A rsb r0,r0,#0x0 */
    g_cpu.R[15] = 0x030003A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003A4 = 1u;
    _cyc_030003A4 = 1u;
    uint32_t _rn_030003A4 = g_cpu.R[0];
    uint32_t _r_030003A4;
    _r_030003A4 = 0x00000000u - _rn_030003A4;
    g_cpu.R[0] = _r_030003A4;
    g_cpu.R[15] = 0x030003A8u;
    runtime_tick(_cyc_030003A4);
    /* 030003A8  030003a8 A bx r12 */
    g_cpu.R[15] = 0x030003A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003A8 = 1u;
    _cyc_030003A8 = 3u;
    uint32_t _bxt_030003A8 = g_cpu.R[12];
    g_cpu.R[15] = _bxt_030003A8 & ~1u;
    runtime_tick(_cyc_030003A8);
    if (_bxt_030003A8 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030003A8);
    return;
    g_cpu.R[15] = 0x030003ACu;
    runtime_tick(_cyc_030003A8);
    /* fall-through to 0x030003AC */
    g_cpu.R[15] = 0x030003ACu;
    runtime_dispatch(0x030003ACu);
    return;
}

/* 0x030004A4  mode=arm  end=0x030004DC  branches=5  indirect */


/* 0x030003AC arm */
void gf_iwram_unsigned_divmod_routine(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030003ACu);
    /* 030003AC  030003ac A stm r13!,{r14} */
    g_cpu.R[15] = 0x030003ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003AC = 1u;
    _cyc_030003AC = 1u;
    uint32_t _b_030003AC = g_cpu.R[13];
    uint32_t _a_030003AC = _b_030003AC - 4u;
    uint32_t _fb_030003AC = _b_030003AC - 4u;
    _cyc_030003AC += runtime_mem_cycles(_a_030003AC & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030003ACu, _a_030003AC & ~3u, g_cpu.R[14], 4u);
    bus_write_u32(_a_030003AC & ~3u, g_cpu.R[14]);
    _a_030003AC += 4u;
    g_cpu.R[13] = _fb_030003AC;
    g_cpu.R[15] = 0x030003B0u;
    runtime_tick(_cyc_030003AC);
    /* 030003B0  030003b0 A eor r12,r0,r1 */
    g_cpu.R[15] = 0x030003B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003B0 = 1u;
    _cyc_030003B0 = 1u;
    uint32_t _rm_030003B0 = g_cpu.R[1];
    uint32_t _op2_030003B0;
    uint32_t _co_030003B0;
    _op2_030003B0 = _rm_030003B0;
    _co_030003B0 = cpsr_c();
    uint32_t _rn_030003B0 = g_cpu.R[0];
    uint32_t _r_030003B0;
    _r_030003B0 = _rn_030003B0 ^ _op2_030003B0;
    g_cpu.R[12] = _r_030003B0;
    g_cpu.R[15] = 0x030003B4u;
    runtime_tick(_cyc_030003B0);
    /* 030003B4  030003b4 A movs r2,r1 */
    g_cpu.R[15] = 0x030003B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003B4 = 1u;
    _cyc_030003B4 = 1u;
    uint32_t _rm_030003B4 = g_cpu.R[1];
    uint32_t _op2_030003B4;
    uint32_t _co_030003B4;
    _op2_030003B4 = _rm_030003B4;
    _co_030003B4 = cpsr_c();
    uint32_t _r_030003B4;
    _r_030003B4 = _op2_030003B4;
    arm_set_nzc_logic(_r_030003B4, _co_030003B4);
    g_cpu.R[2] = _r_030003B4;
    g_cpu.R[15] = 0x030003B8u;
    runtime_tick(_cyc_030003B4);
    /* 030003B8  030003b8 A rsbmi r2,r2,#0x0 */
    g_cpu.R[15] = 0x030003B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003B8 = 1u;
    if (arm_cond_passes(0x4u)) {
        _cyc_030003B8 = 1u;
        uint32_t _rn_030003B8 = g_cpu.R[2];
        uint32_t _r_030003B8;
        _r_030003B8 = 0x00000000u - _rn_030003B8;
        g_cpu.R[2] = _r_030003B8;
    }
    g_cpu.R[15] = 0x030003BCu;
    runtime_tick(_cyc_030003B8);
    /* 030003BC  030003bc A movs r1,r0 */
    g_cpu.R[15] = 0x030003BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003BC = 1u;
    _cyc_030003BC = 1u;
    uint32_t _rm_030003BC = g_cpu.R[0];
    uint32_t _op2_030003BC;
    uint32_t _co_030003BC;
    _op2_030003BC = _rm_030003BC;
    _co_030003BC = cpsr_c();
    uint32_t _r_030003BC;
    _r_030003BC = _op2_030003BC;
    arm_set_nzc_logic(_r_030003BC, _co_030003BC);
    g_cpu.R[1] = _r_030003BC;
    g_cpu.R[15] = 0x030003C0u;
    runtime_tick(_cyc_030003BC);
    /* 030003C0  030003c0 A rsbmi r1,r1,#0x0 */
    g_cpu.R[15] = 0x030003C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003C0 = 1u;
    if (arm_cond_passes(0x4u)) {
        _cyc_030003C0 = 1u;
        uint32_t _rn_030003C0 = g_cpu.R[1];
        uint32_t _r_030003C0;
        _r_030003C0 = 0x00000000u - _rn_030003C0;
        g_cpu.R[1] = _r_030003C0;
    }
    g_cpu.R[15] = 0x030003C4u;
    runtime_tick(_cyc_030003C0);
    /* 030003C4  030003c4 A mov r0,#0x0 */
    g_cpu.R[15] = 0x030003C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003C4 = 1u;
    _cyc_030003C4 = 1u;
    uint32_t _r_030003C4;
    _r_030003C4 = 0x00000000u;
    g_cpu.R[0] = _r_030003C4;
    g_cpu.R[15] = 0x030003C8u;
    runtime_tick(_cyc_030003C4);
    /* 030003C8  030003c8 A bl 0x030003fc */
    g_cpu.R[15] = 0x030003C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003C8 = 1u;
    _cyc_030003C8 = 3u;
    g_cpu.R[14] = 0x030003CCu;
    g_cpu.R[15] = 0x030003FCu;
    runtime_call_push_return(0x030003CCu);
    runtime_tick(_cyc_030003C8);
    _cyc_030003C8 = 0u;
    gf_iwram_lzss_decompress_stream();
    if (g_cpu.R[15] != 0x030003CCu) { runtime_call_cancel_return(0x030003CCu); return; }
    g_cpu.R[15] = 0x030003CCu;
    runtime_tick(_cyc_030003C8);
    /* 030003CC  030003cc A mov r0,r1 */
    g_cpu.R[15] = 0x030003CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003CC = 1u;
    _cyc_030003CC = 1u;
    uint32_t _rm_030003CC = g_cpu.R[1];
    uint32_t _op2_030003CC;
    uint32_t _co_030003CC;
    _op2_030003CC = _rm_030003CC;
    _co_030003CC = cpsr_c();
    uint32_t _r_030003CC;
    _r_030003CC = _op2_030003CC;
    g_cpu.R[0] = _r_030003CC;
    g_cpu.R[15] = 0x030003D0u;
    runtime_tick(_cyc_030003CC);
    /* 030003D0  030003d0 A movs r12,r12 */
    g_cpu.R[15] = 0x030003D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003D0 = 1u;
    _cyc_030003D0 = 1u;
    uint32_t _rm_030003D0 = g_cpu.R[12];
    uint32_t _op2_030003D0;
    uint32_t _co_030003D0;
    _op2_030003D0 = _rm_030003D0;
    _co_030003D0 = cpsr_c();
    uint32_t _r_030003D0;
    _r_030003D0 = _op2_030003D0;
    arm_set_nzc_logic(_r_030003D0, _co_030003D0);
    g_cpu.R[12] = _r_030003D0;
    g_cpu.R[15] = 0x030003D4u;
    runtime_tick(_cyc_030003D0);
    /* 030003D4  030003d4 A rsbmi r0,r0,#0x0 */
    g_cpu.R[15] = 0x030003D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003D4 = 1u;
    if (arm_cond_passes(0x4u)) {
        _cyc_030003D4 = 1u;
        uint32_t _rn_030003D4 = g_cpu.R[0];
        uint32_t _r_030003D4;
        _r_030003D4 = 0x00000000u - _rn_030003D4;
        g_cpu.R[0] = _r_030003D4;
    }
    g_cpu.R[15] = 0x030003D8u;
    runtime_tick(_cyc_030003D4);
    /* 030003D8  030003d8 A ldm r13!,{r14} */
    g_cpu.R[15] = 0x030003D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003D8 = 1u;
    _cyc_030003D8 = 2u;
    uint32_t _b_030003D8 = g_cpu.R[13];
    uint32_t _a_030003D8 = _b_030003D8;
    uint32_t _fb_030003D8 = _b_030003D8 + 4u;
    _cyc_030003D8 += runtime_mem_cycles(_a_030003D8 & ~3u, 4u, 0u);
    g_cpu.R[14] = bus_read_u32(_a_030003D8 & ~3u);
    _a_030003D8 += 4u;
    g_cpu.R[13] = _fb_030003D8;
    g_cpu.R[15] = 0x030003DCu;
    runtime_tick(_cyc_030003D8);
    /* 030003DC  030003dc A bx r14 */
    g_cpu.R[15] = 0x030003DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003DC = 1u;
    _cyc_030003DC = 3u;
    uint32_t _bxt_030003DC = g_cpu.R[14];
    g_cpu.R[15] = _bxt_030003DC & ~1u;
    runtime_tick(_cyc_030003DC);
    if (_bxt_030003DC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030003DC);
    return;
    g_cpu.R[15] = 0x030003E0u;
    runtime_tick(_cyc_030003DC);
    /* fall-through to 0x030003E0 */
    g_cpu.R[15] = 0x030003E0u;
    runtime_dispatch(0x030003E0u);
    return;
}

/* 0x080001E8  mode=thumb  end=0x080001EC  branches=1  indirect */


/* 0x030003E0 arm */
void gf_iwram_signed_modulo_routine(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030003E0u);
    /* 030003E0  030003e0 A mov r12,r14 */
    g_cpu.R[15] = 0x030003E0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003E0 = 1u;
    _cyc_030003E0 = 1u;
    uint32_t _rm_030003E0 = g_cpu.R[14];
    uint32_t _op2_030003E0;
    uint32_t _co_030003E0;
    _op2_030003E0 = _rm_030003E0;
    _co_030003E0 = cpsr_c();
    uint32_t _r_030003E0;
    _r_030003E0 = _op2_030003E0;
    g_cpu.R[12] = _r_030003E0;
    g_cpu.R[15] = 0x030003E4u;
    runtime_tick(_cyc_030003E0);
    /* 030003E4  030003e4 A bl 0x030003f0 */
    g_cpu.R[15] = 0x030003E4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003E4 = 1u;
    _cyc_030003E4 = 3u;
    g_cpu.R[14] = 0x030003E8u;
    g_cpu.R[15] = 0x030003F0u;
    runtime_call_push_return(0x030003E8u);
    runtime_tick(_cyc_030003E4);
    _cyc_030003E4 = 0u;
    gf_iwram_decompress_header_dispatch();
    if (g_cpu.R[15] != 0x030003E8u) { runtime_call_cancel_return(0x030003E8u); return; }
    g_cpu.R[15] = 0x030003E8u;
    runtime_tick(_cyc_030003E4);
    /* 030003E8  030003e8 A mov r0,r1 */
    g_cpu.R[15] = 0x030003E8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003E8 = 1u;
    _cyc_030003E8 = 1u;
    uint32_t _rm_030003E8 = g_cpu.R[1];
    uint32_t _op2_030003E8;
    uint32_t _co_030003E8;
    _op2_030003E8 = _rm_030003E8;
    _co_030003E8 = cpsr_c();
    uint32_t _r_030003E8;
    _r_030003E8 = _op2_030003E8;
    g_cpu.R[0] = _r_030003E8;
    g_cpu.R[15] = 0x030003ECu;
    runtime_tick(_cyc_030003E8);
    /* 030003EC  030003ec A bx r12 */
    g_cpu.R[15] = 0x030003ECu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003EC = 1u;
    _cyc_030003EC = 3u;
    uint32_t _bxt_030003EC = g_cpu.R[12];
    g_cpu.R[15] = _bxt_030003EC & ~1u;
    runtime_tick(_cyc_030003EC);
    if (_bxt_030003EC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030003EC);
    return;
    g_cpu.R[15] = 0x030003F0u;
    runtime_tick(_cyc_030003EC);
    /* fall-through to 0x030003F0 */
    g_cpu.R[15] = 0x030003F0u;
    runtime_dispatch(0x030003F0u);
    return;
}

/* 0x03000434  mode=arm  end=0x0300046C  branches=7  indirect */


/* 0x030003F0 arm */
void gf_iwram_decompress_header_dispatch(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030003F0u);
    /* 030003F0  030003f0 A mov r2,r1 */
    g_cpu.R[15] = 0x030003F0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003F0 = 1u;
    _cyc_030003F0 = 1u;
    uint32_t _rm_030003F0 = g_cpu.R[1];
    uint32_t _op2_030003F0;
    uint32_t _co_030003F0;
    _op2_030003F0 = _rm_030003F0;
    _co_030003F0 = cpsr_c();
    uint32_t _r_030003F0;
    _r_030003F0 = _op2_030003F0;
    g_cpu.R[2] = _r_030003F0;
    g_cpu.R[15] = 0x030003F4u;
    runtime_tick(_cyc_030003F0);
    /* 030003F4  030003f4 A mov r1,r0 */
    g_cpu.R[15] = 0x030003F4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003F4 = 1u;
    _cyc_030003F4 = 1u;
    uint32_t _rm_030003F4 = g_cpu.R[0];
    uint32_t _op2_030003F4;
    uint32_t _co_030003F4;
    _op2_030003F4 = _rm_030003F4;
    _co_030003F4 = cpsr_c();
    uint32_t _r_030003F4;
    _r_030003F4 = _op2_030003F4;
    g_cpu.R[1] = _r_030003F4;
    g_cpu.R[15] = 0x030003F8u;
    runtime_tick(_cyc_030003F4);
    /* 030003F8  030003f8 A mov r0,#0x0 */
    g_cpu.R[15] = 0x030003F8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003F8 = 1u;
    _cyc_030003F8 = 1u;
    uint32_t _r_030003F8;
    _r_030003F8 = 0x00000000u;
    g_cpu.R[0] = _r_030003F8;
    g_cpu.R[15] = 0x030003FCu;
    runtime_tick(_cyc_030003F8);
    /* fall-through to 0x030003FC */
    g_cpu.R[15] = 0x030003FCu;
    runtime_dispatch(0x030003FCu);
    return;
}

/* 0x030005C0  mode=arm  end=0x030005D0  branches=1  indirect */


/* 0x030003FC arm */
void gf_iwram_lzss_decompress_stream(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030003FCu);
    /* 030003FC  030003fc A rsbs r3,r2,r1,lsr #28 */
    g_cpu.R[15] = 0x030003FCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030003FC = 1u;
    _cyc_030003FC = 1u;
    uint32_t _rm_030003FC = g_cpu.R[1];
    uint32_t _op2_030003FC;
    uint32_t _co_030003FC;
    _op2_030003FC = _rm_030003FC >> 28;
    _co_030003FC = (_rm_030003FC >> 27) & 1u;
    uint32_t _rn_030003FC = g_cpu.R[2];
    uint32_t _r_030003FC;
    _r_030003FC = _op2_030003FC - _rn_030003FC;
    arm_set_nzcv_sub(_op2_030003FC, _rn_030003FC, _r_030003FC);
    g_cpu.R[3] = _r_030003FC;
    g_cpu.R[15] = 0x03000400u;
    runtime_tick(_cyc_030003FC);
    /* 03000400  03000400 A bcc 0x03000434 */
    g_cpu.R[15] = 0x03000400u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000400 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000400 = 3u;
        g_cpu.R[15] = 0x03000434u;
        runtime_tick(_cyc_03000400);
        gf_iwram_ppu_display_reg_entry_init();
        return;
    }
    g_cpu.R[15] = 0x03000404u;
    runtime_tick(_cyc_03000400);
    /* 03000404  03000404 A rsbs r3,r2,r1,lsr #31 */
    g_cpu.R[15] = 0x03000404u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000404 = 1u;
    _cyc_03000404 = 1u;
    uint32_t _rm_03000404 = g_cpu.R[1];
    uint32_t _op2_03000404;
    uint32_t _co_03000404;
    _op2_03000404 = _rm_03000404 >> 31;
    _co_03000404 = (_rm_03000404 >> 30) & 1u;
    uint32_t _rn_03000404 = g_cpu.R[2];
    uint32_t _r_03000404;
    _r_03000404 = _op2_03000404 - _rn_03000404;
    arm_set_nzcv_sub(_op2_03000404, _rn_03000404, _r_03000404);
    g_cpu.R[3] = _r_03000404;
    g_cpu.R[15] = 0x03000408u;
    runtime_tick(_cyc_03000404);
    /* 03000408  03000408 A orrcs r0,r0,#0x80000000 */
    g_cpu.R[15] = 0x03000408u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000408 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000408 = 1u;
        uint32_t _rn_03000408 = g_cpu.R[0];
        uint32_t _r_03000408;
        _r_03000408 = _rn_03000408 | 0x80000000u;
        g_cpu.R[0] = _r_03000408;
    }
    g_cpu.R[15] = 0x0300040Cu;
    runtime_tick(_cyc_03000408);
    /* 0300040C  0300040c A subcs r1,r1,r2,lsl #31 */
    g_cpu.R[15] = 0x0300040Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300040C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300040C = 1u;
        uint32_t _rm_0300040C = g_cpu.R[2];
        uint32_t _op2_0300040C;
        uint32_t _co_0300040C;
        _op2_0300040C = _rm_0300040C << 31;
        _co_0300040C = (_rm_0300040C >> 1) & 1u;
        uint32_t _rn_0300040C = g_cpu.R[1];
        uint32_t _r_0300040C;
        _r_0300040C = _rn_0300040C - _op2_0300040C;
        g_cpu.R[1] = _r_0300040C;
    }
    g_cpu.R[15] = 0x03000410u;
    runtime_tick(_cyc_0300040C);
    /* 03000410  03000410 A rsbs r3,r2,r1,lsr #30 */
    g_cpu.R[15] = 0x03000410u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000410 = 1u;
    _cyc_03000410 = 1u;
    uint32_t _rm_03000410 = g_cpu.R[1];
    uint32_t _op2_03000410;
    uint32_t _co_03000410;
    _op2_03000410 = _rm_03000410 >> 30;
    _co_03000410 = (_rm_03000410 >> 29) & 1u;
    uint32_t _rn_03000410 = g_cpu.R[2];
    uint32_t _r_03000410;
    _r_03000410 = _op2_03000410 - _rn_03000410;
    arm_set_nzcv_sub(_op2_03000410, _rn_03000410, _r_03000410);
    g_cpu.R[3] = _r_03000410;
    g_cpu.R[15] = 0x03000414u;
    runtime_tick(_cyc_03000410);
    /* 03000414  03000414 A orrcs r0,r0,#0x40000000 */
    g_cpu.R[15] = 0x03000414u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000414 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000414 = 1u;
        uint32_t _rn_03000414 = g_cpu.R[0];
        uint32_t _r_03000414;
        _r_03000414 = _rn_03000414 | 0x40000000u;
        g_cpu.R[0] = _r_03000414;
    }
    g_cpu.R[15] = 0x03000418u;
    runtime_tick(_cyc_03000414);
    /* 03000418  03000418 A subcs r1,r1,r2,lsl #30 */
    g_cpu.R[15] = 0x03000418u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000418 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000418 = 1u;
        uint32_t _rm_03000418 = g_cpu.R[2];
        uint32_t _op2_03000418;
        uint32_t _co_03000418;
        _op2_03000418 = _rm_03000418 << 30;
        _co_03000418 = (_rm_03000418 >> 2) & 1u;
        uint32_t _rn_03000418 = g_cpu.R[1];
        uint32_t _r_03000418;
        _r_03000418 = _rn_03000418 - _op2_03000418;
        g_cpu.R[1] = _r_03000418;
    }
    g_cpu.R[15] = 0x0300041Cu;
    runtime_tick(_cyc_03000418);
    /* 0300041C  0300041c A rsbs r3,r2,r1,lsr #29 */
    g_cpu.R[15] = 0x0300041Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300041C = 1u;
    _cyc_0300041C = 1u;
    uint32_t _rm_0300041C = g_cpu.R[1];
    uint32_t _op2_0300041C;
    uint32_t _co_0300041C;
    _op2_0300041C = _rm_0300041C >> 29;
    _co_0300041C = (_rm_0300041C >> 28) & 1u;
    uint32_t _rn_0300041C = g_cpu.R[2];
    uint32_t _r_0300041C;
    _r_0300041C = _op2_0300041C - _rn_0300041C;
    arm_set_nzcv_sub(_op2_0300041C, _rn_0300041C, _r_0300041C);
    g_cpu.R[3] = _r_0300041C;
    g_cpu.R[15] = 0x03000420u;
    runtime_tick(_cyc_0300041C);
    /* 03000420  03000420 A orrcs r0,r0,#0x20000000 */
    g_cpu.R[15] = 0x03000420u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000420 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000420 = 1u;
        uint32_t _rn_03000420 = g_cpu.R[0];
        uint32_t _r_03000420;
        _r_03000420 = _rn_03000420 | 0x20000000u;
        g_cpu.R[0] = _r_03000420;
    }
    g_cpu.R[15] = 0x03000424u;
    runtime_tick(_cyc_03000420);
    /* 03000424  03000424 A subcs r1,r1,r2,lsl #29 */
    g_cpu.R[15] = 0x03000424u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000424 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000424 = 1u;
        uint32_t _rm_03000424 = g_cpu.R[2];
        uint32_t _op2_03000424;
        uint32_t _co_03000424;
        _op2_03000424 = _rm_03000424 << 29;
        _co_03000424 = (_rm_03000424 >> 3) & 1u;
        uint32_t _rn_03000424 = g_cpu.R[1];
        uint32_t _r_03000424;
        _r_03000424 = _rn_03000424 - _op2_03000424;
        g_cpu.R[1] = _r_03000424;
    }
    g_cpu.R[15] = 0x03000428u;
    runtime_tick(_cyc_03000424);
    /* 03000428  03000428 A rsbs r3,r2,r1,lsr #28 */
    g_cpu.R[15] = 0x03000428u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000428 = 1u;
    _cyc_03000428 = 1u;
    uint32_t _rm_03000428 = g_cpu.R[1];
    uint32_t _op2_03000428;
    uint32_t _co_03000428;
    _op2_03000428 = _rm_03000428 >> 28;
    _co_03000428 = (_rm_03000428 >> 27) & 1u;
    uint32_t _rn_03000428 = g_cpu.R[2];
    uint32_t _r_03000428;
    _r_03000428 = _op2_03000428 - _rn_03000428;
    arm_set_nzcv_sub(_op2_03000428, _rn_03000428, _r_03000428);
    g_cpu.R[3] = _r_03000428;
    g_cpu.R[15] = 0x0300042Cu;
    runtime_tick(_cyc_03000428);
    /* 0300042C  0300042c A orrcs r0,r0,#0x10000000 */
    g_cpu.R[15] = 0x0300042Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300042C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300042C = 1u;
        uint32_t _rn_0300042C = g_cpu.R[0];
        uint32_t _r_0300042C;
        _r_0300042C = _rn_0300042C | 0x10000000u;
        g_cpu.R[0] = _r_0300042C;
    }
    g_cpu.R[15] = 0x03000430u;
    runtime_tick(_cyc_0300042C);
    /* 03000430  03000430 A subcs r1,r1,r2,lsl #28 */
    g_cpu.R[15] = 0x03000430u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000430 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000430 = 1u;
        uint32_t _rm_03000430 = g_cpu.R[2];
        uint32_t _op2_03000430;
        uint32_t _co_03000430;
        _op2_03000430 = _rm_03000430 << 28;
        _co_03000430 = (_rm_03000430 >> 4) & 1u;
        uint32_t _rn_03000430 = g_cpu.R[1];
        uint32_t _r_03000430;
        _r_03000430 = _rn_03000430 - _op2_03000430;
        g_cpu.R[1] = _r_03000430;
    }
    g_cpu.R[15] = 0x03000434u;
    runtime_tick(_cyc_03000430);
    /* fall-through to 0x03000434 */
    g_cpu.R[15] = 0x03000434u;
    runtime_dispatch(0x03000434u);
    return;
}

/* 0x08000170  mode=thumb  end=0x08000174  branches=1  indirect */


/* 0x03000434 arm */
void gf_iwram_ppu_display_reg_entry_init(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000434u);
    /* 03000434  03000434 A rsbs r3,r2,r1,lsr #24 */
    g_cpu.R[15] = 0x03000434u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000434 = 1u;
    _cyc_03000434 = 1u;
    uint32_t _rm_03000434 = g_cpu.R[1];
    uint32_t _op2_03000434;
    uint32_t _co_03000434;
    _op2_03000434 = _rm_03000434 >> 24;
    _co_03000434 = (_rm_03000434 >> 23) & 1u;
    uint32_t _rn_03000434 = g_cpu.R[2];
    uint32_t _r_03000434;
    _r_03000434 = _op2_03000434 - _rn_03000434;
    arm_set_nzcv_sub(_op2_03000434, _rn_03000434, _r_03000434);
    g_cpu.R[3] = _r_03000434;
    g_cpu.R[15] = 0x03000438u;
    runtime_tick(_cyc_03000434);
    /* 03000438  03000438 A bcc 0x0300046c */
    g_cpu.R[15] = 0x03000438u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000438 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000438 = 3u;
        g_cpu.R[15] = 0x0300046Cu;
        runtime_tick(_cyc_03000438);
        gf_iwram_fast_ram_work_entry_unpack();
        return;
    }
    g_cpu.R[15] = 0x0300043Cu;
    runtime_tick(_cyc_03000438);
    /* 0300043C  0300043c A rsbs r3,r2,r1,lsr #27 */
    g_cpu.R[15] = 0x0300043Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300043C = 1u;
    _cyc_0300043C = 1u;
    uint32_t _rm_0300043C = g_cpu.R[1];
    uint32_t _op2_0300043C;
    uint32_t _co_0300043C;
    _op2_0300043C = _rm_0300043C >> 27;
    _co_0300043C = (_rm_0300043C >> 26) & 1u;
    uint32_t _rn_0300043C = g_cpu.R[2];
    uint32_t _r_0300043C;
    _r_0300043C = _op2_0300043C - _rn_0300043C;
    arm_set_nzcv_sub(_op2_0300043C, _rn_0300043C, _r_0300043C);
    g_cpu.R[3] = _r_0300043C;
    g_cpu.R[15] = 0x03000440u;
    runtime_tick(_cyc_0300043C);
    /* 03000440  03000440 A orrcs r0,r0,#0x8000000 */
    g_cpu.R[15] = 0x03000440u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000440 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000440 = 1u;
        uint32_t _rn_03000440 = g_cpu.R[0];
        uint32_t _r_03000440;
        _r_03000440 = _rn_03000440 | 0x08000000u;
        g_cpu.R[0] = _r_03000440;
    }
    g_cpu.R[15] = 0x03000444u;
    runtime_tick(_cyc_03000440);
    /* 03000444  03000444 A subcs r1,r1,r2,lsl #27 */
    g_cpu.R[15] = 0x03000444u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000444 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000444 = 1u;
        uint32_t _rm_03000444 = g_cpu.R[2];
        uint32_t _op2_03000444;
        uint32_t _co_03000444;
        _op2_03000444 = _rm_03000444 << 27;
        _co_03000444 = (_rm_03000444 >> 5) & 1u;
        uint32_t _rn_03000444 = g_cpu.R[1];
        uint32_t _r_03000444;
        _r_03000444 = _rn_03000444 - _op2_03000444;
        g_cpu.R[1] = _r_03000444;
    }
    g_cpu.R[15] = 0x03000448u;
    runtime_tick(_cyc_03000444);
    /* 03000448  03000448 A rsbs r3,r2,r1,lsr #26 */
    g_cpu.R[15] = 0x03000448u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000448 = 1u;
    _cyc_03000448 = 1u;
    uint32_t _rm_03000448 = g_cpu.R[1];
    uint32_t _op2_03000448;
    uint32_t _co_03000448;
    _op2_03000448 = _rm_03000448 >> 26;
    _co_03000448 = (_rm_03000448 >> 25) & 1u;
    uint32_t _rn_03000448 = g_cpu.R[2];
    uint32_t _r_03000448;
    _r_03000448 = _op2_03000448 - _rn_03000448;
    arm_set_nzcv_sub(_op2_03000448, _rn_03000448, _r_03000448);
    g_cpu.R[3] = _r_03000448;
    g_cpu.R[15] = 0x0300044Cu;
    runtime_tick(_cyc_03000448);
    /* 0300044C  0300044c A orrcs r0,r0,#0x4000000 */
    g_cpu.R[15] = 0x0300044Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300044C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300044C = 1u;
        uint32_t _rn_0300044C = g_cpu.R[0];
        uint32_t _r_0300044C;
        _r_0300044C = _rn_0300044C | 0x04000000u;
        g_cpu.R[0] = _r_0300044C;
    }
    g_cpu.R[15] = 0x03000450u;
    runtime_tick(_cyc_0300044C);
    /* 03000450  03000450 A subcs r1,r1,r2,lsl #26 */
    g_cpu.R[15] = 0x03000450u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000450 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000450 = 1u;
        uint32_t _rm_03000450 = g_cpu.R[2];
        uint32_t _op2_03000450;
        uint32_t _co_03000450;
        _op2_03000450 = _rm_03000450 << 26;
        _co_03000450 = (_rm_03000450 >> 6) & 1u;
        uint32_t _rn_03000450 = g_cpu.R[1];
        uint32_t _r_03000450;
        _r_03000450 = _rn_03000450 - _op2_03000450;
        g_cpu.R[1] = _r_03000450;
    }
    g_cpu.R[15] = 0x03000454u;
    runtime_tick(_cyc_03000450);
    /* 03000454  03000454 A rsbs r3,r2,r1,lsr #25 */
    g_cpu.R[15] = 0x03000454u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000454 = 1u;
    _cyc_03000454 = 1u;
    uint32_t _rm_03000454 = g_cpu.R[1];
    uint32_t _op2_03000454;
    uint32_t _co_03000454;
    _op2_03000454 = _rm_03000454 >> 25;
    _co_03000454 = (_rm_03000454 >> 24) & 1u;
    uint32_t _rn_03000454 = g_cpu.R[2];
    uint32_t _r_03000454;
    _r_03000454 = _op2_03000454 - _rn_03000454;
    arm_set_nzcv_sub(_op2_03000454, _rn_03000454, _r_03000454);
    g_cpu.R[3] = _r_03000454;
    g_cpu.R[15] = 0x03000458u;
    runtime_tick(_cyc_03000454);
    /* 03000458  03000458 A orrcs r0,r0,#0x2000000 */
    g_cpu.R[15] = 0x03000458u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000458 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000458 = 1u;
        uint32_t _rn_03000458 = g_cpu.R[0];
        uint32_t _r_03000458;
        _r_03000458 = _rn_03000458 | 0x02000000u;
        g_cpu.R[0] = _r_03000458;
    }
    g_cpu.R[15] = 0x0300045Cu;
    runtime_tick(_cyc_03000458);
    /* 0300045C  0300045c A subcs r1,r1,r2,lsl #25 */
    g_cpu.R[15] = 0x0300045Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300045C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300045C = 1u;
        uint32_t _rm_0300045C = g_cpu.R[2];
        uint32_t _op2_0300045C;
        uint32_t _co_0300045C;
        _op2_0300045C = _rm_0300045C << 25;
        _co_0300045C = (_rm_0300045C >> 7) & 1u;
        uint32_t _rn_0300045C = g_cpu.R[1];
        uint32_t _r_0300045C;
        _r_0300045C = _rn_0300045C - _op2_0300045C;
        g_cpu.R[1] = _r_0300045C;
    }
    g_cpu.R[15] = 0x03000460u;
    runtime_tick(_cyc_0300045C);
    /* 03000460  03000460 A rsbs r3,r2,r1,lsr #24 */
    g_cpu.R[15] = 0x03000460u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000460 = 1u;
    _cyc_03000460 = 1u;
    uint32_t _rm_03000460 = g_cpu.R[1];
    uint32_t _op2_03000460;
    uint32_t _co_03000460;
    _op2_03000460 = _rm_03000460 >> 24;
    _co_03000460 = (_rm_03000460 >> 23) & 1u;
    uint32_t _rn_03000460 = g_cpu.R[2];
    uint32_t _r_03000460;
    _r_03000460 = _op2_03000460 - _rn_03000460;
    arm_set_nzcv_sub(_op2_03000460, _rn_03000460, _r_03000460);
    g_cpu.R[3] = _r_03000460;
    g_cpu.R[15] = 0x03000464u;
    runtime_tick(_cyc_03000460);
    /* 03000464  03000464 A orrcs r0,r0,#0x1000000 */
    g_cpu.R[15] = 0x03000464u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000464 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000464 = 1u;
        uint32_t _rn_03000464 = g_cpu.R[0];
        uint32_t _r_03000464;
        _r_03000464 = _rn_03000464 | 0x01000000u;
        g_cpu.R[0] = _r_03000464;
    }
    g_cpu.R[15] = 0x03000468u;
    runtime_tick(_cyc_03000464);
    /* 03000468  03000468 A subcs r1,r1,r2,lsl #24 */
    g_cpu.R[15] = 0x03000468u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000468 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000468 = 1u;
        uint32_t _rm_03000468 = g_cpu.R[2];
        uint32_t _op2_03000468;
        uint32_t _co_03000468;
        _op2_03000468 = _rm_03000468 << 24;
        _co_03000468 = (_rm_03000468 >> 8) & 1u;
        uint32_t _rn_03000468 = g_cpu.R[1];
        uint32_t _r_03000468;
        _r_03000468 = _rn_03000468 - _op2_03000468;
        g_cpu.R[1] = _r_03000468;
    }
    g_cpu.R[15] = 0x0300046Cu;
    runtime_tick(_cyc_03000468);
    /* fall-through to 0x0300046C */
    g_cpu.R[15] = 0x0300046Cu;
    runtime_dispatch(0x0300046Cu);
    return;
}

/* 0x030004DC  mode=arm  end=0x03000514  branches=4  indirect */


/* 0x0300046C arm */
void gf_iwram_fast_ram_work_entry_unpack(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300046Cu);
    /* 0300046C  0300046c A rsbs r3,r2,r1,lsr #20 */
    g_cpu.R[15] = 0x0300046Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300046C = 1u;
    _cyc_0300046C = 1u;
    uint32_t _rm_0300046C = g_cpu.R[1];
    uint32_t _op2_0300046C;
    uint32_t _co_0300046C;
    _op2_0300046C = _rm_0300046C >> 20;
    _co_0300046C = (_rm_0300046C >> 19) & 1u;
    uint32_t _rn_0300046C = g_cpu.R[2];
    uint32_t _r_0300046C;
    _r_0300046C = _op2_0300046C - _rn_0300046C;
    arm_set_nzcv_sub(_op2_0300046C, _rn_0300046C, _r_0300046C);
    g_cpu.R[3] = _r_0300046C;
    g_cpu.R[15] = 0x03000470u;
    runtime_tick(_cyc_0300046C);
    /* 03000470  03000470 A bcc 0x030004a4 */
    g_cpu.R[15] = 0x03000470u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000470 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000470 = 3u;
        g_cpu.R[15] = 0x030004A4u;
        runtime_tick(_cyc_03000470);
        gf_iwram_fast_ram_work_entry_expand();
        return;
    }
    g_cpu.R[15] = 0x03000474u;
    runtime_tick(_cyc_03000470);
    /* 03000474  03000474 A rsbs r3,r2,r1,lsr #23 */
    g_cpu.R[15] = 0x03000474u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000474 = 1u;
    _cyc_03000474 = 1u;
    uint32_t _rm_03000474 = g_cpu.R[1];
    uint32_t _op2_03000474;
    uint32_t _co_03000474;
    _op2_03000474 = _rm_03000474 >> 23;
    _co_03000474 = (_rm_03000474 >> 22) & 1u;
    uint32_t _rn_03000474 = g_cpu.R[2];
    uint32_t _r_03000474;
    _r_03000474 = _op2_03000474 - _rn_03000474;
    arm_set_nzcv_sub(_op2_03000474, _rn_03000474, _r_03000474);
    g_cpu.R[3] = _r_03000474;
    g_cpu.R[15] = 0x03000478u;
    runtime_tick(_cyc_03000474);
    /* 03000478  03000478 A orrcs r0,r0,#0x800000 */
    g_cpu.R[15] = 0x03000478u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000478 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000478 = 1u;
        uint32_t _rn_03000478 = g_cpu.R[0];
        uint32_t _r_03000478;
        _r_03000478 = _rn_03000478 | 0x00800000u;
        g_cpu.R[0] = _r_03000478;
    }
    g_cpu.R[15] = 0x0300047Cu;
    runtime_tick(_cyc_03000478);
    /* 0300047C  0300047c A subcs r1,r1,r2,lsl #23 */
    g_cpu.R[15] = 0x0300047Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300047C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300047C = 1u;
        uint32_t _rm_0300047C = g_cpu.R[2];
        uint32_t _op2_0300047C;
        uint32_t _co_0300047C;
        _op2_0300047C = _rm_0300047C << 23;
        _co_0300047C = (_rm_0300047C >> 9) & 1u;
        uint32_t _rn_0300047C = g_cpu.R[1];
        uint32_t _r_0300047C;
        _r_0300047C = _rn_0300047C - _op2_0300047C;
        g_cpu.R[1] = _r_0300047C;
    }
    g_cpu.R[15] = 0x03000480u;
    runtime_tick(_cyc_0300047C);
    /* 03000480  03000480 A rsbs r3,r2,r1,lsr #22 */
    g_cpu.R[15] = 0x03000480u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000480 = 1u;
    _cyc_03000480 = 1u;
    uint32_t _rm_03000480 = g_cpu.R[1];
    uint32_t _op2_03000480;
    uint32_t _co_03000480;
    _op2_03000480 = _rm_03000480 >> 22;
    _co_03000480 = (_rm_03000480 >> 21) & 1u;
    uint32_t _rn_03000480 = g_cpu.R[2];
    uint32_t _r_03000480;
    _r_03000480 = _op2_03000480 - _rn_03000480;
    arm_set_nzcv_sub(_op2_03000480, _rn_03000480, _r_03000480);
    g_cpu.R[3] = _r_03000480;
    g_cpu.R[15] = 0x03000484u;
    runtime_tick(_cyc_03000480);
    /* 03000484  03000484 A orrcs r0,r0,#0x400000 */
    g_cpu.R[15] = 0x03000484u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000484 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000484 = 1u;
        uint32_t _rn_03000484 = g_cpu.R[0];
        uint32_t _r_03000484;
        _r_03000484 = _rn_03000484 | 0x00400000u;
        g_cpu.R[0] = _r_03000484;
    }
    g_cpu.R[15] = 0x03000488u;
    runtime_tick(_cyc_03000484);
    /* 03000488  03000488 A subcs r1,r1,r2,lsl #22 */
    g_cpu.R[15] = 0x03000488u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000488 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000488 = 1u;
        uint32_t _rm_03000488 = g_cpu.R[2];
        uint32_t _op2_03000488;
        uint32_t _co_03000488;
        _op2_03000488 = _rm_03000488 << 22;
        _co_03000488 = (_rm_03000488 >> 10) & 1u;
        uint32_t _rn_03000488 = g_cpu.R[1];
        uint32_t _r_03000488;
        _r_03000488 = _rn_03000488 - _op2_03000488;
        g_cpu.R[1] = _r_03000488;
    }
    g_cpu.R[15] = 0x0300048Cu;
    runtime_tick(_cyc_03000488);
    /* 0300048C  0300048c A rsbs r3,r2,r1,lsr #21 */
    g_cpu.R[15] = 0x0300048Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300048C = 1u;
    _cyc_0300048C = 1u;
    uint32_t _rm_0300048C = g_cpu.R[1];
    uint32_t _op2_0300048C;
    uint32_t _co_0300048C;
    _op2_0300048C = _rm_0300048C >> 21;
    _co_0300048C = (_rm_0300048C >> 20) & 1u;
    uint32_t _rn_0300048C = g_cpu.R[2];
    uint32_t _r_0300048C;
    _r_0300048C = _op2_0300048C - _rn_0300048C;
    arm_set_nzcv_sub(_op2_0300048C, _rn_0300048C, _r_0300048C);
    g_cpu.R[3] = _r_0300048C;
    g_cpu.R[15] = 0x03000490u;
    runtime_tick(_cyc_0300048C);
    /* 03000490  03000490 A orrcs r0,r0,#0x200000 */
    g_cpu.R[15] = 0x03000490u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000490 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000490 = 1u;
        uint32_t _rn_03000490 = g_cpu.R[0];
        uint32_t _r_03000490;
        _r_03000490 = _rn_03000490 | 0x00200000u;
        g_cpu.R[0] = _r_03000490;
    }
    g_cpu.R[15] = 0x03000494u;
    runtime_tick(_cyc_03000490);
    /* 03000494  03000494 A subcs r1,r1,r2,lsl #21 */
    g_cpu.R[15] = 0x03000494u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000494 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000494 = 1u;
        uint32_t _rm_03000494 = g_cpu.R[2];
        uint32_t _op2_03000494;
        uint32_t _co_03000494;
        _op2_03000494 = _rm_03000494 << 21;
        _co_03000494 = (_rm_03000494 >> 11) & 1u;
        uint32_t _rn_03000494 = g_cpu.R[1];
        uint32_t _r_03000494;
        _r_03000494 = _rn_03000494 - _op2_03000494;
        g_cpu.R[1] = _r_03000494;
    }
    g_cpu.R[15] = 0x03000498u;
    runtime_tick(_cyc_03000494);
    /* 03000498  03000498 A rsbs r3,r2,r1,lsr #20 */
    g_cpu.R[15] = 0x03000498u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000498 = 1u;
    _cyc_03000498 = 1u;
    uint32_t _rm_03000498 = g_cpu.R[1];
    uint32_t _op2_03000498;
    uint32_t _co_03000498;
    _op2_03000498 = _rm_03000498 >> 20;
    _co_03000498 = (_rm_03000498 >> 19) & 1u;
    uint32_t _rn_03000498 = g_cpu.R[2];
    uint32_t _r_03000498;
    _r_03000498 = _op2_03000498 - _rn_03000498;
    arm_set_nzcv_sub(_op2_03000498, _rn_03000498, _r_03000498);
    g_cpu.R[3] = _r_03000498;
    g_cpu.R[15] = 0x0300049Cu;
    runtime_tick(_cyc_03000498);
    /* 0300049C  0300049c A orrcs r0,r0,#0x100000 */
    g_cpu.R[15] = 0x0300049Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300049C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300049C = 1u;
        uint32_t _rn_0300049C = g_cpu.R[0];
        uint32_t _r_0300049C;
        _r_0300049C = _rn_0300049C | 0x00100000u;
        g_cpu.R[0] = _r_0300049C;
    }
    g_cpu.R[15] = 0x030004A0u;
    runtime_tick(_cyc_0300049C);
    /* 030004A0  030004a0 A subcs r1,r1,r2,lsl #20 */
    g_cpu.R[15] = 0x030004A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004A0 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004A0 = 1u;
        uint32_t _rm_030004A0 = g_cpu.R[2];
        uint32_t _op2_030004A0;
        uint32_t _co_030004A0;
        _op2_030004A0 = _rm_030004A0 << 20;
        _co_030004A0 = (_rm_030004A0 >> 12) & 1u;
        uint32_t _rn_030004A0 = g_cpu.R[1];
        uint32_t _r_030004A0;
        _r_030004A0 = _rn_030004A0 - _op2_030004A0;
        g_cpu.R[1] = _r_030004A0;
    }
    g_cpu.R[15] = 0x030004A4u;
    runtime_tick(_cyc_030004A0);
    /* fall-through to 0x030004A4 */
    g_cpu.R[15] = 0x030004A4u;
    runtime_dispatch(0x030004A4u);
    return;
}

/* 0x080000C0  mode=thumb  end=0x080000C4  branches=1  indirect */


/* 0x030004A4 arm */
void gf_iwram_fast_ram_work_entry_expand(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030004A4u);
    /* 030004A4  030004a4 A rsbs r3,r2,r1,lsr #16 */
    g_cpu.R[15] = 0x030004A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004A4 = 1u;
    _cyc_030004A4 = 1u;
    uint32_t _rm_030004A4 = g_cpu.R[1];
    uint32_t _op2_030004A4;
    uint32_t _co_030004A4;
    _op2_030004A4 = _rm_030004A4 >> 16;
    _co_030004A4 = (_rm_030004A4 >> 15) & 1u;
    uint32_t _rn_030004A4 = g_cpu.R[2];
    uint32_t _r_030004A4;
    _r_030004A4 = _op2_030004A4 - _rn_030004A4;
    arm_set_nzcv_sub(_op2_030004A4, _rn_030004A4, _r_030004A4);
    g_cpu.R[3] = _r_030004A4;
    g_cpu.R[15] = 0x030004A8u;
    runtime_tick(_cyc_030004A4);
    /* 030004A8  030004a8 A bcc 0x030004dc */
    g_cpu.R[15] = 0x030004A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004A8 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_030004A8 = 3u;
        g_cpu.R[15] = 0x030004DCu;
        runtime_tick(_cyc_030004A8);
        gf_iwram_fast_ram_work_entry_resolve();
        return;
    }
    g_cpu.R[15] = 0x030004ACu;
    runtime_tick(_cyc_030004A8);
    /* 030004AC  030004ac A rsbs r3,r2,r1,lsr #19 */
    g_cpu.R[15] = 0x030004ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004AC = 1u;
    _cyc_030004AC = 1u;
    uint32_t _rm_030004AC = g_cpu.R[1];
    uint32_t _op2_030004AC;
    uint32_t _co_030004AC;
    _op2_030004AC = _rm_030004AC >> 19;
    _co_030004AC = (_rm_030004AC >> 18) & 1u;
    uint32_t _rn_030004AC = g_cpu.R[2];
    uint32_t _r_030004AC;
    _r_030004AC = _op2_030004AC - _rn_030004AC;
    arm_set_nzcv_sub(_op2_030004AC, _rn_030004AC, _r_030004AC);
    g_cpu.R[3] = _r_030004AC;
    g_cpu.R[15] = 0x030004B0u;
    runtime_tick(_cyc_030004AC);
    /* 030004B0  030004b0 A orrcs r0,r0,#0x80000 */
    g_cpu.R[15] = 0x030004B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004B0 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004B0 = 1u;
        uint32_t _rn_030004B0 = g_cpu.R[0];
        uint32_t _r_030004B0;
        _r_030004B0 = _rn_030004B0 | 0x00080000u;
        g_cpu.R[0] = _r_030004B0;
    }
    g_cpu.R[15] = 0x030004B4u;
    runtime_tick(_cyc_030004B0);
    /* 030004B4  030004b4 A subcs r1,r1,r2,lsl #19 */
    g_cpu.R[15] = 0x030004B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004B4 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004B4 = 1u;
        uint32_t _rm_030004B4 = g_cpu.R[2];
        uint32_t _op2_030004B4;
        uint32_t _co_030004B4;
        _op2_030004B4 = _rm_030004B4 << 19;
        _co_030004B4 = (_rm_030004B4 >> 13) & 1u;
        uint32_t _rn_030004B4 = g_cpu.R[1];
        uint32_t _r_030004B4;
        _r_030004B4 = _rn_030004B4 - _op2_030004B4;
        g_cpu.R[1] = _r_030004B4;
    }
    g_cpu.R[15] = 0x030004B8u;
    runtime_tick(_cyc_030004B4);
    /* 030004B8  030004b8 A rsbs r3,r2,r1,lsr #18 */
    g_cpu.R[15] = 0x030004B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004B8 = 1u;
    _cyc_030004B8 = 1u;
    uint32_t _rm_030004B8 = g_cpu.R[1];
    uint32_t _op2_030004B8;
    uint32_t _co_030004B8;
    _op2_030004B8 = _rm_030004B8 >> 18;
    _co_030004B8 = (_rm_030004B8 >> 17) & 1u;
    uint32_t _rn_030004B8 = g_cpu.R[2];
    uint32_t _r_030004B8;
    _r_030004B8 = _op2_030004B8 - _rn_030004B8;
    arm_set_nzcv_sub(_op2_030004B8, _rn_030004B8, _r_030004B8);
    g_cpu.R[3] = _r_030004B8;
    g_cpu.R[15] = 0x030004BCu;
    runtime_tick(_cyc_030004B8);
    /* 030004BC  030004bc A orrcs r0,r0,#0x40000 */
    g_cpu.R[15] = 0x030004BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004BC = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004BC = 1u;
        uint32_t _rn_030004BC = g_cpu.R[0];
        uint32_t _r_030004BC;
        _r_030004BC = _rn_030004BC | 0x00040000u;
        g_cpu.R[0] = _r_030004BC;
    }
    g_cpu.R[15] = 0x030004C0u;
    runtime_tick(_cyc_030004BC);
    /* 030004C0  030004c0 A subcs r1,r1,r2,lsl #18 */
    g_cpu.R[15] = 0x030004C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004C0 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004C0 = 1u;
        uint32_t _rm_030004C0 = g_cpu.R[2];
        uint32_t _op2_030004C0;
        uint32_t _co_030004C0;
        _op2_030004C0 = _rm_030004C0 << 18;
        _co_030004C0 = (_rm_030004C0 >> 14) & 1u;
        uint32_t _rn_030004C0 = g_cpu.R[1];
        uint32_t _r_030004C0;
        _r_030004C0 = _rn_030004C0 - _op2_030004C0;
        g_cpu.R[1] = _r_030004C0;
    }
    g_cpu.R[15] = 0x030004C4u;
    runtime_tick(_cyc_030004C0);
    /* 030004C4  030004c4 A rsbs r3,r2,r1,lsr #17 */
    g_cpu.R[15] = 0x030004C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004C4 = 1u;
    _cyc_030004C4 = 1u;
    uint32_t _rm_030004C4 = g_cpu.R[1];
    uint32_t _op2_030004C4;
    uint32_t _co_030004C4;
    _op2_030004C4 = _rm_030004C4 >> 17;
    _co_030004C4 = (_rm_030004C4 >> 16) & 1u;
    uint32_t _rn_030004C4 = g_cpu.R[2];
    uint32_t _r_030004C4;
    _r_030004C4 = _op2_030004C4 - _rn_030004C4;
    arm_set_nzcv_sub(_op2_030004C4, _rn_030004C4, _r_030004C4);
    g_cpu.R[3] = _r_030004C4;
    g_cpu.R[15] = 0x030004C8u;
    runtime_tick(_cyc_030004C4);
    /* 030004C8  030004c8 A orrcs r0,r0,#0x20000 */
    g_cpu.R[15] = 0x030004C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004C8 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004C8 = 1u;
        uint32_t _rn_030004C8 = g_cpu.R[0];
        uint32_t _r_030004C8;
        _r_030004C8 = _rn_030004C8 | 0x00020000u;
        g_cpu.R[0] = _r_030004C8;
    }
    g_cpu.R[15] = 0x030004CCu;
    runtime_tick(_cyc_030004C8);
    /* 030004CC  030004cc A subcs r1,r1,r2,lsl #17 */
    g_cpu.R[15] = 0x030004CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004CC = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004CC = 1u;
        uint32_t _rm_030004CC = g_cpu.R[2];
        uint32_t _op2_030004CC;
        uint32_t _co_030004CC;
        _op2_030004CC = _rm_030004CC << 17;
        _co_030004CC = (_rm_030004CC >> 15) & 1u;
        uint32_t _rn_030004CC = g_cpu.R[1];
        uint32_t _r_030004CC;
        _r_030004CC = _rn_030004CC - _op2_030004CC;
        g_cpu.R[1] = _r_030004CC;
    }
    g_cpu.R[15] = 0x030004D0u;
    runtime_tick(_cyc_030004CC);
    /* 030004D0  030004d0 A rsbs r3,r2,r1,lsr #16 */
    g_cpu.R[15] = 0x030004D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004D0 = 1u;
    _cyc_030004D0 = 1u;
    uint32_t _rm_030004D0 = g_cpu.R[1];
    uint32_t _op2_030004D0;
    uint32_t _co_030004D0;
    _op2_030004D0 = _rm_030004D0 >> 16;
    _co_030004D0 = (_rm_030004D0 >> 15) & 1u;
    uint32_t _rn_030004D0 = g_cpu.R[2];
    uint32_t _r_030004D0;
    _r_030004D0 = _op2_030004D0 - _rn_030004D0;
    arm_set_nzcv_sub(_op2_030004D0, _rn_030004D0, _r_030004D0);
    g_cpu.R[3] = _r_030004D0;
    g_cpu.R[15] = 0x030004D4u;
    runtime_tick(_cyc_030004D0);
    /* 030004D4  030004d4 A orrcs r0,r0,#0x10000 */
    g_cpu.R[15] = 0x030004D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004D4 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004D4 = 1u;
        uint32_t _rn_030004D4 = g_cpu.R[0];
        uint32_t _r_030004D4;
        _r_030004D4 = _rn_030004D4 | 0x00010000u;
        g_cpu.R[0] = _r_030004D4;
    }
    g_cpu.R[15] = 0x030004D8u;
    runtime_tick(_cyc_030004D4);
    /* 030004D8  030004d8 A subcs r1,r1,r2,lsl #16 */
    g_cpu.R[15] = 0x030004D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004D8 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004D8 = 1u;
        uint32_t _rm_030004D8 = g_cpu.R[2];
        uint32_t _op2_030004D8;
        uint32_t _co_030004D8;
        _op2_030004D8 = _rm_030004D8 << 16;
        _co_030004D8 = (_rm_030004D8 >> 16) & 1u;
        uint32_t _rn_030004D8 = g_cpu.R[1];
        uint32_t _r_030004D8;
        _r_030004D8 = _rn_030004D8 - _op2_030004D8;
        g_cpu.R[1] = _r_030004D8;
    }
    g_cpu.R[15] = 0x030004DCu;
    runtime_tick(_cyc_030004D8);
    /* fall-through to 0x030004DC */
    g_cpu.R[15] = 0x030004DCu;
    runtime_dispatch(0x030004DCu);
    return;
}

/* 0x030005D0  mode=arm  end=0x030005E0  branches=3 */


/* 0x030004DC arm */
void gf_iwram_fast_ram_work_entry_resolve(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030004DCu);
    /* 030004DC  030004dc A rsbs r3,r2,r1,lsr #12 */
    g_cpu.R[15] = 0x030004DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004DC = 1u;
    _cyc_030004DC = 1u;
    uint32_t _rm_030004DC = g_cpu.R[1];
    uint32_t _op2_030004DC;
    uint32_t _co_030004DC;
    _op2_030004DC = _rm_030004DC >> 12;
    _co_030004DC = (_rm_030004DC >> 11) & 1u;
    uint32_t _rn_030004DC = g_cpu.R[2];
    uint32_t _r_030004DC;
    _r_030004DC = _op2_030004DC - _rn_030004DC;
    arm_set_nzcv_sub(_op2_030004DC, _rn_030004DC, _r_030004DC);
    g_cpu.R[3] = _r_030004DC;
    g_cpu.R[15] = 0x030004E0u;
    runtime_tick(_cyc_030004DC);
    /* 030004E0  030004e0 A bcc 0x03000514 */
    g_cpu.R[15] = 0x030004E0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004E0 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_030004E0 = 3u;
        g_cpu.R[15] = 0x03000514u;
        runtime_tick(_cyc_030004E0);
        gf_iwram_fast_ram_work_entry_lookup();
        return;
    }
    g_cpu.R[15] = 0x030004E4u;
    runtime_tick(_cyc_030004E0);
    /* 030004E4  030004e4 A rsbs r3,r2,r1,lsr #15 */
    g_cpu.R[15] = 0x030004E4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004E4 = 1u;
    _cyc_030004E4 = 1u;
    uint32_t _rm_030004E4 = g_cpu.R[1];
    uint32_t _op2_030004E4;
    uint32_t _co_030004E4;
    _op2_030004E4 = _rm_030004E4 >> 15;
    _co_030004E4 = (_rm_030004E4 >> 14) & 1u;
    uint32_t _rn_030004E4 = g_cpu.R[2];
    uint32_t _r_030004E4;
    _r_030004E4 = _op2_030004E4 - _rn_030004E4;
    arm_set_nzcv_sub(_op2_030004E4, _rn_030004E4, _r_030004E4);
    g_cpu.R[3] = _r_030004E4;
    g_cpu.R[15] = 0x030004E8u;
    runtime_tick(_cyc_030004E4);
    /* 030004E8  030004e8 A orrcs r0,r0,#0x8000 */
    g_cpu.R[15] = 0x030004E8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004E8 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004E8 = 1u;
        uint32_t _rn_030004E8 = g_cpu.R[0];
        uint32_t _r_030004E8;
        _r_030004E8 = _rn_030004E8 | 0x00008000u;
        g_cpu.R[0] = _r_030004E8;
    }
    g_cpu.R[15] = 0x030004ECu;
    runtime_tick(_cyc_030004E8);
    /* 030004EC  030004ec A subcs r1,r1,r2,lsl #15 */
    g_cpu.R[15] = 0x030004ECu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004EC = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004EC = 1u;
        uint32_t _rm_030004EC = g_cpu.R[2];
        uint32_t _op2_030004EC;
        uint32_t _co_030004EC;
        _op2_030004EC = _rm_030004EC << 15;
        _co_030004EC = (_rm_030004EC >> 17) & 1u;
        uint32_t _rn_030004EC = g_cpu.R[1];
        uint32_t _r_030004EC;
        _r_030004EC = _rn_030004EC - _op2_030004EC;
        g_cpu.R[1] = _r_030004EC;
    }
    g_cpu.R[15] = 0x030004F0u;
    runtime_tick(_cyc_030004EC);
    /* 030004F0  030004f0 A rsbs r3,r2,r1,lsr #14 */
    g_cpu.R[15] = 0x030004F0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004F0 = 1u;
    _cyc_030004F0 = 1u;
    uint32_t _rm_030004F0 = g_cpu.R[1];
    uint32_t _op2_030004F0;
    uint32_t _co_030004F0;
    _op2_030004F0 = _rm_030004F0 >> 14;
    _co_030004F0 = (_rm_030004F0 >> 13) & 1u;
    uint32_t _rn_030004F0 = g_cpu.R[2];
    uint32_t _r_030004F0;
    _r_030004F0 = _op2_030004F0 - _rn_030004F0;
    arm_set_nzcv_sub(_op2_030004F0, _rn_030004F0, _r_030004F0);
    g_cpu.R[3] = _r_030004F0;
    g_cpu.R[15] = 0x030004F4u;
    runtime_tick(_cyc_030004F0);
    /* 030004F4  030004f4 A orrcs r0,r0,#0x4000 */
    g_cpu.R[15] = 0x030004F4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004F4 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004F4 = 1u;
        uint32_t _rn_030004F4 = g_cpu.R[0];
        uint32_t _r_030004F4;
        _r_030004F4 = _rn_030004F4 | 0x00004000u;
        g_cpu.R[0] = _r_030004F4;
    }
    g_cpu.R[15] = 0x030004F8u;
    runtime_tick(_cyc_030004F4);
    /* 030004F8  030004f8 A subcs r1,r1,r2,lsl #14 */
    g_cpu.R[15] = 0x030004F8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004F8 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030004F8 = 1u;
        uint32_t _rm_030004F8 = g_cpu.R[2];
        uint32_t _op2_030004F8;
        uint32_t _co_030004F8;
        _op2_030004F8 = _rm_030004F8 << 14;
        _co_030004F8 = (_rm_030004F8 >> 18) & 1u;
        uint32_t _rn_030004F8 = g_cpu.R[1];
        uint32_t _r_030004F8;
        _r_030004F8 = _rn_030004F8 - _op2_030004F8;
        g_cpu.R[1] = _r_030004F8;
    }
    g_cpu.R[15] = 0x030004FCu;
    runtime_tick(_cyc_030004F8);
    /* 030004FC  030004fc A rsbs r3,r2,r1,lsr #13 */
    g_cpu.R[15] = 0x030004FCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030004FC = 1u;
    _cyc_030004FC = 1u;
    uint32_t _rm_030004FC = g_cpu.R[1];
    uint32_t _op2_030004FC;
    uint32_t _co_030004FC;
    _op2_030004FC = _rm_030004FC >> 13;
    _co_030004FC = (_rm_030004FC >> 12) & 1u;
    uint32_t _rn_030004FC = g_cpu.R[2];
    uint32_t _r_030004FC;
    _r_030004FC = _op2_030004FC - _rn_030004FC;
    arm_set_nzcv_sub(_op2_030004FC, _rn_030004FC, _r_030004FC);
    g_cpu.R[3] = _r_030004FC;
    g_cpu.R[15] = 0x03000500u;
    runtime_tick(_cyc_030004FC);
    /* 03000500  03000500 A orrcs r0,r0,#0x2000 */
    g_cpu.R[15] = 0x03000500u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000500 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000500 = 1u;
        uint32_t _rn_03000500 = g_cpu.R[0];
        uint32_t _r_03000500;
        _r_03000500 = _rn_03000500 | 0x00002000u;
        g_cpu.R[0] = _r_03000500;
    }
    g_cpu.R[15] = 0x03000504u;
    runtime_tick(_cyc_03000500);
    /* 03000504  03000504 A subcs r1,r1,r2,lsl #13 */
    g_cpu.R[15] = 0x03000504u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000504 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000504 = 1u;
        uint32_t _rm_03000504 = g_cpu.R[2];
        uint32_t _op2_03000504;
        uint32_t _co_03000504;
        _op2_03000504 = _rm_03000504 << 13;
        _co_03000504 = (_rm_03000504 >> 19) & 1u;
        uint32_t _rn_03000504 = g_cpu.R[1];
        uint32_t _r_03000504;
        _r_03000504 = _rn_03000504 - _op2_03000504;
        g_cpu.R[1] = _r_03000504;
    }
    g_cpu.R[15] = 0x03000508u;
    runtime_tick(_cyc_03000504);
    /* 03000508  03000508 A rsbs r3,r2,r1,lsr #12 */
    g_cpu.R[15] = 0x03000508u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000508 = 1u;
    _cyc_03000508 = 1u;
    uint32_t _rm_03000508 = g_cpu.R[1];
    uint32_t _op2_03000508;
    uint32_t _co_03000508;
    _op2_03000508 = _rm_03000508 >> 12;
    _co_03000508 = (_rm_03000508 >> 11) & 1u;
    uint32_t _rn_03000508 = g_cpu.R[2];
    uint32_t _r_03000508;
    _r_03000508 = _op2_03000508 - _rn_03000508;
    arm_set_nzcv_sub(_op2_03000508, _rn_03000508, _r_03000508);
    g_cpu.R[3] = _r_03000508;
    g_cpu.R[15] = 0x0300050Cu;
    runtime_tick(_cyc_03000508);
    /* 0300050C  0300050c A orrcs r0,r0,#0x1000 */
    g_cpu.R[15] = 0x0300050Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300050C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300050C = 1u;
        uint32_t _rn_0300050C = g_cpu.R[0];
        uint32_t _r_0300050C;
        _r_0300050C = _rn_0300050C | 0x00001000u;
        g_cpu.R[0] = _r_0300050C;
    }
    g_cpu.R[15] = 0x03000510u;
    runtime_tick(_cyc_0300050C);
    /* 03000510  03000510 A subcs r1,r1,r2,lsl #12 */
    g_cpu.R[15] = 0x03000510u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000510 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000510 = 1u;
        uint32_t _rm_03000510 = g_cpu.R[2];
        uint32_t _op2_03000510;
        uint32_t _co_03000510;
        _op2_03000510 = _rm_03000510 << 12;
        _co_03000510 = (_rm_03000510 >> 20) & 1u;
        uint32_t _rn_03000510 = g_cpu.R[1];
        uint32_t _r_03000510;
        _r_03000510 = _rn_03000510 - _op2_03000510;
        g_cpu.R[1] = _r_03000510;
    }
    g_cpu.R[15] = 0x03000514u;
    runtime_tick(_cyc_03000510);
    /* fall-through to 0x03000514 */
    g_cpu.R[15] = 0x03000514u;
    runtime_dispatch(0x03000514u);
    return;
}

/* 0x0300054C  mode=arm  end=0x03000584  branches=2  indirect */


/* 0x03000514 arm */
void gf_iwram_fast_ram_work_entry_lookup(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000514u);
    /* 03000514  03000514 A rsbs r3,r2,r1,lsr #8 */
    g_cpu.R[15] = 0x03000514u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000514 = 1u;
    _cyc_03000514 = 1u;
    uint32_t _rm_03000514 = g_cpu.R[1];
    uint32_t _op2_03000514;
    uint32_t _co_03000514;
    _op2_03000514 = _rm_03000514 >> 8;
    _co_03000514 = (_rm_03000514 >> 7) & 1u;
    uint32_t _rn_03000514 = g_cpu.R[2];
    uint32_t _r_03000514;
    _r_03000514 = _op2_03000514 - _rn_03000514;
    arm_set_nzcv_sub(_op2_03000514, _rn_03000514, _r_03000514);
    g_cpu.R[3] = _r_03000514;
    g_cpu.R[15] = 0x03000518u;
    runtime_tick(_cyc_03000514);
    /* 03000518  03000518 A bcc 0x0300054c */
    g_cpu.R[15] = 0x03000518u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000518 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000518 = 3u;
        g_cpu.R[15] = 0x0300054Cu;
        runtime_tick(_cyc_03000518);
        gf_iwram_fast_ram_work_entry_match();
        return;
    }
    g_cpu.R[15] = 0x0300051Cu;
    runtime_tick(_cyc_03000518);
    /* 0300051C  0300051c A rsbs r3,r2,r1,lsr #11 */
    g_cpu.R[15] = 0x0300051Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300051C = 1u;
    _cyc_0300051C = 1u;
    uint32_t _rm_0300051C = g_cpu.R[1];
    uint32_t _op2_0300051C;
    uint32_t _co_0300051C;
    _op2_0300051C = _rm_0300051C >> 11;
    _co_0300051C = (_rm_0300051C >> 10) & 1u;
    uint32_t _rn_0300051C = g_cpu.R[2];
    uint32_t _r_0300051C;
    _r_0300051C = _op2_0300051C - _rn_0300051C;
    arm_set_nzcv_sub(_op2_0300051C, _rn_0300051C, _r_0300051C);
    g_cpu.R[3] = _r_0300051C;
    g_cpu.R[15] = 0x03000520u;
    runtime_tick(_cyc_0300051C);
    /* 03000520  03000520 A orrcs r0,r0,#0x800 */
    g_cpu.R[15] = 0x03000520u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000520 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000520 = 1u;
        uint32_t _rn_03000520 = g_cpu.R[0];
        uint32_t _r_03000520;
        _r_03000520 = _rn_03000520 | 0x00000800u;
        g_cpu.R[0] = _r_03000520;
    }
    g_cpu.R[15] = 0x03000524u;
    runtime_tick(_cyc_03000520);
    /* 03000524  03000524 A subcs r1,r1,r2,lsl #11 */
    g_cpu.R[15] = 0x03000524u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000524 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000524 = 1u;
        uint32_t _rm_03000524 = g_cpu.R[2];
        uint32_t _op2_03000524;
        uint32_t _co_03000524;
        _op2_03000524 = _rm_03000524 << 11;
        _co_03000524 = (_rm_03000524 >> 21) & 1u;
        uint32_t _rn_03000524 = g_cpu.R[1];
        uint32_t _r_03000524;
        _r_03000524 = _rn_03000524 - _op2_03000524;
        g_cpu.R[1] = _r_03000524;
    }
    g_cpu.R[15] = 0x03000528u;
    runtime_tick(_cyc_03000524);
    /* 03000528  03000528 A rsbs r3,r2,r1,lsr #10 */
    g_cpu.R[15] = 0x03000528u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000528 = 1u;
    _cyc_03000528 = 1u;
    uint32_t _rm_03000528 = g_cpu.R[1];
    uint32_t _op2_03000528;
    uint32_t _co_03000528;
    _op2_03000528 = _rm_03000528 >> 10;
    _co_03000528 = (_rm_03000528 >> 9) & 1u;
    uint32_t _rn_03000528 = g_cpu.R[2];
    uint32_t _r_03000528;
    _r_03000528 = _op2_03000528 - _rn_03000528;
    arm_set_nzcv_sub(_op2_03000528, _rn_03000528, _r_03000528);
    g_cpu.R[3] = _r_03000528;
    g_cpu.R[15] = 0x0300052Cu;
    runtime_tick(_cyc_03000528);
    /* 0300052C  0300052c A orrcs r0,r0,#0x400 */
    g_cpu.R[15] = 0x0300052Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300052C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300052C = 1u;
        uint32_t _rn_0300052C = g_cpu.R[0];
        uint32_t _r_0300052C;
        _r_0300052C = _rn_0300052C | 0x00000400u;
        g_cpu.R[0] = _r_0300052C;
    }
    g_cpu.R[15] = 0x03000530u;
    runtime_tick(_cyc_0300052C);
    /* 03000530  03000530 A subcs r1,r1,r2,lsl #10 */
    g_cpu.R[15] = 0x03000530u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000530 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000530 = 1u;
        uint32_t _rm_03000530 = g_cpu.R[2];
        uint32_t _op2_03000530;
        uint32_t _co_03000530;
        _op2_03000530 = _rm_03000530 << 10;
        _co_03000530 = (_rm_03000530 >> 22) & 1u;
        uint32_t _rn_03000530 = g_cpu.R[1];
        uint32_t _r_03000530;
        _r_03000530 = _rn_03000530 - _op2_03000530;
        g_cpu.R[1] = _r_03000530;
    }
    g_cpu.R[15] = 0x03000534u;
    runtime_tick(_cyc_03000530);
    /* 03000534  03000534 A rsbs r3,r2,r1,lsr #9 */
    g_cpu.R[15] = 0x03000534u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000534 = 1u;
    _cyc_03000534 = 1u;
    uint32_t _rm_03000534 = g_cpu.R[1];
    uint32_t _op2_03000534;
    uint32_t _co_03000534;
    _op2_03000534 = _rm_03000534 >> 9;
    _co_03000534 = (_rm_03000534 >> 8) & 1u;
    uint32_t _rn_03000534 = g_cpu.R[2];
    uint32_t _r_03000534;
    _r_03000534 = _op2_03000534 - _rn_03000534;
    arm_set_nzcv_sub(_op2_03000534, _rn_03000534, _r_03000534);
    g_cpu.R[3] = _r_03000534;
    g_cpu.R[15] = 0x03000538u;
    runtime_tick(_cyc_03000534);
    /* 03000538  03000538 A orrcs r0,r0,#0x200 */
    g_cpu.R[15] = 0x03000538u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000538 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000538 = 1u;
        uint32_t _rn_03000538 = g_cpu.R[0];
        uint32_t _r_03000538;
        _r_03000538 = _rn_03000538 | 0x00000200u;
        g_cpu.R[0] = _r_03000538;
    }
    g_cpu.R[15] = 0x0300053Cu;
    runtime_tick(_cyc_03000538);
    /* 0300053C  0300053c A subcs r1,r1,r2,lsl #9 */
    g_cpu.R[15] = 0x0300053Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300053C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300053C = 1u;
        uint32_t _rm_0300053C = g_cpu.R[2];
        uint32_t _op2_0300053C;
        uint32_t _co_0300053C;
        _op2_0300053C = _rm_0300053C << 9;
        _co_0300053C = (_rm_0300053C >> 23) & 1u;
        uint32_t _rn_0300053C = g_cpu.R[1];
        uint32_t _r_0300053C;
        _r_0300053C = _rn_0300053C - _op2_0300053C;
        g_cpu.R[1] = _r_0300053C;
    }
    g_cpu.R[15] = 0x03000540u;
    runtime_tick(_cyc_0300053C);
    /* 03000540  03000540 A rsbs r3,r2,r1,lsr #8 */
    g_cpu.R[15] = 0x03000540u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000540 = 1u;
    _cyc_03000540 = 1u;
    uint32_t _rm_03000540 = g_cpu.R[1];
    uint32_t _op2_03000540;
    uint32_t _co_03000540;
    _op2_03000540 = _rm_03000540 >> 8;
    _co_03000540 = (_rm_03000540 >> 7) & 1u;
    uint32_t _rn_03000540 = g_cpu.R[2];
    uint32_t _r_03000540;
    _r_03000540 = _op2_03000540 - _rn_03000540;
    arm_set_nzcv_sub(_op2_03000540, _rn_03000540, _r_03000540);
    g_cpu.R[3] = _r_03000540;
    g_cpu.R[15] = 0x03000544u;
    runtime_tick(_cyc_03000540);
    /* 03000544  03000544 A orrcs r0,r0,#0x100 */
    g_cpu.R[15] = 0x03000544u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000544 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000544 = 1u;
        uint32_t _rn_03000544 = g_cpu.R[0];
        uint32_t _r_03000544;
        _r_03000544 = _rn_03000544 | 0x00000100u;
        g_cpu.R[0] = _r_03000544;
    }
    g_cpu.R[15] = 0x03000548u;
    runtime_tick(_cyc_03000544);
    /* 03000548  03000548 A subcs r1,r1,r2,lsl #8 */
    g_cpu.R[15] = 0x03000548u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000548 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000548 = 1u;
        uint32_t _rm_03000548 = g_cpu.R[2];
        uint32_t _op2_03000548;
        uint32_t _co_03000548;
        _op2_03000548 = _rm_03000548 << 8;
        _co_03000548 = (_rm_03000548 >> 24) & 1u;
        uint32_t _rn_03000548 = g_cpu.R[1];
        uint32_t _r_03000548;
        _r_03000548 = _rn_03000548 - _op2_03000548;
        g_cpu.R[1] = _r_03000548;
    }
    g_cpu.R[15] = 0x0300054Cu;
    runtime_tick(_cyc_03000548);
    /* fall-through to 0x0300054C */
    g_cpu.R[15] = 0x0300054Cu;
    runtime_dispatch(0x0300054Cu);
    return;
}

/* 0x0300058C  mode=arm  end=0x030005C0  branches=0  indirect */


/* 0x0300054C arm */
void gf_iwram_fast_ram_work_entry_match(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300054Cu);
    /* 0300054C  0300054c A rsbs r3,r2,r1,lsr #4 */
    g_cpu.R[15] = 0x0300054Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300054C = 1u;
    _cyc_0300054C = 1u;
    uint32_t _rm_0300054C = g_cpu.R[1];
    uint32_t _op2_0300054C;
    uint32_t _co_0300054C;
    _op2_0300054C = _rm_0300054C >> 4;
    _co_0300054C = (_rm_0300054C >> 3) & 1u;
    uint32_t _rn_0300054C = g_cpu.R[2];
    uint32_t _r_0300054C;
    _r_0300054C = _op2_0300054C - _rn_0300054C;
    arm_set_nzcv_sub(_op2_0300054C, _rn_0300054C, _r_0300054C);
    g_cpu.R[3] = _r_0300054C;
    g_cpu.R[15] = 0x03000550u;
    runtime_tick(_cyc_0300054C);
    /* 03000550  03000550 A bcc 0x03000584 */
    g_cpu.R[15] = 0x03000550u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000550 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000550 = 3u;
        g_cpu.R[15] = 0x03000584u;
        runtime_tick(_cyc_03000550);
        gf_iwram_fast_ram_work_entry_find();
        return;
    }
    g_cpu.R[15] = 0x03000554u;
    runtime_tick(_cyc_03000550);
    /* 03000554  03000554 A rsbs r3,r2,r1,lsr #7 */
    g_cpu.R[15] = 0x03000554u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000554 = 1u;
    _cyc_03000554 = 1u;
    uint32_t _rm_03000554 = g_cpu.R[1];
    uint32_t _op2_03000554;
    uint32_t _co_03000554;
    _op2_03000554 = _rm_03000554 >> 7;
    _co_03000554 = (_rm_03000554 >> 6) & 1u;
    uint32_t _rn_03000554 = g_cpu.R[2];
    uint32_t _r_03000554;
    _r_03000554 = _op2_03000554 - _rn_03000554;
    arm_set_nzcv_sub(_op2_03000554, _rn_03000554, _r_03000554);
    g_cpu.R[3] = _r_03000554;
    g_cpu.R[15] = 0x03000558u;
    runtime_tick(_cyc_03000554);
    /* 03000558  03000558 A orrcs r0,r0,#0x80 */
    g_cpu.R[15] = 0x03000558u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000558 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000558 = 1u;
        uint32_t _rn_03000558 = g_cpu.R[0];
        uint32_t _r_03000558;
        _r_03000558 = _rn_03000558 | 0x00000080u;
        g_cpu.R[0] = _r_03000558;
    }
    g_cpu.R[15] = 0x0300055Cu;
    runtime_tick(_cyc_03000558);
    /* 0300055C  0300055c A subcs r1,r1,r2,lsl #7 */
    g_cpu.R[15] = 0x0300055Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300055C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300055C = 1u;
        uint32_t _rm_0300055C = g_cpu.R[2];
        uint32_t _op2_0300055C;
        uint32_t _co_0300055C;
        _op2_0300055C = _rm_0300055C << 7;
        _co_0300055C = (_rm_0300055C >> 25) & 1u;
        uint32_t _rn_0300055C = g_cpu.R[1];
        uint32_t _r_0300055C;
        _r_0300055C = _rn_0300055C - _op2_0300055C;
        g_cpu.R[1] = _r_0300055C;
    }
    g_cpu.R[15] = 0x03000560u;
    runtime_tick(_cyc_0300055C);
    /* 03000560  03000560 A rsbs r3,r2,r1,lsr #6 */
    g_cpu.R[15] = 0x03000560u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000560 = 1u;
    _cyc_03000560 = 1u;
    uint32_t _rm_03000560 = g_cpu.R[1];
    uint32_t _op2_03000560;
    uint32_t _co_03000560;
    _op2_03000560 = _rm_03000560 >> 6;
    _co_03000560 = (_rm_03000560 >> 5) & 1u;
    uint32_t _rn_03000560 = g_cpu.R[2];
    uint32_t _r_03000560;
    _r_03000560 = _op2_03000560 - _rn_03000560;
    arm_set_nzcv_sub(_op2_03000560, _rn_03000560, _r_03000560);
    g_cpu.R[3] = _r_03000560;
    g_cpu.R[15] = 0x03000564u;
    runtime_tick(_cyc_03000560);
    /* 03000564  03000564 A orrcs r0,r0,#0x40 */
    g_cpu.R[15] = 0x03000564u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000564 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000564 = 1u;
        uint32_t _rn_03000564 = g_cpu.R[0];
        uint32_t _r_03000564;
        _r_03000564 = _rn_03000564 | 0x00000040u;
        g_cpu.R[0] = _r_03000564;
    }
    g_cpu.R[15] = 0x03000568u;
    runtime_tick(_cyc_03000564);
    /* 03000568  03000568 A subcs r1,r1,r2,lsl #6 */
    g_cpu.R[15] = 0x03000568u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000568 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000568 = 1u;
        uint32_t _rm_03000568 = g_cpu.R[2];
        uint32_t _op2_03000568;
        uint32_t _co_03000568;
        _op2_03000568 = _rm_03000568 << 6;
        _co_03000568 = (_rm_03000568 >> 26) & 1u;
        uint32_t _rn_03000568 = g_cpu.R[1];
        uint32_t _r_03000568;
        _r_03000568 = _rn_03000568 - _op2_03000568;
        g_cpu.R[1] = _r_03000568;
    }
    g_cpu.R[15] = 0x0300056Cu;
    runtime_tick(_cyc_03000568);
    /* 0300056C  0300056c A rsbs r3,r2,r1,lsr #5 */
    g_cpu.R[15] = 0x0300056Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300056C = 1u;
    _cyc_0300056C = 1u;
    uint32_t _rm_0300056C = g_cpu.R[1];
    uint32_t _op2_0300056C;
    uint32_t _co_0300056C;
    _op2_0300056C = _rm_0300056C >> 5;
    _co_0300056C = (_rm_0300056C >> 4) & 1u;
    uint32_t _rn_0300056C = g_cpu.R[2];
    uint32_t _r_0300056C;
    _r_0300056C = _op2_0300056C - _rn_0300056C;
    arm_set_nzcv_sub(_op2_0300056C, _rn_0300056C, _r_0300056C);
    g_cpu.R[3] = _r_0300056C;
    g_cpu.R[15] = 0x03000570u;
    runtime_tick(_cyc_0300056C);
    /* 03000570  03000570 A orrcs r0,r0,#0x20 */
    g_cpu.R[15] = 0x03000570u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000570 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000570 = 1u;
        uint32_t _rn_03000570 = g_cpu.R[0];
        uint32_t _r_03000570;
        _r_03000570 = _rn_03000570 | 0x00000020u;
        g_cpu.R[0] = _r_03000570;
    }
    g_cpu.R[15] = 0x03000574u;
    runtime_tick(_cyc_03000570);
    /* 03000574  03000574 A subcs r1,r1,r2,lsl #5 */
    g_cpu.R[15] = 0x03000574u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000574 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000574 = 1u;
        uint32_t _rm_03000574 = g_cpu.R[2];
        uint32_t _op2_03000574;
        uint32_t _co_03000574;
        _op2_03000574 = _rm_03000574 << 5;
        _co_03000574 = (_rm_03000574 >> 27) & 1u;
        uint32_t _rn_03000574 = g_cpu.R[1];
        uint32_t _r_03000574;
        _r_03000574 = _rn_03000574 - _op2_03000574;
        g_cpu.R[1] = _r_03000574;
    }
    g_cpu.R[15] = 0x03000578u;
    runtime_tick(_cyc_03000574);
    /* 03000578  03000578 A rsbs r3,r2,r1,lsr #4 */
    g_cpu.R[15] = 0x03000578u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000578 = 1u;
    _cyc_03000578 = 1u;
    uint32_t _rm_03000578 = g_cpu.R[1];
    uint32_t _op2_03000578;
    uint32_t _co_03000578;
    _op2_03000578 = _rm_03000578 >> 4;
    _co_03000578 = (_rm_03000578 >> 3) & 1u;
    uint32_t _rn_03000578 = g_cpu.R[2];
    uint32_t _r_03000578;
    _r_03000578 = _op2_03000578 - _rn_03000578;
    arm_set_nzcv_sub(_op2_03000578, _rn_03000578, _r_03000578);
    g_cpu.R[3] = _r_03000578;
    g_cpu.R[15] = 0x0300057Cu;
    runtime_tick(_cyc_03000578);
    /* 0300057C  0300057c A orrcs r0,r0,#0x10 */
    g_cpu.R[15] = 0x0300057Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300057C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300057C = 1u;
        uint32_t _rn_0300057C = g_cpu.R[0];
        uint32_t _r_0300057C;
        _r_0300057C = _rn_0300057C | 0x00000010u;
        g_cpu.R[0] = _r_0300057C;
    }
    g_cpu.R[15] = 0x03000580u;
    runtime_tick(_cyc_0300057C);
    /* 03000580  03000580 A subcs r1,r1,r2,lsl #4 */
    g_cpu.R[15] = 0x03000580u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000580 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000580 = 1u;
        uint32_t _rm_03000580 = g_cpu.R[2];
        uint32_t _op2_03000580;
        uint32_t _co_03000580;
        _op2_03000580 = _rm_03000580 << 4;
        _co_03000580 = (_rm_03000580 >> 28) & 1u;
        uint32_t _rn_03000580 = g_cpu.R[1];
        uint32_t _r_03000580;
        _r_03000580 = _rn_03000580 - _op2_03000580;
        g_cpu.R[1] = _r_03000580;
    }
    g_cpu.R[15] = 0x03000584u;
    runtime_tick(_cyc_03000580);
    /* fall-through to 0x03000584 */
    g_cpu.R[15] = 0x03000584u;
    runtime_dispatch(0x03000584u);
    return;
}

/* 0x030013D8  mode=arm  end=0x030013E8  branches=3  indirect */


/* 0x03000584 arm */
void gf_iwram_fast_ram_work_entry_find(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000584u);
    /* 03000584  03000584 A rsbs r3,r2,r1 */
    g_cpu.R[15] = 0x03000584u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000584 = 1u;
    _cyc_03000584 = 1u;
    uint32_t _rm_03000584 = g_cpu.R[1];
    uint32_t _op2_03000584;
    uint32_t _co_03000584;
    _op2_03000584 = _rm_03000584;
    _co_03000584 = cpsr_c();
    uint32_t _rn_03000584 = g_cpu.R[2];
    uint32_t _r_03000584;
    _r_03000584 = _op2_03000584 - _rn_03000584;
    arm_set_nzcv_sub(_op2_03000584, _rn_03000584, _r_03000584);
    g_cpu.R[3] = _r_03000584;
    g_cpu.R[15] = 0x03000588u;
    runtime_tick(_cyc_03000584);
    /* 03000588  03000588 A bxcc r14 */
    g_cpu.R[15] = 0x03000588u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000588 = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_03000588 = 3u;
        uint32_t _bxt_03000588 = g_cpu.R[14];
        g_cpu.R[15] = _bxt_03000588 & ~1u;
        runtime_tick(_cyc_03000588);
        if (_bxt_03000588 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
        if (runtime_call_should_return(g_cpu.R[15])) return;
        runtime_dispatch_with_exchange(_bxt_03000588);
        return;
    }
    g_cpu.R[15] = 0x0300058Cu;
    runtime_tick(_cyc_03000588);
    /* fall-through to 0x0300058C */
    g_cpu.R[15] = 0x0300058Cu;
    runtime_dispatch(0x0300058Cu);
    return;
}

/* 0x030013D0  mode=arm  end=0x030013D8  branches=3  indirect */


/* 0x0300058C arm */
void gf_iwram_fast_ram_work_entry_select(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300058Cu);
    /* 0300058C  0300058c A rsbs r3,r2,r1,lsr #3 */
    g_cpu.R[15] = 0x0300058Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300058C = 1u;
    _cyc_0300058C = 1u;
    uint32_t _rm_0300058C = g_cpu.R[1];
    uint32_t _op2_0300058C;
    uint32_t _co_0300058C;
    _op2_0300058C = _rm_0300058C >> 3;
    _co_0300058C = (_rm_0300058C >> 2) & 1u;
    uint32_t _rn_0300058C = g_cpu.R[2];
    uint32_t _r_0300058C;
    _r_0300058C = _op2_0300058C - _rn_0300058C;
    arm_set_nzcv_sub(_op2_0300058C, _rn_0300058C, _r_0300058C);
    g_cpu.R[3] = _r_0300058C;
    g_cpu.R[15] = 0x03000590u;
    runtime_tick(_cyc_0300058C);
    /* 03000590  03000590 A orrcs r0,r0,#0x8 */
    g_cpu.R[15] = 0x03000590u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000590 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000590 = 1u;
        uint32_t _rn_03000590 = g_cpu.R[0];
        uint32_t _r_03000590;
        _r_03000590 = _rn_03000590 | 0x00000008u;
        g_cpu.R[0] = _r_03000590;
    }
    g_cpu.R[15] = 0x03000594u;
    runtime_tick(_cyc_03000590);
    /* 03000594  03000594 A subcs r1,r1,r2,lsl #3 */
    g_cpu.R[15] = 0x03000594u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000594 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_03000594 = 1u;
        uint32_t _rm_03000594 = g_cpu.R[2];
        uint32_t _op2_03000594;
        uint32_t _co_03000594;
        _op2_03000594 = _rm_03000594 << 3;
        _co_03000594 = (_rm_03000594 >> 29) & 1u;
        uint32_t _rn_03000594 = g_cpu.R[1];
        uint32_t _r_03000594;
        _r_03000594 = _rn_03000594 - _op2_03000594;
        g_cpu.R[1] = _r_03000594;
    }
    g_cpu.R[15] = 0x03000598u;
    runtime_tick(_cyc_03000594);
    /* 03000598  03000598 A rsbs r3,r2,r1,lsr #2 */
    g_cpu.R[15] = 0x03000598u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000598 = 1u;
    _cyc_03000598 = 1u;
    uint32_t _rm_03000598 = g_cpu.R[1];
    uint32_t _op2_03000598;
    uint32_t _co_03000598;
    _op2_03000598 = _rm_03000598 >> 2;
    _co_03000598 = (_rm_03000598 >> 1) & 1u;
    uint32_t _rn_03000598 = g_cpu.R[2];
    uint32_t _r_03000598;
    _r_03000598 = _op2_03000598 - _rn_03000598;
    arm_set_nzcv_sub(_op2_03000598, _rn_03000598, _r_03000598);
    g_cpu.R[3] = _r_03000598;
    g_cpu.R[15] = 0x0300059Cu;
    runtime_tick(_cyc_03000598);
    /* 0300059C  0300059c A orrcs r0,r0,#0x4 */
    g_cpu.R[15] = 0x0300059Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300059C = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_0300059C = 1u;
        uint32_t _rn_0300059C = g_cpu.R[0];
        uint32_t _r_0300059C;
        _r_0300059C = _rn_0300059C | 0x00000004u;
        g_cpu.R[0] = _r_0300059C;
    }
    g_cpu.R[15] = 0x030005A0u;
    runtime_tick(_cyc_0300059C);
    /* 030005A0  030005a0 A subcs r1,r1,r2,lsl #2 */
    g_cpu.R[15] = 0x030005A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005A0 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030005A0 = 1u;
        uint32_t _rm_030005A0 = g_cpu.R[2];
        uint32_t _op2_030005A0;
        uint32_t _co_030005A0;
        _op2_030005A0 = _rm_030005A0 << 2;
        _co_030005A0 = (_rm_030005A0 >> 30) & 1u;
        uint32_t _rn_030005A0 = g_cpu.R[1];
        uint32_t _r_030005A0;
        _r_030005A0 = _rn_030005A0 - _op2_030005A0;
        g_cpu.R[1] = _r_030005A0;
    }
    g_cpu.R[15] = 0x030005A4u;
    runtime_tick(_cyc_030005A0);
    /* 030005A4  030005a4 A rsbs r3,r2,r1,lsr #1 */
    g_cpu.R[15] = 0x030005A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005A4 = 1u;
    _cyc_030005A4 = 1u;
    uint32_t _rm_030005A4 = g_cpu.R[1];
    uint32_t _op2_030005A4;
    uint32_t _co_030005A4;
    _op2_030005A4 = _rm_030005A4 >> 1;
    _co_030005A4 = (_rm_030005A4 >> 0) & 1u;
    uint32_t _rn_030005A4 = g_cpu.R[2];
    uint32_t _r_030005A4;
    _r_030005A4 = _op2_030005A4 - _rn_030005A4;
    arm_set_nzcv_sub(_op2_030005A4, _rn_030005A4, _r_030005A4);
    g_cpu.R[3] = _r_030005A4;
    g_cpu.R[15] = 0x030005A8u;
    runtime_tick(_cyc_030005A4);
    /* 030005A8  030005a8 A orrcs r0,r0,#0x2 */
    g_cpu.R[15] = 0x030005A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005A8 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030005A8 = 1u;
        uint32_t _rn_030005A8 = g_cpu.R[0];
        uint32_t _r_030005A8;
        _r_030005A8 = _rn_030005A8 | 0x00000002u;
        g_cpu.R[0] = _r_030005A8;
    }
    g_cpu.R[15] = 0x030005ACu;
    runtime_tick(_cyc_030005A8);
    /* 030005AC  030005ac A subcs r1,r1,r2,lsl #1 */
    g_cpu.R[15] = 0x030005ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005AC = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030005AC = 1u;
        uint32_t _rm_030005AC = g_cpu.R[2];
        uint32_t _op2_030005AC;
        uint32_t _co_030005AC;
        _op2_030005AC = _rm_030005AC << 1;
        _co_030005AC = (_rm_030005AC >> 31) & 1u;
        uint32_t _rn_030005AC = g_cpu.R[1];
        uint32_t _r_030005AC;
        _r_030005AC = _rn_030005AC - _op2_030005AC;
        g_cpu.R[1] = _r_030005AC;
    }
    g_cpu.R[15] = 0x030005B0u;
    runtime_tick(_cyc_030005AC);
    /* 030005B0  030005b0 A rsbs r3,r2,r1 */
    g_cpu.R[15] = 0x030005B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005B0 = 1u;
    _cyc_030005B0 = 1u;
    uint32_t _rm_030005B0 = g_cpu.R[1];
    uint32_t _op2_030005B0;
    uint32_t _co_030005B0;
    _op2_030005B0 = _rm_030005B0;
    _co_030005B0 = cpsr_c();
    uint32_t _rn_030005B0 = g_cpu.R[2];
    uint32_t _r_030005B0;
    _r_030005B0 = _op2_030005B0 - _rn_030005B0;
    arm_set_nzcv_sub(_op2_030005B0, _rn_030005B0, _r_030005B0);
    g_cpu.R[3] = _r_030005B0;
    g_cpu.R[15] = 0x030005B4u;
    runtime_tick(_cyc_030005B0);
    /* 030005B4  030005b4 A orrcs r0,r0,#0x1 */
    g_cpu.R[15] = 0x030005B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005B4 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030005B4 = 1u;
        uint32_t _rn_030005B4 = g_cpu.R[0];
        uint32_t _r_030005B4;
        _r_030005B4 = _rn_030005B4 | 0x00000001u;
        g_cpu.R[0] = _r_030005B4;
    }
    g_cpu.R[15] = 0x030005B8u;
    runtime_tick(_cyc_030005B4);
    /* 030005B8  030005b8 A subcs r1,r1,r2 */
    g_cpu.R[15] = 0x030005B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005B8 = 1u;
    if (arm_cond_passes(0x2u)) {
        _cyc_030005B8 = 1u;
        uint32_t _rm_030005B8 = g_cpu.R[2];
        uint32_t _op2_030005B8;
        uint32_t _co_030005B8;
        _op2_030005B8 = _rm_030005B8;
        _co_030005B8 = cpsr_c();
        uint32_t _rn_030005B8 = g_cpu.R[1];
        uint32_t _r_030005B8;
        _r_030005B8 = _rn_030005B8 - _op2_030005B8;
        g_cpu.R[1] = _r_030005B8;
    }
    g_cpu.R[15] = 0x030005BCu;
    runtime_tick(_cyc_030005B8);
    /* 030005BC  030005bc A bx r14 */
    g_cpu.R[15] = 0x030005BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005BC = 1u;
    _cyc_030005BC = 3u;
    uint32_t _bxt_030005BC = g_cpu.R[14];
    g_cpu.R[15] = _bxt_030005BC & ~1u;
    runtime_tick(_cyc_030005BC);
    if (_bxt_030005BC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030005BC);
    return;
    g_cpu.R[15] = 0x030005C0u;
    runtime_tick(_cyc_030005BC);
    /* fall-through to 0x030005C0 */
    g_cpu.R[15] = 0x030005C0u;
    runtime_dispatch(0x030005C0u);
    return;
}

/* 0x0300064C  mode=arm  end=0x03000658  branches=0  indirect */


/* 0x030005C0 arm */
void gf_iwram_rle_huffman_decompress(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030005C0u);
    /* 030005C0  030005c0 A ldrb r2,[r0],#0x1 */
    g_cpu.R[15] = 0x030005C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005C0 = 1u;
    _cyc_030005C0 = 2u;
    uint32_t _base_030005C0 = g_cpu.R[0];
    uint32_t _off_030005C0;
    _off_030005C0 = 0x00000001u;
    uint32_t _ea_030005C0 = _base_030005C0;
    uint32_t _post_030005C0 = _base_030005C0 + _off_030005C0;
    _cyc_030005C0 += runtime_mem_cycles(_ea_030005C0, 1u, 0u);
    uint32_t _v_030005C0;
    _v_030005C0 = bus_read_u8(_ea_030005C0);
    if (0u != 2u) g_cpu.R[0] = _post_030005C0;
    g_cpu.R[2] = _v_030005C0;
    g_cpu.R[15] = 0x030005C4u;
    runtime_tick(_cyc_030005C0);
    /* 030005C4  030005c4 A ldrb r3,[r0],#0x1 */
    g_cpu.R[15] = 0x030005C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005C4 = 1u;
    _cyc_030005C4 = 2u;
    uint32_t _base_030005C4 = g_cpu.R[0];
    uint32_t _off_030005C4;
    _off_030005C4 = 0x00000001u;
    uint32_t _ea_030005C4 = _base_030005C4;
    uint32_t _post_030005C4 = _base_030005C4 + _off_030005C4;
    _cyc_030005C4 += runtime_mem_cycles(_ea_030005C4, 1u, 0u);
    uint32_t _v_030005C4;
    _v_030005C4 = bus_read_u8(_ea_030005C4);
    if (0u != 3u) g_cpu.R[0] = _post_030005C4;
    g_cpu.R[3] = _v_030005C4;
    g_cpu.R[15] = 0x030005C8u;
    runtime_tick(_cyc_030005C4);
    /* 030005C8  030005c8 A orrs r2,r2,r3,lsl #8 */
    g_cpu.R[15] = 0x030005C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005C8 = 1u;
    _cyc_030005C8 = 1u;
    uint32_t _rm_030005C8 = g_cpu.R[3];
    uint32_t _op2_030005C8;
    uint32_t _co_030005C8;
    _op2_030005C8 = _rm_030005C8 << 8;
    _co_030005C8 = (_rm_030005C8 >> 24) & 1u;
    uint32_t _rn_030005C8 = g_cpu.R[2];
    uint32_t _r_030005C8;
    _r_030005C8 = _rn_030005C8 | _op2_030005C8;
    arm_set_nzc_logic(_r_030005C8, _co_030005C8);
    g_cpu.R[2] = _r_030005C8;
    g_cpu.R[15] = 0x030005CCu;
    runtime_tick(_cyc_030005C8);
    /* 030005CC  030005cc A bxeq r14 */
    g_cpu.R[15] = 0x030005CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005CC = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_030005CC = 3u;
        uint32_t _bxt_030005CC = g_cpu.R[14];
        g_cpu.R[15] = _bxt_030005CC & ~1u;
        runtime_tick(_cyc_030005CC);
        if (_bxt_030005CC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
        if (runtime_call_should_return(g_cpu.R[15])) return;
        runtime_dispatch_with_exchange(_bxt_030005CC);
        return;
    }
    g_cpu.R[15] = 0x030005D0u;
    runtime_tick(_cyc_030005CC);
    /* fall-through to 0x030005D0 */
    g_cpu.R[15] = 0x030005D0u;
    runtime_dispatch(0x030005D0u);
    return;
}

/* 0x03001388  mode=arm  end=0x03001398  branches=0  indirect */


/* 0x030005D0 arm */
void gf_iwram_fast_ram_work_entry_pick(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030005D0u);
    /* 030005D0  030005d0 A stm r13!,{r5,r6,r7} */
    g_cpu.R[15] = 0x030005D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005D0 = 1u;
    _cyc_030005D0 = 1u;
    uint32_t _b_030005D0 = g_cpu.R[13];
    uint32_t _a_030005D0 = _b_030005D0 - 12u;
    uint32_t _fb_030005D0 = _b_030005D0 - 12u;
    _cyc_030005D0 += runtime_mem_cycles(_a_030005D0 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030005D0u, _a_030005D0 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030005D0 & ~3u, g_cpu.R[5]);
    _a_030005D0 += 4u;
    _cyc_030005D0 += runtime_mem_cycles(_a_030005D0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030005D0u, _a_030005D0 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030005D0 & ~3u, g_cpu.R[6]);
    _a_030005D0 += 4u;
    _cyc_030005D0 += runtime_mem_cycles(_a_030005D0 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030005D0u, _a_030005D0 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030005D0 & ~3u, g_cpu.R[7]);
    _a_030005D0 += 4u;
    g_cpu.R[13] = _fb_030005D0;
    g_cpu.R[15] = 0x030005D4u;
    runtime_tick(_cyc_030005D0);
    /* 030005D4  030005d4 A mov r6,r0 */
    g_cpu.R[15] = 0x030005D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005D4 = 1u;
    _cyc_030005D4 = 1u;
    uint32_t _rm_030005D4 = g_cpu.R[0];
    uint32_t _op2_030005D4;
    uint32_t _co_030005D4;
    _op2_030005D4 = _rm_030005D4;
    _co_030005D4 = cpsr_c();
    uint32_t _r_030005D4;
    _r_030005D4 = _op2_030005D4;
    g_cpu.R[6] = _r_030005D4;
    g_cpu.R[15] = 0x030005D8u;
    runtime_tick(_cyc_030005D4);
    /* 030005D8  030005d8 A add r2,r2,r0 */
    g_cpu.R[15] = 0x030005D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005D8 = 1u;
    _cyc_030005D8 = 1u;
    uint32_t _rm_030005D8 = g_cpu.R[0];
    uint32_t _op2_030005D8;
    uint32_t _co_030005D8;
    _op2_030005D8 = _rm_030005D8;
    _co_030005D8 = cpsr_c();
    uint32_t _rn_030005D8 = g_cpu.R[2];
    uint32_t _r_030005D8;
    _r_030005D8 = _rn_030005D8 + _op2_030005D8;
    g_cpu.R[2] = _r_030005D8;
    g_cpu.R[15] = 0x030005DCu;
    runtime_tick(_cyc_030005D8);
    /* 030005DC  030005dc A sub r2,r2,#0x2 */
    g_cpu.R[15] = 0x030005DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005DC = 1u;
    _cyc_030005DC = 1u;
    uint32_t _rn_030005DC = g_cpu.R[2];
    uint32_t _r_030005DC;
    _r_030005DC = _rn_030005DC - 0x00000002u;
    g_cpu.R[2] = _r_030005DC;
    g_cpu.R[15] = 0x030005E0u;
    runtime_tick(_cyc_030005DC);
    /* fall-through to 0x030005E0 */
    g_cpu.R[15] = 0x030005E0u;
    runtime_dispatch(0x030005E0u);
    return;
}

/* 0x030005E8  mode=arm  end=0x03000608  branches=3 */


/* 0x030005E0 arm */
void gf_iwram_fast_ram_work_entry_filter(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030005E0u);
    /* 030005E0  030005e0 A ldrb r3,[r2],#0x1 */
    g_cpu.R[15] = 0x030005E0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005E0 = 1u;
    _cyc_030005E0 = 2u;
    uint32_t _base_030005E0 = g_cpu.R[2];
    uint32_t _off_030005E0;
    _off_030005E0 = 0x00000001u;
    uint32_t _ea_030005E0 = _base_030005E0;
    uint32_t _post_030005E0 = _base_030005E0 + _off_030005E0;
    _cyc_030005E0 += runtime_mem_cycles(_ea_030005E0, 1u, 0u);
    uint32_t _v_030005E0;
    _v_030005E0 = bus_read_u8(_ea_030005E0);
    if (2u != 3u) g_cpu.R[2] = _post_030005E0;
    g_cpu.R[3] = _v_030005E0;
    g_cpu.R[15] = 0x030005E4u;
    runtime_tick(_cyc_030005E0);
    /* 030005E4  030005e4 A orr r3,r3,#0x100 */
    g_cpu.R[15] = 0x030005E4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005E4 = 1u;
    _cyc_030005E4 = 1u;
    uint32_t _rn_030005E4 = g_cpu.R[3];
    uint32_t _r_030005E4;
    _r_030005E4 = _rn_030005E4 | 0x00000100u;
    g_cpu.R[3] = _r_030005E4;
    g_cpu.R[15] = 0x030005E8u;
    runtime_tick(_cyc_030005E4);
    /* fall-through to 0x030005E8 */
    g_cpu.R[15] = 0x030005E8u;
    runtime_dispatch(0x030005E8u);
    return;
}

/* 0x03000608  mode=arm  end=0x03000630  branches=3 */


/* 0x030005E8 arm */
void gf_iwram_fast_ram_work_entry_test(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030005E8u);
L_030005E8:
    /* 030005E8  030005e8 A movs r3,r3,lsr #1 */
    g_cpu.R[15] = 0x030005E8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005E8 = 1u;
    _cyc_030005E8 = 1u;
    uint32_t _rm_030005E8 = g_cpu.R[3];
    uint32_t _op2_030005E8;
    uint32_t _co_030005E8;
    _op2_030005E8 = _rm_030005E8 >> 1;
    _co_030005E8 = (_rm_030005E8 >> 0) & 1u;
    uint32_t _r_030005E8;
    _r_030005E8 = _op2_030005E8;
    arm_set_nzc_logic(_r_030005E8, _co_030005E8);
    g_cpu.R[3] = _r_030005E8;
    g_cpu.R[15] = 0x030005ECu;
    runtime_tick(_cyc_030005E8);
    /* 030005EC  030005ec A bcc 0x03000608 */
    g_cpu.R[15] = 0x030005ECu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005EC = 1u;
    if (arm_cond_passes(0x3u)) {
        _cyc_030005EC = 3u;
        g_cpu.R[15] = 0x03000608u;
        runtime_tick(_cyc_030005EC);
        gf_iwram_fast_ram_work_entry_verify();
        return;
    }
    g_cpu.R[15] = 0x030005F0u;
    runtime_tick(_cyc_030005EC);
    /* 030005F0  030005f0 A beq 0x030005e0 */
    g_cpu.R[15] = 0x030005F0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005F0 = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_030005F0 = 3u;
        g_cpu.R[15] = 0x030005E0u;
        runtime_tick(_cyc_030005F0);
        gf_iwram_fast_ram_work_entry_filter();
        return;
    }
    g_cpu.R[15] = 0x030005F4u;
    runtime_tick(_cyc_030005F0);
    /* 030005F4  030005f4 A ldrb r4,[r0],#0x1 */
    g_cpu.R[15] = 0x030005F4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005F4 = 1u;
    _cyc_030005F4 = 2u;
    uint32_t _base_030005F4 = g_cpu.R[0];
    uint32_t _off_030005F4;
    _off_030005F4 = 0x00000001u;
    uint32_t _ea_030005F4 = _base_030005F4;
    uint32_t _post_030005F4 = _base_030005F4 + _off_030005F4;
    _cyc_030005F4 += runtime_mem_cycles(_ea_030005F4, 1u, 0u);
    uint32_t _v_030005F4;
    _v_030005F4 = bus_read_u8(_ea_030005F4);
    if (0u != 4u) g_cpu.R[0] = _post_030005F4;
    g_cpu.R[4] = _v_030005F4;
    g_cpu.R[15] = 0x030005F8u;
    runtime_tick(_cyc_030005F4);
    /* 030005F8  030005f8 A subs r5,r4,#0xdf */
    g_cpu.R[15] = 0x030005F8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005F8 = 1u;
    _cyc_030005F8 = 1u;
    uint32_t _rn_030005F8 = g_cpu.R[4];
    uint32_t _r_030005F8;
    _r_030005F8 = _rn_030005F8 - 0x000000DFu;
    arm_set_nzcv_sub(_rn_030005F8, 0x000000DFu, _r_030005F8);
    g_cpu.R[5] = _r_030005F8;
    g_cpu.R[15] = 0x030005FCu;
    runtime_tick(_cyc_030005F8);
    /* 030005FC  030005fc A addhi r1,r1,r5 */
    g_cpu.R[15] = 0x030005FCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030005FC = 1u;
    if (arm_cond_passes(0x8u)) {
        _cyc_030005FC = 1u;
        uint32_t _rm_030005FC = g_cpu.R[5];
        uint32_t _op2_030005FC;
        uint32_t _co_030005FC;
        _op2_030005FC = _rm_030005FC;
        _co_030005FC = cpsr_c();
        uint32_t _rn_030005FC = g_cpu.R[1];
        uint32_t _r_030005FC;
        _r_030005FC = _rn_030005FC + _op2_030005FC;
        g_cpu.R[1] = _r_030005FC;
    }
    g_cpu.R[15] = 0x03000600u;
    runtime_tick(_cyc_030005FC);
    /* 03000600  03000600 A strbls r4,[r1],#0x1 */
    g_cpu.R[15] = 0x03000600u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000600 = 1u;
    if (arm_cond_passes(0x9u)) {
        _cyc_03000600 = 1u;
        uint32_t _base_03000600 = g_cpu.R[1];
        uint32_t _off_03000600;
        _off_03000600 = 0x00000001u;
        uint32_t _ea_03000600 = _base_03000600;
        uint32_t _post_03000600 = _base_03000600 + _off_03000600;
        _cyc_03000600 += runtime_mem_cycles(_ea_03000600, 1u, 0u);
        runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03000600u, _ea_03000600, (uint32_t)(g_cpu.R[4] & 0xFFu), 1u);
        bus_write_u8(_ea_03000600, (uint8_t)(g_cpu.R[4] & 0xFFu));
        g_cpu.R[1] = _post_03000600;
    }
    g_cpu.R[15] = 0x03000604u;
    runtime_tick(_cyc_03000600);
    /* 03000604  03000604 A b 0x030005e8 */
    g_cpu.R[15] = 0x03000604u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000604 = 1u;
    _cyc_03000604 = 3u;
    g_cpu.R[15] = 0x030005E8u;
    runtime_trace_event(RUNTIME_TRACE_BRANCH, 0x03000604u, 0x030005E8u, 0u, 0u);
    runtime_tick(_cyc_03000604);
    goto L_030005E8;
    g_cpu.R[15] = 0x03000608u;
    runtime_tick(_cyc_03000604);
    /* fall-through to 0x03000608 */
    g_cpu.R[15] = 0x03000608u;
    runtime_dispatch(0x03000608u);
    return;
}

/* 0x030013B0  mode=arm  end=0x030013B8  branches=3  indirect */


/* 0x03000608 arm */
void gf_iwram_fast_ram_work_entry_verify(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000608u);
    /* 03000608  03000608 A ldrb r4,[r2],#0x1 */
    g_cpu.R[15] = 0x03000608u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000608 = 1u;
    _cyc_03000608 = 2u;
    uint32_t _base_03000608 = g_cpu.R[2];
    uint32_t _off_03000608;
    _off_03000608 = 0x00000001u;
    uint32_t _ea_03000608 = _base_03000608;
    uint32_t _post_03000608 = _base_03000608 + _off_03000608;
    _cyc_03000608 += runtime_mem_cycles(_ea_03000608, 1u, 0u);
    uint32_t _v_03000608;
    _v_03000608 = bus_read_u8(_ea_03000608);
    if (2u != 4u) g_cpu.R[2] = _post_03000608;
    g_cpu.R[4] = _v_03000608;
    g_cpu.R[15] = 0x0300060Cu;
    runtime_tick(_cyc_03000608);
    /* 0300060C  0300060c A ldrb r12,[r2],#0x1 */
    g_cpu.R[15] = 0x0300060Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300060C = 1u;
    _cyc_0300060C = 2u;
    uint32_t _base_0300060C = g_cpu.R[2];
    uint32_t _off_0300060C;
    _off_0300060C = 0x00000001u;
    uint32_t _ea_0300060C = _base_0300060C;
    uint32_t _post_0300060C = _base_0300060C + _off_0300060C;
    _cyc_0300060C += runtime_mem_cycles(_ea_0300060C, 1u, 0u);
    uint32_t _v_0300060C;
    _v_0300060C = bus_read_u8(_ea_0300060C);
    if (2u != 12u) g_cpu.R[2] = _post_0300060C;
    g_cpu.R[12] = _v_0300060C;
    g_cpu.R[15] = 0x03000610u;
    runtime_tick(_cyc_0300060C);
    /* 03000610  03000610 A orrs r4,r12,r4,lsl #8 */
    g_cpu.R[15] = 0x03000610u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000610 = 1u;
    _cyc_03000610 = 1u;
    uint32_t _rm_03000610 = g_cpu.R[4];
    uint32_t _op2_03000610;
    uint32_t _co_03000610;
    _op2_03000610 = _rm_03000610 << 8;
    _co_03000610 = (_rm_03000610 >> 24) & 1u;
    uint32_t _rn_03000610 = g_cpu.R[12];
    uint32_t _r_03000610;
    _r_03000610 = _rn_03000610 | _op2_03000610;
    arm_set_nzc_logic(_r_03000610, _co_03000610);
    g_cpu.R[4] = _r_03000610;
    g_cpu.R[15] = 0x03000614u;
    runtime_tick(_cyc_03000610);
    /* 03000614  03000614 A beq 0x0300064c */
    g_cpu.R[15] = 0x03000614u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000614 = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_03000614 = 3u;
        g_cpu.R[15] = 0x0300064Cu;
        runtime_tick(_cyc_03000614);
        gf_iwram_fast_ram_work_entry_clamp();
        return;
    }
    g_cpu.R[15] = 0x03000618u;
    runtime_tick(_cyc_03000614);
    /* 03000618  03000618 A bic r12,r4,#0xf000 */
    g_cpu.R[15] = 0x03000618u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000618 = 1u;
    _cyc_03000618 = 1u;
    uint32_t _rn_03000618 = g_cpu.R[4];
    uint32_t _r_03000618;
    _r_03000618 = _rn_03000618 & ~(0x0000F000u);
    g_cpu.R[12] = _r_03000618;
    g_cpu.R[15] = 0x0300061Cu;
    runtime_tick(_cyc_03000618);
    /* 0300061C  0300061c A sub r12,r6,r12 */
    g_cpu.R[15] = 0x0300061Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300061C = 1u;
    _cyc_0300061C = 1u;
    uint32_t _rm_0300061C = g_cpu.R[12];
    uint32_t _op2_0300061C;
    uint32_t _co_0300061C;
    _op2_0300061C = _rm_0300061C;
    _co_0300061C = cpsr_c();
    uint32_t _rn_0300061C = g_cpu.R[6];
    uint32_t _r_0300061C;
    _r_0300061C = _rn_0300061C - _op2_0300061C;
    g_cpu.R[12] = _r_0300061C;
    g_cpu.R[15] = 0x03000620u;
    runtime_tick(_cyc_0300061C);
    /* 03000620  03000620 A movs r4,r4,lsr #12 */
    g_cpu.R[15] = 0x03000620u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000620 = 1u;
    _cyc_03000620 = 1u;
    uint32_t _rm_03000620 = g_cpu.R[4];
    uint32_t _op2_03000620;
    uint32_t _co_03000620;
    _op2_03000620 = _rm_03000620 >> 12;
    _co_03000620 = (_rm_03000620 >> 11) & 1u;
    uint32_t _r_03000620;
    _r_03000620 = _op2_03000620;
    arm_set_nzc_logic(_r_03000620, _co_03000620);
    g_cpu.R[4] = _r_03000620;
    g_cpu.R[15] = 0x03000624u;
    runtime_tick(_cyc_03000620);
    /* 03000624  03000624 A ldrbeq r4,[r2],#0x1 */
    g_cpu.R[15] = 0x03000624u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000624 = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_03000624 = 2u;
        uint32_t _base_03000624 = g_cpu.R[2];
        uint32_t _off_03000624;
        _off_03000624 = 0x00000001u;
        uint32_t _ea_03000624 = _base_03000624;
        uint32_t _post_03000624 = _base_03000624 + _off_03000624;
        _cyc_03000624 += runtime_mem_cycles(_ea_03000624, 1u, 0u);
        uint32_t _v_03000624;
        _v_03000624 = bus_read_u8(_ea_03000624);
        if (2u != 4u) g_cpu.R[2] = _post_03000624;
        g_cpu.R[4] = _v_03000624;
    }
    g_cpu.R[15] = 0x03000628u;
    runtime_tick(_cyc_03000624);
    /* 03000628  03000628 A addeq r4,r4,#0x10 */
    g_cpu.R[15] = 0x03000628u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000628 = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_03000628 = 1u;
        uint32_t _rn_03000628 = g_cpu.R[4];
        uint32_t _r_03000628;
        _r_03000628 = _rn_03000628 + 0x00000010u;
        g_cpu.R[4] = _r_03000628;
    }
    g_cpu.R[15] = 0x0300062Cu;
    runtime_tick(_cyc_03000628);
    /* 0300062C  0300062c A add r4,r4,#0x1 */
    g_cpu.R[15] = 0x0300062Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300062C = 1u;
    _cyc_0300062C = 1u;
    uint32_t _rn_0300062C = g_cpu.R[4];
    uint32_t _r_0300062C;
    _r_0300062C = _rn_0300062C + 0x00000001u;
    g_cpu.R[4] = _r_0300062C;
    g_cpu.R[15] = 0x03000630u;
    runtime_tick(_cyc_0300062C);
    /* fall-through to 0x03000630 */
    g_cpu.R[15] = 0x03000630u;
    runtime_dispatch(0x03000630u);
    return;
}

/* 0x030013E8  mode=arm  end=0x030013F8  branches=1  indirect */


/* 0x03000630 arm */
void gf_iwram_fast_ram_work_entry_validate(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03000630u);
L_03000630:
    /* 03000630  03000630 A ldrb r5,[r12],#0x1 */
    g_cpu.R[15] = 0x03000630u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000630 = 1u;
    _cyc_03000630 = 2u;
    uint32_t _base_03000630 = g_cpu.R[12];
    uint32_t _off_03000630;
    _off_03000630 = 0x00000001u;
    uint32_t _ea_03000630 = _base_03000630;
    uint32_t _post_03000630 = _base_03000630 + _off_03000630;
    _cyc_03000630 += runtime_mem_cycles(_ea_03000630, 1u, 0u);
    uint32_t _v_03000630;
    _v_03000630 = bus_read_u8(_ea_03000630);
    if (12u != 5u) g_cpu.R[12] = _post_03000630;
    g_cpu.R[5] = _v_03000630;
    g_cpu.R[15] = 0x03000634u;
    runtime_tick(_cyc_03000630);
    /* 03000634  03000634 A subs r7,r5,#0xdf */
    g_cpu.R[15] = 0x03000634u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000634 = 1u;
    _cyc_03000634 = 1u;
    uint32_t _rn_03000634 = g_cpu.R[5];
    uint32_t _r_03000634;
    _r_03000634 = _rn_03000634 - 0x000000DFu;
    arm_set_nzcv_sub(_rn_03000634, 0x000000DFu, _r_03000634);
    g_cpu.R[7] = _r_03000634;
    g_cpu.R[15] = 0x03000638u;
    runtime_tick(_cyc_03000634);
    /* 03000638  03000638 A addhi r1,r1,r7 */
    g_cpu.R[15] = 0x03000638u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000638 = 1u;
    if (arm_cond_passes(0x8u)) {
        _cyc_03000638 = 1u;
        uint32_t _rm_03000638 = g_cpu.R[7];
        uint32_t _op2_03000638;
        uint32_t _co_03000638;
        _op2_03000638 = _rm_03000638;
        _co_03000638 = cpsr_c();
        uint32_t _rn_03000638 = g_cpu.R[1];
        uint32_t _r_03000638;
        _r_03000638 = _rn_03000638 + _op2_03000638;
        g_cpu.R[1] = _r_03000638;
    }
    g_cpu.R[15] = 0x0300063Cu;
    runtime_tick(_cyc_03000638);
    /* 0300063C  0300063c A strbls r5,[r1],#0x1 */
    g_cpu.R[15] = 0x0300063Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300063C = 1u;
    if (arm_cond_passes(0x9u)) {
        _cyc_0300063C = 1u;
        uint32_t _base_0300063C = g_cpu.R[1];
        uint32_t _off_0300063C;
        _off_0300063C = 0x00000001u;
        uint32_t _ea_0300063C = _base_0300063C;
        uint32_t _post_0300063C = _base_0300063C + _off_0300063C;
        _cyc_0300063C += runtime_mem_cycles(_ea_0300063C, 1u, 0u);
        runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300063Cu, _ea_0300063C, (uint32_t)(g_cpu.R[5] & 0xFFu), 1u);
        bus_write_u8(_ea_0300063C, (uint8_t)(g_cpu.R[5] & 0xFFu));
        g_cpu.R[1] = _post_0300063C;
    }
    g_cpu.R[15] = 0x03000640u;
    runtime_tick(_cyc_0300063C);
    /* 03000640  03000640 A subs r4,r4,#0x1 */
    g_cpu.R[15] = 0x03000640u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000640 = 1u;
    _cyc_03000640 = 1u;
    uint32_t _rn_03000640 = g_cpu.R[4];
    uint32_t _r_03000640;
    _r_03000640 = _rn_03000640 - 0x00000001u;
    arm_set_nzcv_sub(_rn_03000640, 0x00000001u, _r_03000640);
    g_cpu.R[4] = _r_03000640;
    g_cpu.R[15] = 0x03000644u;
    runtime_tick(_cyc_03000640);
    /* 03000644  03000644 A bpl 0x03000630 */
    g_cpu.R[15] = 0x03000644u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000644 = 1u;
    if (arm_cond_passes(0x5u)) {
        _cyc_03000644 = 3u;
        g_cpu.R[15] = 0x03000630u;
        runtime_trace_event(RUNTIME_TRACE_BRANCH, 0x03000644u, 0x03000630u, 0u, 0u);
        runtime_tick(_cyc_03000644);
        goto L_03000630;
    }
    g_cpu.R[15] = 0x03000648u;
    runtime_tick(_cyc_03000644);
    /* 03000648  03000648 A b 0x030005e8 */
    g_cpu.R[15] = 0x03000648u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000648 = 1u;
    _cyc_03000648 = 3u;
    g_cpu.R[15] = 0x030005E8u;
    runtime_tick(_cyc_03000648);
    gf_iwram_fast_ram_work_entry_test();
    return;
    g_cpu.R[15] = 0x0300064Cu;
    runtime_tick(_cyc_03000648);
    /* fall-through to 0x0300064C */
    g_cpu.R[15] = 0x0300064Cu;
    runtime_dispatch(0x0300064Cu);
    return;
}

/* 0x030013B8  mode=arm  end=0x030013C0  branches=3  indirect */


/* 0x0300064C arm */
void gf_iwram_fast_ram_work_entry_clamp(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x0300064Cu);
    /* 0300064C  0300064c A ldm r13!,{r5,r6,r7} */
    g_cpu.R[15] = 0x0300064Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300064C = 1u;
    _cyc_0300064C = 2u;
    uint32_t _b_0300064C = g_cpu.R[13];
    uint32_t _a_0300064C = _b_0300064C;
    uint32_t _fb_0300064C = _b_0300064C + 12u;
    _cyc_0300064C += runtime_mem_cycles(_a_0300064C & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_0300064C & ~3u);
    _a_0300064C += 4u;
    _cyc_0300064C += runtime_mem_cycles(_a_0300064C & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_0300064C & ~3u);
    _a_0300064C += 4u;
    _cyc_0300064C += runtime_mem_cycles(_a_0300064C & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_0300064C & ~3u);
    _a_0300064C += 4u;
    g_cpu.R[13] = _fb_0300064C;
    g_cpu.R[15] = 0x03000650u;
    runtime_tick(_cyc_0300064C);
    /* 03000650  03000650 A mov r0,#0x0 */
    g_cpu.R[15] = 0x03000650u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000650 = 1u;
    _cyc_03000650 = 1u;
    uint32_t _r_03000650;
    _r_03000650 = 0x00000000u;
    g_cpu.R[0] = _r_03000650;
    g_cpu.R[15] = 0x03000654u;
    runtime_tick(_cyc_03000650);
    /* 03000654  03000654 A bx r14 */
    g_cpu.R[15] = 0x03000654u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03000654 = 1u;
    _cyc_03000654 = 3u;
    uint32_t _bxt_03000654 = g_cpu.R[14];
    g_cpu.R[15] = _bxt_03000654 & ~1u;
    runtime_tick(_cyc_03000654);
    if (_bxt_03000654 & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_03000654);
    return;
    g_cpu.R[15] = 0x03000658u;
    runtime_tick(_cyc_03000654);
    /* fall-through to 0x03000658 */
    g_cpu.R[15] = 0x03000658u;
    runtime_dispatch(0x03000658u);
    return;
}

/* 0x080000D8  mode=thumb  end=0x080000DC  branches=1  indirect */


/* 0x03001388 arm */
void gf_iwram_fast_block_copy_words(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03001388u);
    /* 03001388  03001388 A stm r13!,{r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x03001388u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03001388 = 1u;
    _cyc_03001388 = 1u;
    uint32_t _b_03001388 = g_cpu.R[13];
    uint32_t _a_03001388 = _b_03001388 - 20u;
    uint32_t _fb_03001388 = _b_03001388 - 20u;
    _cyc_03001388 += runtime_mem_cycles(_a_03001388 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03001388u, _a_03001388 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_03001388 & ~3u, g_cpu.R[5]);
    _a_03001388 += 4u;
    _cyc_03001388 += runtime_mem_cycles(_a_03001388 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03001388u, _a_03001388 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_03001388 & ~3u, g_cpu.R[6]);
    _a_03001388 += 4u;
    _cyc_03001388 += runtime_mem_cycles(_a_03001388 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03001388u, _a_03001388 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_03001388 & ~3u, g_cpu.R[7]);
    _a_03001388 += 4u;
    _cyc_03001388 += runtime_mem_cycles(_a_03001388 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03001388u, _a_03001388 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_03001388 & ~3u, g_cpu.R[8]);
    _a_03001388 += 4u;
    _cyc_03001388 += runtime_mem_cycles(_a_03001388 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x03001388u, _a_03001388 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_03001388 & ~3u, g_cpu.R[9]);
    _a_03001388 += 4u;
    g_cpu.R[13] = _fb_03001388;
    g_cpu.R[15] = 0x0300138Cu;
    runtime_tick(_cyc_03001388);
    /* 0300138C  0300138c A ands r12,r2,#0xe0 */
    g_cpu.R[15] = 0x0300138Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300138C = 1u;
    _cyc_0300138C = 1u;
    uint32_t _rn_0300138C = g_cpu.R[2];
    uint32_t _r_0300138C;
    _r_0300138C = _rn_0300138C & 0x000000E0u;
    arm_set_nzc_logic(_r_0300138C, cpsr_c());
    g_cpu.R[12] = _r_0300138C;
    g_cpu.R[15] = 0x03001390u;
    runtime_tick(_cyc_0300138C);
    /* 03001390  03001390 A rsb r12,r12,#0xf0 */
    g_cpu.R[15] = 0x03001390u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03001390 = 1u;
    _cyc_03001390 = 1u;
    uint32_t _rn_03001390 = g_cpu.R[12];
    uint32_t _r_03001390;
    _r_03001390 = 0x000000F0u - _rn_03001390;
    g_cpu.R[12] = _r_03001390;
    g_cpu.R[15] = 0x03001394u;
    runtime_tick(_cyc_03001390);
    /* 03001394  03001394 A add r15,r15,r12,lsr #2 */
    g_cpu.R[15] = 0x03001394u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03001394 = 1u;
    _cyc_03001394 = 3u;
    uint32_t _rm_03001394 = g_cpu.R[12];
    uint32_t _op2_03001394;
    uint32_t _co_03001394;
    _op2_03001394 = _rm_03001394 >> 2;
    _co_03001394 = (_rm_03001394 >> 1) & 1u;
    uint32_t _rn_03001394 = 0x0300139Cu;
    uint32_t _r_03001394;
    _r_03001394 = _rn_03001394 + _op2_03001394;
    uint32_t _pc_03001394 = _r_03001394 & ~3u;
    g_cpu.R[15] = _pc_03001394;
    runtime_tick(_cyc_03001394);
    runtime_dispatch(_pc_03001394);
    return;
    g_cpu.R[15] = 0x03001398u;
    runtime_tick(_cyc_03001394);
    /* fall-through to 0x03001398 */
    g_cpu.R[15] = 0x03001398u;
    runtime_dispatch(0x03001398u);
    return;
}

/* 0x08000100  mode=thumb  end=0x08000104  branches=1  indirect */


/* 0x03001398 arm */
void gf_iwram_fast_block_copy_unroll_alpha(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x03001398u);
    /* 03001398  03001398 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x03001398u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_03001398 = 1u;
    _cyc_03001398 = 2u;
    uint32_t _b_03001398 = g_cpu.R[1];
    uint32_t _a_03001398 = _b_03001398;
    uint32_t _fb_03001398 = _b_03001398 + 32u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    _cyc_03001398 += runtime_mem_cycles(_a_03001398 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_03001398 & ~3u);
    _a_03001398 += 4u;
    g_cpu.R[1] = _fb_03001398;
    g_cpu.R[15] = 0x0300139Cu;
    runtime_tick(_cyc_03001398);
    /* 0300139C  0300139c A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x0300139Cu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_0300139C = 1u;
    _cyc_0300139C = 1u;
    uint32_t _b_0300139C = g_cpu.R[0];
    uint32_t _a_0300139C = _b_0300139C;
    uint32_t _fb_0300139C = _b_0300139C + 32u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[3]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[4]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[5]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[6]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[7]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[8]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[9]);
    _a_0300139C += 4u;
    _cyc_0300139C += runtime_mem_cycles(_a_0300139C & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x0300139Cu, _a_0300139C & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_0300139C & ~3u, g_cpu.R[12]);
    _a_0300139C += 4u;
    g_cpu.R[0] = _fb_0300139C;
    g_cpu.R[15] = 0x030013A0u;
    runtime_tick(_cyc_0300139C);
    /* fall-through to 0x030013A0 */
    g_cpu.R[15] = 0x030013A0u;
    runtime_dispatch(0x030013A0u);
    return;
}

/* 0x08000000  mode=arm  end=0x08000004  branches=1 */


/* 0x030013A0 arm */
void gf_iwram_fast_block_copy_unroll_beta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013A0u);
    /* 030013A0  030013a0 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013A0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013A0 = 1u;
    _cyc_030013A0 = 2u;
    uint32_t _b_030013A0 = g_cpu.R[1];
    uint32_t _a_030013A0 = _b_030013A0;
    uint32_t _fb_030013A0 = _b_030013A0 + 32u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    _cyc_030013A0 += runtime_mem_cycles(_a_030013A0 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013A0 & ~3u);
    _a_030013A0 += 4u;
    g_cpu.R[1] = _fb_030013A0;
    g_cpu.R[15] = 0x030013A4u;
    runtime_tick(_cyc_030013A0);
    /* 030013A4  030013a4 A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013A4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013A4 = 1u;
    _cyc_030013A4 = 1u;
    uint32_t _b_030013A4 = g_cpu.R[0];
    uint32_t _a_030013A4 = _b_030013A4;
    uint32_t _fb_030013A4 = _b_030013A4 + 32u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[3]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[4]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[5]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[6]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[7]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[8]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[9]);
    _a_030013A4 += 4u;
    _cyc_030013A4 += runtime_mem_cycles(_a_030013A4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013A4u, _a_030013A4 & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013A4 & ~3u, g_cpu.R[12]);
    _a_030013A4 += 4u;
    g_cpu.R[0] = _fb_030013A4;
    g_cpu.R[15] = 0x030013A8u;
    runtime_tick(_cyc_030013A4);
    /* fall-through to 0x030013A8 */
    g_cpu.R[15] = 0x030013A8u;
    runtime_dispatch(0x030013A8u);
    return;
}

/* 0x030013A8  mode=arm  end=0x030013B0  branches=3  indirect */


/* 0x030013A8 arm */
void gf_iwram_fast_block_copy_unroll_gamma(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013A8u);
    /* 030013A8  030013a8 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013A8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013A8 = 1u;
    _cyc_030013A8 = 2u;
    uint32_t _b_030013A8 = g_cpu.R[1];
    uint32_t _a_030013A8 = _b_030013A8;
    uint32_t _fb_030013A8 = _b_030013A8 + 32u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    _cyc_030013A8 += runtime_mem_cycles(_a_030013A8 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013A8 & ~3u);
    _a_030013A8 += 4u;
    g_cpu.R[1] = _fb_030013A8;
    g_cpu.R[15] = 0x030013ACu;
    runtime_tick(_cyc_030013A8);
    /* 030013AC  030013ac A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013ACu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013AC = 1u;
    _cyc_030013AC = 1u;
    uint32_t _b_030013AC = g_cpu.R[0];
    uint32_t _a_030013AC = _b_030013AC;
    uint32_t _fb_030013AC = _b_030013AC + 32u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[3]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[4]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[5]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[6]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[7]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[8]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[9]);
    _a_030013AC += 4u;
    _cyc_030013AC += runtime_mem_cycles(_a_030013AC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ACu, _a_030013AC & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013AC & ~3u, g_cpu.R[12]);
    _a_030013AC += 4u;
    g_cpu.R[0] = _fb_030013AC;
    g_cpu.R[15] = 0x030013B0u;
    runtime_tick(_cyc_030013AC);
    /* fall-through to 0x030013B0 */
    g_cpu.R[15] = 0x030013B0u;
    runtime_dispatch(0x030013B0u);
    return;
}

/* 0x08000158  mode=thumb  end=0x0800015C  branches=1  indirect */


/* 0x030013B0 arm */
void gf_iwram_fast_block_copy_unroll_delta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013B0u);
    /* 030013B0  030013b0 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013B0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013B0 = 1u;
    _cyc_030013B0 = 2u;
    uint32_t _b_030013B0 = g_cpu.R[1];
    uint32_t _a_030013B0 = _b_030013B0;
    uint32_t _fb_030013B0 = _b_030013B0 + 32u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    _cyc_030013B0 += runtime_mem_cycles(_a_030013B0 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013B0 & ~3u);
    _a_030013B0 += 4u;
    g_cpu.R[1] = _fb_030013B0;
    g_cpu.R[15] = 0x030013B4u;
    runtime_tick(_cyc_030013B0);
    /* 030013B4  030013b4 A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013B4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013B4 = 1u;
    _cyc_030013B4 = 1u;
    uint32_t _b_030013B4 = g_cpu.R[0];
    uint32_t _a_030013B4 = _b_030013B4;
    uint32_t _fb_030013B4 = _b_030013B4 + 32u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[3]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[4]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[5]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[6]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[7]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[8]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[9]);
    _a_030013B4 += 4u;
    _cyc_030013B4 += runtime_mem_cycles(_a_030013B4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013B4u, _a_030013B4 & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013B4 & ~3u, g_cpu.R[12]);
    _a_030013B4 += 4u;
    g_cpu.R[0] = _fb_030013B4;
    g_cpu.R[15] = 0x030013B8u;
    runtime_tick(_cyc_030013B4);
    /* fall-through to 0x030013B8 */
    g_cpu.R[15] = 0x030013B8u;
    runtime_dispatch(0x030013B8u);
    return;
}

/* 0x030013C0  mode=arm  end=0x030013C8  branches=3  indirect */


/* 0x030013B8 arm */
void gf_iwram_fast_block_copy_unroll_epsilon(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013B8u);
    /* 030013B8  030013b8 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013B8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013B8 = 1u;
    _cyc_030013B8 = 2u;
    uint32_t _b_030013B8 = g_cpu.R[1];
    uint32_t _a_030013B8 = _b_030013B8;
    uint32_t _fb_030013B8 = _b_030013B8 + 32u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    _cyc_030013B8 += runtime_mem_cycles(_a_030013B8 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013B8 & ~3u);
    _a_030013B8 += 4u;
    g_cpu.R[1] = _fb_030013B8;
    g_cpu.R[15] = 0x030013BCu;
    runtime_tick(_cyc_030013B8);
    /* 030013BC  030013bc A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013BCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013BC = 1u;
    _cyc_030013BC = 1u;
    uint32_t _b_030013BC = g_cpu.R[0];
    uint32_t _a_030013BC = _b_030013BC;
    uint32_t _fb_030013BC = _b_030013BC + 32u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[3]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[4]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[5]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[6]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[7]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[8]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[9]);
    _a_030013BC += 4u;
    _cyc_030013BC += runtime_mem_cycles(_a_030013BC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013BCu, _a_030013BC & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013BC & ~3u, g_cpu.R[12]);
    _a_030013BC += 4u;
    g_cpu.R[0] = _fb_030013BC;
    g_cpu.R[15] = 0x030013C0u;
    runtime_tick(_cyc_030013BC);
    /* fall-through to 0x030013C0 */
    g_cpu.R[15] = 0x030013C0u;
    runtime_dispatch(0x030013C0u);
    return;
}

/* 0x030013C8  mode=arm  end=0x030013D0  branches=3  indirect */


/* 0x030013C0 arm */
void gf_iwram_fast_block_copy_unroll_zeta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013C0u);
    /* 030013C0  030013c0 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013C0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013C0 = 1u;
    _cyc_030013C0 = 2u;
    uint32_t _b_030013C0 = g_cpu.R[1];
    uint32_t _a_030013C0 = _b_030013C0;
    uint32_t _fb_030013C0 = _b_030013C0 + 32u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    _cyc_030013C0 += runtime_mem_cycles(_a_030013C0 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013C0 & ~3u);
    _a_030013C0 += 4u;
    g_cpu.R[1] = _fb_030013C0;
    g_cpu.R[15] = 0x030013C4u;
    runtime_tick(_cyc_030013C0);
    /* 030013C4  030013c4 A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013C4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013C4 = 1u;
    _cyc_030013C4 = 1u;
    uint32_t _b_030013C4 = g_cpu.R[0];
    uint32_t _a_030013C4 = _b_030013C4;
    uint32_t _fb_030013C4 = _b_030013C4 + 32u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[3]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[4]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[5]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[6]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[7]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[8]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[9]);
    _a_030013C4 += 4u;
    _cyc_030013C4 += runtime_mem_cycles(_a_030013C4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013C4u, _a_030013C4 & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013C4 & ~3u, g_cpu.R[12]);
    _a_030013C4 += 4u;
    g_cpu.R[0] = _fb_030013C4;
    g_cpu.R[15] = 0x030013C8u;
    runtime_tick(_cyc_030013C4);
    /* fall-through to 0x030013C8 */
    g_cpu.R[15] = 0x030013C8u;
    runtime_dispatch(0x030013C8u);
    return;
}

/* 0x08000260  mode=thumb  end=0x08000264  branches=1  indirect */


/* 0x030013C8 arm */
void gf_iwram_fast_block_copy_unroll_eta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013C8u);
    /* 030013C8  030013c8 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013C8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013C8 = 1u;
    _cyc_030013C8 = 2u;
    uint32_t _b_030013C8 = g_cpu.R[1];
    uint32_t _a_030013C8 = _b_030013C8;
    uint32_t _fb_030013C8 = _b_030013C8 + 32u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    _cyc_030013C8 += runtime_mem_cycles(_a_030013C8 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013C8 & ~3u);
    _a_030013C8 += 4u;
    g_cpu.R[1] = _fb_030013C8;
    g_cpu.R[15] = 0x030013CCu;
    runtime_tick(_cyc_030013C8);
    /* 030013CC  030013cc A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013CCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013CC = 1u;
    _cyc_030013CC = 1u;
    uint32_t _b_030013CC = g_cpu.R[0];
    uint32_t _a_030013CC = _b_030013CC;
    uint32_t _fb_030013CC = _b_030013CC + 32u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[3]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[4]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[5]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[6]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[7]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[8]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[9]);
    _a_030013CC += 4u;
    _cyc_030013CC += runtime_mem_cycles(_a_030013CC & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013CCu, _a_030013CC & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013CC & ~3u, g_cpu.R[12]);
    _a_030013CC += 4u;
    g_cpu.R[0] = _fb_030013CC;
    g_cpu.R[15] = 0x030013D0u;
    runtime_tick(_cyc_030013CC);
    /* fall-through to 0x030013D0 */
    g_cpu.R[15] = 0x030013D0u;
    runtime_dispatch(0x030013D0u);
    return;
}

/* 0x08000108  mode=thumb  end=0x0800010C  branches=1  indirect */


/* 0x030013D0 arm */
void gf_iwram_fast_block_copy_unroll_theta(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013D0u);
    /* 030013D0  030013d0 A ldm r1!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013D0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013D0 = 1u;
    _cyc_030013D0 = 2u;
    uint32_t _b_030013D0 = g_cpu.R[1];
    uint32_t _a_030013D0 = _b_030013D0;
    uint32_t _fb_030013D0 = _b_030013D0 + 32u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[4] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[5] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    _cyc_030013D0 += runtime_mem_cycles(_a_030013D0 & ~3u, 4u, 1u);
    g_cpu.R[12] = bus_read_u32(_a_030013D0 & ~3u);
    _a_030013D0 += 4u;
    g_cpu.R[1] = _fb_030013D0;
    g_cpu.R[15] = 0x030013D4u;
    runtime_tick(_cyc_030013D0);
    /* 030013D4  030013d4 A stm r0!,{r3,r4,r5,r6,r7,r8,r9,r12} */
    g_cpu.R[15] = 0x030013D4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013D4 = 1u;
    _cyc_030013D4 = 1u;
    uint32_t _b_030013D4 = g_cpu.R[0];
    uint32_t _a_030013D4 = _b_030013D4;
    uint32_t _fb_030013D4 = _b_030013D4 + 32u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[3]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[4], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[4]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[5], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[5]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[6], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[6]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[7], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[7]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[8], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[8]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[9], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[9]);
    _a_030013D4 += 4u;
    _cyc_030013D4 += runtime_mem_cycles(_a_030013D4 & ~3u, 4u, 1u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013D4u, _a_030013D4 & ~3u, g_cpu.R[12], 4u);
    bus_write_u32(_a_030013D4 & ~3u, g_cpu.R[12]);
    _a_030013D4 += 4u;
    g_cpu.R[0] = _fb_030013D4;
    g_cpu.R[15] = 0x030013D8u;
    runtime_tick(_cyc_030013D4);
    /* fall-through to 0x030013D8 */
    g_cpu.R[15] = 0x030013D8u;
    runtime_dispatch(0x030013D8u);
    return;
}

/* 0x08000118  mode=thumb  end=0x0800011C  branches=1  indirect */


/* 0x030013D8 arm */
void gf_iwram_fast_block_copy_unroll_iota(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013D8u);
    /* 030013D8  030013d8 A subs r2,r2,#0x100 */
    g_cpu.R[15] = 0x030013D8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013D8 = 1u;
    _cyc_030013D8 = 1u;
    uint32_t _rn_030013D8 = g_cpu.R[2];
    uint32_t _r_030013D8;
    _r_030013D8 = _rn_030013D8 - 0x00000100u;
    arm_set_nzcv_sub(_rn_030013D8, 0x00000100u, _r_030013D8);
    g_cpu.R[2] = _r_030013D8;
    g_cpu.R[15] = 0x030013DCu;
    runtime_tick(_cyc_030013D8);
    /* 030013DC  030013dc A bpl 0x03001398 */
    g_cpu.R[15] = 0x030013DCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013DC = 1u;
    if (arm_cond_passes(0x5u)) {
        _cyc_030013DC = 3u;
        g_cpu.R[15] = 0x03001398u;
        runtime_tick(_cyc_030013DC);
        gf_iwram_fast_block_copy_unroll_alpha();
        return;
    }
    g_cpu.R[15] = 0x030013E0u;
    runtime_tick(_cyc_030013DC);
    /* 030013E0  030013e0 A ands r2,r2,#0x1c */
    g_cpu.R[15] = 0x030013E0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013E0 = 1u;
    _cyc_030013E0 = 1u;
    uint32_t _rn_030013E0 = g_cpu.R[2];
    uint32_t _r_030013E0;
    _r_030013E0 = _rn_030013E0 & 0x0000001Cu;
    arm_set_nzc_logic(_r_030013E0, cpsr_c());
    g_cpu.R[2] = _r_030013E0;
    g_cpu.R[15] = 0x030013E4u;
    runtime_tick(_cyc_030013E0);
    /* 030013E4  030013e4 A beq 0x030013f8 */
    g_cpu.R[15] = 0x030013E4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013E4 = 1u;
    if (arm_cond_passes(0x0u)) {
        _cyc_030013E4 = 3u;
        g_cpu.R[15] = 0x030013F8u;
        runtime_tick(_cyc_030013E4);
        gf_iwram_fast_ram_work_entry_scale();
        return;
    }
    g_cpu.R[15] = 0x030013E8u;
    runtime_tick(_cyc_030013E4);
    /* fall-through to 0x030013E8 */
    g_cpu.R[15] = 0x030013E8u;
    runtime_dispatch(0x030013E8u);
    return;
}

/* 0x080000C8  mode=thumb  end=0x080000CC  branches=1  indirect */


/* 0x030013E8 arm */
void gf_iwram_fast_ram_work_entry_align(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013E8u);
L_030013E8:
    /* 030013E8  030013e8 A ldm r1!,{r3} */
    g_cpu.R[15] = 0x030013E8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013E8 = 1u;
    _cyc_030013E8 = 2u;
    uint32_t _b_030013E8 = g_cpu.R[1];
    uint32_t _a_030013E8 = _b_030013E8;
    uint32_t _fb_030013E8 = _b_030013E8 + 4u;
    _cyc_030013E8 += runtime_mem_cycles(_a_030013E8 & ~3u, 4u, 0u);
    g_cpu.R[3] = bus_read_u32(_a_030013E8 & ~3u);
    _a_030013E8 += 4u;
    g_cpu.R[1] = _fb_030013E8;
    g_cpu.R[15] = 0x030013ECu;
    runtime_tick(_cyc_030013E8);
    /* 030013EC  030013ec A stm r0!,{r3} */
    g_cpu.R[15] = 0x030013ECu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013EC = 1u;
    _cyc_030013EC = 1u;
    uint32_t _b_030013EC = g_cpu.R[0];
    uint32_t _a_030013EC = _b_030013EC;
    uint32_t _fb_030013EC = _b_030013EC + 4u;
    _cyc_030013EC += runtime_mem_cycles(_a_030013EC & ~3u, 4u, 0u);
    runtime_trace_event(RUNTIME_TRACE_MEM_WRITE, 0x030013ECu, _a_030013EC & ~3u, g_cpu.R[3], 4u);
    bus_write_u32(_a_030013EC & ~3u, g_cpu.R[3]);
    _a_030013EC += 4u;
    g_cpu.R[0] = _fb_030013EC;
    g_cpu.R[15] = 0x030013F0u;
    runtime_tick(_cyc_030013EC);
    /* 030013F0  030013f0 A subs r2,r2,#0x4 */
    g_cpu.R[15] = 0x030013F0u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013F0 = 1u;
    _cyc_030013F0 = 1u;
    uint32_t _rn_030013F0 = g_cpu.R[2];
    uint32_t _r_030013F0;
    _r_030013F0 = _rn_030013F0 - 0x00000004u;
    arm_set_nzcv_sub(_rn_030013F0, 0x00000004u, _r_030013F0);
    g_cpu.R[2] = _r_030013F0;
    g_cpu.R[15] = 0x030013F4u;
    runtime_tick(_cyc_030013F0);
    /* 030013F4  030013f4 A bgt 0x030013e8 */
    g_cpu.R[15] = 0x030013F4u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013F4 = 1u;
    if (arm_cond_passes(0xcu)) {
        _cyc_030013F4 = 3u;
        g_cpu.R[15] = 0x030013E8u;
        runtime_trace_event(RUNTIME_TRACE_BRANCH, 0x030013F4u, 0x030013E8u, 0u, 0u);
        runtime_tick(_cyc_030013F4);
        goto L_030013E8;
    }
    g_cpu.R[15] = 0x030013F8u;
    runtime_tick(_cyc_030013F4);
    /* fall-through to 0x030013F8 */
    g_cpu.R[15] = 0x030013F8u;
    runtime_dispatch(0x030013F8u);
    return;
}

/* 0x08000268  mode=thumb  end=0x0800026C  branches=1  indirect */


/* 0x030013F8 arm */
void gf_iwram_fast_ram_work_entry_scale(void) {
    if (g_runtime_fn_entry_hook) g_runtime_fn_entry_hook(0x030013F8u);
    /* 030013F8  030013f8 A ldm r13!,{r5,r6,r7,r8,r9} */
    g_cpu.R[15] = 0x030013F8u;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013F8 = 1u;
    _cyc_030013F8 = 2u;
    uint32_t _b_030013F8 = g_cpu.R[13];
    uint32_t _a_030013F8 = _b_030013F8;
    uint32_t _fb_030013F8 = _b_030013F8 + 20u;
    _cyc_030013F8 += runtime_mem_cycles(_a_030013F8 & ~3u, 4u, 0u);
    g_cpu.R[5] = bus_read_u32(_a_030013F8 & ~3u);
    _a_030013F8 += 4u;
    _cyc_030013F8 += runtime_mem_cycles(_a_030013F8 & ~3u, 4u, 1u);
    g_cpu.R[6] = bus_read_u32(_a_030013F8 & ~3u);
    _a_030013F8 += 4u;
    _cyc_030013F8 += runtime_mem_cycles(_a_030013F8 & ~3u, 4u, 1u);
    g_cpu.R[7] = bus_read_u32(_a_030013F8 & ~3u);
    _a_030013F8 += 4u;
    _cyc_030013F8 += runtime_mem_cycles(_a_030013F8 & ~3u, 4u, 1u);
    g_cpu.R[8] = bus_read_u32(_a_030013F8 & ~3u);
    _a_030013F8 += 4u;
    _cyc_030013F8 += runtime_mem_cycles(_a_030013F8 & ~3u, 4u, 1u);
    g_cpu.R[9] = bus_read_u32(_a_030013F8 & ~3u);
    _a_030013F8 += 4u;
    g_cpu.R[13] = _fb_030013F8;
    g_cpu.R[15] = 0x030013FCu;
    runtime_tick(_cyc_030013F8);
    /* 030013FC  030013fc A bx r14 */
    g_cpu.R[15] = 0x030013FCu;
    if (runtime_should_yield()) return;
    if (g_runtime_insn_trace) runtime_insn_fp();
    uint32_t _cyc_030013FC = 1u;
    _cyc_030013FC = 3u;
    uint32_t _bxt_030013FC = g_cpu.R[14];
    g_cpu.R[15] = _bxt_030013FC & ~1u;
    runtime_tick(_cyc_030013FC);
    if (_bxt_030013FC & 1u) g_cpu.cpsr |= CPSR_T_BIT; else g_cpu.cpsr &= ~CPSR_T_BIT;
    if (runtime_call_should_return(g_cpu.R[15])) return;
    runtime_dispatch_with_exchange(_bxt_030013FC);
    return;
    g_cpu.R[15] = 0x03001400u;
    runtime_tick(_cyc_030013FC);
    /* fall-through to 0x03001400 */
    g_cpu.R[15] = 0x03001400u;
    runtime_dispatch(0x03001400u);
    return;
}

/* 0x08000130  mode=thumb  end=0x08000134  branches=1  indirect */

