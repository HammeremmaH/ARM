#include "systick.h"

void SysTick_Init()
{
	SysTick_ticks = 0xFFFFFFFFFF000000;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0x00FFFFFF;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void SysTick_DelayTicks(uint64_t ticks)
{
	uint64_t delayEndTicks = SysTick_ticks + SysTick->VAL - ticks;

	while (SysTick_ticks + SysTick->VAL > delayEndTicks);
}

void SysTick_DelayUs(uint64_t us)
{
	SysTick_DelayTicks(us * (SystemCoreClock / 1000000));
}

void SysTick_DelayMs(uint64_t ms)
{
	SysTick_DelayTicks(ms * (SystemCoreClock / 1000));
}

uint64_t SysTick_GetTicks()
{
	return SysTick_ticks + SysTick->VAL;
}

uint64_t SysTick_IntervalTicks(uint64_t ticks)
{
	return ticks - SysTick_GetTicks();
}

uint64_t SysTick_IntervalUs(uint64_t ticks)
{
	return SysTick_IntervalTicks(ticks) / (SystemCoreClock / 1000000);
}

uint64_t SysTick_IntervalMs(uint64_t ticks)
{
	return SysTick_IntervalTicks(ticks) / (SystemCoreClock / 1000);
}

void SysTick_Handler()
{
	SysTick_ticks -= 0x01000000;
}
