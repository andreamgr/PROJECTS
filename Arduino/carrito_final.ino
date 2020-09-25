#include <SoftwareSerial.h>
SoftwareSerial bt (0,1);
int BluetoothData;


#include <Servo.h>
Servo miServo;
int pinServo = 13;
int angulo = 90;

#define DER_FRENTE 11
#define DER_ATRAS 3
#define IZQ_FRENTE 10
#define IZQ_ATRAS 9

int vel_der = 127;
int vel_izq = 127;

int trigPin = 7;
int echoPin = 8;
long duracion, cm;

//SETUP---------------------------------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin (9600);

pinMode (DER_FRENTE, OUTPUT);
pinMode (DER_ATRAS, OUTPUT);
pinMode (IZQ_FRENTE, OUTPUT);
pinMode (IZQ_ATRAS, OUTPUT);

digitalWrite (DER_FRENTE, LOW);
digitalWrite (DER_ATRAS, LOW);
digitalWrite (IZQ_FRENTE, LOW);
digitalWrite (IZQ_ATRAS, LOW);

pinMode (trigPin, OUTPUT);
pinMode (echoPin, INPUT);
pinMode (trigPin, LOW);

miServo.attach (pinServo); //indicas donde esta conectado 
miServo.write (angulo); //write sirve para decirle que debes de hacer 

    
}
//SENSOR----------
void sensor () {
  digitalWrite (trigPin, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin, LOW);
duracion = pulseIn (echoPin, HIGH) ; 
cm = (duracion/2) / 29.1;
Serial.print ("cm= ");
Serial.println (cm);


}
//SERVO-----------
void servo () {
  miServo.write (angulo);
delay (1000);
angulo = angulo + 45;

if (angulo > 180) {
  angulo = 0;
}
}

//MOVIMIENTO-----------------
void mueve (){
  analogWrite (DER_FRENTE, HIGH);
analogWrite (IZQ_FRENTE, HIGH);
digitalWrite (DER_ATRAS, LOW);
digitalWrite (IZQ_ATRAS, LOW);
delay (1000);
}

//LOOP---------------------
void loop() {
  // put your main code here, to run repeatedly:

while (bt.available()){
  BluetoothData = bt.parseInt();
  Serial.parseInt();
  Serial.println(BluetoothData);
}
  

mueve
if (cm<=20) {
  digitalWrite (DER_FRENTE, HIGH);
  digitalWrite (DER_ATRAS, HIGH);
  digitalWrite (IZQ_FRENTE, HIGH);
  digitalWrite (IZQ_ATRAS, HIGH);
}
}
servo () {
  if (angulo<180 & cm>20) {
   digitalWrite (DER_FRENTE, LOW);
   digitalWrite (DER_ATRAS, HIGH);
   digitalWrite (IZQ_FRENTE, HIGH);
   digitalWrite (IZQ_ATRAS, LOW);
   delay(//DEPENDE DEL TIEMPO QUE TARDE EN GIRAR 90grados)
    else {
   digitalWrite (DER_FRENTE, HIGH);
   digitalWrite (DER_ATRAS, LOW);
   digitalWrite (IZQ_FRENTE, LOW);
   digitalWrite (IZQ_ATRAS, HIGH);
   delay(//DEPENDE DEL TIEMPO QUE TARDE EN GIRAR 90grados)
    }
  }
}


}
