// Pines de los sensores
// Centro
const int trigPin1 = 2;
const int echoPin1 = 3;

// Izquierda
const int trigPin2 = 4;
const int echoPin2 = 5;

// Derecha
const int trigPin3 = 6;
const int echoPin3 = 7;

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2; // cm
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  Serial.println("Iniciando test de sensores...");
}

void loop() {
  long centro = readDistance(trigPin1, echoPin1);
  long izquierda = readDistance(trigPin2, echoPin2);
  long derecha = readDistance(trigPin3, echoPin3);

  Serial.println("Lectura de sensores (cm):");
  Serial.print("Izquierda: "); Serial.print(izquierda); Serial.print(" cm | ");
  Serial.print("Centro: "); Serial.print(centro); Serial.print(" cm | ");
  Serial.print("Derecha: "); Serial.print(derecha); Serial.println(" cm");

  // Mostrar posición relativa
  if (centro < 20) {
    Serial.println("Obstáculo al frente");
  } else if (izquierda < 20) {
    Serial.println("Obstáculo a la izquierda");
  } else if (derecha < 20) {
    Serial.println("Obstáculo a la derecha");
  } else {
    Serial.println("Área libre");
  }

  Serial.println("-----------------------");
  delay(1000);
}
