#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int16_t gx, gy, gz;
  mpu.getRotation(&gx, &gy, &gz);

  float giroZ = gz / 131.0; 

  if (abs(giroZ) > 5) {
    Serial.println("Desviación detectada");
  } else {
    Serial.println("Movimiento recto");
  }

  delay(500);
}
