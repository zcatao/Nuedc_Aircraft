#ifndef __DELAY_H
#define __DELAY_H 			   

#include "CPU_BUS.h"

void Delay_Init(unsigned int PIT_IRQ_FREQ);

void Delay_ms(unsigned int nms);

void Delay_us(unsigned int nus);

void Delay(unsigned long delay_time);

#endif