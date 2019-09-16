/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservoelbow;
Servo myservowrist1;
Servo myservowrist2;
Servo myservogripper1;

int potpinbase = 0;
int potpinelbow= 0;
int potpinwrist1 = 0;
int potpinwrist2 = 0;
int potpingripper1 = 0;     // analog pin used to connect the potentiometer
                 // values  by pot pins
int val;    // variable to read the value from the analog pin
int val1; 
int val2; 
int val3; 
int val4; 

void setup() {
  myservo.attach(8);
  myservoelbow.attach(9);
  myservowrist1.attach(10);
  myservowrist2.attach(11);
  myservogripper1.attach(12);
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}


void base360()
{
  val = analogRead(potpinbase);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 360);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val);// waits for the servo to get there
  }

void elbow180()
{
  val1 = analogRead(potpinelbow);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservoelbow.write(val1);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val1);// waits for the servo to get there
  }

void wrist180()
{
  val2 = analogRead(potpinwrist1);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservowrist1.write(val2);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val2);// waits for the servo to get there
  }

 void wrist360()
{
  val3 = analogRead(potpinwrist2);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = map(val3, 0, 1023, 0, 360);     // scale it to use it with the servo (value between 0 and 180)
  myservowrist2.write(val3);                  // sets the servo position according to the scaled value
  delay(15);         
  Serial.println(val3);// waits for the servo to get there
  }

void gripper180()
{
  val4 = analogRead(potpingripper1);            // reads the value of the potentiometer (value between 0 and 1023)
  val4 = map(val4, 0, 1023, 0, 360);     // scale it to use it with the servo (value between 0 and 180)
  myservogripper1.write(val4);                  // sets the servo position according to the scaled value
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

