#include "sensor.h"
#include "DHT.h"
#define DHTTYPE 11
#define DHTPIN 5
#define DHTCOUNT 1

class DHT11Sensor : public sensorBase {
public:
    DHT11Sensor(uint8_t pin);
    bool begin() override;
    float read() override;
    float readHum();
    String getName() override;
private:
    DHT dht;
    uint8_t _pin;
    String _name;
    float lastValueT;
    float lastValueH;
    
}