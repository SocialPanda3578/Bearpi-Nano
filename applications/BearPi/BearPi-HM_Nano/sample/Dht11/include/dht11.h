#ifndef _DHT11_H
#define _DHT11_H
#include "utils_config.h"
 
#define  DHT11_OUT  PC_OUT(13)
#define  DHT11_IN   PC_IN(13)
 
int DHT11Init(void);
int DHT11ReadData(int *Humi,int *Temp);
int DHT11RstAndCheck(void);
void delay_us(int num);
#endif