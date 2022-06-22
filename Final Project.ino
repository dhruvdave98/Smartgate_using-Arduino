//Name : Dhruv Dave
//Date : 5 Dec. 2020
//Description : Smart gate using ultrasonic sensor with different message (Final Project)

//header files to use different libraries
#include <Servo.h>
#include <LiquidCrystal.h>

//Initialise the Serial LCD.
LiquidCrystal lcd(10,2,3,4,5,6); //These pin numbers are hard coded in on the serial backpack

//initializaing variables and LEDs
float distance = 0, duration;
int trigPin = 12;
int echoPin = 13;
int redLed = 7;
int greenLed = 9;
Servo myservo;

void setup() //setup function run once
{
  myservo.attach(11);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  lcd.begin (16,2); //Initialize the LCD.
}

void loop() //loop fumction runs forever
{
  myservo.write(90); //microservo set to 90(angle), gate is closed
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line
  lcd.print("Gate Closed"); //Print at cursor Location
  delay(5000);
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin and get the sound wave travel time
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  /*Speed of sound is 340 meter per second and 
  we are converting it centimeters*/ 
  distance = (duration*.0343)/2;
  if (distance <= 100) 
  {
    //microservo set to 180(angle), gate is open
    myservo.write(180); 
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    lcd.clear();
    lcd.setCursor(0,0); //goto first column and first line and keep moving
    lcd.print("Welcome"); //Print at cursor Location
    delay(5000); 
    myservo.write(90); //microservo set to 90(angle), gate is closed
  }
  myservo.write(90); //microservo set to 90(angle), gate is closed
}