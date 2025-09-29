// Pines del motor (L298N típico)
int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;
int ENA = 10; // PWM Motor A
int ENB = 5;  // PWM Motor B

void setup() {
  // Configurar pines como salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
  Serial.println("Test de motores iniciado...");
}

void loop() {
  // Motor A adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // Velocidad

  // Motor B adelante
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200); // Velocidad

  Serial.println("Motores hacia adelante");
  delay(2000);

  // Parar motores
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  Serial.println("Motores detenidos");
  delay(1000);

  // Motor A atrás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);

  // Motor B atrás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);

  Serial.println("Motores hacia atrás");
  delay(2000);

  // Parar
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  Serial.println("Fin del ciclo");
  delay(2000);
}
