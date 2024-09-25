#include "stm32f10x.h"                  // Device header

char RECS_GPS[100];
int GPS_Flag=0;
unsigned char j;


void GPS_SendString(char *String)
{
	int i=0;
	for(i=0;String[i]!=0;i++)
	{
	USART_SendData(USART2,String[i]);
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET);
	}
		
}


void USART2_IRQHandler(void)
{
	  if(USART_GetITStatus(USART2,USART_IT_RXNE))
	 {
		RECS_GPS[j++]=USART_ReceiveData(USART2);
		if((RECS_GPS[j-2]=='\r')|(RECS_GPS[j-1]=='\n'))  
		{
			RECS_GPS[j-2]='\0';
			j = 0;
			GPS_Flag=1;
		}
	}
}



void GPS_Init(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
  GPIO_InitTypeDef P_RX;
	GPIO_InitTypeDef P_TX;
	
	P_RX.GPIO_Mode=GPIO_Mode_IPU;
	P_RX.GPIO_Pin=GPIO_Pin_3;
	P_RX.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&P_RX);
	
	P_TX.GPIO_Mode=GPIO_Mode_AF_PP;
	P_TX.GPIO_Pin=GPIO_Pin_2;
	P_TX.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&P_TX);
	 
	//配置串口单元
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate=9600;             //
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //硬件流
	USART_InitStruct.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	
  USART_Init(USART2,&USART_InitStruct);
    
  USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//优先级分组
	
	NVIC_InitTypeDef P_NVIC;
	P_NVIC.NVIC_IRQChannel=USART2_IRQn;   //中断通道
	P_NVIC.NVIC_IRQChannelCmd=ENABLE;    
	P_NVIC.NVIC_IRQChannelPreemptionPriority=2;  
	P_NVIC.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&P_NVIC);
	
	USART_Cmd(USART2,ENABLE);
}


