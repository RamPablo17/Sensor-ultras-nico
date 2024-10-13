int TRIG = 13;        // Define el pin 13 para el pin TRIG del sensor ultrasónico.
int ECHO = 12;        // Define el pin 12 para el pin ECHO del sensor ultrasónico.
int LED = 5;          // Define el pin 5 como el pin del LED.
int duracion;         // Variable para almacenar la duración del pulso de ultrasonido en microsegundos.
int distancia;        // Variable para almacenar la distancia calculada en centímetros.


void setup()
{
  pinMode(TRIG, OUTPUT); // Configura el pin TRIG como salida para enviar señales de ultrasonido.
  pinMode(ECHO, INPUT); // Configura el pin ECHO como entrada para recibir la señal reflejada.
  pinMode(LED, OUTPUT); // Configura el pin del LED como salida para encender o apagar el LED.
}
void loop()
{
  digitalWrite(TRIG, HIGH); // Activa el TRIG enviando una señal alta.
  delayMicroseconds(1);  // Espera 1 microsegundo con el TRIG en alto.
  digitalWrite(TRIG, LOW); // Desactiva el TRIG enviando una señal baja.
  delayMicroseconds(1);  // Espera 1 microsegundo con el TRIG en alto.
  
  duracion = pulseIn(ECHO, HIGH); // Mide el tiempo que tarda la señal en ir y regresar (eco).
  distancia = duracion/58.2; // Calcula la distancia en centímetros usando la fórmula.
  
  if (distancia < 45) // Si la distancia es menor a 45 cm
  {
    digitalWrite(LED, HIGH); // Enciende el LED.
  }
  else
    digitalWrite(LED, LOW); // Apaga el LED. 
}