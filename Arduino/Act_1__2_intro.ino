

void setup() {
  pinMode (3, OUTPUT);   //pinMode (13, OUTPUT);
  pinMode (9, OUTPUT);   //digitalWrite (13, LOW); //solo utiliza high y low (solo 0 y 1) digital 
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);

  digitalWrite (3, LOW);
  digitalWrite (9, LOW);
  digitalWrite (10, LOW);
  digitalWrite (11, LOW);
  digitalWrite (12, LOW);
  
  }

void loop()
{
   digitalWrite (9, LOW);    //digitalWrite (13,HIGH);
   digitalWrite (10, HIGH);     //delay (1000);
   digitalWrite (3, LOW);       //digitalWrite (13,LOW);
   digitalWrite (11, HIGH);    // delay (1000);
   delay (1000);

   digitalWrite (9, HIGH);
   digitalWrite (10, HIGH);
   digitalWrite (3, HIGH);
   digitalWrite (11, HIGH);
   delay (1000);
}
