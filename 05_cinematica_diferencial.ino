// Pines motores
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;
const int ENA = 10;
const int ENB = 5;

// Parámetros del robot
const float r = 0.033; // radio rueda (metros)
const float L = 0.16;  // distancia entre ruedas (metros)
const float motorSpeedPWM = 150; // Velocidad PWM [0 - 255]

const float v_L = 0.2; // velocidad de rueda izquierda (m/s)
const float v_R = 0.2; // velocidad de rueda derecha (m/s)

// Posición y orientación
float x = 0.0;
float y = 0.0;
float theta = 0.0;

// Tiempo
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);

  // Configurar pines de motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Activar motores hacia adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, motorSpeedPWM);
  analogWrite(ENB, motorSpeedPWM);

  lastTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0; // convertir ms a s

  // Cinemática diferencial
  float v = (v_R + v_L) / 2.0;
  float omega = (v_R - v_L) / L;

  x += v * cos(theta) * dt;
  y += v * sin(theta) * dt;
  theta += omega * dt;

  // Mostrar posición
  Serial.print("x: ");
  Serial.print(x, 3);
  Serial.print(" m, y: ");
  Serial.print(y, 3);
  Serial.print(" m, theta: ");
  Serial.println(theta, 3);

  lastTime = currentTime;
  delay(500); // Esperar 500 ms antes del siguiente cálculo
}
