#include <MatrizLed.h>

MatrizLed pantalla;
const char text[29] = "*TP1 - GRUPO 17 - SECCION A*";

void setup()
{
  pantalla.begin(13, 11, 12, 2);
  pantalla.rotar(true);
}

void loop()
{

  
  setSentecesStatic(1);
}
/* ---------------------- --> Codigo entrada 1 <-- ----------------------------- */
void sentencesScroll(int velocidad)
{
  pantalla.borrar();
  if (velocidad == 0)
  {
    pantalla.escribirFraseScroll("*TP1 GRUPO 17 SECCION A*", 200);
  }
  else
  {
    pantalla.escribirFraseScroll("*TP1 GRUPO 17 SECCION A*", 700);
  }
}
void setSentecesStatic(int velocidad)
{

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
    if (velocidad == 0)
    {
      delay(200);
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
