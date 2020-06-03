/*
*   Created by Jonah Simmons 6-3-2020 ~4:20PM
*/

//motor pins
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

//booleans for turning
boolean left = true;
boolean right = false;


void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}

void setMotorPower(double power){
  analogWrite(ENB, abs(power) * 255);
  analogWrite(ENA, abs(power) * 255);
}
void pause(int Time){
  setMotorPower(0);
  delay(Time);
}
void driveMilliseconds(double power, int Time){
  setMotorPower(power);
  digitalWrite(IN1, (power > 0) ? HIGH : LOW);
  digitalWrite(IN2, (power > 0) ? LOW : HIGH);
  digitalWrite(IN3, (power > 0) ? LOW : HIGH);
  digitalWrite(IN4, (power > 0) ? HIGH : LOW);
  delay(Time);
  pause(500);
}
void turnn(double power, boolean direction, long Time){
  setMotorPower(power);
  digitalWrite(IN1,(direction == left) ? LOW : HIGH);
  digitalWrite(IN2,(direction == left) ? HIGH : LOW);
  digitalWrite(IN3,(direction == left) ? LOW : HIGH);
  digitalWrite(IN4,(direction == left) ? HIGH : LOW);
  delay(Time);
  pause(500);
}



void loop() {
  turnn(0.5, left, 1000);
  pause(1000);
  
}

