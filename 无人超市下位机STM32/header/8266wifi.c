#include "8266wifi.h"
#include <stdio.h>

//先向串口发送AT指令，用于配置wifi模块，连接好热点
//之后使用AT+CIPMODE告知wifi模块要发送数据
//最后向串口发送101001，通过wifi模块向服务器发送这个数据
void Wifi_TCP_Init(void)
{
   Serial_Init();
		

	Serial_SendString("AT+RST\r\n");
	Delay_s(1);
	
	Serial_SendString("AT+CWMODE=3\r\n");	//同时作为站点和热点
	Delay_s(1);
	
	Serial_SendString("AT+CWJAP=\"Yy\",\"20021209\"\r\n"); //连接热点
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

