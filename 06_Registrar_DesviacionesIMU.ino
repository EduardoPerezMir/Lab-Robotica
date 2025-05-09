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

float giroZ = 0;
float umbralGiro = 2.0;  // Umbral para detectar desviación (en grados por segundo)

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

  // Obtener el valor de giro en el eje Z
  giroZ = g.gyro.z;

  // Si el giro excede el umbral, corregir la dirección
  if (giroZ > umbralGiro) {
    Serial.println("Desviación a la derecha detectada.");
    corregirDireccion(-motorPWM, motorPWM);  // Giro a la izquierda para corregir
  }
  else if (giroZ < -umbralGiro) {
    Serial.println("Desviación a la izquierda detectada.");
    corregirDireccion(motorPWM, -motorPWM);  // Giro a la derecha para corregir
  } else {
    // Si no hay desviación significativa, continuar en línea recta
    mantenerDireccion();
  }

  Serial.print("Desviación angular Z (°/s): ");
  Serial.println(giroZ);

  delay(100);  // Esperar un poco antes de la siguiente medición
}

void mantenerDireccion() {
  // Mantener dirección recta sin corrección
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  
  analogWrite(ENA, motorPWM);
  analogWrite(ENB, motorPWM);
}

void corregirDireccion(int pwmIzq, int pwmDer) {
  // Detener los motores y aplicar corrección
  analogWrite(ENA, 0);  
  analogWrite(ENB, 0);  
  delay(100);  // Pausar brevemente para aplicar corrección

  // Ajustar los motores
  digitalWrite(IN1, pwmIzq > 0 ? HIGH : LOW);
  digitalWrite(IN2, pwmIzq < 0 ? HIGH : LOW);
  digitalWrite(IN3, pwmDer > 0 ? HIGH : LOW);
  digitalWrite(IN4, pwmDer < 0 ? HIGH : LOW);
  analogWrite(ENA, abs(pwmIzq));  
  analogWrite(ENB, abs(pwmDer));  
}
