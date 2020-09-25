
#include <Servo.h>

int pichx = -7; // Ajuste para que mire al centro depende de la montura del servo
int pichy = -20; // Ajuste para que mire al centro depende de la montura del servo
int centerX = 89 + pichx; // Posicion central para Y
int centerY = 89 + pichy; // Posicion central para Y
const int develop_mode = false; // En modo develop no funcionan los motores solo debug en serial
const int scanservopin = 9; // Pin number for scan servo
const int scanservopinY = 10; // Pin number for scan servo
int turntime = 650 ; // Tiempo necesario para dar una vuelta completa.
int turnaroundtime = turntime *2 ;
const int distancelimit = 20; //Limite de distancia a un obejo
const int max_mesure_distance = 100; //Maxima distancia a medir en cm.
AF_DCMotor motor(1,MOTOR12_8KHZ);
AF_DCMotor motor2(2,MOTOR12_8KHZ);
Servo scanservo; //Ping Sensor Servo
Servo scanservoY; //Ping Sensor Servo
// Declare ultrasonic
Ultrasonic ultrasonic(5,6,max_mesure_distance * 58); // (Trig PIN,Echo PIN, Max.TimeOut) centímetros * 58 = Max.TimeOut
int speed = 220;
int pitch = 0; // Diferencia de velocidad para que vaya recto si un motor es mas r´pido que el otro
void setup() {
 Serial.begin(9600); // set up Serial library at 9600 bps
 Serial.println("Robot test!");
 scanservo.attach(scanservopin); // Attach the scan servo
 scanservoY.attach(scanservopinY); // Attach the scan servo
 // turn on motor
 motor.setSpeed(speed);
 motor2.setSpeed(speed+pitch); 
 motor.run(RELEASE);
 motor2.run(RELEASE);
 scan_to_center();
 delay(2000);
} // End setup
void loop() {
 go(); // if nothing is wrong the go forward using go() function below.
 int distance = ping(); // us the ping() function to see if anything is ahead.
 if (distance < distancelimit){
 stopmotors(); // If something is ahead, stop the motors.
 char turndirection = scan(); //Decide which direction to turn.
 switch (turndirection){
 case 'l': {
 turnleft(turntime);
 backward(turntime);
 break;
 }
 case 'r':
 turnright(turntime);
 backward(turntime);
 break;
 case 's':
 turnleft(turnaroundtime);
 break;
 }
 }
} // End Loop<
void go(){
 if ( develop_mode ) {
 ; // Serial.println("Go()");
 }
 else {
 motor.run(FORWARD);
 motor2.run(FORWARD);
 motor.setSpeed(speed); 
 motor2.setSpeed(speed+pitch);
 } 
}
void turnleft(int t){
 if ( develop_mode ) {
 Serial.println("turnleft()");
 }
 else
 {
 motor.run(FORWARD);
 motor2.run(BACKWARD);
 }
 delay(t);
}

void turnright(int t){
 if ( develop_mode ) {
 Serial.println("turnright()");
 }
 else
 { 
 motor.run(BACKWARD);
 motor2.run(FORWARD);
 }
 delay(t);
} 
void forward(int t){
 if ( develop_mode ) {
 Serial.println("forward()");
 }
 else
 {
 motor.run(FORWARD);
 motor2.run(FORWARD);
 }
 delay(t);
}
void backward(int t){
 if ( develop_mode ) {
 Serial.println("backward()");
 }
 else
 {
 motor.setSpeed(speed); 
 motor2.setSpeed(speed-pitch); 
 motor.run(BACKWARD);
 motor2.run(BACKWARD);
 }
 delay(t);
}
void stopmotors(){
 if ( develop_mode ) {
 Serial.println("stopmotors()");
 }
 else
 {
 motor.run(RELEASE);
 motor2.run(RELEASE);
 }
}
// Mira al frente 
void scan_to_center(){
 scanservo.write(centerX);
 scanservoY.write(centerY);
 delay(100); // waits 100ms for the servo to reach the position 
}
// Se le pasa posicion X e Y y mueve los dos servos para posicionar
void movexy(int x, int y){
 scanservo.write(x); // tell servo to go to position in variable 'pos' 
 scanservoY.write(y); // tell servo to go to position in variable 'pos' 
 delay(20); // waits 20ms for the servo to reach the position 
}
int ping(){
 long cm;
 cm = ultrasonic.Ranging(CM);
 // Serial.print("Ping : cm. ");
 // Serial.println(cm);
 return round(cm);
}
char scan(){
 int leftscanval, centerscanval, rightscanval;
 char choice;
 //Look left
 movexy(40,95);
 //scanservo.write(30);
 delay(300);
 leftscanval = ping();
 // look center
 movexy(centerX,centerY);
 delay(300);
 centerscanval = ping();
 //Look right
 movexy(160,95);
 delay(300);
 rightscanval = ping();
 //center scan servo
 scan_to_center();
 Serial.print("leftscanval ");
 Serial.println(leftscanval);
 Serial.print("rightscanval ");
 Serial.println(rightscanval);
 Serial.print("centerscanval ");
 Serial.println(centerscanval);
if (leftscanval>rightscanval && leftscanval>centerscanval){
 choice = 'l';
 }
 else if (rightscanval>leftscanval && rightscanval>centerscanval){
 choice = 'r';
 }
 else{
 choice = 's';
 }
 Serial.print("Choice: ");
 Serial.println(choice);
 return choice;
}
