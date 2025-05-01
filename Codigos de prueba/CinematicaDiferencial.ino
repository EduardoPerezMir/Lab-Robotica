float x = 0.0, y = 0.0;
float velocidad = 13.0; 
float angulo = 0.0;   

unsigned long tiempoAnterior = 0;

void setup() {
  Serial.begin(9600);
  tiempoAnterior = millis();
}

void loop() {
  unsigned long tiempoActual = millis();
  float deltaT = (tiempoActual - tiempoAnterior) / 1000.0;

  x += velocidad * cos(angulo) * deltaT;
  y += velocidad * sin(angulo) * deltaT;

  Serial.print("X: "); Serial.print(x);
  Serial.print(" | Y: "); Serial.println(y);

  tiempoAnterior = tiempoActual;
  delay(500);
}
