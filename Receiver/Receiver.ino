#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); //RXD 10, TXD 11

int motorInput1 = 2;
int motorInput2 = 3;
int motorInput3 = 4;
int motorInput4 = 5;

int motor2Input1 = 6;
int motor2Input2 = 7;
int motor2Input3 = 8;
int motor2Input4 = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);

  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, LOW);
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, LOW);
  Serial.begin(9600);
  BTSerial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available() > 0) {
    char tiltDirection = BTSerial.read();
    if (tiltDirection == 'F') {
      Serial.println("Forward");
      forward();
    }

    if (tiltDirection == 'B') {
      Serial.println("Backward");
      backward();
    }

    if (tiltDirection == 'L') {
      Serial.println("Left");
      left();
    }

    if (tiltDirection == 'R') {
      Serial.println("Right");
      right();
    }

    if (tiltDirection == 'S') {
      Serial.println("Stop");
      motorStop();
    }

  } else {
      motorStop();
    }

}

void forward()
{
  /*The pin numbers and high, low values might be different depending on your connections */

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
  /*front */
  digitalWrite(motor2Input1, HIGH);
  digitalWrite(motor2Input2, LOW);
  digitalWrite(motor2Input3, HIGH);
  digitalWrite(motor2Input4, LOW);

}
void backward()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  /*back*/
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
  /*front */
  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, HIGH);
  digitalWrite(motor2Input3, HIGH);
  digitalWrite(motor2Input4, LOW);



}
void right()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  /*back*/
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
  /*front */
  digitalWrite(motor2Input1, HIGH);
  digitalWrite(motor2Input2, LOW);
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, LOW);
}
void left()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  /*back*/
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
  /*front */
  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, HIGH);
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, LOW);
}

void motorStop() {
  /*back*/
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
  /*front */
  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, LOW);
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, LOW);
}
