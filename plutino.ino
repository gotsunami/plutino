/*
 * Code for waving robot: greats you when you get close 
 *
 * ----------------------------------
 * $Author: ab@gotsunami $
 * $Date: 2016-06-08
 * $Revision: 1 $
 * ----------------------------------
 */

#include <Ultrasonic.h>
#include <Servo.h> 

#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define SERVO_PIN    12

Ultrasonic eyes(TRIGGER_PIN, ECHO_PIN);
Servo arm; 
int theta;
int dtheta;

void setup() {
  theta = 30;
  arm.attach(SERVO_PIN);
  arm.write(theta);
  Serial.begin(9600);
}

void loop() {
  float cmMsec, inMsec;
  long microsec = eyes.timing();

  cmMsec = eyes.convert(microsec, Ultrasonic::CM);
/*   inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); */
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.println(cmMsec);
/*   Serial.print(", IN: "); */
/*   Serial.println(inMsec); */


  if (cmMsec > 60) {
    theta = 30;
  } else {
    if (theta == 90) {
      theta = 60;
    } else {
      theta = 90;
    }
  }
  arm.write(theta);
  delay(500);
}