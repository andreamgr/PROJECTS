#define DER_FRENTE 3
#define DER_ATRAS 11
#define IZQ_FRENTE 10
#define IZQ_ATRAS 9

int vel_der = 225; //255
int vel_izq = 225;


void setup() {
  // put your setup code here, to run once:
pinMode (DER_FRENTE, OUTPUT);
pinMode (DER_ATRAS, OUTPUT);
pinMode (IZQ_FRENTE, OUTPUT);
pinMode (IZQ_ATRAS, OUTPUT);

digitalWrite (DER_FRENTE, LOW);
digitalWrite (DER_ATRAS, LOW);
digitalWrite (IZQ_FRENTE, LOW);
digitalWrite (DER_ATRAS, LOW);



}

void loop() {
  // put your main code here, to run repeatedly:

analogWrite (DER_FRENTE, vel_der );
analogWrite (IZQ_FRENTE, vel_izq);
digitalWrite (DER_ATRAS, LOW);
digitalWrite (IZQ_ATRAS, LOW);
delay (1000);

digitalWrite (DER_FRENTE, LOW);
digitalWrite (DER_ATRAS, LOW);
digitalWrite (IZQ_FRENTE, LOW);
digitalWrite (DER_ATRAS, LOW);
delay (1000);


}
