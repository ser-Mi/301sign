#include "My_Saying.h"

#include <ArduinoJson.h>
#include <HTTPClient.h>

My_Saying::My_Saying(const char *ch)
{
    My_Saying::SayingGetUrl = String(My_Saying::SayingHOST) + "/?c=";
    My_Saying::SayingGetUrl += String(ch);
    My_Saying::SayingGetUrl += "&encode=json";
}
void My_Saying::Init()
{
    My_Saying::SayingHttp.setTimeout(500);
    My_Saying::SayingHttp.begin(My_Saying::SayingGetUrl);
    // Serial.println(My_Saying::SayingGetUrl);
}
void My_Saying::Saying()
{
    int httpCode = My_Saying::SayingHttp.GET();
    if (httpCode > 0)
    {
        if (httpCode == HTTP_CODE_OK)
        {
            strcpy(My_Saying::SayingInput, (char *)My_Saying::SayingHttp.getString().c_str()); // 将返回的文本拷贝到数组
            // Serial.println(My_Saying::SayingInput);
            StaticJsonDocument<512> doc;

            DeserializationError error = deserializeJson(doc, My_Saying::SayingInput, 512);

            if (error)
            {
                Serial.print(F("反序列化Json() 失败: "));
                Serial.println(error.f_str());
            }
            const char *uuid = doc["uuid"];         // "eec692dc-5efe-473e-b4d3-97800ea1616a"       一言唯一标识；可以链接到 https://hitokoto.cn?uuid=eec692dc-5efe-473e-b4d3-97800ea1616a
            const char *hitokoto = doc["hitokoto"]; // "清风策萍影 远夜如移 纵入冥泥 明镜仍为寄"      一言正文
            const char *from = doc["from"];         // "魔道祖师"                                   一言的出处

            /* 信息筛选
                int id = doc["id"];                     // 3896
                const char *type = doc["type"];         // "d"
                const char *creator = doc["creator"];         // "我養你啊_"
                int creator_uid = doc["creator_uid"];         // 2033
                int reviewer = doc["reviewer"];               // 0
                const char *commit_from = doc["commit_from"]; // "web"
                const char *created_at = doc["created_at"];   // "1537445839"
                int length = doc["length"];                   // 21
            */
            
            Serial.print(hitokoto); //一言正文
            Serial.print("                 ");
            Serial.println(from);     //一言的出处
//            Serial.println(uuid);     //一言唯一标识；可以链接到 https://hitokoto.cn?uuid=7e6677e9-9224-4425-82ae-b84c569f8870
        }
        else
        {
            Serial.println(httpCode);
        }
    }
    else
    {
        Serial.printf("[HTTP] GET... 失败, 错误: %s\n", My_Saying::SayingHttp.errorToString(httpCode).c_str());
    }
    My_Saying::SayingHttp.end();//结束请求
}
