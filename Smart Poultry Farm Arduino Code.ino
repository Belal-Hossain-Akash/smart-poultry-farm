

#include <Servo.h>   //servo library


Servo servo;
int smoke = A2;
int fanPin = 4;
int pinTemp = A1;
int trigPin = 9;    
int echoPin = 8;   
int servoPin = 7;
int led1= 10;
int led2= 11;
long duration, dist, average;   
long aver[3];   //array for average
int buzzer = 6;
int buzzer1 = 5;


void setup() {       
    Serial.begin(9600);
    pinMode(smoke, INPUT); 
    servo.attach(servoPin); 
    pinMode(fanPin,OUTPUT);
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT); 
   
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach(); 
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
} 

void measure() 
{  
digitalWrite(led1,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 Serial.print(" Distance: ");
 Serial.print(dist);
 dist=(aver[0]+aver[1]+aver[2])/3;
 Serial. print('\n');
 
  
  int temp= analogRead(pinTemp);    //Read the digital pin
  temp = temp * 0.48828125;   // convert output (mv) to readable celcius
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("C");  //print the temperature status
  delay(1000); 
  Serial. print('\n');
  
  
  smoke =analogRead(smoke);
  Serial.print("SMOKE: ");
  Serial.print(smoke);
  Serial. print('\n');
  
  
    if(dist<250)
   { int j;
      for(j=0; j=10000; j++)
      {
      tone(buzzer, 1000);
      delay(100);
      noTone(buzzer);
      delay(100);
      }} 
  

if ( temp<25 )
{
//Change distance as per your need
  digitalWrite(led2,HIGH);
  tone(buzzer1, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer1);     // Stop sound...
  delay(1000);        // ...for 1sec
  servo.attach(servoPin);
  delay(1);
  servo.write(90);  
  delay(3000);       

 servo.detach();   
  
}
  else
    digitalWrite(fanPin, LOW);
    
  

  
  
  if(temp>78)
  {
    digitalWrite(fanPin,HIGH);
  }
   else
   {
    digitalWrite(fanPin,LOW);  
   }
       if(smoke>1000)
   { int j;
      for(j=0; j=10000; j++)
      {
      tone(buzzer, 100);
      delay(100);
      noTone(buzzer);
      delay(100);
      }}

Serial.print(dist);
}