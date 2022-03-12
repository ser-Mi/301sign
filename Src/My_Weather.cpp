#include "My_Weather.h"

#include <ArduinoJson.h>
#include <HTTPClient.h>

My_Weather::My_Weather(const char *ApiKey, const char *location)
{
    My_Weather::WeatherGetUrl = String(My_Weather::WeatherHOST) + "v3/weather/now.json?key=";
    My_Weather::WeatherGetUrl += ApiKey;
    My_Weather::WeatherGetUrl += "&location="; //地区
    My_Weather::WeatherGetUrl += location;
    My_Weather::WeatherGetUrl += "&language="; //语言
    My_Weather::WeatherGetUrl += My_Weather::language;
    My_Weather::WeatherGetUrl += "&unit=c"; //数据格式
}

void My_Weather::Init()
{
    My_Weather::WeatherHttp.setTimeout(500); //设置超时时间
    My_Weather::WeatherHttp.begin(My_Weather::WeatherGetUrl);
    // Serial.println(My_Weather::WeatherGetUrl);
}

void My_Weather::Weather()
{
    int httpCode = My_Weather::WeatherHttp.GET();
    if (httpCode > 0)
    {
        if (httpCode == HTTP_CODE_OK)
        {
            strcpy(My_Weather::WeatherInput, (char *)My_Weather::WeatherHttp.getString().c_str()); // 将返回的文本拷贝到数组
            // Serial.println(My_Weather::WeatherInput);                                  //测试

            StaticJsonDocument<256> doc;
            DeserializationError error = deserializeJson(doc, My_Weather::WeatherInput, 300);
            if (error)
            {
                Serial.print(F("反序列化Json() 失败: "));
                Serial.println(error.f_str());
            }

            JsonObject results_0 = doc["results"][0];
            JsonObject results_0_location = results_0["location"];
            JsonObject results_0_now = results_0["now"];
            /*
                const char *results_0_location_id = results_0_location["id"];                           // "WW607X60CDS4"
                const char *results_0_location_country = results_0_location["country"];                 // "CN"
                const char *results_0_location_path = results_0_location["path"];                       // "菏泽,菏泽,山东,中国"
                const char *results_0_location_timezone = results_0_location["timezone"];               // "Asia/Shanghai"
                const char *results_0_location_timezone_offset = results_0_location["timezone_offset"]; // "+08:00"
            */
            const char *results_0_location_name = results_0_location["name"];     // "菏泽"
            const char *results_0_now_text = results_0_now["text"];               // "阴"
            const char *results_0_now_code = results_0_now["code"];               // "9"
            const char *results_0_now_temperature = results_0_now["temperature"]; // "22"
            const char *results_0_last_update = results_0["last_update"];         // "2021-05-06T09:40:00+08:00"

            Serial.println(results_0_location_name);
            Serial.println(results_0_now_text);  
//            Serial.println(results_0_now); 
        }
        else
        {
            Serial.print(httpCode);
        }
    }
    else
    {
        Serial.printf("[HTTP] GET... 失败, 错误: %s\n", WeatherHttp.errorToString(httpCode).c_str());
    }
    My_Weather::WeatherHttp.end();
}
void My_Weather::test()
{
    My_Weather::Weather();
}
