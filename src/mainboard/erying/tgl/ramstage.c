/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/ramstage.h>
#include "gpio.h"


void mainboard_silicon_init_params(FSP_S_CONFIG *params)
{
        // PEG0 Config
        params->CpuPcieRpAdvancedErrorReporting[0] = 1;
        params->CpuPcieRpLtrEnable[0] = 1;
        params->CpuPcieRpPtmEnabled[0] = 1;

        // PEG1 Config
        params->CpuPcieRpAdvancedErrorReporting[1] = 1;
        params->CpuPcieRpLtrEnable[1] = 1;
        params->CpuPcieRpPtmEnabled[1] = 1;

        // Low latency legacy I/O
        params->PchLegacyIoLowLatency = 1;
}

static void mainboard_init(void *chip_info)
{
	mainboard_configure_gpios();
}

struct chip_operations mainboard_ops = {
	.init = mainboard_init,
};
