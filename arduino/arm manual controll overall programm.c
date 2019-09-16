/*NOTE: Four Servos of the Robotic Arm are connected to 4 PWM Pins of Arduino 
and these 4 servos are named a, b, c and d. 
If you want to control servo a, then type "90a/", 
where "90" is the PWM value (range is 0 - 255), 
"a" means servo a and "/" is string parse delimiter. 
Some other examples: 100a/ or 120b/ or 40c/ or 25d/
*/

String readString;
int x=90, y=90, z=90, p=90; 
#include <Servo.h> 
Servo myservoa, myservob, myservoc, myservod;

void setup() 
{
  Serial.begin(9600);


  myservoa.attach(3); 
  myservob.attach(5); 
  myservoc.attach(6);
  myservod.attach(9); 
  myservoa.write(x);
  myservob.write(y);
  myservoc.write(z);
  myservod.write(p);
}

void loop() 
{
  if (Serial.available())  
  {
    char m = Serial.read();
    if (m == '/') 
    {
      if (readString.length() >1) 
      {
        Serial.println(readString);

        int temp = readString.toInt();
        
          Serial.print("writing Angle: ");
          Serial.println(temp);
          if(readString.indexOf('a') >=0)
          {
            if (temp>x)
            {
              for (int i=x; i<temp; i++)
              {
                myservoa.write(i);
                delay(10);
              }
              x=temp;
            }
            else 
            {
            for (int i=x; i>temp; i--)
              {
                myservoa.write(i);
                delay(30);
              }
            }
            x=temp;
         }
         //next partition         
          if(readString.indexOf('b') >=0)
          {
            if (temp>y)
            {
              for (int i=y; i<temp; i++)
             { myservob.write(i);
              delay(10);
             }
              y=temp;
            }
            else 
            {
            for (int i=y; i>temp; i--)
             { 
              myservob.write(i);
              delay(10);
             }
              y=temp;
          }
         }
         // next partition
          if(readString.indexOf('c') >=0) //myservoc.write(n);
          {
            if (temp>z)
            {
              for (int i=z; i<temp; i++)
              {myservoc.write(i);
              delay(10);}
              z=temp;
            }
            else 
            {
            for (int i=z; i>temp; i--)
             { 
              myservoc.write(i);
              delay(10);
              }
              z=temp;
            }
         }
// next partition
         if(readString.indexOf('d') >=0)
          {
            if (temp>p)
            {
              for (int i=p; i<temp; i++)
              {
                myservod.write(i);
                delay(10);
              }
              p=temp;
            }
            else 
            {
            for (int i=p; i>temp; i--)
              {
                myservod.write(i);
                delay(30);
              }
            }
            p=temp;
         }

       readString="";
      }
    }  
    else 
    {     
      readString += m;
    }
  }
}