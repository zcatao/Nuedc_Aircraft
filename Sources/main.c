#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Include.h"
#include <stdio.h>
#include <time.h>
#define DEBUG

volatile unsigned char datatemp;



void main(void) {
	
	volatile uint32_t   time1 = 0, time2 = 0;

	time1 = clock();
	SetBusCLK_80M();
	
	SCI1_Init();

#ifdef DEBUG
	printf("初始化......\n");
	printf("锁相环已稳定，总线频率：%ldM\n", BUS_FREQ/1000000);
	printf("串口初始化成功，波特率：%ld\n", BAUD1);
#else
	printf("没有输出咯");
#endif // DEBUG
	SPR_init();
	oled_Init();
	LED_P6x8Str(10, 0, "HoHai University");
#ifdef DEBUG
	printf("系统初始化成功\n");
#endif // DEBUG

	EnableInterrupts;


	for (;;){

		while (UartBuf_Cnt(&UartRxbuf)){

			//UartBuf_WD(&UartTxbuf, UartBuf_RD(&UartRxbuf));

			//SCI1CR2_TIE = 1;

		}

		//SCI1_Send('I');
	}
	
	


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
