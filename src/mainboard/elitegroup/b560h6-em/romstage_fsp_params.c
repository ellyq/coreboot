/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/meminit.h>
#include <soc/romstage.h>

static const struct mb_cfg mem_config = {
	.type = MEM_TYPE_DDR4,
	.ddr4_config = { .dq_pins_interleaved = true },
};

static const struct mem_spd spd_info = {
	.topo = MEM_TOPO_DIMM_MODULE,
	.smbus = {
		[0] = {
			.addr_dimm[0] = 0x50,
			.addr_dimm[1] = 0x51,
		},
		[1] = {
			.addr_dimm[0] = 0x52,
			.addr_dimm[1] = 0x53,
		},
	},
};

const bool half_populated = false;

void mainboard_memory_init_params(FSPM_UPD *mupd)
{
	// FSP-M settings
	mupd->FspmConfig.EnableAbove4GBMmio = 1;
	mupd->FspmConfig.SkipExtGfxScan = 0;
	mupd->FspmConfig.DmiMaxLinkSpeed = 3;
	mupd->FspmConfig.DmiAspm = 0;
	mupd->FspmConfig.DmiAspmCtrl = 0;

	// Memory settings
	mupd->FspmConfig.SpdProfileSelected = 0; // Default Profile
	mupd->FspmConfig.RefClk = 0; // 133MHz
	mupd->FspmConfig.VddVoltage = 1350; // 1.35V (Applicable only with XMP Profile 1)
	mupd->FspmConfig.Ratio = 0; // Auto
	mupd->FspmConfig.RingDownBin = 0;
	mupd->FspmConfig.GearRatio = 0; // Auto

	memcfg_init(mupd, &mem_config, &spd_info, half_populated);
}
