#ifndef DATA_SENDER_H
#define DATA_SENDER_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

class DataSender {
private:
    String serverUrl;
    String deviceId;
    int maxRetries = 3;

    bool httpPost(const String& payload);
    String buildJSON(float temperature, bool motion, bool leak);

public:
    DataSender(const String& url, const String& id);
    void begin(); // http client
    bool sendData(float temperature, bool motion, bool leak);
};


#endif 