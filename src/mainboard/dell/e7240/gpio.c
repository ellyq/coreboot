/* SPDX-License-Identifier: GPL-2.0-only */

#include <southbridge/intel/lynxpoint/lp_gpio.h>

const struct pch_lp_gpio_map mainboard_lp_gpio_map[] = {
	[0]  = LP_GPIO_OUT_LOW,
	[1]  = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL },
	[2]  = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[3]  = LP_GPIO_OUT_LOW,
	[4]  = LP_GPIO_NATIVE,
	[5]  = LP_GPIO_NATIVE,
	[6]  = LP_GPIO_NATIVE,
	[7]  = LP_GPIO_NATIVE,
	[8]  = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[9]  = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[10] = LP_GPIO_OUT_LOW,
	[11] = LP_GPIO_NATIVE,
	[12] = LP_GPIO_NATIVE,
	[13] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[14] = LP_GPIO_OUT_LOW,
	[15] = LP_GPIO_OUT_LOW,
	[16] = LP_GPIO_OUT_HIGH,
	[17] = LP_GPIO_OUT_LOW,
	[18] = LP_GPIO_NATIVE,
	[19] = LP_GPIO_NATIVE,
	[20] = LP_GPIO_NATIVE,
	[21] = LP_GPIO_NATIVE,
	[22] = LP_GPIO_NATIVE,
	[23] = LP_GPIO_NATIVE,
	[24] = LP_GPIO_OUT_LOW,
	[25] = LP_GPIO_OUT_LOW,
	[26] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT },
	[27] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[28] = LP_GPIO_OUT_LOW,
	[29] = LP_GPIO_NATIVE,
	[30] = LP_GPIO_NATIVE,
	[31] = LP_GPIO_NATIVE,
	[32] = LP_GPIO_NATIVE,
	[33] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[34] = LP_GPIO_OUT_HIGH,
	[35] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[36] = LP_GPIO_OUT_LOW,
	[37] = LP_GPIO_NATIVE,
	[38] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[39] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[40] = LP_GPIO_NATIVE,
	[41] = LP_GPIO_NATIVE,
	[42] = LP_GPIO_NATIVE,
	[43] = LP_GPIO_NATIVE,
	[44] = LP_GPIO_OUT_LOW,
	[45] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL,
		 .route = GPIO_ROUTE_SMI,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[46] = LP_GPIO_OUT_LOW,
	[47] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[48] = LP_GPIO_OUT_LOW,
	[49] = LP_GPIO_OUT_LOW,
	[50] = LP_GPIO_OUT_HIGH,
	[51] = LP_GPIO_OUT_LOW,
	[52] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[53] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT, .pirq = GPIO_PIRQ_APIC_ROUTE },
	[54] = LP_GPIO_OUT_LOW,
	[55] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT,
		 .pirq  = GPIO_PIRQ_APIC_ROUTE },
	[56] = LP_GPIO_OUT_HIGH,
	[57] = LP_GPIO_OUT_HIGH,
	[58] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT },
	[59] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[60] = LP_GPIO_OUT_LOW,
	[61] = LP_GPIO_NATIVE,
	[62] = LP_GPIO_NATIVE,
	[63] = LP_GPIO_NATIVE,
	[64] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[65] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[66] = LP_GPIO_OUT_LOW,
	[67] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL },
	[68] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL },
	[69] = LP_GPIO_OUT_HIGH,
	[70] = LP_GPIO_OUT_LOW,
	[71] = LP_GPIO_NATIVE,
	[72] = LP_GPIO_NATIVE,
	[73] = LP_GPIO_OUT_LOW,
	[74] = LP_GPIO_NATIVE,
	[75] = LP_GPIO_NATIVE,
	[76] = LP_GPIO_OUT_HIGH,
	[77] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[78] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL },
	[79] = LP_GPIO_OUT_LOW,
	[80] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL },
	[81] = LP_GPIO_NATIVE,
	[82] = LP_GPIO_NATIVE,
	[83] = LP_GPIO_OUT_HIGH,
	[84] = LP_GPIO_OUT_HIGH,
	[85] = LP_GPIO_OUT_HIGH,
	[86] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL },
	[87] = LP_GPIO_OUT_LOW,
	[88] = LP_GPIO_OUT_LOW,
	[89] = LP_GPIO_OUT_HIGH,
	[90] = LP_GPIO_OUT_HIGH,
	[91] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[92] = { .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT | GPIO_IRQ_LEVEL },
	[93] = LP_GPIO_OUT_LOW,
	[94] = LP_GPIO_OUT_LOW,
	LP_GPIO_END
};
