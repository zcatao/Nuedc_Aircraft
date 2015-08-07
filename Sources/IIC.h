

#ifndef  IIC_H_

#define  IIC_H_



#define  IIC_SCL  	
#define  IIC_SDA

#define	SCL_IN()   
#define SCL_OUT()
#define SDA_IN()
#define SDA_OUT()

void IIC_Init(void);

void IIC_Start(void);

void IIC_Stop(void);

void IIC_Ack(void);

void IIC_NAck(void);

char IIC_Wait_Ack(void);

#endif



