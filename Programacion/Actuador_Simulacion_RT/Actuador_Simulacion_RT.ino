#include <Arduino_FreeRTOS.h>

#define final1_ext 22
#define final1_contr 23
#define motor1_enable1 24
#define motor1_enable2 25

String leeCadena;
int Speed;

void TaskActuator1( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    if (digitalRead(final1_ext) == HIGH || digitalRead(final1_contr) == HIGH)
    {
      analogWrite(motor1_enable1, LOW);
      analogWrite(motor1_enable2, LOW);
    }

    else
    {
      if (Speed < 0)
      {
        analogWrite(motor1_enable1, LOW);
        analogWrite(motor1_enable2, Speed);
      }
      else if (Speed > 0)
      {
        analogWrite(motor1_enable1, Speed);
        analogWrite(motor1_enable2, LOW);
      }
      else
      {
        ;
      }
    }
  }
}

void TaskSerialReceiver( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    while (Serial.available())
    {
      vTaskDelay( 500 / portTICK_PERIOD_MS );
      char c  = Serial.read();
      leeCadena += c;
    }
    if (leeCadena.length() > 0)
    {
      Speed = leeCadena.toInt();
      vTaskDelay( 500 / portTICK_PERIOD_MS ); // delay(500)
    }
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(final1_ext, INPUT);
  pinMode(final1_contr, INPUT);
  pinMode(motor1_enable1, OUTPUT);
  pinMode(motor1_enable2, OUTPUT);

  xTaskCreate(
    TaskActuator1
    ,  (const portCHAR *)"Actuator1"
    ,  128
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    TaskSerialReceiver
    ,  (const portCHAR *)"SerialReceiver"
    ,  128
    ,  NULL
    ,  1
    ,  NULL );
}

void loop() {}
