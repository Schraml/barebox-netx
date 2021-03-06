#include <common.h>
#include <mach/esdctl.h>
#include <mach/generic.h>
#include <asm/barebox-arm-head.h>
#include <asm/barebox-arm.h>

extern char __dtb_imx51_babbage_start[];

ENTRY_FUNCTION(start_imx51_babbage, r0, r1, r2)
{
	void *fdt;

	imx5_cpu_lowlevel_init();
	arm_setup_stack(0x20000000 - 16);

	fdt = __dtb_imx51_babbage_start - get_runtime_offset();

	imx51_barebox_entry(fdt);
}
