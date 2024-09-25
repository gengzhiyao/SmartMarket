#ifndef   _SERIAL_
#define  _SERIAL_


typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;

extern int Serial_Flag;
extern char RECS[100];


void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);

void Serial_SendArray(uint8_t* arr,int length);

void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);






#endif


