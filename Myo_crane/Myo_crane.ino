/*
Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <MyoController.h>

#define FIST_PIN 4
#define WAVEIN_PIN 5
#define WAVEOUT_PIN 6
#define FINGERSSPREAD_PIN 7
#define DOUBLETAP_PIN 8

MyoController myo = MyoController();

Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int forward = 12;
int backward = 13;

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 myservo.write(90);

  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  
  myo.initMyo();
  //exit(0);
}

void loop()
{ 
   //Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN,LOW); 
      digitalWrite(WAVEIN_PIN,LOW);
      digitalWrite(WAVEOUT_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      digitalWrite(DOUBLETAP_PIN,LOW);
      analogWrite(forward, 0);
      analogWrite(backward, 0);
      break;
      
    case fist:
      digitalWrite(FIST_PIN,HIGH);  //Pick the weight up
      analogWrite(forward, 255);
      analogWrite(backward, 0);
      myservo.write(pos);
      break;
      
    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH); //Rotate left at max 90 degrees
      analogWrite(forward, 0);
      analogWrite(backward, 0);
      if (pos < 180){
        myservo.write(pos+=1);     
        delay(15);} 
      break;
      
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH); //Rotate right at max 90 degrees
      analogWrite(forward, 0);
      analogWrite(backward, 0);
      if (pos > 0){
        myservo.write(pos-=1);     
        delay(15);} 
      break;
      
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH); //Drop the weight down
      analogWrite(forward, 0);
      analogWrite(backward, 255);
      myservo.write(pos);
      //delay(2000);
      break;
      
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH); //
      analogWrite(forward, 0);
      analogWrite(backward, 0);
      if (pos!=90){
        if (pos > 90)
        {
          for(; pos>=90; pos-=1)     // goes from 180 degrees to 90 degrees
          {
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(5);                       // waits 5ms for the servo to reach the position
          }
         }
        else if (pos < 90)
        {
          for(; pos<=90; pos+=1)     // goes from 90 degrees to 0 degrees
          {
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(5);                       // waits 5ms for the servo to reach the position
          }
         }
      }
      break;
   } 
   delay(10);
}
