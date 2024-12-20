/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <spd_bin.h>
#include <fsp/api.h>
#include <soc/meminit.h>
#include <soc/romstage.h>
#include <gpio.h>

static const struct mb_cfg lp5_mem_config = {
	.type = MEM_TYPE_LP5X,
	.UserBd = BOARD_TYPE_ULT_ULX,
	.ect = 1,
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
const bool half_populated = true;

void mainboard_memory_init_params(FSPM_UPD *memupd)
{
	const struct mem_spd memory_down_spd_info = {
		.topo = MEM_TOPO_MEMORY_DOWN,
		.cbfs_index = get_spd_index(),
	};

	memcfg_init(memupd, &lp5_mem_config, &memory_down_spd_info, half_populated);
}
