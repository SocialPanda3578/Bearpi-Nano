#ifndef _RFID_H
#define _RFID_H
#include "utils_config.h"
  
int RFIDInit(void);
int RFIDReadData(int *Humi,int *Temp);
int RFIDRstAndCheck(void);
void delay_us(int num);
#endif