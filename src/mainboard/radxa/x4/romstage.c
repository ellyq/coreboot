/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <spd_bin.h>
#include <fsp/api.h>
#include <soc/meminit.h>
#include <soc/romstage.h>
#include <gpio.h>

static const struct mb_cfg lp5_mem_config = {
	.type = MEM_TYPE_LP5X,
	.UserBd = BOARD_TYPE_ULT_ULX,
	.ect = true,
	.lp_ddr_dq_dqs_re_training = 1

	/* Board uses 100ohm rcomp resistor */
	.rcomp = {
		.resistor = 100,
	},

	/* Values copied from mb/google/brya/variants/crota.
	 * Most definitely NOT correct, need to figure out how to map it based on the schematic.
	 * Board is currently NOT booting.
	 *
	 * [DEBUG]  SPD index = 0
	 * [SPEW ]  CBFS DEBUG: _cbfs_alloc(name='spd.bin', alloc=0x00000000(0x00000000),
	 * force_ro=false, type=171)
	 * [INFO ]  CBFS: Found 'spd.bin' @0x55540 size 0x200 in mcache @0xfef8c3b8
	 * [INFO ]  SPD: module type is LPDDR5
	 * [INFO ]  SPD: module part number is
	 * [INFO ]  SPD: banks 8, ranks 1, rows 16, columns 11, density 16384 Mb
	 * [INFO ]  SPD: device width 16 bits, bus width 16 bits
	 * [INFO ]  SPD: module size is 2048 MB (per channel)
	 * [EMERG]  FspMemoryInit error, status=0x80000007
	 */

	/*
	.lpx_dq_map = {
		.ddr0 = {
			.dq0 = {  6,  14,  12,  15, 11,  10,  8,  9, },
			.dq1 = {  7,  5,  4,  6,  0,  3,  1,  2 },
		},
		.ddr1 = {
			.dq0 = {  1,  3,  0,  2,  7,  4,  6,  5, },
			.dq1 = {  12,  13,  14,  15,  11,  10,  9,  8 },
		},
		.ddr2 = {
			.dq0 = {  0,  2,  1,  3,  6,  4,  7,  5 },
			.dq1 = {  14,  13,  15,  12,  8,  11,  10,  9, },
		},
		.ddr3 = {
			.dq0 = {  6,  5,  7,  4,  2,  3,  1,  0, },
			.dq1 = {  10,  8,  11,  9,  12,  15,  13,  14 },
		},
		.ddr4 = {
			.dq0 = {  2,  1,  3,  0,  4,  7,  5,  6 },
			.dq1 = {  15,  14,  12,  13,  9,  11,  10,  8, },
		},
		.ddr5 = {
			.dq0 = {  6,  5,  7,  4,  3,  1,  0,  2, },
			.dq1 = {  10,  9,  11,  8,  13,  14,  12,  15 },
		},
		.ddr6 = {
			.dq0 = {  9,  10,  11,  8,  14,  12,  13, 15, },
			.dq1 = {  0,  1,  2,  3,  5,  7,  4,  6 },
		},
		.ddr7 = {
			.dq0 = {  0,  1,  2,  3,  7,  5,  6,  4, },
			.dq1 = {  14,  13,  15,  12,  10,  8,  11,  9 },
		},
	},

	.lpx_dqs_map = {
		.ddr0 = { .dqs0 = 1, .dqs1 = 0 },
		.ddr1 = { .dqs0 = 0, .dqs1 = 1 },
		.ddr2 = { .dqs0 = 0, .dqs1 = 1 },
		.ddr3 = { .dqs0 = 0, .dqs1 = 1 },
		.ddr4 = { .dqs0 = 0, .dqs1 = 1 },
		.ddr5 = { .dqs0 = 0, .dqs1 = 1 },
		.ddr6 = { .dqs0 = 1, .dqs1 = 0 },
		.ddr7 = { .dqs0 = 0, .dqs1 = 1 }
	}, */

};

static size_t get_spd_index(void)
{
	/* Following straps are used to configure memory:
	 * GPP_E10:GPP_E11:
	 * 0:0 == 4GB
	 * 0:1 == 8GB
	 * 1:0 == 16GB
	 * 1:1 == 32GB */
	gpio_t spd_gpios[] = {
		GPP_E10,
		GPP_E11,
	};

	return gpio_base2_value(spd_gpios, ARRAY_SIZE(spd_gpios));
};

/* ADL-N is a single-channel SoC */
bool half_populated = true;

void mainboard_memory_init_params(FSPM_UPD *memupd)
{
	const struct mem_spd memory_down_spd_info = {
		.topo = MEM_TOPO_MEMORY_DOWN,
		.cbfs_index = get_spd_index(),
	};

	memcfg_init(memupd, &lp5_mem_config, &memory_down_spd_info, half_populated);
}
