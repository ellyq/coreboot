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
        params->CpuPcieRpAdvancedErrorReporting[0] = 1;
	params->CpuPcieRpMultiVcEnabled[0] = 1;
        params->CpuPcieRpMaxPayload[0] = 2;
        params->CpuPcieRpPeerToPeerMode[0] = 1;

        // PEG1 - PCI-E x16
	params->CpuPcieRpSlotImplemented[1] = 1;
        params->CpuPcieRpAdvancedErrorReporting[1] = 1;
	params->CpuPcieRpMultiVcEnabled[1] = 1;
        params->CpuPcieRpMaxPayload[1] = 2;
        params->CpuPcieRpPeerToPeerMode[1] = 1;

	// DMI/FSP settings
	params->PcieRpFunctionSwap = 0;
	params->CpuPcieRpFunctionSwap = 0;
	params->PchLegacyIoLowLatency = 1;
	params->PchDmiAspmCtrl = 0;
}
