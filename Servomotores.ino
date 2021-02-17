#include <Servo.h>

/*---------- --> SERVOMOTOR<-- ------------*/
Servo servo1;
Servo servo2;
int pinServo1 = 13;
int pinServo2 = 12;
// Variable para la posicion del servo
int posServo1 = 0;
int posServo2 = 0;
/*---------- ---- ------------*/
void setup()
{
  // Inicializacion del servomotor
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
}

void loop()
{
  runServo1();
  runServo2();
}

/**
 * Metodo que ejecuta las fucinoes del servomotor uno.
 * Gira 90 grados.
 * **/
void runServo1()
{
  // Realiza el giro 0-90 grados
  for (posServo1 = 0; posServo1 < 90; posServo1++)
  {
    servo1.write(posServo1);
    delay(15);
  }
  delay(100);
  // Realiza el giro de 90-0 grados
  for (posServo1 = 90; posServo1 >= 0; posServo1--)
  {
    servo1.write(posServo1);
    delay(15);
  }
}

/**
 * Metodo que ejecuta las fucinoes del servomotor dos.
 * Gira 90 grados.
 * **/
void runServo2()
{
  // Realiza el giro 0-90 grados
  for (posServo2 = 0; posServo2 < 90; posServo2++)
  {
    servo2.write(posServo2);
    delay(15);
  }
  delay(100);
  // Realiza el giro de 90-0 grados
  for (posServo2 = 90; posServo2 >= 0; posServo2--)
  {
    servo2.write(posServo2);
    delay(15);
  }
}
