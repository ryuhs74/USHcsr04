#include "us_hcsr04.h"

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

#define US_HCSR04_TEST

#ifdef US_HCSR04_TEST
usHcsr_04* pusHcsr_04 = NULL;
#endif

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);

#ifdef US_HCSR04_TEST
  pusHcsr_04 = new usHcsr_04(trigPin, echoPin);
#else  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
#endif
  Serial.println ("test");
}

void loop() {
  long duration, distance;
#ifdef US_HCSR04_TEST
  distance = pusHcsr_04->get_distance();
#else
  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  Serial.print (duration);
  Serial.println ("  duration ");
#endif

  if (distance < 10) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(led2,LOW);
  } else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}

