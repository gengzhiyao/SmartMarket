#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include <stdio.h>
#include "NMEA0183.h"
#include "GPS.h"
#include "SPI.h"
#include "RC522.h"
#include "Serial.h"
#include "8266wifi.h"
#include "DHT11.h"
#include "Servo.h"
#include <string.h>
#include "abc.h"


int main()
{
	 OLED_Init();  
	// OLED_ShowString(2,3,"345");
   Wifi_TCP_Init();
	 Serial_Init();
   GPS_Init();
	 DHT11_GPIO_Config();
   Servo_Init();
	

	uint8_t cardID[4] = {0};
	SPIClass.SPI1_Init(); // SPI初始化
	MFRC522_Init(); // RC522初始化

	
  
	while(1) 
		{
			
		if(!RC522_cardScan(cardID))
		{
	    send_idcard(cardID);
		} 
		
		Delay_ms(250);
		
		 if(GPS_Flag==1)  
	  { 
	    send_gps();
		 }
		 
		 Delay_ms(350);
		 
		if(Read_DHT11(&DHT11_Data) == SUCCESS)
		{
			send_wunshidu();
		}
		
		Delay_ms(250);
		
		if(Serial_Flag==1)
		{
		  My_Servo_SetAngle();
		}

	}
		
	
}


