#include <Servo.h> 
#include <AFMotor.h>
AF_DCMotor motor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
int usbchdktrigger = 2;
 
Servo myservo;  // create servo object to control a servo 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(105);              // tell servo to go to position in variable 'pos' 
  pinMode(usbchdktrigger, OUTPUT);
  digitalWrite(usbchdktrigger, LOW);  //Make trigger inactive for now until after first movement of panorama head
  motor.setSpeed(255);     // set the speed to 200/255
  delay(5000);  
} 
 
 
void loop() 
{ 
  while(pos < 50){
    motor.run(FORWARD); //Move panorama head anti-clockwise   
    delay(1500); 
    motor.run(RELEASE); //Stop moving to allow picture to be taken
    delay(1000);
 
    myservo.write(85);              // tell servo to go to position in variable 'pos'
    delay(500);
    digitalWrite(usbchdktrigger, HIGH);
    delay(200);
    digitalWrite(usbchdktrigger, LOW);
    delay(1500);
 
    myservo.write(105);              // tell servo to go to position in variable 'pos' 
    delay(500);
    digitalWrite(usbchdktrigger, HIGH);
    delay(200);
    digitalWrite(usbchdktrigger, LOW);
    delay(1500);
 
    myservo.write(150);              // tell servo to go to position in variable 'pos' 
    delay(500);
    digitalWrite(usbchdktrigger, HIGH);
    delay(200);
    digitalWrite(usbchdktrigger, LOW);
    delay(1500); 
 
    myservo.write(180);              // tell servo to go to position in variable 'pos' 
    delay(500);
    digitalWrite(usbchdktrigger, HIGH);
    delay(200);
    digitalWrite(usbchdktrigger, LOW);
    delay(1000);
 
    myservo.write(105);              // tell servo to go to position in variable 'pos' 
    pos++;
  }
}
