#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Include.h"


void TERMIO_PutChar(char C){
	SCI1_Send(C);
}
char TERMIO_GetChar(void){
	return SCI1_Read();
}



void main(void) {

	SetBusCLK_80M();
	SCI1_Init();
	SPR_init();
	
	DDRJ_DDRJ0 = 1;
	PPSJ_PPSJ0 = 0;
	PERJ_PERJ0 = 1;
	PTJ_PTJ0 = 1;

	EnableInterrupts;
	
	for (;;){

		SCI1_Send('I');
	}
	
	


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
