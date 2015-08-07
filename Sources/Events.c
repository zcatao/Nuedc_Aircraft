


#include "Include.h"



#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vpit0  void PIT_ISR1(void)
{
	PITTF_PTF0 = 1;										// clear Interrupt flag
	EnableInterrupts;


}
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG __NEAR_SEG NON_BANKED

void  interrupt VectorNumber_Vsci1 SCIbu1_re(void)
{
	unsigned char ch;
	ch = SCI1_Read();
	SCI1_Send(ch):
//
//    static i = 0;
//    unsigned char ch;
//    ch = SCI1_Read();
//	SCI1_Send(ch);
//    if (ch == SEND_HEAD)
//    {
//       i = 0;
//    }
//    g_STBuf[i++] = ch;
//    if (i == 4)
//    {
//        i = 0;
//        g_SCI1_READ_flag = 1;
//    }
}
#pragma CODE_SEG DEFAULT
