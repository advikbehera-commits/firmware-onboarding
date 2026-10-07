#pragma once
#include <Adafruit_BME280.h>
#include "BMEConstants.h"


class BMESPIInterface {
public:
    BMESPIInterface(uint8_t csPin);
    bool init();
    float readTemperature();
private:
    Adafruit_BME280 bme;
    uint8_t cs_pin;
};