/**
 * Hardware servo library. Available pins on the Arduino Due: 6, 7, 8, 9.
 */
#ifndef DUE_SERVO_H
#define DUE_SERVO_H

#include <Arduino.h>

#define PWM_DUTY_MIN    544
#define PWM_DUTY_MAX    2400

void writeMicros(int pin, uint16_t dutyCycle);
void initServo(int pin, uint16_t dutyCycle);
#endif