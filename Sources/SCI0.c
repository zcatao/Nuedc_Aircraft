/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*                 					  BAUD:	9600
*
* File : SCI0.h
* By   : atao
*********************************************************************************************************
*/
#include "Include.h"


void SCI0_Init()
{
	SCI0BD = BUS_FREQ / 16 / 9600;                   // Ãƒâ€”ÃƒÅ“ÃƒÂÃƒÅ¸ÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œ32M Ãƒâ€°ÃƒÂ¨Ãƒâ€“ÃƒÆ’SCI1Ã‚Â²Ã‚Â¨ÃƒÅ’ÃƒËœÃƒâ€šÃƒÅ  115200
	SCI0CR1 = 0X00; //             //Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹Ãƒâ€ ÃƒÂ¦Ãƒâ€¦Ã‚Â¼ÃƒÂÃ‚Â£Ãƒâ€˜ÃƒÂ©
	SCI0CR2 = 0X2c;                //TIE =  Ãƒâ€ÃƒÅ ÃƒÂÃƒÂ­Ãƒâ€“ÃƒÂÃ‚Â·Ã‚Â¢Ãƒâ€¹ÃƒÂÃƒâ€ ÃƒÂ·Ãƒâ€“ÃƒÂÃ‚Â¶ÃƒÂÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//TCIE = 0 Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹Ã‚Â·Ã‚Â¢Ãƒâ€¹ÃƒÂÃƒÂÃƒÂªÃ‚Â³Ãƒâ€°TCÃƒâ€“ÃƒÂÃ‚Â¶ÃƒÂ
	//RIE =    Ã‚Â½Ãƒâ€œÃƒÅ Ãƒâ€¢Ãƒâ€ ÃƒÂ·Ãƒâ€šÃƒÂºÃƒâ€“ÃƒÂÃ‚Â¶ÃƒÂÃƒÅ Ã‚Â¹RDRFÃ‚Â»ÃƒÂ²ORÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//TE = 1 Ã‚Â·Ã‚Â¢Ãƒâ€¹ÃƒÂÃƒâ€ ÃƒÂ·ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//RE = 1 Ã‚Â½Ãƒâ€œÃƒÅ Ãƒâ€¢Ãƒâ€ ÃƒÂ·ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//RWU = 0 Ã‚Â½Ãƒâ€œÃƒÅ Ãƒâ€¢Ãƒâ€ ÃƒÂ·Ãƒâ€¢ÃƒÂ½Ã‚Â³Ã‚Â£Ã‚Â¹Ã‚Â¤Ãƒâ€”ÃƒÂ·
}

void SCI0_Send(uchar data)
{
	while (!(SCI0SR1 & 0x80));    //SCISR1Â¼Ã„Â´Ã¦Ã†Ã·Ã—Ã®Â¸ÃŸÃŽÂ»ÂµÃˆÂ´Ã½
	SCI0DRH = 0;
	SCI0DRL = data;              //ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·Â´Ã¦ÃˆÃ«ÃŠÃ½Â¾Ã
}



//----------------------Â¶ÃSCIÃŠÃ½Â¾Ã-----------------------------//
unsigned char SCI0_Read()
{
	if (SCI0SR1_RDRF == 1)     // Â±Ã­ÃƒÃ·ÃŠÃ½Â¾ÃÂ´Ã“ÃŽÂ»Ã’Ã†Â¼Ã„Â´Ã¦Ã†Ã·Â´Â«ÃŠÃ¤ÂµÂ½SCI ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·
	{
		SCI0SR1_RDRF = 1;     //Â¶ÃÃˆÂ¡ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·Â»Ã¡Â½Â«RDRFÃ‡Ã¥Â³Ã½Ã–Ã˜ÃÃ‚Ã–ÃƒÃŽÂ»
		return SCI0DRL;        //Â·ÂµÂ»Ã˜ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·ÂµÃ„ÃŠÃ½Â¾Ã
	}
}