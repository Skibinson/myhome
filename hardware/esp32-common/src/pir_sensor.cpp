#include "pir_sensor.h"

bool PIRSensor::begin() {
    pinMode(PIRPIN, INPUT);
    delay(1000);
    _name = "PIR";
    return true;
}

float PIRSensor::read() {
    lastValue = digitalread(PIRPIN) == HIGH; 
    return lastValue ? 1.0f : 0.0f;
}

String PIRSensor::getName() {
    return _name; 
}
