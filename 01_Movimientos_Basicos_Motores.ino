// Definición de los pines de control de los motores (sin ENA y ENB para PWM)
const int IN1 = 9;  
const int IN2 = 8; 

const int IN4 = 7;
const int IN3 = 6;

void setup() {
  // Configuración de los pines IN1, IN2, IN3, IN4 para el control de los motores
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);

  // No es necesario configurar ENA y ENB aquí, ya que los jumpers los conectan directamente a 5V
  // En el código sin jumpers, deberíamos configurar ENA y ENB con pinMode() como OUTPUT
  // pinMode(ENA, OUTPUT); 
  // pinMode(ENB, OUTPUT);
}

void avanzar(int tiempo) {
  // Movimiento hacia adelante: IN1 a LOW, IN2 a HIGH; IN3 a LOW, IN4 a HIGH
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  delay(tiempo);  // El tiempo del movimiento sigue dependiendo de `delay()`
}

void retroceder(int tiempo) {
  // Movimiento hacia atrás: IN1 a HIGH, IN2 a LOW; IN3 a HIGH, IN4 a LOW
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  delay(tiempo);  // El tiempo del movimiento sigue dependiendo de `delay()`
}

void girarDerecha(int tiempo) {
  // Giro a la derecha: IN1 a LOW, IN2 a HIGH; IN3 a HIGH, IN4 a LOW
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  delay(tiempo);  // El tiempo del movimiento sigue dependiendo de `delay()`
}

void girarIzquierda(int tiempo) {
  // Giro a la izquierda: IN1 a HIGH, IN2 a LOW; IN3 a LOW, IN4 a HIGH
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  delay(tiempo);  // El tiempo del movimiento sigue dependiendo de `delay()`
}

void detenerse(int tiempo) {
  // Detener motores: todos los pines de control en LOW
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW);
  delay(tiempo);  // El tiempo de detención sigue dependiendo de `delay()`
}

void loop() {
  detenerse(5000);     // Detenemos por 5 segundos
  avanzar(1000);       // Avanzamos por 1 segundo
  detenerse(2500);     // Detenemos por 2.5 segundos
  retroceder(1000);    // Retrocedemos por 1 segundo
  detenerse(2500);     // Detenemos por 2.5 segundos
  girarDerecha(1000);  // Giramos a la derecha por 1 segundo
  detenerse(2500);     // Detenemos por 2.5 segundos
  girarIzquierda(1000); // Giramos a la izquierda por 1 segundo
}
