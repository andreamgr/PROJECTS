#include <SoftwareSerial.h>

float medicionLM35; // variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = A0;
float mv;
float tempV;
float tempC;

SoftawareSeria 



void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600); 
  pinMode (pinLM35, INPUT );
  
}

void loop() {
  // put your main code here, to run 

  medicionLM35 = analogRead (pinLM35);
  tempV = (medicionLM35*5)/1023;
  tempC = tempV/10;
  Serial.print (tempC);
  delay (1000);
  

}
