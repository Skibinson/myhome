#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H
#include <WiFi.h>
#include "wifi_config.h"

class WifiManager {
private:
    const char* WIFI_SSID = WIFI_SSID;
    const char* WIFI_PASSWORD = WIFI_PASSWORD;

    bool is_conected;

};


#endif