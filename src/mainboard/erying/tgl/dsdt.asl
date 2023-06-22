/* SPDX-License-Identifier: GPL-2.0-only */

#include <acpi/acpi.h>

DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	ACPI_DSDT_REV_2,
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x20110725
)
{
	#include <acpi/dsdt_top.asl>
	#include <soc/intel/common/block/acpi/acpi/platform.asl>
	#include <soc/intel/common/block/acpi/acpi/globalnvs.asl>
	#include <cpu/intel/common/acpi/cpu.asl>

	Device (\_SB.PCI0)
	{
		#include <soc/intel/common/block/acpi/acpi/northbridge.asl>
		#include <soc/intel/tigerlake/acpi/southbridge.asl>
	}

<<<<<<< HEAD
<<<<<<< HEAD
=======
	#include <southbridge/intel/common/acpi/sleepstates.asl>
>>>>>>> e145e41c7f (Revert commit changing DMI link, PCI-E is unstable)
=======
>>>>>>> f291bfd160 (Drop TCSS ACPI tables)

	Scope (\_SB.PCI0.LPCB)
	{
	}

	#include <southbridge/intel/common/acpi/sleepstates.asl>
}
