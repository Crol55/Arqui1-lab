#include <MatrizLed.h>

MatrizLed pantalla;
const char text[29] = "*TP1 - GRUPO 17 - SECCION A*";
int pin5 = 5;
int pin4 = 4;
int pin3 = 3;
int pin1 = 1;
void setup()
{
  Serial.begin(9600);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin1,OUTPUT);
  pantalla.begin(13, 11, 12, 2);
  pantalla.rotar(true);
}

void loop()
{
  //Entrada #1
  if (digitalRead(pin5) == HIGH and digitalRead(pin4) == LOW)
  {
    pantalla.encender();
    //fucion 0 - 1
    if (digitalRead(pin3) == LOW)
    {
      //Cambio de velocidad
      if(digitalRead(pin1) == LOW){
        sentencesScroll(0);
      }else{
        sentencesScroll(1);
      }
    }
    else
    {
      //Cambio de velocidad
      if(digitalRead(pin1) == LOW){
        setSentecesStatic(0);
      }else{
        setSentecesStatic(1);
      }
    }

    //Entrada #2
  }
  else if (digitalRead(pin4) == HIGH and digitalRead(pin5) == LOW)
  {
    if (digitalRead(pin3) == HIGH)
    {
    }
    else
    {
    }
  }else if (digitalRead(pin4) == LOW and digitalRead(pin5) == LOW){
    pantalla.apagar();
  }
  
 
}
/* ---------------------- --> Codigo entrada 1 <-- ----------------------------- */
void sentencesScroll(int velocidad)
{
  pantalla.borrar();
  if (velocidad == 1)
  {
    pantalla.escribirFraseScroll("*TP1 GRUPO 17 SECCION A*", 100);
  }
  else
  {
    pantalla.escribirFraseScroll("*TP1 GRUPO 17 SECCION A*", 700);
  }
}
void setSentecesStatic(int velocidad)
{
  pantalla.borrar();
  for (int i = 0; i < 29; i++)
  {
    char caracter = text[i];
    if (caracter != '-' && caracter != ' ')
    {
      pantalla.escribirCaracter(caracter, 0);
    }
    else if (caracter == '-')
    {
      guion();
    }
    if (velocidad == 1)
    {
      delay(100);
    }
    else
    {
      delay(800);
    }
    pantalla.borrar();
  }
}
void guion()
{
  pantalla.setRow(1, 0, B00000000);
  pantalla.setRow(1, 1, B00000000);
  pantalla.setRow(1, 2, B00000000);
  pantalla.setRow(1, 3, B11111111);
  pantalla.setRow(1, 4, B00000000);
  pantalla.setRow(1, 5, B00000000);
  pantalla.setRow(1, 6, B00000000);
  pantalla.setRow(1, 7, B00000000);
}


/* ---------------------- ---------------------------------- ----------------------------- */
