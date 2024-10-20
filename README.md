<h1>  Sensor últrasonico</h1>

<p>En muchos de nuestros proyectos, tenemos la necesidad de sensar nuestro entorno, saber si en frente hay un obstáculo y a que distancia se encuentra, el sensor HC-SR04 nos permite hacer eso.

El sensor HC-SR04 es un sensor de distancia de bajo costo, su uso es muy frecuente en la robótica, utiliza transductores de ultrasonido para detectar objetos.
Su funcionamiento consiste en emitir un sonido ultrasónico por uno de sus transductores, y esperar que el sonido rebote de algún objeto presente, el eco es captador por el segundo transductor. La distancia es proporcional al tiempo que demora en llegar el eco.
Para empezar a utilizar el sensor HC-SR04 solo necesitas una placa Arduino, en este tutorial utilizaremos un Arduino

</p>

![image](https://github.com/user-attachments/assets/d20728fa-e0d0-4d93-924f-eadfe164b751)
![image](https://github.com/user-attachments/assets/614f8766-50ba-4815-8fdd-fc78de4fdd7f)

<h2> Programa 1</h2>

<h3>Programa 2: Control de un motor por medio del sensor últrasonico</h3>
<p>Nombre del archivo:Prog2_ControlDeUnMotor</p>
<p>Este código controla un motor utilizando un sensor ultrasónico conectado a un Arduino. El sensor mide la distancia de un objeto, y si detecta algo a 5 cm o menos, apaga el motor. Si no hay un objeto cercano, el motor permanece encendido. El código mide continuamente la distancia y ajusta el estado del motor en función de esa lectura. Además, muestra la distancia medida en el monitor serial para su monitoreo. </p>
<p>Mayor a 5 cm</p>

![image](https://github.com/user-attachments/assets/9b6adb85-18d8-4de4-a216-06fe71ea2560)

<p>Manor a 5 cm</p>

![image](https://github.com/user-attachments/assets/d0b72be2-ff9f-46f9-929c-a60cd279d60c)

