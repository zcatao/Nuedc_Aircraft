/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*                 					  BAUD:	9600
*
* File : SCI1.h
* By   : atao
*********************************************************************************************************
*/
#include "Include.h"
/***************************************/
/*     添加底层函数以便使用标准输入输出*/
void TERMIO_PutChar(char C){
	SCI1_Send(C);

}
char TERMIO_GetChar(void){
	return SCI1_Read();
}



UartBuf UartTxbuf;//环形发送结构体
UartBuf UartRxbuf;//环形接收结构体

volatile uint8_t Chartemp;


unsigned char rx_buffer[RX_BUFFER_SIZE];
unsigned char tx_buffer[TX_BUFFER_SIZE];


void UartBuf_Init()
{
	UartRxbuf.Rd_Indx = UartRxbuf.Wd_Indx = 0;
	UartRxbuf.Mask = RX_BUFFER_SIZE - 1;
	UartRxbuf.pbuf = rx_buffer;

	UartTxbuf.Rd_Indx = UartTxbuf.Wd_Indx = 0;
	UartRxbuf.Mask = TX_BUFFER_SIZE - 1;
	UartTxbuf.pbuf = tx_buffer;
}
void SCI1_Init()
{
	SCI1BD = BUS_FREQ / 16 / 115200;                   // Ãƒâ€”ÃƒÅ“ÃƒÂÃƒÅ¸ÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œ32M Ãƒâ€°ÃƒÂ¨Ãƒâ€“ÃƒÆ’SCI1Ã‚Â²Ã‚Â¨ÃƒÅ’ÃƒËœÃƒâ€šÃƒÅ  115200
	SCI1CR1 = 0X00; //             //Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹Ãƒâ€ ÃƒÂ¦Ãƒâ€¦Ã‚Â¼ÃƒÂÃ‚Â£Ãƒâ€˜ÃƒÂ©
	SCI1CR2 = 0X2c;                //TIE =  Ãƒâ€ÃƒÅ ÃƒÂÃƒÂ­Ãƒâ€“ÃƒÂÃ‚Â·Ã‚Â¢Ãƒâ€¹ÃƒÂÃƒâ€ ÃƒÂ·Ãƒâ€“ÃƒÂÃ‚Â¶ÃƒÂÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//TCIE = 0 Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹Ã‚Â·Ã‚Â¢Ãƒâ€¹ÃƒÂÃƒÂÃƒÂªÃ‚Â³Ãƒâ€°TCÃƒâ€“ÃƒÂÃ‚Â¶ÃƒÂ
	//RIE =    Ã‚Â½Ãƒâ€œÃƒÅ Ãƒâ€¢Ãƒâ€ ÃƒÂ·Ãƒâ€šÃƒÂºÃƒâ€“ÃƒÂÃ‚Â¶ÃƒÂÃƒÅ Ã‚Â¹RDRFÃ‚Â»ÃƒÂ²ORÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//TE = 1 Ã‚Â·Ã‚Â¢Ãƒâ€¹ÃƒÂÃƒâ€ ÃƒÂ·ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//RE = 1 Ã‚Â½Ãƒâ€œÃƒÅ Ãƒâ€¢Ãƒâ€ ÃƒÂ·ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“
	//RWU = 0 Ã‚Â½Ãƒâ€œÃƒÅ Ãƒâ€¢Ãƒâ€ ÃƒÂ·Ãƒâ€¢ÃƒÂ½Ã‚Â³Ã‚Â£Ã‚Â¹Ã‚Â¤Ãƒâ€”ÃƒÂ·

	UartBuf_Init();
}



void SCI1_Send(uchar data)
{
	while (!(SCI1SR1 & 0x80));    //SCISR1Â¼Ã„Â´Ã¦Ã†Ã·Ã—Ã®Â¸ÃŸÃŽÂ»ÂµÃˆÂ´Ã½
	SCI1DRH = 0;
	SCI1DRL = data;              //ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·Â´Ã¦ÃˆÃ«ÃŠÃ½Â¾Ã
}



//----------------------Â¶ÃSCIÃŠÃ½Â¾Ã-----------------------------//
unsigned char SCI1_Read()
{
	if (SCI1SR1_RDRF == 1)     // Â±Ã­ÃƒÃ·ÃŠÃ½Â¾ÃÂ´Ã“ÃŽÂ»Ã’Ã†Â¼Ã„Â´Ã¦Ã†Ã·Â´Â«ÃŠÃ¤ÂµÂ½SCI ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·
	{
		SCI1SR1_RDRF = 1;     //Â¶ÃÃˆÂ¡ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·Â»Ã¡Â½Â«RDRFÃ‡Ã¥Â³Ã½Ã–Ã˜ÃÃ‚Ã–ÃƒÃŽÂ»
		return SCI1DRL;        //Â·ÂµÂ»Ã˜ÃŠÃ½Â¾ÃÂ¼Ã„Â´Ã¦Ã†Ã·ÂµÃ„ÃŠÃ½Â¾Ã
	}
}
//读取环形数据中的一个字节
uint8_t UartBuf_RD(UartBuf *Ringbuf)
{
	uint8_t temp;
	temp = Ringbuf->pbuf[Ringbuf->Rd_Indx & Ringbuf->Mask];//数据长度掩码很重要，这是决定数据环形的关键
	Ringbuf->Rd_Indx++;//读取完成一次，读指针加1，为下一次 读取做 准备
	return temp;
}
//将一个字节写入一个环形结构体中
void UartBuf_WD(UartBuf *Ringbuf, uint8_t DataIn)
{

	Ringbuf->pbuf[Ringbuf->Wd_Indx & Ringbuf->Mask] = DataIn;//数据长度掩码很重要，这是决定数据环形的关键
	Ringbuf->Wd_Indx++;//写完一次，写指针加1，为下一次写入做准备

}
//环形数据区的可用字节长度，当写指针写完一圈，追上了读指针
//那么证明数据写满了，此时应该增加缓冲区长度，或者缩短外围数据处理时间
uint16_t UartBuf_Cnt(UartBuf *Ringbuf)
{
	return (Ringbuf->Wd_Indx - Ringbuf->Rd_Indx) & Ringbuf->Mask;//数据长度掩码很重要，这是决定数据环形的关键
}

void UartBufClear(UartBuf *Ringbuf)
{
	Ringbuf->Rd_Indx = Ringbuf->Wd_Indx;
}

void UartSendBuffer(uint8_t *dat, uint8_t len)
{
	volatile uint8_t i = 0;

	for (i = 0; i < len; i++){

		UartBuf_WD(&UartTxbuf, *dat);
		dat++;
	}
	if (len)
		SCI1CR2_TIE = 1; //打开串口发送器中断 开始啪啪啪的发送缓冲中的数据
	
}


#pragma CODE_SEG __NEAR_SEG NON_BANKED

void interrupt VectorNumber_Vsci1 SCI1_ISR(void)
{
	volatile uint8_t datatemp = 0;
	//如果发送器中断使能且发送器空则表明触发发送器中断

	


	if (SCI1CR2_TIE & SCI1SR1_TDRE){
		
		if (UartBuf_Cnt(&UartTxbuf))
			SCI1DRL = UartBuf_RD(&UartTxbuf);
		else{
			SCI1CR2_TIE = 0;//如果发送缓存空，则关闭发送中断
		}

	}
	else if (SCI1SR1_RDRF|SCI1SR1_OR ){

		Chartemp = (uint8_t)SCI1DRL;
		led_printf(Chartemp);
		UartBuf_WD(&UartRxbuf, Chartemp);

		//printf("%c", Chartemp);
	}


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
