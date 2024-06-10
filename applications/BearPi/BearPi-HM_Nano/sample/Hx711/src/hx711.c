#include "hx711.h"
#include "hi_flashboot_gpio.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#include "wifiiot_adc.h"
#include <stdio.h>
#include "cmsis_os2.h"
#include <ohos_init.h>
#include <unistd.h>
#include <time.h>

long HX711_Buffer = 0;
long Weight_Maopi = 0,Weight_Shiwu = 0;
hi_gpio_value DTval;

#define GapValue 430

//****************************************************
//GPIO初始化
//****************************************************
void HX711_Init(void)
{
    hi_gpio_set_dir(HX711_DT_PIN, HI_GPIO_DIR_IN);
    hi_gpio_set_dir(HX711_SCK_PIN, HI_GPIO_DIR_OUT);
}


//****************************************************
//获取毛皮
//****************************************************
void Get_Maopi(void)
{
	Weight_Maopi = HX711_Read();		
} 

//****************************************************
//获取实物重量
//****************************************************
int Get_Weight(void)
{
	HX711_Buffer = HX711_Read();
	Weight_Shiwu = HX711_Buffer;
	
	Weight_Shiwu = Weight_Shiwu - Weight_Maopi;				//获取称重的实物重量
	Weight_Shiwu = (long)((float)Weight_Shiwu/GapValue); 	
	return Weight_Shiwu;
}

int GetHX711_DT(void)
{
	hi_gpio_get_input_val(HX711_DT_PIN,&DTval);
	return DTval;
}

//****************************************************
//读取HX711
//****************************************************
int32_t HX711_Read(void)
{
    int i;
    int32_t data = 0;
 
    // 等待 HX711 就绪
    while(GetHX711_DT());
 
    // 发送一个脉冲以开始转换
    hi_gpio_set_output_val(HX711_SCK_PIN, LOW);
    usleep(1);
    hi_gpio_set_output_val(HX711_SCK_PIN, HIGH);
    usleep(1);
    hi_gpio_set_output_val(HX711_SCK_PIN, LOW);
 
    // 读取24位数据
    for(i = 0; i < 24; i++) {
        hi_gpio_set_output_val(HX711_SCK_PIN, HIGH);
        usleep(1);
        data <<= 1;
        if(GetHX711_DT()) {
            data++;
        }
        hi_gpio_set_output_val(HX711_SCK_PIN, LOW);
        usleep(1);
    }
 
    // 恢复到默认状态
    hi_gpio_set_output_val(HX711_SCK_PIN, HIGH);
    usleep(1);
    hi_gpio_set_output_val(HX711_SCK_PIN, LOW);
 
    // 判断读数是否为负数
    if(data & 0x800000) {
        data |= 0xff000000;
    }
 
    return data;
}