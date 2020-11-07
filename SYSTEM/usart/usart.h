#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#include "string.h"

//����봮���жϽ��գ��벻Ҫע�����º궨��
#define USART_REC_LEN  			700  	//�����������ֽ��� 700
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern char USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 i;							 //����������������

void uart1_init(u32 bound);
void uart2_init(u32 bound);
char Find(char *a);

#endif


