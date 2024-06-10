#ifndef _hx711_H
#define _hx711_H
#include "utils_config.h"

#define HX711_SCK_PIN 2
#define HX711_DT_PIN 3
#define LOW HI_GPIO_VALUE0
#define HIGH HI_GPIO_VALUE1

void HX711_Init(void);
void Get_Maopi(void);
int Get_Weight(void);
int GetHX711_DT(void);
int HX711_Read(void);

#endif