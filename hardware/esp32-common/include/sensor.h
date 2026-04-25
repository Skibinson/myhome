#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <Arduino.h>

class sensorBase {
protected:
    virtual ~sensorBase() {}
    virtual void begin() = 0;
    virtual float read() = 0;
    virtual std::string getName() = 0;
};


class sensorTemperature: public sensorBase {
private:
    String device;
};

#endif