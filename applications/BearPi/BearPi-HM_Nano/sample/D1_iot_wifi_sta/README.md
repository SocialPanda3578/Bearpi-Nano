# BearPi-HM_Nano开发板WiFi编程开发——Wifi热点扫描


本示例将演示如何在BearPi-HM_Nano开发板上编写一个Wifi热点扫描业务程序

![BearPi-HM_Nano](/applications/BearPi/BearPi-HM_Nano/docs/figures/00_public/BearPi-HM_Nano.png)
## Wifi API分析
本案例主要使用了以下几个API完成Wifi热点扫描
## RegisterWifiEvent()
```c
WifiErrorCode RegisterWifiEvent (WifiEvent * event)
```
 **描述：**
为指定的Wi-Fi事件注册回调函数。当WifiEvent中定义的Wi-Fi事件发生时，将调用已注册的回调函数
**参数：**

|名字|描述|
|:--|:------| 
| event | 表示要注册回调的事件.  |


## EnableWifi()
```c
WifiErrorCode EnableWifi (void )
```
**描述：**

启用STA模式

## Scan()
```c
WifiErrorCode Scan (void )
```
**描述：**

启动Wi-Fi扫描

## GetScanInfoList()
```c
WifiErrorCode GetScanInfoList (WifiScanInfo * result, unsigned int * size )
```
**描述：**

获取在Wi-Fi扫描中检测到的热点列表。Wi-Fi扫描完成后，才能获得热点列表。

**参数：**

|名字|描述|
|:--|:------| 
| result | 表示在Wi-Fi扫描中检测到的热点列表.  |
| size | 表示扫描出的Wifi热点数量  |



## DisableWifi()
```c
WifiErrorCode DisableWifi (void )
```
**描述：**

关闭STA模式



## 软件设计

**主要代码分析**

完成Wifi热点的扫描需要以下几步

1. 通过 `RegisterWifiEvent` 接口向系统注册扫描状态监听函数，用于接收扫描状态通知，如扫描动作是否完成等
    
    * `OnWifiScanStateChangedHandler` 用于绑定扫描状态监听函数，该回调函数有两个参数 `state` 和 `size` ；

        * state表示扫描状态，取值为0和1，1表示扫描动作完成；
        * size表示扫描到的热点个数；
    * 当扫描动作完成后且有扫描到Wifi热点，该回调函数会将扫描成功标志位 `g_staScanSuccess` 置 1 
2. 调用 `EnableWifi` 接口，使能 Wifi STA 模式
3. 调用 `Scan` 接口，触发Wifi扫描动作。
4. 调用 `WaitSacnResult` 接口等待，该函数中会有15s的时间去轮询扫描成功标志位 `g_staScanSuccess`，当`g_staScanSuccess` 为 1 时退出等待。
5. 调用 `GetScanInfoList` 函数获取扫描结果，GetScanResult函数有两个第二个参数；
    * 第一个参数result指向用于存放结果的数组，需要大于等于WIFI_SCAN_HOTSPOT_LIMIT，
    * 第二个参数size类型为指针是为了内部能够修改它的值，返回后size指向的值是实际搜索到的热点个数；
    * 调用GetScanResult函数前，第二个参数size指向的实际值不能为0，否则会包参数错误；
    
```c
static BOOL WifiSTATask(void)
{
    WifiScanInfo *info = NULL;
    unsigned int size = WIFI_SCAN_HOTSPOT_LIMIT;

    osDelay(200);

    printf("<--System Init-->\r\n");

    WiFiInit();

    if (EnableWifi() != WIFI_IOT_SUCCESS)
    {
        printf("EnableWifi failed, error = %d\n", error);
        return -1;
    }

    if (IsWifiActive() == 0)
    {
        printf("Wifi station is not actived.\n");
        return -1;
    }

    g_staScanSuccess = 0;
    ssid_count = 0;
    error = Scan();
    WaitSacnResult();

    info = malloc(sizeof(WifiScanInfo) * ssid_count);
    if (info == NULL)
    {
        return -1;
    }

    error = GetScanInfoList(info, &size);

    for (uint8_t i = 0; i < ssid_count - 1; i++)
    {
        printf("No:%d, ssid:%s\r\n", i, info[i].ssid);
    }

    osDelay(200);

    free((uint8_t *)info);
    info = NULL;

    while (1)
    {
        osDelay(10);
    }
}
```

## 编译调试

### 修改 BUILD.gn 文件

修改 `applications\BearPi\BearPi-HM_Nano\sample` 路径下 BUILD.gn 文件，指定 `wifi_sta` 参与编译。
```r
"D1_iot_wifi_sta:wifi_sta",
#"D2_iot_wifi_sta_connect:wifi_sta_connect",        
#"D3_iot_udp_client:udp_client",
#"D4_iot_tcp_server:tcp_server",
#"D5_iot_mqtt:iot_mqtt",        
#"D6_iot_cloud_oc:oc_mqtt",
#"D7_iot_cloud_onenet:onenet_mqtt",
```    


### 运行结果<a name="section18115713118"></a>

示例代码编译烧录代码后，按下开发板的RESET按键，通过串口助手查看日志，会打印扫描到的Wifi热点信息。
```
<--System Init-->

<--Wifi Init-->

callback function for wifi scan:0, 0

+NOTICE:SCANFINISH
callback function for wifi scan:1, 22

WaitSacnResult:wait success[1]s

No:0, ssid:DIRECT-UuDESKTOP-O1MFS98msDX

No:1, ssid:DIRECT-E3-HP Laser 136nw

No:2, ssid:iTV-QXxe

No:3, ssid:Hold

No:4, ssid:ChinaNet-A7Vx
```


