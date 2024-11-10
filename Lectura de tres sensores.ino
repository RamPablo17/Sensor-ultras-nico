// Pines del sensor 1(Trasero)
const int trigPin1 = 5;  // Pin de disparo (Trig) del primer sensor conectado al pin 12 del Arduino
const int echoPin1 = 6;  // Pin de eco (Echo) del primer sensor conectado al pin 11 del Arduino
// Pines del sensor 2 (Frente derecho)
const int trigPin2 = 7;   // Pin de disparo (Trig) del segundo sensor conectado al pin 8 del Arduino
const int echoPin2 = 8;   // Pin de eco (Echo) del segundo sensor conectado al pin 7 del Arduino
// Pines del sensor 1(Frente Izquierdo)
const int trigPin3 = 9;  // Pin de disparo (Trig) del tercer sensor conectado al pin 10 del Arduino
const int echoPin3 = 10;   // Pin de eco (Echo) del tercer sensor conectado al pin 9 del Arduino
// Pines del motor
const int motorPin1 = 13; // Primer motor conectado al pin 13 del Arduino
const int motorPin2 = 12;  // Segundo motor conectado al pin 12 del Arduino
//Pin de los leds traseros
const int LedTrasero = 4; //Pin leds traseros

// Variables para el tiempo y la distancia de los tres sensores
long duration1, duration2, duration3;  // Duración del eco para cada sensor
int distance1, distance2, distance3;   // Distancia medida por cada sensor

void setup() {
  // Configuración de los pines del primer sensor ultrasónico
  pinMode(trigPin1, OUTPUT);  // Establecer el pin Trig del primer sensor como salida
  pinMode(echoPin1, INPUT);   // Establecer el pin Echo del primer sensor como entrada

  // Configuración de los pines del segundo sensor ultrasónico
  pinMode(trigPin2, OUTPUT);  // Establecer el pin Trig del segundo sensor como salida
  pinMode(echoPin2, INPUT);   // Establecer el pin Echo del segundo sensor como entrada

  // Configuración de los pines del tercer sensor ultrasónico
  pinMode(trigPin3, OUTPUT);  // Establecer el pin Trig del tercer sensor como salida
  pinMode(echoPin3, INPUT);   // Establecer el pin Echo del tercer sensor como entrada
  
  // Configuración de los pines del motor como salida
  pinMode(motorPin1, OUTPUT);  
  pinMode(motorPin2, OUTPUT);  

  // Iniciar la comunicación serial para depuración
  Serial.begin(9600);
  
  // Mostrar un mensaje en el monitor serial indicando que el programa esperará 2 segundos
  Serial.println("Esperando 2 segundos antes de arrancar los motores...");

  // Pausa de 2 segundos antes de comenzar a ejecutar el loop
  delay(2000);
}

// Función para medir la distancia de un sensor ultrasónico
int getDistance(int trigPin, int echoPin) {
  // Asegurarse de que el pin Trig esté en bajo antes de iniciar la medición
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // Pausa de 2 microsegundos

  // Enviar un pulso de 10 microsegundos al pin Trig para disparar el sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // Pausa de 10 microsegundos
  digitalWrite(trigPin, LOW);  // Volver a poner el pin Trig en bajo

  // Medir la duración del pulso de eco (tiempo que tarda en recibir el eco)
  long duration = pulseIn(echoPin, HIGH);

  // Convertir la duración en distancia en centímetros (con fórmula de tiempo/distancia del sonido)
  return duration * 0.034 / 2;  // Regresar la distancia calculada
}

void loop() {
  // Medir la distancia con el primer sensor ultrasónico
  distance1 = getDistance(trigPin1, echoPin1);
  // Medir la distancia con el segundo sensor ultrasónico
  distance2 = getDistance(trigPin2, echoPin2);
  // Medir la distancia con el tercer sensor ultrasónico
  distance3 = getDistance(trigPin3, echoPin3);

  // Mostrar las distancias medidas en el monitor serial
  Serial.print("Distancia Trasero: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distancia Frente derecho: ");
  Serial.print(distance2);
  Serial.println(" cm");
  Serial.print("Distancia Frente izquierdo: ");
  Serial.print(distance3);
  Serial.println(" cm");
  
  // Verificar si alguna distancia es menor o igual a 10 cm
  if (distance1 <= 10 ) {
    // Detener los motores si la distancia es menor o igual a 10 cm
    digitalWrite(motorPin1, LOW);
    digitalWrite(LedTrasero, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println("¡Obstáculo detectado! Motores detenidos.");
  } else {
    // Encender los motores si no hay obstáculos
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(LedTrasero, LOW);
    Serial.println("Motores en marcha.");
  }
  
  // Pausa de 100 milisegundos antes de la siguiente lectura
  delay(100);
}
