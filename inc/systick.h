#ifndef SYSTICK_H
#define SYSTICK_H

#include "stm32f10x.h"

volatile uint64_t SysTick_ticks;

void SysTick_Init();

void SysTick_DelayTicks(uint64_t ticks);
void SysTick_DelayUs(uint64_t us);
void SysTick_DelayMs(uint64_t ms);

uint64_t SysTick_GetTicks();
uint64_t SysTick_IntervalTicks(uint64_t ticks);
uint64_t SysTick_IntervalUs(uint64_t ticks);
uint64_t SysTick_IntervalMs(uint64_t ticks);

void SysTick_Handler();

#endif
