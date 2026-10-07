#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

BMEI2CInterface bmeSensor;
LEDController led(LED_BUILTIN);

void setup() {
    Serial.begin(115200);
    led.init();
    
    if (!bmeSensor.init()) {
        Serial.println("Could not find a valid BME280 sensor over I2C!");
    }
}

void loop() {
    float temp = bmeSensor.readTemperature();
    led.update(temp);
    Serial.println(temp);
    delay(10);
}