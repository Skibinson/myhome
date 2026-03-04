#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H
#include <WiFi.h>
#include Arduino.h

class WifiManager {
private:
    const char* WIFI_SSID;
    const char* WIFI_PASSWORD;

    int status = WL_IDLE_STATUS;  // Empty 
public:
    WifiManager(const char* _ssid, const char* _pwd);
    void connect();
    int isConnected();
    String getLocalIP();
    int getRSSI();      // returns strength 
    void printStatus();
    void disconnect();

};


#endif