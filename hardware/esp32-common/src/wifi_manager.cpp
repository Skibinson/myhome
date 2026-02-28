#include <WiFi.h>
#include <wifi_config.h>

void setup()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi Ok");
    }
    delay(5000);
}
