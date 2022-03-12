// #include "My_WiFi.h"
// #include <ArduinoJson.h>
// #include <HTTPClient.h>

// /*WiFi 配置*/
// #define My_SSID "esp"
// #define My_PSK "66666666"

// /*****************************************************************************/
// const char *WeatherHOST = "http://api.seniverse.com";
// char WeatherInput[256];
// HTTPClient WeatherHttp; //天气HTTP
// String WeatherGetUrl;   //天气URL

// // typedef struct weather
// // {
// //     char weatherinfo_city[6]; // "菏泽"
// //     char weatherinfo_temp[4]; // "22.7"
// //     char weatherinfo_WD[6];   // "西风"
// //     char weatherinfo_WS[10];  // "小于3级"
// //     char weatherinfo_SD[4];   // "66%"     湿度
// //     char weatherinfo_AP[10];  // "1001.5hPa"   气压
// //     char weatherinfo_time[6]; // "18:00"   时间
// //     int httpcode;
// // } WeatherStruct;

// /*****************************************************************************/

// void WeatherInit()
// {
//     WeatherGetUrl = String(WeatherHOST) + "v3/weather/now.json?key=SXygZHJn6d3INMfzC&location=beijing&language=zh-Hans&unit=c"; //url拼接
//     WeatherHttp.setTimeout(500);                                                                                                //设置超时时间
//     WeatherHttp.begin(WeatherGetUrl);
//                                                                                          //初始化http
// }
// WeatherStruct Weather()
// {
//     WeatherStruct Weathertemp;
//     int httpCode = WeatherHttp.GET(); //GET请求代码
//     Weathertemp.httpcode = httpCode;
//     if (httpCode > 0)
//     {
//         if (httpCode == HTTP_CODE_OK)
//         {
//             strcpy(WeatherInput, (char *)WeatherHttp.getString().c_str());
//             Serial.println(WeatherInput);
//             StaticJsonDocument<256> doc;
//             DeserializationError error = deserializeJson(doc, WeatherInput, 256);
//             if (error)
//             {
//                 Serial.print(F("反序列化Json() 失败: "));
//                 Serial.println(error.f_str());
//             }

//             JsonObject results_0 = doc["results"][0];

//             JsonObject results_0_location = results_0["location"];
//             const char *results_0_location_id = results_0_location["id"];                           // "WW607X60CDS4"
//             const char *results_0_location_name = results_0_location["name"];                       // "菏泽"
//             const char *results_0_location_country = results_0_location["country"];                 // "CN"
//             const char *results_0_location_path = results_0_location["path"];                       // "菏泽,菏泽,山东,中国"
//             const char *results_0_location_timezone = results_0_location["timezone"];               // "Asia/Shanghai"
//             const char *results_0_location_timezone_offset = results_0_location["timezone_offset"]; // "+08:00"

//             JsonObject results_0_now = results_0["now"];
//             const char *results_0_now_text = results_0_now["text"];               // "阴"
//             const char *results_0_now_code = results_0_now["code"];               // "9"
//             const char *results_0_now_temperature = results_0_now["temperature"]; // "22"

//             const char *results_0_last_update = results_0["last_update"]; // "2021-05-06T09:40:00+08:00"

//             Serial.print(results_0_last_update);
//         }
//     }
//     else
//     {
//         Serial.printf("[HTTP] GET... 失败, 错误: %s\n", WeatherHttp.errorToString(httpCode).c_str());
//     }
//     WeatherHttp.end();
//     return Weathertemp;
// }
// void setup()
// {
//     Serial.begin(115200);
//     My_WiFi("esp", "66666666");
//     WeatherInit();
// }

// void loop()
// {
//     WeatherStruct temp = Weather();
//     delay(5000);
// }
