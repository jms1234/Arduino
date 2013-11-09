#include <Arduino.h>
#include <DueServo.h>

#define SERVO_PIN 6
bool high = false;

void setup() {
        initServo(SERVO_PIN, 900);
}

void loop() {
        high = !high;
        writeMicros(SERVO_PIN, high?1800:900);
        delay(500);
}
