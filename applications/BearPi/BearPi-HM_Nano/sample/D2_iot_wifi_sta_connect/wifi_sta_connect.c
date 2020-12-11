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

#include "lwip/netif.h"
#include "lwip/netifapi.h"
#include "lwip/ip4_addr.h"
#include "lwip/api_shell.h"

#include "cmsis_os2.h"
#include "hos_types.h"
#include "wifi_device.h"
#include "wifiiot_errno.h"
#include "ohos_init.h"

#define DEF_TIMEOUT 15
#define ONE_SECOND 1

static void WiFiInit(void);
static void WaitSacnResult(void);
static int WaitConnectResult(void);
static void OnWifiScanStateChangedHandler(int state, int size);
static void OnWifiConnectionChangedHandler(int state, WifiLinkedInfo *info);
static void OnHotspotStaJoinHandler(StationInfo *info);
static void OnHotspotStateChangedHandler(int state);
static void OnHotspotStaLeaveHandler(StationInfo *info);

static int g_staScanSuccess = 0;
static int g_ConnectSuccess = 0;
static int ssid_count = 0;
WifiEvent g_wifiEventHandler = {0};
WifiErrorCode error;

#define SELECT_WLAN_PORT "wlan0"

#define SELECT_WIFI_SSID "Hold"
#define SELECT_WIFI_PASSWORD "0987654321"

static BOOL WifiSTATask(void)
{
    WifiScanInfo *info = NULL;
    unsigned int size = WIFI_SCAN_HOTSPOT_LIMIT;
    static struct netif *g_lwip_netif = NULL;

    osDelay(200);

    printf("<--System Init-->\r\n");

    WiFiInit();

    if (EnableWifi() != WIFI_SUCCESS)
    {
        printf("EnableWifi failed, error = %d\n", error);
        return -1;
    }

    if (IsWifiActive() == 0)
    {
        printf("Wifi station is not actived.\n");
        return -1;
    }

    info = malloc(sizeof(WifiScanInfo) * WIFI_SCAN_HOTSPOT_LIMIT);

    if (info == NULL)
    {
        return -1;
    }

    while (1)
    {
        g_staScanSuccess = 0;
        ssid_count = 0;
        error = Scan();
        WaitSacnResult();

        error = GetScanInfoList(info, &size);

        for (uint8_t i = 0; i < ssid_count; i++)
        {
            if (strcmp(SELECT_WIFI_SSID, info[i].ssid) == 0)
            {

                int result;
                g_ConnectSuccess = 0;
                
                //Find Select ssid
                WifiDeviceConfig select_ap_config = {0};
                strcpy(select_ap_config.ssid, info[i].ssid);
                strcpy(select_ap_config.preSharedKey, SELECT_WIFI_PASSWORD);
                select_ap_config.securityType = info[i].securityType;

                if (AddDeviceConfig(&select_ap_config, &result) == WIFI_SUCCESS)
                {
                    if (ConnectTo(result) == WIFI_SUCCESS && WaitConnectResult() == 1)
                    {
                        printf("connect succeed!\r\n");
                        g_lwip_netif = netifapi_netif_find(SELECT_WLAN_PORT);

                        if (g_lwip_netif)
                        {
                            result = netifapi_dhcp_start(g_lwip_netif);
                            printf("net dhcp start:%d\r\n", result);

                            //等待 DHCP 获取IP
                            osDelay(200); 

                            netifapi_netif_common(g_lwip_netif, dhcp_clients_info_show, NULL);
                            while (1)
                            {
                                /* code */
                                osDelay(100);
                            }
                        }
                    }
                    else
                    {
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

static void WiFiInit(void)
{
    printf("<--Wifi Init-->\r\n");
    g_wifiEventHandler.OnWifiScanStateChanged = OnWifiScanStateChangedHandler;
    g_wifiEventHandler.OnWifiConnectionChanged = OnWifiConnectionChangedHandler;
    g_wifiEventHandler.OnHotspotStaJoin = OnHotspotStaJoinHandler;
    g_wifiEventHandler.OnHotspotStaLeave = OnHotspotStaLeaveHandler;
    g_wifiEventHandler.OnHotspotStateChanged = OnHotspotStateChangedHandler;
    error = RegisterWifiEvent(&g_wifiEventHandler);
    if (error != WIFI_SUCCESS)
    {
        printf("register wifi event fail!\r\n");
    }
    else
    {
        printf("register wifi event succeed!\r\n");
    }
}

static void OnWifiScanStateChangedHandler(int state, int size)
{
    (void)state;
    if (size > 0)
    {
        ssid_count = size;
        g_staScanSuccess = 1;
    }
    return;
}

static void OnWifiConnectionChangedHandler(int state, WifiLinkedInfo *info)
{
    (void)info;

    if (state > 0)
    {
        g_ConnectSuccess = 1;
        printf("callback function for wifi connect\r\n");
    }
    else
    {
        printf("connect error,please check password\r\n");
    }
    return;
}

static void OnHotspotStaJoinHandler(StationInfo *info)
{
    (void)info;
    printf("STA join AP\n");
    return;
}

static void OnHotspotStaLeaveHandler(StationInfo *info)
{
    (void)info;
    printf("HotspotStaLeave:info is null.\n");
    return;
}

static void OnHotspotStateChangedHandler(int state)
{
    printf("HotspotStateChanged:state is %d.\n", state);
    return;
}

static void WaitSacnResult(void)
{
    int scanTimeout = DEF_TIMEOUT;
    while (scanTimeout > 0)
    {
        sleep(ONE_SECOND);
        scanTimeout--;
        if (g_staScanSuccess == 1)
        {
            printf("WaitSacnResult:wait success[%d]s\n", (DEF_TIMEOUT - scanTimeout));
            break;
        }
    }
    if (scanTimeout <= 0)
    {
        printf("WaitSacnResult:timeout!\n");
    }
}

static int WaitConnectResult(void)
{
    int ConnectTimeout = DEF_TIMEOUT;
    while (ConnectTimeout > 0)
    {
        sleep(1);
        ConnectTimeout--;
        if (g_ConnectSuccess == 1)
        {
            printf("WaitConnectResult:wait success[%d]s\n", (DEF_TIMEOUT - ConnectTimeout));
            break;
        }
    }
    if (ConnectTimeout <= 0)
    {
        printf("WaitConnectResult:timeout!\n");
        return 0;
    }

    return 1;
}

static void WifiClientSTA(void)
{
    osThreadAttr_t attr;

    attr.name = "WifiSTATask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 10240;
    attr.priority = 24;

    if (osThreadNew((osThreadFunc_t)WifiSTATask, NULL, &attr) == NULL)
    {
        printf("Falied to create WifiSTATask!\n");
    }
}

APP_FEATURE_INIT(WifiClientSTA);
