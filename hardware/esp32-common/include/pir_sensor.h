#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H
#include "sensor.h"
#define PIRPIN
class PIRSensor : sensorBase {
public:
    bool begin() override;
    float read() override;
    String getName() override;
private:
    lastValue;
    _name;
}

#endif