#include <Arduino.h>
#include "LEDController.h"
#include "BMEConstants.h"

LEDController::LEDController(uint8_t pin) : pin(pin), lastToggleTime(0), ledState(false) {}

void LEDController::init() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void LEDController::update(float currentTemp) {
    unsigned long interval = (currentTemp > BMEConstants::TEMP_THRESHOLD) ? 200 : 1000;
    
    if (millis() - lastToggleTime >= interval) {
        lastToggleTime = millis();
        ledState = !ledState;
        digitalWrite(pin, ledState ? HIGH : LOW);
    }
}