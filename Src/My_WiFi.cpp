#include "My_WiFi.h"
#include <WiFi.h>
/*******************************************************************************
** 方法名称: My_WiFi
** 功能描述: 初始化WiFi
** 参数说明: 名称
** 返回说明: void
** 创建人员: Main
** 创建日期: 2021-04-22
**------------------------------------------------------------------------------
** 修改人员:
** 修改日期:
** 修改描述:
**------------------------------------------------------------------------------
********************************************************************************/
My_WiFi::My_WiFi(const char *AP_SSID, const char *AP_PSK)
{
    strcpy(My_WiFi::AP_PSK, AP_PSK);
    strcpy(My_WiFi::AP_SSID, AP_SSID);
}
void My_WiFi::Init()
{
    uint16_t FRTD = 10;  //尝试时间
    WiFi.mode(WIFI_STA); //设置 Wifi 工作模式

    WiFi.begin(My_WiFi::AP_SSID, My_WiFi::AP_PSK); //连接wifi
    WiFi.setAutoConnect(true);
    Serial.println("WiFi 连接中 ");

    while ((WiFi.status() != WL_CONNECTED) || (FRTD > 0))
    {
        FRTD--;
        delay(50);
        Serial.print(".. ");
    }

    Serial.println(" ");
    Serial.println("无线网络连接成功");
    Serial.print("IP 地址: ");
    Serial.println(WiFi.localIP());
}
