String voice;

int red = 11;
int gree = 10;
int blu = 9;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(gree, OUTPUT);
  pinMode(blu, OUTPUT);
}

void alloff() {
  digitalWrite(red, LOW) ;
  digitalWrite(blu, LOW) ;
  digitalWrite(gree, LOW) ;
}

void loop() {
  while (Serial.available()) {
    delay(10);
    char c = Serial.read();
    if (c == '#')
    {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);
    if (voice == "red")
    {
      digitalWrite(red, HIGH) ;
    }
    else if (voice == "green")
    {
      digitalWrite(gree, HIGH) ;
    }
    else if (voice == "blue")
    {
      digitalWrite(blu, HIGH);
    }
    else if (voice =="off"){
      alloff ();
    }
    voice = "";
  }
}

