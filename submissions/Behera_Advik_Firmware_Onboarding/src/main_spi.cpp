#include <Arduino.h>
#include "BMEConstants.h"
#include "BMESPIInterface.h"
#include "LEDController.h"

BMESPIInterface bmeSensor(BMEConstants::CS_PIN);
LEDController led(LED_BUILTIN);

void setup() {
    Serial.begin(115200);
    led.init();
    
    if (!bmeSensor.init()) {
        Serial.println("Could not find a valid BME280 sensor over SPI!");
    }
}

void loop() {
    float temp = bmeSensor.readTemperature();
    led.update(temp);
    delay(10);
}