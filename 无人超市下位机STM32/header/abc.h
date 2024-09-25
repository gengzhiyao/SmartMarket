#ifndef _ABC_
#define _ABC_


typedef unsigned char           uint8_t;

extern DHT11_Data_TypeDef DHT11_Data;

void beep_set(int state);

void send_idcard(uint8_t *cardID);

void send_gps();

void My_Servo_SetAngle();

void send_wunshidu();


#endif



