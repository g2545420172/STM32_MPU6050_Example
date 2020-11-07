/*********************************************************************************
˵����ֻ�õ���VCC(5V),GND,SCL,SDA�ĸ��ܽš�XDA��XCL���������������ⲿ�豸��
AD0��16λAD���������״ֵ̬�����Ǳ��������ֱ�Ӷ�ȡ�Ĵ�����ֵ���������û�б�Ҫ��
INT���жϣ����ò�ƿ������ڳ����У����ǲ�̫��Ϥ��ô����������ʾ����Ϊ����Ϥ����һ�š�
����4ͨ���ġ�
*********************************************************************************/


#include"stm32f10x.h"
#include"delay.h"
#include"usart.h" /* printf����������������ڣ����Ա����������ļ� */
#include<stdio.h>  /* ��Ϊ�õ���printf���������Ա����������ļ� */
#include"mpu6050.h"
#include"i2c.h"
#include"Kalman_Filter.h"
#include"Tim.h"
#include"ocsctl.h"
 s16 Gyro_x;
 s16 Gyro_y;
 s16 Gyro_z;
 s16 Ayro_x;
 s16 Ayro_y;
 s16 Ayro_z;
 s16 TempC;
 float ag_x=0;
 float  ax;
 float  gx;
 float ag_y=0;
 float  ay;
 float  gy;
 float ag_z=0;
 float  az;
 float  gz;
 float  temp_c;
//extern float angle2, angle_dot; 
/**************ʹ�÷�˼�����ٷ��̳��еķ������нǶ��ں�*************************/


int main(void)
{  
   
   SystemInit();
   delay_init(72);
   TIM3_Init();
   Initial_UART1(115200);
   Soft_I2C_Init();
   Init_MPU6050();
//  printf("\r\n��ʼ���ɹ�\r\n");
   while(1)
   {
//      UART1_ReportMotion(Ayro_x,Ayro_y,Ayro_z,Gyro_x,Gyro_y,Gyro_z,0,0,0);
//	  UART1_ReportIMU((int16_t)(az*10),(int16_t)(ag_z*10),0,0,0,0,100);
	  //UART1_ReportIMU(int16_t yaw,int16_t pitch,int16_t roll
//,int16_t alt,int16_t tempr,int16_t press,int16_t IMUpersec);

      OCS_displayData(ag_x,ag_y,ag_z,0);
	   delay_ms(20);
 
    }
  
}
