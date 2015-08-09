


#include "Include.h"



#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vpit0  void PIT_ISR1(void)
{
	PITTF_PTF0 = 1;										// clear Interrupt flag
	EnableInterrupts;


}
#pragma CODE_SEG DEFAULT

