#ifndef __ASM_ARM_COMMON_H
#define __ASM_ARM_COMMON_H

#define ARCH_SHUTDOWN

static inline unsigned long get_pc(void)
{
	unsigned long pc;

	__asm__ __volatile__(
                "mov    %0, pc\n"
                : "=r" (pc)
                :
                : "memory");

	return pc;
}

static inline unsigned long get_lr(void)
{
	unsigned long lr;

	__asm__ __volatile__(
                "mov    %0, lr\n"
                : "=r" (lr)
                :
                : "memory");

	return lr;
}

static inline unsigned long get_sp(void)
{
	unsigned long sp;

	__asm__ __volatile__(
                "mov    %0, sp\n"
                : "=r" (sp)
                :
                : "memory");

	return sp;
}

static inline void arm_setup_stack(unsigned long top)
{
	__asm__ __volatile__("mov sp, %0" : : "r"(top));
}

#endif /* __ASM_ARM_COMMON_H */
