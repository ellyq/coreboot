/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/device.h>
#include <soc/pci_devs.h>
#include <soc/ramstage.h>
#include "gpio.h"

static void init_mainboard(void *chip_info)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}

struct chip_operations mainboard_ops = {
	.init = init_mainboard,
};

void mainboard_silicon_init_params(FSP_S_CONFIG *params)
{
	// PEG0 - Gen4 NVME
	params->CpuPcieRpSlotImplemented[0] = 1;
	params->CpuPcieRpAdvancedErrorReporting[0] = 1;
	params->CpuPcieRpMaxPayload[0] = 2;
	params->CpuPcieRpPeerToPeerMode[0] = 1;
	params->CpuPcieRpPtmEnabled[0] = 1;
	params->CpuPcieRpLtrEnable[0] = 1;
	params->CpuPcieRpPmSci[0] = 1;
	params->CpuPcieRpTransmitterHalfSwing[0] = 0;

	// PEG1 - PCI-E x16
	params->CpuPcieRpSlotImplemented[1] = 1;
	params->CpuPcieRpAdvancedErrorReporting[1] = 1;
	params->CpuPcieRpMaxPayload[1] = 2;
	params->CpuPcieRpPeerToPeerMode[1] = 1;
	params->CpuPcieRpPtmEnabled[1] = 1;
	params->CpuPcieRpLtrEnable[1] = 1;
	params->CpuPcieRpPmSci[1] = 1;
	params->CpuPcieRpTransmitterHalfSwing[1] = 0;

	// Power management - ASPM is broken even on vendor FW
	params->PchLegacyIoLowLatency = 1;
	params->PchDmiAspmCtrl = 0;

	// PCH RootPorts
	params->PcieRpMaxPayload[4]  = 2; // M.2 Gen3
	params->PcieRpPmSci[4] = 1;
	// params->PcieRpEnableCpm[4] = 0;
	// params->PcieRpL1Substates[4] = 0;
	// params->PcieRpAspm[4] = 0;

	params->PcieRpMaxPayload[8]  = 1;
	params->PcieRpPmSci[8] = 1;// M.2 NGFF
	// params->PcieRpEnableCpm[8] = 0;
	// params->PcieRpL1Substates[8] = 0;
	// params->PcieRpAspm[8] = 0;

	params->PcieRpMaxPayload[10]  = 1; // RTL8111 NIC
	params->PcieRpPmSci[10] = 1;
	// params->PcieRpEnableCpm[10] = 0;
	// params->PcieRpL1Substates[10] = 0;
	// params->PcieRpAspm[10] = 0;

	params->PcieRpMaxPayload[11]  = 1; // PCI-E x1 Gen3
	params->PcieRpPmSci[11] = 1;
	// params->PcieRpEnableCpm[11] = 0;
	// params->PcieRpL1Substates[11] = 0;
	// params->PcieRpAspm[11] = 0;

	// FSP settings
	params->CpuPcieRpFunctionSwap = 1;
	params->PcieRpFunctionSwap = 0;
	params->ITbtPcieTunnelingForUsb4 = 0;
	params->PchUsbOverCurrentEnable = 0;
	params->RC1pFreqEnable = 1;
	params->PavpEnable = 1;
	params->CdynmaxClampEnable = 0;
	params->PchEspiHostC10ReportEnable = 1;
}
