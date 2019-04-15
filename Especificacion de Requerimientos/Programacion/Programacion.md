# Programacion
Placa de control
---
* Se usara arduino(Variante a definir) por controlador para el simulador, luego este tendra como interface con el motor una placa puente H(a definir integrado)
* El arduino recibe orvenes via interface serial desde el computador con el prograa simulador corriendo(A definir si se va a usar una interface entre simulador y puerto serial o se usara existente)
* El arduino recibe la posicion de los motores por dos medios, uno de ellos es de redundancia: encoders(principal) y finales de carrera(redundancia)

Caracteristicas del programa en el controlador
---
* El programa se escribira en el lenguaje nativo de Arduino (mezcla de Processing y C++)

Caracteristicas del programa en el controlador
---
* Si el programa interface se debe escribir desde cero se preferira usar VB.NET

Tentativa de algoritmo de control
---
1. El computador manda instrucciones por serial al Arduino
2. El arduino traduce las variables recibidas en posicion, la cual se verifica con el encoder y se mueve con el puente H enviando PWM a este
3. Si por algun problema o incidente el actuador no se detiene existen finales de carrera en los actuadores que detienen la ejecucion del programa
