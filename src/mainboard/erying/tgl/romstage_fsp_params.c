/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/meminit.h>
#include <soc/romstage.h>
#include "gpio.h"

void mainboard_memory_init_params(FSPM_UPD *mupd)
{

	static const struct mb_cfg mem_type = {
		.type = MEM_TYPE_DDR4,
		.ddr4_config = { .dq_pins_interleaved = true }, // Can this cause issue with single rank memories? disabling results in no post
	};
	static const struct mem_spd spd_info = {
		.topo = MEM_TOPO_DIMM_MODULE,
		.smbus = {
			[0] = { .addr_dimm[0] = 0x50, },
			[1] = { .addr_dimm[0] = 0x52, },
		},
	};
	const bool half_populated = false;

	// FSP Configuration
	mupd->FspmConfig.UserBd = 1;
	mupd->FspmConfig.SmbusEnable = 1;
	mupd->FspmConfig.SmbusDynamicPowerGating = 1;
	mupd->FspmConfig.PchIshEnable = 1;
	mupd->FspmConfig.DmiMaxLinkSpeed = 4;
	mupd->FspmConfig.BdatEnable = 1;
	mupd->FspmConfig.BdatTestType = 1;

	// Performance settings
	mupd->FspmConfig.VtdDisable = 0;
	mupd->FspmConfig.VmxEnable = 1;
	mupd->FspmConfig.HyperThreading = 1;
	mupd->FspmConfig.EnableAbove4GBMmio = 1;
	mupd->FspmConfig.OcSupport = 1;
	mupd->FspmConfig.OcLock = 0;
	mupd->FspmConfig.SaOcSupport = 1;

	/* XMP Configuration - Not functional yet! - Will result in FspNotify error 0x80000007! */
	// mupd->FspmConfig.SpdProfileSelected = 2;	
	mupd->FspmConfig.RefClk = 1; // 100MHz
	mupd->FspmConfig.VddVoltage = 1350; // 1.35v
	mupd->FspmConfig.Ratio = 0;
	mupd->FspmConfig.RingDownBin = 0;
	mupd->FspmConfig.GearRatio = 1;
	mupd->FspmConfig.NModeSupport = 1;
	
	// Testing
	mupd->FspmConfig.VccInMaxLimit = 2250; //Some boards have ther vcore limited due to this value, issue also present in the Erying AMI BIOS

	//mupd->FspmConfig.CpuBclkOcFrequency = 10064;  //BCLK is set to 98 MHz, this should bring it to 100MHz - This also affects Erying original BIOS

	//mupd->FspmConfig.DynamicMemoryChange = 1; 
	//mupd->FspmConfig.SaVoltageMode = 1;
	//mupd->FspmConfig.SaVoltageOverride = 1200;  // Any changes on this and the board does not boot, this might be required in order to reach some XMP profiles/Custom profiles

	// Be carefull it won't boot with wrong values - Very personal values, how can we get this more versatile?

	// mupd->FspmConfig.SpdProfileSelected = 1; // Setting customized profile, can't post with this option

	//mupd->FspmConfig.Ratio = 23; // This seems to be ignored, I believe it needs the Custom profile
	
	//Haven't get to the point of hardcoding timings
	// mupd->FspmConfig.tCL = 14;
	// mupd->FspmConfig.tRCDtRP = 14;
	// mupd->FspmConfig.tRAS = 29;
	// mupd->FspmConfig.tCWL = 12;
	// mupd->FspmConfig.tFAW = 14;
	// mupd->FspmConfig.tREFI = 65535;
	// mupd->FspmConfig.tRFC = 250;
	// mupd->FspmConfig.tRRD = 4;
	// mupd->FspmConfig.tRTP = 8;
	// mupd->FspmConfig.tWR = 16;
	// mupd->FspmConfig.tWTR = 4;



	memcfg_init(mupd, &mem_type, &spd_info, half_populated);

	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
