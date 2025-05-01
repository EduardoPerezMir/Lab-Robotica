const int enA = 8;
const int enB = 4;
const int in1 = 9;
const int in2 = 10;
const int in3 = 6;
const int in4 = 5;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);

  analogWrite(enA, 100);  // velocidad baja
  analogWrite(enB, 100);
  delay(2000);

  analogWrite(enA, 200);  // velocidad media
  analogWrite(enB, 200);
  delay(2000);

  analogWrite(enA, 255);  // velocidad alta
  analogWrite(enB, 255);
  delay(2000);
}
