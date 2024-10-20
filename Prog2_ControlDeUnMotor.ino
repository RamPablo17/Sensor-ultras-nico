// Definimos los pines para el sensor ultrasónico
const int trigPin = 12;   // Pin de disparo (Trig) conectado al pin 12 del Arduino
const int echoPin = 11;   // Pin de eco (Echo) conectado al pin 11 del Arduino
// Definimos el pin para el motor
const int motorPin = 13;  // Pin del motor conectado al pin 13 del Arduino

// Variables para almacenar el tiempo de duración del eco y la distancia calculada
long duration;  // Variable para almacenar el tiempo que tarda en recibir el eco
int distance;   // Variable para almacenar la distancia en centímetros

void setup() {
  // Configuración de los pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);  // El pin Trig será una salida
  pinMode(echoPin, INPUT);   // El pin Echo será una entrada
  
  // Configuración del pin del motor
  pinMode(motorPin, OUTPUT); // El pin del motor será una salida
  
  // Iniciamos la comunicación serial para mostrar la distancia medida
  Serial.begin(9600);        // Velocidad de la comunicación serial a 9600 bps
}

void loop() {
  // Antes de enviar una señal, se asegura que el pin Trig esté en bajo
  digitalWrite(trigPin, LOW);  // Ponemos el pin Trig en estado bajo
  delayMicroseconds(2);        // Esperamos 2 microsegundos
  
  // Enviamos un pulso de 10 microsegundos en el pin Trig para iniciar la medición
  digitalWrite(trigPin, HIGH); // Ponemos el pin Trig en alto
  delayMicroseconds(10);       // Mantenemos el pin Trig en alto durante 10 microsegundos
  digitalWrite(trigPin, LOW);  // Ponemos el pin Trig en bajo nuevamente
  
  // Lee el tiempo que tarda el pulso en ser recibido en el pin Echo
  duration = pulseIn(echoPin, HIGH);  // La función pulseIn mide el tiempo que el pin Echo está en alto
  
  // Convertimos el tiempo en distancia (en centímetros)
  // El factor 0.034 se utiliza porque el sonido viaja a 0.034 cm por microsegundo
  // Dividimos por 2 ya que el pulso va y viene
  distance = duration * 0.034 / 2;   // Cálculo de la distancia en centímetros
  
  // Mostramos la distancia en el monitor serial
  Serial.print("Distancia: ");   // Imprime "Distancia: " en el monitor serial
  Serial.print(distance);        // Imprime el valor de la distancia medida
  Serial.println(" cm");         // Imprime " cm" para indicar la unidad de medida

  // Si la distancia es menor o igual a 5 cm, apaga el motor
  if (distance <= 5) {
    digitalWrite(motorPin, LOW);   // Desactiva el motor (pone el pin del motor en bajo)
  } else {
    digitalWrite(motorPin, HIGH);  // Si la distancia es mayor a 5 cm, activa el motor
  }

  delay(100);  // Pausa de 100 milisegundos antes de la siguiente lectura para evitar lecturas muy rápidas
}