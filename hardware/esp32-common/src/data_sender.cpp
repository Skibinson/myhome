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
    JsonArray readings = doc.createNestedArray("readings");
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
    http.setTimeout(timeoutMs);

    status = http.post(payload);

    if (status == 200 || status == 201)
    {
        http.end();
        return true;
    }
    else {
        error = http.getString();
        Sertial.println("HTTP error: " + status + ":" + error);
    }
    http.end();

    return false;
}

