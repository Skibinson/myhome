#include "wifi_manager.h"
#include "wifi_config.h"
#include <unity.h>
#include <Arduino.h>
#include "../../src/wifi_manager.cpp"

WifiManager* wifi = nullptr;
unsigned long testStartTime;

void setUp()
{
    Serial.println("\n=== SETUP ===");
    wifi = new WifiManager(WIFI_SSID, WIFI_PASSWORD);
    testStartTime = millis();
}

void tearDown()
{
    Serial.println("=== TEARDOWN ===\n");
    delete wifi;
}

void test_real_wifi_connection() {
    TEST_MESSAGE("Attempting to connect to WiFi...");
    Serial.print("SSID: ");
    Serial.println(WIFI_SSID);
    
    wifi->connect();
    
    // Проверяем статус сразу после connect()
    Serial.print("Status after connect: ");
    Serial.println(wifi->getStatusCode());  // добавь этот метод в класс
    
    // Даем время на установку соединения
    int attempts = 0;
    while (!wifi->isConnected() && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }
    Serial.println();
    
    if (wifi->isConnected()) {
        Serial.println("WiFi Connected!");
        Serial.print("IP: ");
        Serial.println(wifi->getLocalIP());
        Serial.print("RSSI: ");
        Serial.println(wifi->getRSSI());
        
        TEST_ASSERT_TRUE_MESSAGE(true, "Connection successful");
    } else {
        Serial.println("WiFi NOT connected");
        Serial.print("Final status code: ");
        Serial.println(wifi->getStatusCode());
        
        TEST_ASSERT_TRUE_MESSAGE(false, "Failed to connect to WiFi");
    }
}

void setup() {
    delay(2000);
    Serial.begin(115200);
    Serial.println("\n\n=================================");
    Serial.println("STARTING WIFI TEST");
    Serial.println("=================================\n");
    
    UNITY_BEGIN();
    RUN_TEST(test_real_wifi_connection);
    UNITY_END();
}

void loop() {}