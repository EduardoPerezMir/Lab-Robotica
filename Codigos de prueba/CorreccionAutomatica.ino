#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int enA = 8, enB = 4;
const int in1 = 9, in2 = 10, in3 = 6, in4 = 5;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();

  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
}

void loop() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);

  int16_t gx, gy, gz;
  mpu.getRotation(&gx, &gy, &gz);
  float giroZ = gz / 131.0;

  if (giroZ > 5) {
    analogWrite(enA, 180); analogWrite(enB, 255);  // gira a la izquierda
  } else if (giroZ < -5) {
    analogWrite(enA, 255); analogWrite(enB, 180);  // gira a la derecha
  } else {
    analogWrite(enA, 255); analogWrite(enB, 255);  // recto
  }

  delay(100);
}
