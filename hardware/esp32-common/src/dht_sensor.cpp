#include "dht_sensor.h"

DHT11Sensor::DHT11Sensor(uint8_t pin) {
    _pin = pin;
    _name = "temperature";
    dht(_pin, DHT11);
}

bool DHT11Sensor::begin() {
    dht.begin(0, 0);
    return true;
}

float DHT11Sensor::read() {
    lastValueT = dht.readTemperature();
    return lastValueT;
}

float DHT11Sensor::readHum() {
    lastValueH = dht.readHumidity();
    return lastValueH;
}

String DHT11Sensor::getName() {
    return _name;
}