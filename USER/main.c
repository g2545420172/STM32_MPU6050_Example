/*************************************************************************************************************
�����ۺϵ��ӹ�����(GIE������)        ��Ʒ
Gearing Interated Electronics Studio

MPU6050ʾ������
����ħ��2������Ƭ������
��main.c�⼸�������Ի�����

��עBվUP����GIE������ ��ø�����Ƶ��Դ����̬

2018-2-28��һ��
��Ȩ���� ��ֹδ�����������κ���ҵ��;��
*************************************************************************************************************/
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "timer.h"
#include "Tim.h"
#include "i2c.h"
extern void Init_MPU6050(void);
extern void Refresh6050(void);
extern float ag_x;
extern float ag_y;
extern float ag_z;
extern float  temp_c;
extern float abs6050(float u);
 int main(void)
 {		 
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE); 	 
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);   
	//delay_init();	    	 //��ʱ������ʼ��	  
	 delay_ms(100);	
	NVIC_Configuration(); 
	Soft_I2C_Init();//���IIC��ʼ��������6050������Ϣ
 	Init_MPU6050();//��ʼ�����ٶȼ�6050
	uart1_init(9600);
		while(1)
		{	  	
			delay_ms(100);			
			Refresh6050();//��ȡ6050���ٶ���Ϣ��������Ϊ�Ƕ�
			printf("Angle_X:%3.2f", ag_x);//���ڴ�ӡ��������Ϣ
			printf(" Angle_Y:%3.2f", ag_y);
			printf(" Angle_Z:%3.2f", ag_z);
			printf(" Temp:%3.2f\n", temp_c);
		}     


}


