#ifndef SENSOR_H
#define SENSOR_H
#include <string>

class sensorBase {
    virtual void begin() = 0;
    virtual float read() = 0;
    virtual std::string getName() = 0;
};


class tempSensor : public sensorBase {
private:
    float temp = 22.5;
    unsigned long lastChanged = 0;
public:
    void begin();
    float read();
    std::string getName();
};

#endif