/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootblock_common.h>
#include <soc/gpio.h>

/* Configure GPIOs for LPSS UART in bootblock */
static const struct pad_config early_gpio_table[] = {
	/* UART0 RX - TP1 */
	PAD_CFG_NF(GPP_H10, NONE, DEEP, NF2),
	/* UART0 TX - TP2 */
	PAD_CFG_NF(GPP_H11, NONE, DEEP, NF2),
};

void bootblock_mainboard_early_init(void)
{
	 gpio_configure_pads(early_gpio_table, ARRAY_SIZE(early_gpio_table));
}
