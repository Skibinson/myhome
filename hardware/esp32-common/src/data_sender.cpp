#include "data_sender.h"

DataSender::DataSender(const String& url, const String& id)
{
    serverUrl = url;
    deviceId = id;
}

void DataSender::begin()
{
    Serial.println("DataSender initialized for device: " + deviceId);
}

String DataSender::buildJSON(float temperature, bool motion, bool leak)
{
    StaticJsonDocument<256> doc;
    doc["device_id"] = deviceId;
    JsonObject readings = doc.createNestedObject("readings");
    readings["temperature"] = temperature;
    readings["motion"] = motion;
    readings["leak"] = leak;

    String dataJSON;
    serializeJson(doc, dataJSON);
    
    return dataJSON;
}

bool DataSender::httpPost(const String& payload)
{
    HTTPClient http; 
    http.addHeader("Content-Type", "application/json");
    http.setTimeout(100);

    int status = http.POST(payload);

    if (status == 200 || status == 201)
    {
        http.end();
        return true;
    }
    else {
        String error = http.getString();
        Serial.println("HTTP error: " + error);
    }
    http.end();

    return false;
}

bool DataSender::sendData(float temperature, 
                           bool motion, bool leak) {
    
    String json = buildJSON(temperature, motion, leak);
    
    Serial.println("Sending: " + json);
    
    for (int attempt = 0; attempt < maxRetries; attempt++) {
        if (attempt > 0) {
            Serial.print("Retry ");
            Serial.print(attempt + 1);
            Serial.print("/");
            Serial.println(maxRetries);
            delay(1000);
        }
        
        if (httpPost(json)) {
            Serial.println("Data sent successfully");
            return true;
        }
    }
    
    Serial.println("Failed to send data after " + String(maxRetries) + " attempts");
    return false;
}

