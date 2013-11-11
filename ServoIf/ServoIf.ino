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
int pulsestart1 = 0;
int pulsestart2 = 0;
int pulsestart3 = 0;
int pulsestart4 = 0;
int pulsestart5 = 0;
int pulsestart6 = 0;
int pulsestart7 = 0;

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
  // Drive each servo one at a time in a back and forth sweeping motion
  // Speed can be varied throughout the cycle also by setting high/low limits
  // Example: pwm.setPWM(15, 1024, 3072) goes low for the first 25%, ramps up to high, then back to low at 75%
  for (uint16_t pulselen = 0; pulselen < endcount; pulselen++) {
    if (pulselen >= 0 && pulselen < framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= framecount && pulselen < 2*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 2*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 2*framecount && pulselen < 3*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 3*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }


    }
    if (pulselen >= 3*framecount && pulselen < 4*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 4*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 4*framecount && pulselen < 5*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 5*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 5*framecount && pulselen < 6*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 6*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 6*framecount && pulselen < 7*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 7*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 7*framecount && pulselen < 8*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 8*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 8*framecount && pulselen < 9*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 9*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 9*framecount && pulselen < 10*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 10*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 10*framecount && pulselen < 11*framecount+pulsestart1){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 11*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 11*framecount+pulsestart1 && pulselen < 12*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 12*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 12*framecount && pulselen < 13*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 13*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 13*framecount && pulselen < 14*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 14*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 14*framecount && pulselen < 15*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 15*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 15*framecount && pulselen < 16*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 16*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 16*framecount && pulselen < 17*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 17*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 17*framecount && pulselen < 18*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 18*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 18*framecount && pulselen < 19*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 19*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 19*framecount && pulselen < 20*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 20*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 20*framecount && pulselen < 21*framecount+pulsestart1){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 21*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 21*framecount+pulsestart1 && pulselen < 22*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 22*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 22*framecount && pulselen < 23*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 23*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 23*framecount && pulselen < 24*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 24*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 24*framecount && pulselen < 25*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 25*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 25*framecount && pulselen < 26*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 26*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 26*framecount && pulselen < 27*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 27*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 27*framecount && pulselen < 28*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 28*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 28*framecount && pulselen < 29*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 29*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
    if (pulselen >= 29*framecount && pulselen < 30*framecount){
      pwm.setPWM(1, 0, 1*framecount+pulsestart1);
      pwm.setPWM(2, 0, 1*framecount+pulsestart2);
      pwm.setPWM(3, 0, 1*framecount+pulsestart3);
      pwm.setPWM(4, 0, 1*framecount+pulsestart4);
      pwm.setPWM(5, 0, 1*framecount+pulsestart5);
      pwm.setPWM(6, 0, 1*framecount+pulsestart6);
      pwm.setPWM(7, 0, 1*framecount+pulsestart7);
      if (pulselen == 30*framecount - 1){
        pulsestart1 = 1*framecount+pulsestart1;
        pulsestart2 = 1*framecount+pulsestart2;
        pulsestart3 = 1*framecount+pulsestart3;
        pulsestart4 = 1*framecount+pulsestart4;
        pulsestart5 = 1*framecount+pulsestart5;
        pulsestart6 = 1*framecount+pulsestart6;
        pulsestart7 = 1*framecount+pulsestart7;
      }
    }
  }
}


