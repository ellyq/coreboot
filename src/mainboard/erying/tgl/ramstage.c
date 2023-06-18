/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/device.h>
#include <soc/pci_devs.h>
#include <soc/ramstage.h>
#include <string.h>
#include "gpio.h"

void mainboard_silicon_init_params(FSP_S_CONFIG *params)
{
        // PEG0 - Gen4 NVME
	params->CpuPcieRpSlotImplemented[0] = 1;
        params->CpuPcieRpLtrEnable[0] = 1;
        params->CpuPcieRpPtmEnabled[0] = 1;
        params->CpuPcieRpAdvancedErrorReporting[0] = 1;
        params->CpuPcieRpMaxPayload[0] = 2;
        params->CpuPcieRpEnableCpm[0] = 1;
        params->CpuPcieRpPeerToPeerMode[0] = 1;

        // PEG1 - PCI-E x16
	params->CpuPcieRpSlotImplemented[1] = 1;
        params->CpuPcieRpLtrEnable[1] = 1;
        params->CpuPcieRpPtmEnabled[1] = 1;
        params->CpuPcieRpAdvancedErrorReporting[1] = 1;
        params->CpuPcieRpMaxPayload[1] = 2;
        params->CpuPcieRpEnableCpm[1] = 1;
        params->CpuPcieRpPeerToPeerMode[1] = 1;
}
