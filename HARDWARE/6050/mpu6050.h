#ifndef __MPU6050_H
#define __MPU6050_H 
#include "stm32f10x.h"
#include "stm32f10x_it.h"
/*******��ʼ��MPU3050��������Ҫ��ο�pdf�����޸�************************/
/**********************************************************************
����˵������250��/s      131	 LSB/��/s
          ��500��/s      65.5  LSB/��/s
		  ��1000��/s     32.8  LSB/��/s
		  ��2000��/s     16.4  LSB/��/s
		  ��2g          16384 LSB/mg
		  ��4g          8192  LSB/mg
		  ��8g          4096  LSB/mg
		  ��16g         2048  LSB/mg
		  5V����
*********************************************************************/

// ����MPU6050�ڲ���ַ
//****************************************
#define	SMPLRT_DIV		0x19	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
#define	CONFIG6050		   0x1A	//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
#define	GYRO_CONFIG		0x1b	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
#define	ACCEL_CONFIG	0x1c   	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
#define	ACCEL_XOUT_H	0x3B	//���ٶ���صļĴ���
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42

#define	GYRO_XOUT_H		0x43         //�Ƕ���صļĴ���
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48

#define	PWR_MGMT_1		0x6B	//��Դ��������ֵ��0x00(��������)
#define	WHO_AM_I		0x75	//IIC��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)
#define	MPU6050_Addr   0xD0	  //����������IIC�����еĴӵ�ַ,����ALT  ADDRESS��ַ���Ų�ͬ�޸�
/************************���ٶȼ��ٶ�ƫ��ֵ*************************/
#define  Gx_offset   0
#define  Gy_offset	 0
#define  Gz_offset	 -1

#define   Ax_offset   303
#define   Ax_Max	  8444
#define   Ax_Min 	  -7662

#define  Ay_offset    60    	  
#define  Ay_Max	       8204
#define  Ay_Min		  -8647

#define   Az_offset   -519
#define   Az_Max	   7921
#define   Az_Min 	  -8960


 void Init_MPU6050(void);
 short getAccX(void);
 short getAccY(void);
 short getAccZ(void);

//��ȡ�����ǵ�ֵ
 short getGyroX(void);
 short getGyroY(void);
 short getGyroZ(void);

//�¶�
 short getTemperature(void);

void delay5ms(void);
//void READ_MPU6050(void);
u8 Single_Write(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data);
u8 Single_Read(unsigned char SlaveAddress,unsigned char REG_Address);

#endif
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
  u8 count=0;
