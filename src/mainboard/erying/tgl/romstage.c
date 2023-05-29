/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/meminit.h>
#include <soc/romstage.h>
#include <spd_bin.h>
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

	/* FSP Configuration */
	mupd->FspmConfig.GpioOverride = 0;
	mupd->FspmConfig.DmiMaxLinkSpeed = 4;
	mupd->FspmConfig.UserBd = 1;
	mupd->FspmConfig.PchHdaEnable = 1;
	mupd->FspmConfig.SmbusEnable = 1;
	mupd->FspmConfig.MemorySpdDataLen = 0x200;


	/* Performance settings */
	mupd->FspmConfig.VtdDisable = 0;
	mupd->FspmConfig.VmxEnable = 1;
	mupd->FspmConfig.HyperThreading = 1;
	mupd->FspmConfig.OcSupport = 1;
	mupd->FspmConfig.EnableAbove4GBMmio = 1;

	/* XMP Configuration - selects XMP Profile 1 by default with 1.35v and CLKREF 100MHz.
		To change those settings, refer to:
	  	3rdparty/fsp/TigerLakeFspBinPkg/Client/Include/FspmUpd.h */

	// Not functional yet! - Will result in FspNotify error 0x80000007! //
	// mupd->FspmConfig.SpdProfileSelected = 2;
	mupd->FspmConfig.RefClk = 1;
	mupd->FspmConfig.VddVoltage = 1350;

}
