#include "sensor.h"
#include <Arduino.h>

void tempSensor::begin()
{
    device = "AHT_20";
    
}

float tempSensor::read()
{
    float mockTemp;
    if (millis() - lastChanged > 10000)
    {
        // mockTemp = random(-10, 10) / 10.0;
        mockTemp = 10;
        lastChanged = millis();
    }
    return 20.0;
}

std::string tempSensor::getName()
{
    return "temperature";
}