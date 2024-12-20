/* SPDX-License-Identifier: GPL-2.0-or-later */

subdirs-y += memory
subdirs-$(CONFIG_HAVE_SPD_IN_CBFS) += spd

bootblock-y += bootblock.c
ramstage-y += ramstage.c
romstage-y += romstage.c
