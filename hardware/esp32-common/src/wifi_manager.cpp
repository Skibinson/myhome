#include "wifi_manager.h"
#include <Arduino.h>

WifiManager::WifiManager(const char* _ssid, const char* _pwd)
{
    WIFI_SSID = _ssid;
    WIFI_PASSWORD = _pwd;
}

void WifiManager::connect()
{
    int attempts = 0;
    Serial.print("Attempting to connect to network, SSID: ");
    Serial.println(WIFI_SSID);
    while (status != WL_CONNECTED && attempts < 10)
    {
        attempts++;
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        delay(3000);                                    // delay between attempts 3 sec
        status = WiFi.status();
    }
    if (status == WL_CONNECTED)
    {
        Serial.println("You are connected to the network.");
    }
    else if (status == WL_CONNECT_FAILED)
    {
        Serial.println("Couldn't connect to network.");
    }
}

bool WifiManager::isConnected()
{
    status = WiFi.status();
    if (status == WL_CONNECTED)
    {
        return true;
    }

    return false;
}

String WifiManager::getLocalIP()
{
    if (status == WL_CONNECTED)
    {
        return WiFi.localIP().toString();
    }
    return "Not connected";
}

int WifiManager::getRSSI()
{
    if (status == WL_CONNECTED)
    {
        return WiFi.RSSI();
    }
    return 0; 
}

void WifiManager::disconnect()
{
    WiFi.disconnect();
}

void WifiManager::printStatus()
{
    if(status != WL_CONNECTED)
    {
        Serial.println("You are not connected to network.");
        Serial.print("Statuscode: ");
        Serial.println(status);
    }
    else if (status == WL_CONNECTED)
    {
        Serial.print("You are connected to network. SSID: ");
        Serial.println(WIFI_SSID);
        Serial.print("IP address: ");
        Serial.println(getLocalIP());
        Serial.print("Signal level: ");
        Serial.print(getRSSI());
        Serial.println("dBm");
    }

}

int WifiManager::getStatusCode() {
    return WiFi.status();  // возвращает реальный статус
}