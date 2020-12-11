# BearPi-HM_Nano开发板WiFi编程开发——Wifi连接热点


本示例将演示如何在BearPi-HM_Nano开发板上编写一个Wifi连接热点业务程序

![BearPi-HM_Nano](/applications/BearPi/BearPi-HM_Nano/docs/figures/00_public/BearPi-HM_Nano.png)
## Wifi API分析
本案例主要使用了以下几个API完成Wifi联网
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

## AddDeviceConfig()
```c
WifiErrorCode AddDeviceConfig (const WifiDeviceConfig * config, int * result )
```
**描述：**

添加用于配置连接到热点信息，此函数生成一个networkId

**参数：**

|名字|描述|
|:--|:------| 
| config | 表示要连接的热点信息.  |
| result | 表示生成的networkId。每个networkId匹配一个热点配置  |

## ConnectTo()
```c
WifiErrorCode ConnectTo (int networkId)
```
**描述：**

连接到指定networkId的热点

**参数：**

|名字|描述|
|:--|:------| 
| networkId | 表示与目标热点匹配的网络id.  |




## netifapi_netif_find()
```c
struct netif *netifapi_netif_find(const char *name);
```
**描述：**

获取netif用于IP操作

## netifapi_dhcp_start()

```c
err_t netifapi_dhcp_start(n)
```

**描述：**

启动DHCP, 获取IP


## 软件设计

**主要代码分析**

完成Wifi热点的连接需要以下几步

1. 通过 `RegisterWifiEvent` 接口向系统注册扫描状态监听函数，用于接收扫描状态通知，如扫描动作是否完成等
    
* `OnWifiConnectionChangedHandler` 用于绑定连接状态监听函数，该回调函数有两个参数 `state` 和 `info` ；

    * state表示扫描状态，取值为0和1，1表示热点连接成功；

    * info表示Wi-Fi连接信息，包含以下参数；


        |名字|描述|
        |:--|:------| 
        | ssid [WIFI_MAX_SSID_LEN] | 连接的热点名称.  |
        | bssid [WIFI_MAC_LEN] | MAC地址.  |
        | rssi | 接收信号强度(RSSI).  |
        | connState | Wifi连接状态.  |
        | disconnectedReason | Wi-Fi断开的原因.  |




2. 调用 `EnableWifi` 接口，使能 Wifi。
3. 调用 `AddDeviceConfig` 接口，配置连接的热点信息。
4. 调用 `ConnectTo` 接口，连接到指定networkId的热点。
5. 调用 `WaitConnectResult` 接口等待，该函数中会有15s的时间去轮询连接成功标志位 `g_ConnectSuccess`，当`g_ConnectSuccess` 为 1 时退出等待。
6. 调用 `netifapi_netif_find` 接口，获取 netif 用于 IP 操作
7. 调用 `netifapi_dhcp_start` 接口，启动 DHCP, 获取 IP

```c
static BOOL WifiSTATask(void)
{
    WifiScanInfo* info = NULL;
    unsigned int size = WIFI_SCAN_HOTSPOT_LIMIT;
    static struct netif *g_lwip_netif = NULL;

    osDelay(200);

    printf("<--System Init-->\r\n");

    WiFiInit();

    if(EnableWifi() != WIFI_SUCCESS){
        printf("EnableWifi failed, error = %d\n", error);
        return -1;
    }

    if (IsWifiActive() == 0) {
        printf("Wifi station is not actived.\n");
        return -1;
    }

    info = malloc(sizeof(WifiScanInfo) * WIFI_SCAN_HOTSPOT_LIMIT);

    if(info == NULL)
    {
        return -1;
    }

    while(1){
        g_staScanSuccess = 0;
        ssid_count = 0;        
        error = Scan();
        WaitSacnResult();

        error = GetScanInfoList(info, &size);
        
        for(uint8_t i=0; i<ssid_count; i++){
            if(strcmp(SELECT_WIFI_SSID, info[i].ssid) == 0){

                int result;
                g_ConnectSuccess = 0;
                //Find Select ssid
                WifiDeviceConfig select_ap_config = {0};
                strcpy(select_ap_config.ssid, info[i].ssid);
                strcpy(select_ap_config.preSharedKey, SELECT_WIFI_PASSWORD);
                select_ap_config.securityType = info[i].securityType;
                
                if(AddDeviceConfig(&select_ap_config, &result) == WIFI_SUCCESS){
                    if(ConnectTo(result) == WIFI_SUCCESS && WaitConnectResult() == 1){                        
                        printf("connect succeed!\r\n");                        
                        g_lwip_netif = netifapi_netif_find(SELECT_WLAN_PORT);

                        if(g_lwip_netif){
                            result = netifapi_dhcp_start(g_lwip_netif);
                            printf("net dhcp start:%d\r\n", result);

                            int DHCP_STATE_OK = 1;
                            //Successful
                            while(netifapi_dhcp_is_bound(g_lwip_netif) == 0){
                                osDelay(10);
                                printf("Wait DHCP...\r\n");
                                }
                            printf("DHCP succeed!\r\n");
                            while (1)
                            {
                                /* code */
                                osDelay(100);
                            }               
                        }                        
                    }
                    else{
                        printf("connect failed!\r\n");      
                        return 0;
                    }
                }               
                break;
            }
        }
        osDelay(100);
    }    
}
```

## 编译调试

### 修改 BUILD.gn 文件

修改 `applications\BearPi\BearPi-HM_Nano\sample` 路径下 BUILD.gn 文件，指定 `wifi_sta_connect` 参与编译。
```r
#"D1_iot_wifi_sta:wifi_sta",
"D2_iot_wifi_sta_connect:wifi_sta_connect",        
#"D3_iot_udp_client:udp_client",
#"D4_iot_tcp_server:tcp_server",
#"D5_iot_mqtt:iot_mqtt",        
#"D6_iot_cloud_oc:oc_mqtt",
#"D7_iot_cloud_onenet:onenet_mqtt",
```  
    


### 运行结果<a name="section18115713118"></a>

示例代码编译烧录代码后，按下开发板的RESET按键，通过串口助手查看日志，会打印连接到的Wifi热点信息。
```
<--System Init-->

<--Wifi Init-->

register wifi event succeed!

+NOTICE:SCANFINISH
WaitSacnResult:wait success[1]s
please check ssid

+NOTICE:CONNECTED
callback function for wifi connect

WaitConnectResult:wait success[2]s
connect succeed!

net dhcp start:0

server :
	server_id : 192.168.0.1
	mask : 255.255.255.0, 1
	gw : 192.168.0.1
	T0 : 7200
	T1 : 3600
	T2 : 6300
clients <1> :
	mac_idx mac             addr            state   lease   tries   rto     
	0       281131acd14a    192.168.0.230   12      0       1       17 
```


