# Laboratorio-1-Robótica-y-Sistemas-Autónomos

# Presentado por:
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

---


## Preguntas Resueltas Parte 1
1. ¿Qué función cumplen los sensores, actuadores y controladores en el robot?
 
Respuesta: Los sensores tienen la función de percibir y captar información del entorno, como distancia, temperatura, luz, entre otros. Los actuadores permiten al robot ejecutar movimientos físicos o acciones, como desplazar ruedas, mover brazos o activar mecanismos. Por su parte, los controladores procesan la información proveniente de los sensores y generan señales de control para los actuadores, actuando como un puente que coordina la percepción con la acción. En conjunto, estos tres componentes permiten que el robot funcione de manera estructurada y estandarizada.


2. ¿Cómo se puede estimar la velocidad sin encoders?

Respuesta: Se estima de forma manual, registrando la posición inicial en un tiempo inicial, y la posición final en un tiempo final. 

![image](https://github.com/user-attachments/assets/cf4eb19e-e3d6-4433-aa39-66c01a1036a6)


3. ¿Cómo afecta la falta de encoders a la precisión del movimiento?

Respuesta: Sin encoders, el sistema no tiene retroalimentación directa sobre su posición o velocidad real, por lo que debe asumir que los motores se comportan exactamente como se les indica, lo que rara vez ocurre debido a factores como el rozamiento, deslizamiento o carga variable.


4. ¿Qué es PWM y cómo ayuda a controlar la velocidad de los motores?

Respuesta: PWM (Pulse Width Modulation o Modulación por Ancho de Pulso) es una técnica que consiste en encender y apagar rápidamente una señal digital para controlar la cantidad de energía entregada a un dispositivo.


5. ¿Cómo afecta el control de velocidad a la precisión de la navegación sin encoders?

R: Sin encoders, incluso con control de velocidad, no se puede asegurar que el robot se desplace a la distancia esperada, lo que reduce la precisión en la navegación.

---

## Documentación Parte 1

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

Respuesta:La inclinación o giro puede desviar al robot de su trayectoria. El IMU detecta estos cambios de orientación y permite corregir la dirección en tiempo real, mejorando la precisión del movimiento.


---

## Documentación Parte 2

---
