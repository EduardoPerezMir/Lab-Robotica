#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;
const int ENA = 10;
const int ENB = 5;

const int motorPWM = 150;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!mpu.begin()) {
    Serial.println("No se pudo encontrar el MPU6050");
    while (1);
  }

  Serial.println("MPU6050 listo!");

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);

  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  
  analogWrite(ENA, motorPWM);
  analogWrite(ENB, motorPWM);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float giroZ = g.gyro.z;

  Serial.print("Desviación angular Z (°/s): ");
  Serial.println(giroZ);

  delay(500);
}
