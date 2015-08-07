/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
* File : Events.c
* By   : atao
*********************************************************************************************************
*/
#ifndef EVENTS_H_
#define EVENTS_H_



#pragma CODE_SEG __NEAR_SEG NON_BANKED

__interrupt void PIT_ISR1(void);

#pragma CODE_SEG DEFAULT

#endif
