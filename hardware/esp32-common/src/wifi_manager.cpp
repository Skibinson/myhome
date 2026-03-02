#include <WiFi.h>
#include <wifi_config.h>
#include <wifi_manager.h>

void setup()
{
    connectToWifi();
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connection lost. Reconnecting...");
        connectToWifi();

    }
    delay(5000);
}

void connectToWifi()
{
    Serial.print("Connecting to WiFi");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20)
    {
        delay(500);
        Serial.println(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\n Connected! IP: " + WiFi.localIP().toString());

    } else {
        Serial.println("\nFailed to connect.");
    }
}


