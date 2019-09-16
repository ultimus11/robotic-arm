/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int potpin = 0;
int potpin1= 0;
int potpin2 = 0;
int potpin3 = 0;
int potpin4 = 0;     // analog pin used to connect the potentiometer
                 // values  by pot pins
int val;    // variable to read the value from the analog pin
int val1; 
int val2; 
int val3; 
int val4; 

void setup() {
  myservo.attach(8);
  myservo1.attach(7);
  myservo2.attach(6);
  myservo3.attach(11);
  myservo4.attach(12);
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}


void base360()
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 360);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val);// waits for the servo to get there
  }

void elbow180()
{
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val1);// waits for the servo to get there
  }

void wrist180()
{
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val2);// waits for the servo to get there
  }

 void wrist360()
{
  val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = map(val3, 0, 1023, 0, 360);     // scale it to use it with the servo (value between 0 and 180)
  myservo3.write(val3);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val3);// waits for the servo to get there
  }

void gripper180()
{
  val4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023)
  val4 = map(val4, 0, 1023, 0, 360);     // scale it to use it with the servo (value between 0 and 180)
  myservo4.write(val4);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val4);// waits for the servo to get there
  }



void loop() {
base360();
elbow180();
wrist180();
wrist360();
gripper180();
}                                //this code is for 180 rotation servoes manual controll

