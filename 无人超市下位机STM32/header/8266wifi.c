#include "8266wifi.h"
#include <stdio.h>

//���򴮿ڷ���ATָ���������wifiģ�飬���Ӻ��ȵ�
//֮��ʹ��AT+CIPMODE��֪wifiģ��Ҫ��������
//����򴮿ڷ���101001��ͨ��wifiģ��������������������
void Wifi_TCP_Init(void)
{
   Serial_Init();
		

	Serial_SendString("AT+RST\r\n");
	Delay_s(1);
	
	Serial_SendString("AT+CWMODE=3\r\n");	//ͬʱ��Ϊվ����ȵ�
	Delay_s(1);
	
	Serial_SendString("AT+CWJAP=\"Yy\",\"20021209\"\r\n"); //�����ȵ�
	Delay_s(5);
	                                     //10.142.68.120,110.42.228.65
//	192.168.188.138
	Serial_SendString("AT+CIPSTART=\"TCP\",\"110.42.228.65\",8888\r\n");
	Delay_s(4); 
	
	Serial_SendString("AT+CIPMODE=1\r\n");
		Delay_s(1); 
	
	Serial_SendString("AT+CIPSEND\r\n");
	Delay_s(1); 
	
	Serial_SendString("101001");
	Delay_s(1); 

}

