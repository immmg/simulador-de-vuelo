#define final_ext 22
#define final_contr 23
#define motor_enable1 24
#define motor_enable2 25

String leeCadena;
int Speed;

void setup() 
{
  Serial.begin(9600);
  pinMode(final_ext, INPUT);
  pinMode(final_contr, INPUT);
  pinMode(motor_enable1, OUTPUT);
  pinMode(motor_enable2, OUTPUT);
}

void loop()
{
  while (Serial.available())
  { 
    delay(500);
    char c  = Serial.read();     
    leeCadena += c;              
  }

  if (leeCadena.length() > 0)
  {
    Speed = leeCadena.toInt();  
    delay(500);
  }

  if (digitalRead(final_ext) == HIGH || digitalRead(final_contr) == HIGH || Speed == 0)
  {
    analogWrite(motor_enable1, LOW);
    analogWrite(motor_enable2, LOW);
  }
  else
  {
    if(Speed < 0)
    {
      analogWrite(motor_enable1, LOW);
      analogWrite(motor_enable2, Speed);
    }
    else if (Speed > 0)
    {
      analogWrite(motor_enable1, Speed);
      analogWrite(motor_enable2, LOW);
    }
    else
    {
      ;
    }
  }

}
