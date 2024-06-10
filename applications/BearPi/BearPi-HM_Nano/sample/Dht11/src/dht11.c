#include "dht11.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#include "wifiiot_adc.h"
#include <stdio.h>
#include "cmsis_os2.h"
#include <ohos_init.h>
#include <unistd.h>
#include <time.h>
/*DHT11复位和检测响应函数，返回值：1-检测到响应信号；0-未检测到响应信号*/
WifiIotGpioValue inputdata={0};
WifiIotGpioValue outputdata={0};
int DHT11RstAndCheck(void)
{
     int timer = 0;
    GpioInit();
    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_14,WIFI_IOT_IO_FUNC_GPIO_14_GPIO);
    IoSetPull(WIFI_IOT_IO_NAME_GPIO_14, WIFI_IOT_IO_PULL_UP);
    GpioSetDir(WIFI_IOT_GPIO_IDX_14,WIFI_IOT_GPIO_DIR_OUT);
    GpioSetOutputVal(WIFI_IOT_GPIO_IDX_14,0);
    osDelay(2U);
    GpioSetOutputVal(WIFI_IOT_GPIO_IDX_14,1);
    delay_us(30);     	       //拉高20~40us  
    GpioSetDir(WIFI_IOT_GPIO_IDX_14,WIFI_IOT_GPIO_DIR_IN);
    GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
    int num=0;
    while(inputdata&&num<=100)
    {
        num++;
        GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
    }
    if(num>100)return 0;
    while(!inputdata&&timer<=100)
    {
        timer++;
        delay_us(1);
        GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
    }
 
    if (timer>100 || timer<20) //判断响应时间
    {
        return 0;
    }
    timer = 0;
    while(inputdata&&timer<=100)
    {
        timer++;
        GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
        delay_us(1);
    }
    if (timer>100 || timer<20) //检测响应信号之后的高电平
    {
        return 0;
    }
    return 1;
}
 
 
// /*读取一字节数据，返回值-读到的数据*/
int DHT11ReadByte(void)
{
    uint8_t i;
    int byt = 0;
    for (i=0; i<8; i++)
    {
        GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
        int num=0;
        while (inputdata&&num<=100)  //等待低电平，数据位前都有50us低电平时隙
        {
            GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
            num++;
        }
        num=0;
        while (!inputdata&&num<=100) //等待高电平，开始传输数据位
        {
            GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
            num++;
        }
        num=0;
        while(inputdata&&num<=80)
        {
            GpioGetInputVal(WIFI_IOT_GPIO_IDX_14,&inputdata);
            num++;
        }
        byt <<= 1;         //因高位在前，所以左移byt，最低位补0
        if (num>30)      //将总线电平值读取到byt最低位中
        {
            byt |= 0x01;
        }
    }
 
    return byt;
}

// /*读取一次数据，返回值：Humi-湿度整数部分数据,Temp-温度整数部分数据；返回值: -1-失败，1-成功*/
int DHT11ReadData(int *Humi, int *Temp)
{
    //printf("access\n");
    int sta = 0;
    uint8_t i;
    int buf[5];
 
    if (DHT11RstAndCheck())         //检测响应信号
    {
        for(i=0;i<5;i++)            //读取40位数据
        {
            buf[i]=DHT11ReadByte(); //读取1字节数据
        }
        if(buf[0]+buf[1]+buf[2]+buf[3] == buf[4]) //校验成功
        {
            *Humi = buf[0];         //保存湿度整数部分数据
            *Temp = buf[2];         //保存温度整数部分数据
        }
        sta = 1;
    }
    else //响应失败返回-1
    {
        *Humi = 0xFF; //响应失败返回255
        *Temp = 0xFF; //响应失败返回255
        sta = -1;
    }
    return sta;    
}
//应该延时了1us吧
void delay_us(int num)
{
    while(num--)
    {
        for(int i=0;i<25;i++){}
    }
}