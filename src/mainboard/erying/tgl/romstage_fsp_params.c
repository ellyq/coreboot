/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/meminit.h>
#include <soc/romstage.h>
#include "gpio.h"

void mainboard_memory_init_params(FSPM_UPD *mupd)
{

	static const struct mb_cfg mem_type = {
		.type = MEM_TYPE_DDR4,
		.ddr4_config = { .dq_pins_interleaved = true },
	};
	static const struct mem_spd spd_info = {
        	.topo = MEM_TOPO_DIMM_MODULE,
		.smbus = {
			[0] = { .addr_dimm[0] = 0x50, },
			[1] = { .addr_dimm[0] = 0x52, },
		},
	};
	const bool half_populated = false;
        memcfg_init(mupd, &mem_type, &spd_info, half_populated);

	// FSP Configuration
	mupd->FspmConfig.UserBd = 1;
	mupd->FspmConfig.VtdDisable = 0;
	mupd->FspmConfig.VtdIgdEnable = 0; /* Disable VT-d for iGPU to avoid stability issues */
	mupd->FspmConfig.VmxEnable = 1;
	mupd->FspmConfig.SmbusEnable = 1;
	mupd->FspmConfig.PchIshEnable = 1;
	mupd->FspmConfig.BdatEnable = 1;

	// DMI (SoC - PCH) Link settings
	mupd->FspmConfig.DmiMaxLinkSpeed = 3;
        mupd->FspmConfig.DmiAspm = 0;
        mupd->FspmConfig.DmiAspmCtrl = 0;

	// Performance settings
	mupd->FspmConfig.HyperThreading = 1;
	mupd->FspmConfig.EnableAbove4GBMmio = 1;
	mupd->FspmConfig.OcSupport = 1;
	mupd->FspmConfig.OcLock = 0;
	mupd->FspmConfig.SaOcSupport = 1;

	/* XMP Configuration - Not functional yet! - Will result in FspNotify error 0x80000007! */
	// mupd->FspmConfig.SpdProfileSelected = 2;	
	mupd->FspmConfig.DdrFreqLimit = 3200;
	mupd->FspmConfig.RefClk = 1; // 100MHz
	mupd->FspmConfig.VddVoltage = 1350; // 1.35v
	mupd->FspmConfig.Ratio = 0;
	mupd->FspmConfig.RingDownBin = 0;
	mupd->FspmConfig.GearRatio = 1;
	mupd->FspmConfig.NModeSupport = 1;

	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
