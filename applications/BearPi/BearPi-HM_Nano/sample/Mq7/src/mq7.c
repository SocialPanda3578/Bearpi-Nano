/*
 * Copyright (c) 2020 Nanjing Xiaoxiongpai Intelligent Technology Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "mq7.h"
#include "wifiiot_errno.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#include "wifiiot_pwm.h"
#include "wifiiot_adc.h"

#define CAL_PPM 20  //校准环境中PPM值
#define RL 1        //RL阻值

static float R0;    //元件在洁净空气中的阻值
//MQ-2 -> GPIO_07 PWM_0 ADC_3
//MQ-7 -> GPIO_09 ADC_4
void Init_mq7(void)
{
    GpioInit();                                                           //初始化GPIO
    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_9, WIFI_IOT_IO_FUNC_GPIO_9_GPIO); //设置GPIO_7引脚复用功能为GPIO
    GpioSetDir(WIFI_IOT_IO_NAME_GPIO_9, WIFI_IOT_GPIO_DIR_IN);           //设置GPIO_7引脚为输入模式    
}

static float Get_MQ7_Voltage(void)
{
    unsigned int ret;
    unsigned short data;

    ret = AdcRead(WIFI_IOT_ADC_CHANNEL_4, &data, WIFI_IOT_ADC_EQU_MODEL_8, WIFI_IOT_ADC_CUR_BAIS_DEFAULT, 0xff);
    if (ret != WIFI_IOT_SUCCESS)
    {
        printf("ADC Read Fail\n");
    }
    return (float)data * 1.8 * 4 / 4096.0;
}

float Get_MQ7_PPM(void)
{
    float voltage, RS, ppm;

    voltage = Get_MQ7_Voltage();
    RS = (5 - voltage) / voltage * RL;    //计算RS
    ppm = 613.9f * pow(RS / R0, -2.074f); //计算ppm
    return ppm;
}

void MQ7_PPM_Calibration(void)
{
    float voltage = Get_MQ7_Voltage();
    float RS = (5 - voltage) / voltage * RL;
    R0 = RS / pow(CAL_PPM / 613.9f, 1 / -2.074f);
}