#pragma once
#include <Arduino.h>

class LEDController {
public:
    LEDController(uint8_t pin);
    void init();
    void update(float currentTemp);
private:
    uint8_t pin;
    unsigned long lastToggleTime;
    bool ledState;
};