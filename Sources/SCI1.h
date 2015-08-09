/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*                 					  BAUD:	115200
*                 
* File : SCI1.h
* By   : atao
*********************************************************************************************************
*/

#ifndef SCI1_H_
#define SCI1_H_
 
#define BAUD1 115200

// USART Receiver buffer
#define RX_BUFFER_SIZE   128
#define TX_BUFFER_SIZE   128


extern unsigned char rx_buffer[RX_BUFFER_SIZE];
extern unsigned char tx_buffer[TX_BUFFER_SIZE];


typedef struct buf
{
	uint16_t volatile Wd_Indx;
	uint16_t volatile Rd_Indx;
	uint16_t Mask;
	uint8_t *pbuf;

}UartBuf;

extern UartBuf UartTxbuf;//环形发送结构体
extern UartBuf UartRxbuf;//环形接收结构体



void SCI1_Init(void);

void SCI1_Send(unsigned char);

unsigned char SCI1_Read(void);

uint8_t UartBuf_RD(UartBuf *Ringbuf);

void UartBuf_WD(UartBuf *Ringbuf, uint8_t DataIn);

uint16_t UartBuf_Cnt(UartBuf *Ringbuf);

void UartBufClear(UartBuf *Ringbuf);

void UartSendBuffer(uint8_t *dat, uint8_t len);

// #pragma CODE_SEG __NEAR_SEG NON_BANKED

// void  interrupt 21 SCIbu0_re(void)

// #pragma CODE_SEG DEFAULT

#pragma CODE_SEG __NEAR_SEG NON_BANKED

__interrupt void SCI1_ISR(void);

#pragma CODE_SEG DEFAULT

#endif