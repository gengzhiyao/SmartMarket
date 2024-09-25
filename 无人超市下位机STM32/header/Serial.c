#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>
#include "Serial.h"

uint16_t a;
int BOOL=0;
char RECS[100];
int Serial_Flag=0;

unsigned char i;

int fputc(int ch, FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}


void Serial_SendArray(uint8_t* arr,int length)
{
	 
    for(int i=0;i<length;i++)
	  {
	   Serial_SendByte(arr[i]);
	  }
	
}

		
void USART1_IRQHandler (void)
{
	  if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		RECS[i++]=USART_ReceiveData(USART1);
		if((RECS[i-2]=='\r')|(RECS[i-1]=='\n'))  
		{
			RECS[i-2]='\0';
			i = 0;	
			
			Serial_Flag=1; 
		}
	}
}


void Serial_SendByte(uint8_t Byte)
{
		USART_SendData(USART1,Byte);
	  while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}



void Serial_SendString(char *String)
{
	int i=0;
	for(i=0;String[i]!=0;i++)
	{
	USART_SendData(USART1,String[i]);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	}
		
}


void Serial_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
  GPIO_InitTypeDef P_RX;
	GPIO_InitTypeDef P_TX;
	
	P_RX.GPIO_Mode=GPIO_Mode_IPU;
	P_RX.GPIO_Pin=GPIO_Pin_10;
	P_RX.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&P_RX);
	
	P_TX.GPIO_Mode=GPIO_Mode_AF_PP;
	P_TX.GPIO_Pin=GPIO_Pin_9;
	P_TX.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&P_TX);
	 
	//配置串口单元
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate=115200;             //
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //硬件流
	USART_InitStruct.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	
  USART_Init(USART1,&USART_InitStruct);
    
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//优先级分组
	
	NVIC_InitTypeDef P_NVIC;
	P_NVIC.NVIC_IRQChannel=USART1_IRQn;   //中断通道
	P_NVIC.NVIC_IRQChannelCmd=ENABLE;    
	P_NVIC.NVIC_IRQChannelPreemptionPriority=2;  
	P_NVIC.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&P_NVIC);
	
	
	
	USART_Cmd(USART1,ENABLE);
}


