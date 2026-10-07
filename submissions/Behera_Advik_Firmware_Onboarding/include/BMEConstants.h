#pragma once
#include <Arduino.h>

namespace BMEConstants {
    constexpr uint8_t I2C_ADDRESS = 0x76;
    constexpr uint8_t CS_PIN = 10;
    constexpr float TEMP_THRESHOLD = 25.0f;
}