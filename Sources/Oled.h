#ifndef _oled_H
#define _oled_H

#ifndef	uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#define LED_SCL       PORTA_PA0
#define LED_SDA       PORTA_PA1
#define LED_RST       PORTA_PA2
#define LED_DC        PORTA_PA3
#define LED_PORT      DDRA

typedef struct {
	uint16_t Wd_Indx;
}Oled;

//extern Oled Oledput;

void oled_Init(void);
void LED_SetPos(uchar ucIdxX, uchar ucIdxY);
void LED_WrDat(uchar ucData);
void LED_P6x8Valuef(uchar ucIdxX,uchar ucIdxY , float Data);
void LED_P6x8Value4(uchar ucIdxX,uchar ucIdxY , uint Data);
void LED_P6x8Value_signed(uchar ucIdxX, uchar ucIdxY,int Data);
void LED_P6x8Value(uchar ucIdxX, uchar ucIdxY,uint Data);
void LED_P6x8Str(uchar ucIdxX, uchar ucIdxY, uchar ucDataStr[]);
void led_printf(uint8_t dat);

#endif
