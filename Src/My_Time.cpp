#include "My_Time.h"

#include <ArduinoJson.h>
#include <HTTPClient.h>

My_Time::My_Time(const char *Api)
{
    My_Time::TimeGetUrl = String(My_Time::TimeHOST) + String(Api);
}

void My_Time::Init()
{
    My_Time::TimeHttp.setTimeout(500); //设置超时时间
    My_Time::TimeHttp.begin(My_Time::TimeGetUrl);
    // Serial.println(My_Time::TimeGetUrl);
}

void My_Time::Time()
{
    int httpCode = My_Time::TimeHttp.GET();
    if (httpCode > 0)
    {
        if (httpCode == HTTP_CODE_OK)
        {
            strcpy(My_Time::TimeInput, (char *)My_Time::TimeHttp.getString().c_str()); // 将返回的文本拷贝到数组
            // Serial.println(My_Time::TimeInput);                                        //测试
            StaticJsonDocument<64> doc;
            DeserializationError error = deserializeJson(doc, My_Time::TimeInput, 64);
            if (error)
            {
                Serial.print(F("deserializeJson() failed: "));
                Serial.println(error.f_str());
                return;
            }
            const char *sysTime2 = doc["sysTime2"]; // "2021-05-06 21:40:51"
            const char *sysTime1 = doc["sysTime1"]; // "20210506214051"
            Serial.println(sysTime2);               //测试
        }
    }
    else
    {
        Serial.printf("[HTTP] GET... 失败, 错误: %s\n", TimeHttp.errorToString(httpCode).c_str());
    }
    My_Time::TimeHttp.end();
}

void My_Time::test()
{
    My_Time::Time();
}
