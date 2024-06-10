#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "mq2.h"

#define TASK_STACK_SIZE 1024*8
#define TASK_PRIO 25

static void Example_Task(void)
{
    float SMOKE_ppm=0;
    Init_mq2();
    /****传感器校准****/
    usleep(1000000);        // 开机1s后进行校准
    MQ2_PPM_Calibration();  // 校准传感器
    
    while(1)
    {   
        SMOKE_ppm = Get_MQ2_PPM();
        printf("SMOKE_PPM:%.3f ", SMOKE_ppm);
        if(SMOKE_ppm > 100){
            printf("Warning! SMOKE_PPM_too_high! \n");
        }else{
            printf("\n");
        }
        usleep(1000000);                        // 延时1s        
    } 
}

static void Run(void)
{
    osThreadAttr_t attr;

    attr.name = "Example_Task";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = TASK_STACK_SIZE;
    attr.priority = TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)Example_Task, NULL, &attr) == NULL) {
        printf("Falied to create Example_Task!\n");
    }
}
APP_FEATURE_INIT(Run);