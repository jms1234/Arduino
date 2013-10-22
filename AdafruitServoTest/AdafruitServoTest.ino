// This code is based on the adafruit sample code and adapted to digital servos

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Initialize adafruit driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Max and min pulse width for the servos should be 600 to 2400 us, according to the online data
#define SERVOMIN  600 // this is the min pulse length count (out of 4096)
#define SERVOMAX  2400 // this is the max pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  
  pwm.begin();
  
  pwm.setPWMFreq(300);  // Digital servo has 300 updates per second
}

// You can use setServoPulse(0, seconds) to set the pulse length in seconds; However, it's not a precise
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  // Set pulselength
  // Note: You can use map(degrees, 0, 180, SERVOMIN, SERVOMAX) to convert degrees to pulselength
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 300;   // 300 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  // Drive each servo one at a time in a back and forth sweeping motion
  // Speed can be varied throughout the cycle also by setting high/low limits
  // Example: pwm.setPWM(15, 1024, 3072) goes low for the first 25%, ramps up to high, then back to low at 75%
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(1, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(1, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(2, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(2, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(3, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(3, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(4, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(4, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(5, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(5, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(6, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(6, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(7, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(7, 0, pulselen);
  }
}
