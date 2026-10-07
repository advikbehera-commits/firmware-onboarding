#include "BMEI2CInterface.h"

bool BMEI2CInterface::init() {
    return bme.begin(BMEConstants::I2C_ADDRESS);
}

float BMEI2CInterface::readTemperature() {
    return bme.readTemperature();
}

float BMEI2CInterface::readPressure() {
    return bme.readPressure() / 100.0F;
}

float BMEI2CInterface::readHumidity() {
    return bme.readHumidity();
}
