#ifndef   _GPS_
#define  _GPS_


typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;

extern int GPS_Flag;
extern char RECS_GPS[200];

void GPS_Init(void);

void GPS_SendString(char *String);






#endif


