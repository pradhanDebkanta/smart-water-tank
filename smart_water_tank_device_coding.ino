#include <LiquidCrystal.h>
LiquidCrystal LCD(7,6,5,4,3,2);
//creating the LiquidCrystal object normal LCD
const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int buzzer =30; 
const int trigPin = 11;
const int echoPin = 12;
const int motor = 13;
long duration;
//int a=30;        //initial distance
int distance;
//int b=30-distance;//fill up distance
//float volume;


void setup() {
LCD.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);
LCD.print("WATER LEVEL");
LCD.setCursor(0,1);
LCD.print(" indicator ");
delay(2000);

}


void loop() {
LCD.clear();


  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
 // volume=b*0.144;
  LCD.clear();  
  LCD.print("Water Volume Is:");
  LCD.setCursor(0,1);
  LCD.print("Now");
  LCD.print(3.0*1.44-distance*0.144);
  LCD.print("Lt");
  delay(2000);

  //loop begins here
  if(distance>=25)
  {
    digitalWrite(motor, HIGH);
    digitalWrite(redLED, HIGH);
    delay(2000);
    digitalWrite(redLED, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
    delay(500);
    LCD.clear();
    LCD.print("Water Tank Low");
    LCD.setCursor(0,1);
    LCD.print("Motor Turn On");
    delay(2000);
  }
 
else if(distance<=18&&distance>=16)
{
  digitalWrite(yellowLED, HIGH);
  delay(2000);
  digitalWrite(yellowLED, LOW);
  delay(1000);
  LCD.clear();
  LCD.print("Water Is ");
  LCD.setCursor(0,1);
  LCD.print("Sufficent");
  delay(2000);
}

else if(distance<=5)
{
  digitalWrite(greenLED, HIGH);
  delay(2000);
  digitalWrite(greenLED, LOW);
  delay(1000);
  digitalWrite(buzzer, HIGH);
  delay(2000);
  digitalWrite(buzzer, LOW);
  delay(500);
  digitalWrite(motor, LOW);
  LCD.clear();
  LCD.print("Water Level Full");
  LCD.setCursor(0,1);  
  LCD.print("Motor Turn Off");
  delay(5000);
}
}
