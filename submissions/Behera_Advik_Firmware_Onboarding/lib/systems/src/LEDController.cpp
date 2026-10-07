#include <Arduino.h>
#include "LEDController.h"
#include "BMEConstants.h"

LEDController::LEDController(uint8_t pin) : pin(pin), lastToggleTime(0), ledState(false) {}

void LEDController::init() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void LEDController::update(float currentTemp) {
    // Map 20.0°C (200) to 32.0°C (320)
    // 20.0°C = 1500 ms (slow), 32.0°C = 80 ms (fast)
    long interval = map((long)(currentTemp * 10.0f), 240, 290, 1500, 80);
    interval = constrain(interval, 80, 1500);

    if (millis() - lastToggleTime >= (unsigned long)interval) {
        lastToggleTime = millis();
        ledState = !ledState;
        digitalWrite(pin, ledState ? HIGH : LOW);
    }
}