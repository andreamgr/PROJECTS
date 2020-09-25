#define IRpin  46 //
#define IRgnd  44 //azul
#define LEDpin 47 //

unsigned char IRstatus = 1;

void setup() {
  pinMode (IRpin, INPUT);
  pinMode (IRgnd, OUTPUT);
  pinMode (LEDpin, OUTPUT);
  digitalWrite (LEDpin, LOW);
  digitalWrite (IRgnd, HIGH);
}

void loop() {
  digitalWrite (IRgnd, LOW);
  delay (2);
  IRstatus = digitalRead (IRpin);
  if (IRstatus == 0){
    digitalWrite (LEDpin, HIGH);
    
  }
  else
    digitalWrite (LEDpin, LOW);
    digitalWrite (IRgnd, HIGH);
    delay (2);
    
}
