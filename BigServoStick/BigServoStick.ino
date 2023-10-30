#include <Servo.h>
#include <Mouse.h>
// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
Servo myservo;
int pos = 0;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  myservo.attach(9);
  Serial.begin(9600);
  Mouse.begin();
}

void loop() {
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  if((abs(analogRead(Y_pin)-516)>300)||(abs(analogRead(X_pin)-512)>300)){
    myservo.write(acos((analogRead(Y_pin)-511.99999)/512)*180/3.14159);
  }
  Serial.print("\n\n");
  if (digitalRead(2) == HIGH) {
    Mouse.click();
  }
  delay(10);
}
