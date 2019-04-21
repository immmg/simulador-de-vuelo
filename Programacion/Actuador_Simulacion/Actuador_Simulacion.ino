#define final_ext 22
#define final_contr 23

#define motor_actuador1 2

String leeCadena;
int Speed;

void setup() {
  Serial.begin(9600);
  pinMode(final_ext, INPUT);
  pinMode(final_contr, INPUT);
  pinMode(motor_actuador1, OUTPUT);
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

  if (digitalRead(final_ext) == HIGH || digitalRead(final_contr) == HIGH)
  {
    analogWrite(motor_actuador1, LOW);
  }
  else
  {
    analogWrite(motor_actuador1, Speed);
  }

}
