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
	params->CpuPcieRpPeerToPeerMode[0] = 1;
	params->CpuPcieRpPtmEnabled[0] = 1;
	params->CpuPcieRpLtrEnable[0] = 1;
	params->CpuPcieRpPmSci[0] = 1;
	params->CpuPcieRpAcsEnabled[0] = 1;
	params->CpuPcieRpTransmitterHalfSwing[0] = 0;

	// PEG1 - PCI-E x16
	params->CpuPcieRpSlotImplemented[1] = 1;
	params->CpuPcieRpAdvancedErrorReporting[1] = 1;
	params->CpuPcieRpPeerToPeerMode[1] = 1;
	params->CpuPcieRpPtmEnabled[1] = 1;
	params->CpuPcieRpLtrEnable[1] = 1;
	params->CpuPcieRpPmSci[1] = 1;
	params->CpuPcieRpAcsEnabled[1] = 1;
	params->CpuPcieRpTransmitterHalfSwing[1] = 0;

	uint8_t aspm, aspm_l1;

	/* ASPM L1 sub-states require CLKREQ, so CLK_PM should be enabled as well */
	if (CONFIG(PCIEXP_L1_SUB_STATE) && CONFIG(PCIEXP_CLK_PM))
		aspm_l1 = 2; // 2 - L1.1 and L1.2
	else
		aspm_l1 = 0;

	if (CONFIG(PCIEXP_ASPM)) {
		aspm = CONFIG(PCIEXP_L1_SUB_STATE) ? 3 : 1; // 3 - L0sL1, 1 - L0s
	} else {
		aspm = 0;
		aspm_l1 = 0;
	}

	// CPU PCI-E ASPM
	params->CpuPciePowerGating = CONFIG(PCIEXP_CLK_PM);
	params->CpuPcieClockGating = CONFIG(PCIEXP_CLK_PM);

	params->CpuPcieRpEnableCpm[0] = CONFIG(PCIEXP_CLK_PM);
	params->CpuPcieRpAspm[0] = aspm;
	params->CpuPcieRpL1Substates[0] = aspm_l1;

	params->CpuPcieRpEnableCpm[1] = CONFIG(PCIEXP_CLK_PM);
	params->CpuPcieRpAspm[1] = aspm;
	params->CpuPcieRpL1Substates[1] = aspm_l1;

	// Power management - ASPM is broken even on vendor FW
	params->PchLegacyIoLowLatency = 1;
	params->PchDmiAspmCtrl = 0;

	// PCH RootPorts
	params->PcieRpMaxPayload[4]  = 2; // M.2 Gen3
	params->PcieRpPmSci[4] = 1;
	params->PcieRpEnableCpm[4] = CONFIG(PCIEXP_CLK_PM);
	params->PcieRpAspm[4] = aspm;
	params->PcieRpL1Substates[4] = aspm_l1;

	params->PcieRpMaxPayload[8]  = 1; // M.2 NGFF
	params->PcieRpPmSci[8] = 1;
	params->PcieRpEnableCpm[8] = CONFIG(PCIEXP_CLK_PM);
	params->PcieRpAspm[8] = aspm;
	params->PcieRpL1Substates[8] = aspm_l1;
	
	params->PcieRpMaxPayload[10]  = 1; // RTL8111 NIC
	params->PcieRpPmSci[10] = 1;
	params->PcieRpEnableCpm[10] = CONFIG(PCIEXP_CLK_PM);
	params->PcieRpAspm[10] = aspm;
	params->PcieRpL1Substates[10] = aspm_l1;


	params->PcieRpMaxPayload[11]  = 1; // PCI-E x1 Gen3
	params->PcieRpPmSci[11] = 1;
	params->PcieRpEnableCpm[11] = CONFIG(PCIEXP_CLK_PM);
	params->PcieRpAspm[11] = aspm;
	params->PcieRpL1Substates[11] = aspm_l1;
	
	// FSP settings
	params->PchUsbOverCurrentEnable = 0;
	params->RC1pFreqEnable = 1;
	params->PavpEnable = 1;
	params->CdynmaxClampEnable = 0;
	params->PchEspiHostC10ReportEnable = 1;
}
