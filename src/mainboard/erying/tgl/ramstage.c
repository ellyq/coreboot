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
	params->CpuPcieRpAcsEnabled[0] = 1;
        params->CpuPcieRpMaxPayload[0] = 2;
	params->CpuPcieRpAspm[0] = 0;

        // PEG1 - PCI-E x16
	params->CpuPcieRpSlotImplemented[1] = 1;
        params->CpuPcieRpAdvancedErrorReporting[1] = 1;
	params->CpuPcieRpAcsEnabled[1] = 1;
        params->CpuPcieRpMaxPayload[1] = 2;
	params->CpuPcieRpAspm[1] = 0;

	// DMI (Link between SoC and PCH)
	params->PchLegacyIoLowLatency = 1;
	params->PchDmiAspmCtrl = 0;

	// FSP settings
	params->PchUsbOverCurrentEnable = 0;
	params->SataLedEnable = 1;
	params->AmtEnabled = 0;
	params->HybridStorageMode = 1;
	params->RC1pFreqEnable = 1;
	params->PavpEnable = 1;
	params->CdynmaxClampEnable = 0;
	params->PeiGraphicsPeimInit = 1;
}
