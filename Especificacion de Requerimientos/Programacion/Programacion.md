# Programacion
## Placa de control

* Se usara un Arduino Mega por controlador para el simulador, luego este tendra como interface con el motor una placa puente H(a definir integrado)
* El arduino recibe ordenes via interface serial desde el computador con el programa simulador corriendo(A definir si se va a usar una interface entre simulador y puerto serial o se usara existente)
* El arduino recibe la posicion de los motores por dos medios, uno de ellos es de redundancia: encoders(principal) y finales de carrera(redundancia)

## Caracteristicas del programa en el controlador
* El programa se escribira en el lenguaje nativo de Arduino (mezcla de Processing y C++)

## Caracteristicas del programa en el controlador
* Si el programa interface con el FSX se debe escribir desde cero se preferira usar VB.NET

## Tentativa de algoritmo de control
1. El computador manda instrucciones por serial al Arduino
2. El arduino traduce las variables recibidas en posicion, la cual se verifica con el encoder y se mueve con el puente H enviando PWM a este
3. Si por algun problema o incidente el actuador no se detiene existen finales de carrera en los actuadores que detienen la ejecucion del programa

## Programa de comunicacion con plataforma
Puede ocurrir que el software que traduzca las posiciones desde el FSX tenga que hacerse desde cero. En ese caso se tendra que diseñar el programa usando una libreria interface entre el simulador y el puerto serial con el arduino.
Algunas librerias son el [SimConnect](https://docs.microsoft.com/en-us/previous-versions/microsoft-esp/cc526983(v=msdn.10)) (propia de microsoft, de uso gratuito) y otra opcion es [FSUIPC](https://www.schiratti.com/dowson.html) (programa interface de pago con una opcion demo)
