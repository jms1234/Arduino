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
uint16_t endcount = 30000;
uint16_t framecount = endcount/30;
int framestart[7][30] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}; // replace 0 with calculated starting value for frame.
int speed_offset[7][30] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}; // replace 0 with calculated speed multiplier for frame.

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
  Serial.print(pulselength); 
  Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); 
  Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {

  for (char frame = 0 ; frame < 30 ; frame++){  //change the speed selected from the array
    for (char i = 0 ; i < framecount ; i++){      //pulse at the current speed repeated according to framecount
      pwm.setPWM(1, 0, framestart[1][frame] + speed_offset[1][frame]*i);
      pwm.setPWM(2, 0, framestart[2][frame] + speed_offset[2][frame]*i);
      pwm.setPWM(3, 0, framestart[3][frame] + speed_offset[3][frame]*i);
      pwm.setPWM(4, 0, framestart[4][frame] + speed_offset[4][frame]*i);
      pwm.setPWM(5, 0, framestart[5][frame] + speed_offset[5][frame]*i);
      pwm.setPWM(6, 0, framestart[6][frame] + speed_offset[6][frame]*i);
      pwm.setPWM(7, 0, framestart[7][frame] + speed_offset[7][frame]*i);
    }
  }
}

