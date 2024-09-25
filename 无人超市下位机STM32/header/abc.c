#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "GPS.h"
#include "SPI.h"
#include "RC522.h"
#include "Serial.h"
#include "8266wifi.h"
#include "DHT11.h"
#include "Servo.h"
#include <string.h>
#include "abc.h"


int count=1;

DHT11_Data_TypeDef DHT11_Data= {0};

void beep_set(int state)
{
    if(count)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
        GPIO_InitTypeDef beep;
        beep.GPIO_Mode=GPIO_Mode_Out_PP;
        beep.GPIO_Pin=GPIO_Pin_2;
        beep.GPIO_Speed=GPIO_Speed_50MHz;
        GPIO_Init(GPIOA, &beep);
        count=0;
    }
    if(state==0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_2);
    }
    else
    {
        GPIO_ResetBits(GPIOA,GPIO_Pin_2);
    }

}

void send_idcard(uint8_t *cardID)
{
    //OLED_ShowString(1,1,(char*)cardID);
    Serial_Printf("1%02X%02X%02X%02X", cardID[0], cardID[1], cardID[2], cardID[3]);
    beep_set(1);
    Delay_ms(250);
    beep_set(0);
}


void send_gps()
{
    static int x=0;
    x++;
    if(x<=6)    //每7轮执行一次
    {
        GPS_Flag=0;
        return;
    }
    x=0;

    //  int asd=1;
    char ff[]="$GPGLL";
    for(int x=0; x<6; x++)
    {
        if(RECS_GPS[x]!=ff[x])
        {
            //asd=0;
            return;
        }
    }

    Serial_Printf("2%s",RECS_GPS);


}

void My_Servo_SetAngle()
{
    OLED_ShowString(1,1,RECS);
    OLED_ShowNum(3,1,2,sizeof(RECS));
    Servo_SetAngle(90);
    Delay_s(5);
    Servo_SetAngle(0);
    Serial_Flag=0;
}


void send_wunshidu()
{
    static int s=0;
    s++;
    if(s<=3)return;  //每4轮执行一次
    s=0;

    Serial_Printf("3%d.%d#%d.%d",DHT11_Data.temp_int,DHT11_Data.temp_deci,DHT11_Data.humi_int,DHT11_Data.humi_deci);
}


