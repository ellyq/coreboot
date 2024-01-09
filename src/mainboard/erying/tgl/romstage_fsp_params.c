/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/meminit.h>
#include <soc/romstage.h>
#include "gpio.h"

static const struct mb_cfg mem_config = {
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

void mainboard_memory_init_params(FSPM_UPD *mupd)
{
	// FSP Configuration
	mupd->FspmConfig.UserBd = 1;
	mupd->FspmConfig.VmxEnable = 1;
	mupd->FspmConfig.SmbusEnable = 1;
	mupd->FspmConfig.PchIshEnable = 1;
	mupd->FspmConfig.BdatEnable = 1;
	mupd->FspmConfig.ScanExtGfxForLegacyOpRom = 1;

	mupd->FspmConfig.PrimaryDisplay = 3; // Auto
	mupd->FspmConfig.VtdDisable = 0;
	mupd->FspmConfig.GttSize = 3; // 8MB
	mupd->FspmConfig.ApertureSize = 3; // 512MB
	mupd->FspmConfig.GtPsmiSupport = 0;
	mupd->FspmConfig.IgdDvmt50PreAlloc = 2; // 64MB
	// mupd->FspmConfig.IgdDvmtMemSize = 2; // 256MB - doesn't exist in FSP headers? what the heck
	mupd->FspmConfig.DfdRestoreEnable = 0;
	mupd->FspmConfig.VmxEnable = 1;


	// DMI (SoC - PCH) Link settings
	mupd->FspmConfig.DmiMaxLinkSpeed = 3;
        mupd->FspmConfig.DmiAspm = 0;
        mupd->FspmConfig.DmiAspmCtrl = 0;

	// Memory training - based on stock
	mupd->FspmConfig.ECT = 1;
	mupd->FspmConfig.LCT = 1;
	mupd->FspmConfig.SOT = 1;
	mupd->FspmConfig.ERDMPRTC2D = 0;
	mupd->FspmConfig.RDMPRT = 1;
	mupd->FspmConfig.RCVET = 1;
	mupd->FspmConfig.JWRL = 1;
	mupd->FspmConfig.EWRTC2D = 1;
	mupd->FspmConfig.ERDTC2D = 1;
	mupd->FspmConfig.WRTC2D = 1;
	mupd->FspmConfig.WRVC1D = 1;
	mupd->FspmConfig.WRVC1D = 1;
	mupd->FspmConfig.DIMMODTT = 1;
	mupd->FspmConfig.DIMMRONT = 1;
	mupd->FspmConfig.WRDSEQT = 1;
	mupd->FspmConfig.WRSRT = 0;
	mupd->FspmConfig.RDODTT = 1;
	mupd->FspmConfig.RDEQT = 1;
	mupd->FspmConfig.RDAPT = 1;
	mupd->FspmConfig.RDTC2D = 1;
	mupd->FspmConfig.WRVC2D = 1;
	mupd->FspmConfig.RDVC2D = 1;
	mupd->FspmConfig.CMDVC = 1;
	mupd->FspmConfig.MrcSafeConfig = 0;
	mupd->FspmConfig.LpDdrDqDqsReTraining = 1;
	mupd->FspmConfig.SafeMode = 0;
	mupd->FspmConfig.OverrideDowngradeForMixedMemory = 0;
	mupd->FspmConfig.MemTestOnWarmBoot = 1;
	mupd->FspmConfig.DdrFreqLimit = 0; // Setting to auto for now.
	mupd->FspmConfig.SaGv = 0;
	// mupd->FspmConfig.RetrainOnFastFail = 1; - Commenting out for now, can't find an equivalent in FSP-M headers.
	mupd->FspmConfig.NModeSupport = 0; // Board type is 1N (1DPC). Shoud be set to "1", testing auto "0" for now.
	mupd->FspmConfig.RhPrevention = 0;
	mupd->FspmConfig.RefreshWm = 1;
	mupd->FspmConfig.ExitOnFailure = 1;

	// Performance settings
	mupd->FspmConfig.SpdProfileSelected = 3; // XMP Profile 2 - platform is unstable with memory above 2933MHz.
	mupd->FspmConfig.RefClk = 1; // 100MHz
	mupd->FspmConfig.VddVoltage = 1200; // 1.2V
	mupd->FspmConfig.Ratio = 0;
	mupd->FspmConfig.RingDownBin = 0;
	mupd->FspmConfig.GearRatio = 0;

        mupd->FspmConfig.HyperThreading = 1;
        mupd->FspmConfig.EnableAbove4GBMmio = 1;
        mupd->FspmConfig.OcSupport = 1;
        mupd->FspmConfig.OcLock = 0;
        mupd->FspmConfig.SaOcSupport = 1;

	memcfg_init(mupd, &mem_config, &spd_info, half_populated);
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
