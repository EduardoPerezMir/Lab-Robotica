# Laboratorio 1 Robótica y Sistemas Autónomos

# Integrantes:
- Claudio Cabello
- David Martínez
- Eduardo Pérez
  
# Laboratorio 1
## Tema: Ensamblar y programar un robot básico.
Objetivos:
- Comprender los componentes básicos de un robot móvil autónomo.
- Implementar un control de movimiento basado en sensores sin usar encoders.
- Aplicar conceptos de cinemática y dinámica en robots móviles.
## Materiales:
- Arduino UNO
- Chasis de robot móvil con dos motores DC basado en impresión 3D.
- Sensores (ultrasónicos, Infrarrojo y RGB) para detección de obstáculos y color.
- Sensor IMU (MPU 6050) para medición de inclinación y giro.
- Batería y módulo de alimentación.
- Driver de motores (puente H) L298N o similar.
- Protoboard y cables de conexión.

##  Índice
1. [Resumen del Proyecto](#resumen-del-proyecto)
2. [Preguntas resueltas Parte 1](#preguntas-resueltas-parte-1)
3. [Documentación Parte 1](#documentación-parte-1)
4. [Preguntas resueltas Parte 2](#preguntas-resueltas-parte-2)
5. [Documentación Parte 2](#documentación-parte-2)
   

## Resumen del Proyecto
En este proyecto se ensambló y programó un robot móvil básico controlado por un Arduino UNO, utilizando dos motores DC, un driver L298N y sensores como el ultrasónico HC-SR04 y el IMU MPU-6050. El objetivo fue implementar control de movimiento sin encoders, estimando la velocidad mediante intervalos de tiempo y modulación PWM. Se probaron funciones de avance, retroceso y giros, y se documentaron tanto los esquemas de conexión como los resultados prácticos. El sistema fue alimentado por una batería de 9V y un portapilas de 4 AA, logrando un funcionamiento autónomo básico con posibles mejoras futuras en la fuente de energía y uso del IMU.

---


## Preguntas Resueltas Parte 1
1. ¿Qué función cumplen los sensores, actuadores y controladores en el robot?
Respuesta: Los sensores tienen la función de percibir y captar información del entorno, como distancia, temperatura, luz, entre otros. Los actuadores permiten al robot ejecutar movimientos físicos o acciones, como desplazar ruedas, mover brazos o activar mecanismos. Por su parte, los controladores procesan la información proveniente de los sensores y generan señales de control para los actuadores, actuando como un puente que coordina la percepción con la acción. En conjunto, estos tres componentes permiten que el robot funcione de manera estructurada y estandarizada.


2. ¿Cómo se puede estimar la velocidad sin encoders?
Respuesta: Se estima de forma manual, registrando la posición inicial en un tiempo inicial, y la posición final en un tiempo final. Así, la velocidad puede calcularse con la siguiente fórmula:

![image](https://github.com/user-attachments/assets/cf4eb19e-e3d6-4433-aa39-66c01a1036a6)

Esta estimación puede hacerse:
- Visualmente (marcando una regla o cinta métrica en el suelo, y cronometrar el desplazamiento total).
- Usando sensores (como el IMU para detectar desplazamiento angular o aceleración).


3. ¿Cómo afecta la falta de encoders a la precisión del movimiento?
Respuesta: La falta de encoders reduce significativamente la precisión del movimiento del robot, ya que el sistema pierde la capacidad de obtener retroalimentación directa sobre la velocidad y posición reales de los motores. En un sistema sin encoders, se asume que los motores responden de manera ideal a las órdenes de control (por ejemplo, avanzar a cierta velocidad por cierto tiempo), pero en la práctica esto rara vez se cumple debido a factores como:
- Rozamiento variable en el suelo o las ruedas.
- Deslizamiento (especialmente en giros o superficies lisas).
- Carga desigual o cambiante (peso del robot o pendientes).
- Diferencias entre motores, aunque sean del mismo modelo.

4. ¿Qué es PWM y cómo ayuda a controlar la velocidad de los motores?
Respuesta: PWM (Pulse Width Modulation), o Modulación por Ancho de Pulso, es una técnica que permite controlar la cantidad de energía entregada a un dispositivo electrónico (como un motor) variando el ciclo de trabajo (duty cycle) de una señal digital. En lugar de enviar una señal analógica, PWM enciende y apaga rápidamente una señal digital (por ejemplo, de 0V a 5V) a una frecuencia constante. La proporción del tiempo que la señal está en alto (ON) frente al tiempo total de un ciclo determina cuánta potencia se entrega al motor. De esta manera, se controla la velocidad en función de la proporción del tiempo en que la señal es enviada.


5. ¿Cómo afecta el control de velocidad a la precisión de la navegación sin encoders?
R: Sin encoders, incluso si se implementa un control de velocidad utilizando técnicas como PWM, no se puede garantizar que el robot mantenga una velocidad constante y precisa, ya que no hay retroalimentación que confirme si los motores realmente están girando a la velocidad deseada. Esto afecta negativamente la precisión de la navegación, ya que cualquier variación en la fricción, el estado de la batería o las condiciones del terreno puede hacer que un motor gire más lento o más rápido de lo esperado. Como resultado, el robot puede desviarse de su trayectoria, recorrer distancias diferentes a las planificadas, o girar de forma asimétrica. En resumen, el control de velocidad mejora la consistencia, pero sin encoders no se puede corregir el error acumulado, lo que limita la precisión en trayectorias largas o maniobras complejas.

---

## Documentación Parte 1
1. Explicacion y conexion correcta de componentes

Esquema de Conexiones Principales
![Esquema de Conexiones General](https://github.com/user-attachments/assets/0cdd423b-ada2-498e-993b-fdcc8e5ad339)


● La imagen muestra las conexiones, que efectivamente fueron realizadas en nuestro trabajo, entre: 
  - El motor A conectado a los pines de OUT1, OUT2 del Driver L298.
  - El motor B conectado a los pines de OUT3, OUT4 del Driver L298.
  - Los pines de control IN1 e IN2 del Driver L298 conectados a los pines digitales 9 Y 8 de Arduino UNO, respectivamente.
  - Los pines de control IN3 e IN4 del Driver L298 conectados a los pines digitales 7 Y 6 de Arduino UNO, respectivamente.
  - Los pines de habilitación ENA y ENB del Driver L298 conectados a los pines digitales 10 y 5 de Arduino UNO, respectivamente.
● En cuanto a la conexión con la fuente de alimentación, consistio en conectar el cable del polo positivo en un extremo de una línea del protoboard y el cable del polo negativo en el otro extremo de esa misma línea, permitiendo que ambos compartan continuidad eléctrica. Mientras que, un cable auxiliar se ubicó en el mismo extremo en el protoboard que el cable con polo positivo, y este cable se conecta al pin de 12V del Driver L298N. Por otra parte, un cable de tierra auxiliar se ubicó en el mismo extremo en el protoboard que el cable con polo negativo, y este cable se conecta al pin GND del Driver L298N. Por último, se ubicó un segundo cable de tierra auxiliar en el mismo extremo en el protoboard que el cable con polo negativo, y este cable se conecta al pin GND de Arduino UNO. De modo que cada módulo pudiera tomar fácilmente tierra de la misma forma.

● Por último, con un cable se conectó el pin de 5V del Driver L298N con el pin de 5V de Arduino UNO.

Tabla  1:

![Conexiones Sensor IMU](https://github.com/user-attachments/assets/8b0cb859-281d-43b2-9176-f318de10a7d2)


Tabla 2:

![Conexiones Sensor Ultrasonico](https://github.com/user-attachments/assets/c16c1f7b-45a0-4da9-ae3c-c15f9bda92dd)

● La tabla 1 muestra cómo el sensor IMU se conecta a Arduino UNO: El sensor IMU utiliza los pines analógicos SDA & SLC.
● La tabla 2 muestra cómo el sensor HC-SR04 se conecta a Arduino UNO: El sensor ultrasónico HC-SR04 emplea dos pines digitales (Trigger/Echo) para medir distancia por ultrasonido.

● Adicionalmente, se conectaron los cables GND al extremo del protoboard, agrupados con el cable de polo negativo de la fuente de alimentación. Mientras que, los cables conectados al pin de 5V del sensor IMU y al pin VCC del sensor ultrasónico están conectados al otro extremo del protoboard, agrupados con el cable de polo positivo de la fuente de alimentación.

● Se utilizó una fuente de alimentación de 4 pilas AA de 1.5V encajadas en un portapilas 4x de pilas AA en serie para hacer funcionar a todo el sistema (Driver L298N, Arduino UNO, 2 Motores DC, Sensor IMU & Sensor Ultrasónico).


2. Implementación del control de motores:
Se realizó una prueba de movimientos básicos de los motores (hacia atrás, hacia adelante, hacer giro hacia la derecho y hacia la izquierda) a velocidad estándar, sin controlar la velocidad.

Link de Vídeo Realizado, en YouTube:
  https://www.youtube.com/watch?v=zlGT86RPtvo


3. Implementación y prueba de control de velocidad por intervalos de tiempo:
Se realizó una prueba donde hubo control de velocidad por intervalos de tiempo, variando las velocidades y los tiempos.

Link de Vídeo Realizado, en YouTube:
https://www.youtube.com/watch?v=EAuy5xxCZF4

5. Respuesta a las preguntas teóricas y análisis de mejoras
Las respuestas a las preguntas teóricas se encuentran en la sección de [Preguntas resueltas Parte 1](#preguntas-resueltas-parte-1).
A continuación se describe un análisis de mejoras:
Hubo problemas prácticos al momento de hacer andar los dos motores de forma simultánea. Sin embargo, logramos hacerlos andar con la batería rectangular de 9v proporcionada inicialmente en el kit, luego de comprobar conexiones repetida y sistemáticamente. Adicionalmente, para hacer funcionar a todo el sistema, consideramos un portapilas 4x de pilas AA en serie, donde van puestas 4 pilas AA de 1.5V. De esta manera, el sistema robótico propuesto en este laboratorio puede funcionar sin ninguna otra fuente de alimentación. Como posible mejora a nuestro trabajo, proponemos el uso de una fuente de alimentación más robusta y estable, como una batería Li-ion recargable de 7.4V (2 celdas). Además, considerar que luego de realizado el laboratorio, se presentó la pérdida de uno de los Jumpers del Driver L298N, por lo que se considera adquirir otro Jumper para reponerlo.

---

## Preguntas Resueltas Parte 2
1. ¿Cómo se calcula la velocidad del robot sin encoders usando PWM?
Respuesta: La velocidad del robot sin encoders puede estimarse indirectamente a partir del valor de PWM, ya que existe una relación aproximadamente lineal entre el ciclo de trabajo del PWM y la velocidad del motor bajo condiciones constantes de carga y voltaje. Esta estimación requiere calibración previa para asociar valores de PWM con velocidades reales medidas.


2. ¿Como factores afectan la trayectoria y velocidad del robot al cambiar los intervalos de tiempo?
Respuesta: Cambiar los intervalos de tiempo afecta la trayectoria y velocidad del robot al modificar la precisión en la estimación de movimiento y la capacidad de respuesta del sistema. Intervalos largos reducen la resolución temporal y pueden generar errores en la trayectoria; intervalos cortos aumentan la sensibilidad al ruido y la carga computacional.


3. ¿Cuáles son las ventajas y desventajas de usar un IMU para ajustar la dirección en lugar de encoders?
Respuesta: 
- Ventajas: Mide orientación en tiempo real, útil en terrenos irregulares y sin deslizamiento.
- Desventajas: Presenta deriva, menor precisión lineal y requiere filtrado.


4. ¿Qué efecto tiene la inclinación o el giro en el movimiento del robot y cómo se corrige con el IMU?
Respuesta: La inclinación o giro puede desviar al robot de su trayectoria. El IMU detecta estos cambios de orientación y permite corregir la dirección en tiempo real, mejorando la precisión del movimiento.


---

## Documentación Parte 2
Respuesta a las preguntas teóricas y análisis de mejoras. 
Sumado a las conexiones realizadas entre el Arduino, el driver L298N, los motores DC y el pack de pilas descritas en la Parte 1, se añaden nuevas conexiones correspondientes al sensor infrarrojo y al sensor IMU, resultando en el siguiente esquema de conexiones:

Esquema de Conexiones Principales

![Conexiones IMU HC-SR04](https://github.com/user-attachments/assets/a50ed15d-5fef-4822-a91b-dadd70f1e723)


● Conexiones para sensor MPU6050 (IMU - giroscopio)
  El MPU6050 usa comunicación I2C, así que los pines son fijos:
  - VCC → 5V del Arduino
  - GND → GND del Arduino
  - SCL → A5 del Arduino
  - SDA → A4 del Arduino

● Conexiones para sensor HC-SR04 (ultrasónico)
  Este sensor usa pines digitales:
  - VCC → 5V del Arduino
  - GND → GND del Arduino
  - Trig → Pin 9 del Arduino
  - Echo → Pin 8 del Arduino

1. 

2. 
   
3. Las respuestas a las preguntas teóricas se encuentran en la sección de [Preguntas resueltas Parte 2](#preguntas-resueltas-parte-2).


---
