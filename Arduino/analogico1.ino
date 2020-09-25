#include <SoftwareSerial.h> 

const int pinResistencia=A0;
const int pinSalida=5;
int valorResistencia;
int porcentajeResistencia;
                //comunicacion  tx,rx
SoftwareSerial mySerial(1,0);
//    caracter limpia el, canal de comunicacion
char myChar = " ";

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (pinResistencia, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  valorResistencia = analogRead(pinResistencia);
  //canal de comunicacion= serial
  //print con ln es el valor que lee
  Serial.print("Valor de Resistencia: ");
  //Serial.println(valorResistencia);

  porcentajeResistencia=map(valorResistencia,0,1024,0,255);
  
   Serial.println(porcentajeResistencia);
   analogWrite(13, porcentajeResistencia);
  delay(10);

}
