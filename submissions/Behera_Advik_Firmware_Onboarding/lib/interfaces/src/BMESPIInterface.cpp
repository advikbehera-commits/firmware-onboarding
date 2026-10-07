#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface(uint8_t csPin) : bme(csPin), cs_pin(csPin) {}

bool BMESPIInterface::init() {
    return bme.begin();
}

float BMESPIInterface::readTemperature() {
    return bme.readTemperature();
}