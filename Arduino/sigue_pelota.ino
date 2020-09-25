#include <AFMotor.h>
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#define IRpin  46//46 
#define IRgnd  44//44
#define LEDpin 47//47

unsigned char IRstatus = 1;

//sensor color
const int s0 = 22; // 1 blanco-marron
const int s1 = 24; // 2 negro
const int s2 = 26; // 3 cafe 
const int s3 = 28; // 4 verde
const int out = 52; //5 naranja 
//gnd gris, azul    vcc gris junto naranja
int rojo = 0;  
int verde = 0;  
int azul = 0;

int colorf = 0;

void setup() {
  pinMode (IRpin, INPUT);
  pinMode (IRgnd, OUTPUT);
  pinMode (LEDpin, OUTPUT);
  digitalWrite (LEDpin, LOW);
  digitalWrite (IRgnd, HIGH);
  //sensor color
  Serial.begin(9600); 
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH); 
  
  //motor
  motor3.setSpeed(250);  //Velocidad estándar de 250, máxima velocidad posible 255
  motor4.setSpeed(250);  //Recuerda que puedes cambiar la velocidad estándar en el loop
}


void loop() {
  color(); 
  Serial.print("   ");  
  Serial.print(rojo, DEC);  
  Serial.print("   ");  
  Serial.print(verde, DEC);  
  Serial.print("   ");  
  Serial.print(azul, DEC);
  
  if ((rojo >= 3) && (rojo <= 15) && (verde >= 8) && (verde <= 15) && (azul >= 3) && (azul <= 15))
  {
    Serial.println("   Amarillo");
    
    siguePelota();//llama a la funcion sigue pelota
  }
  else if ((rojo >= 40) && (rojo <= 55) && (verde >= 42) && (verde <= 53) && (azul >= 40) && (azul <= 55))
  { 
   
   Serial.println("   Negro"); 
   
   siguePelota();
          
  } 
  else if ((rojo >= 15) && (rojo <= 28) && (verde >= 21) && (verde <= 27) && (azul >= 19) && (azul <= 30))  
  {  
   Serial.println("   Verde");
   
   siguePelota(); 
       
  }
  else if ((rojo >= 13) && (rojo <= 16) && (verde >= 8) && (verde <= 16) && (azul >= 8) && (azul <= 16))  
  {  
   Serial.println("   Verde claro");
    
    siguePelota(); 
     
  } 
  else if ((rojo >= 30) && (rojo <= 40) && (verde >= 30) && (verde <= 40) && (azul >= 26) && (azul <= 40))  
  {  
   Serial.println("   Casi negro");
   
   siguePelota();
         
  }  
  else
  Serial.println(" Regresa a los colores, estas en el blanco  "); 
  robotGira();
  delay(900);     
  }  



void siguePelota(){
  
  digitalWrite (IRgnd, LOW);
  delay (10);
  IRstatus = digitalRead (IRpin);
  if (IRstatus == 0){
    digitalWrite (LEDpin, HIGH);
    robotDerecho();
  }
  else
    digitalWrite (LEDpin, LOW);
    digitalWrite (IRgnd, HIGH);
    robotGira();
  
}

void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}


void robotDerecho()
{
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    delay (300);
    motor3.run(BACKWARD);   //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
    motor4.run(FORWARD);
    motor3.setSpeed(152);
    motor4.setSpeed(150);
    delay(70);
    motor3.run(FORWARD);   //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
    motor4.run(FORWARD);
    motor3.setSpeed(240);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
    motor4.setSpeed(240);
    delay (2000);
}

void robotGira(){

    motor3.run(RELEASE);
    motor4.run(RELEASE);
    delay (100);
    motor3.run(BACKWARD);   //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
    motor4.run(FORWARD);
    motor3.setSpeed(152);
    motor4.setSpeed(150);
    delay (100);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    delay (100);  
  
}


    
