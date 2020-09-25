float distancia;
float tiempo;
float distancia2;
float tiempo2;

int triger =6;
int echo =8;
int triger =5;
int echo =4;




int rojo=2;


void setup() {
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
 

  Serial.begin(9600);

}

void loop() {
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  
  
  tiempo =pulseIn(8, HIGH);
  distancia = (tiempo/2) / 29;

  
Serial.println( distancia );
Serial.println("cm");
delay(1000);


  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);
  
  
  tiempo2 =pulseIn(4, HIGH);
  distancia2 = (tiempo2/2) / 29;

  
Serial.println( distancia2 );
Serial.println("cm");
delay(1000);



if (distancia>=7 && distancia <=11){  //
  
}

}
