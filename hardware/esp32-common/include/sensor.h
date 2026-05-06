#ifndef SENSOR_H
#define SENSOR_H
#include <Arduino.h>

class sensorBase {
protected:
    virtual ~sensorBase() {}
    virtual void begin() = 0;
    virtual float read() = 0;
    virtual String getName() = 0;
};

#endif