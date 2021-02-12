#include <MatrizLed.h>
#include <String.h>

MatrizLed pantalla;

void setup()
{
  pantalla.begin(13, 11, 12, 2);
  pantalla.rotar(true);

}

  
void loop() { 

mostrarGM();
mostrarpuntaje(0);

}

void mostrarpuntaje(int puntaje){

  pantalla.borrar();
  pantalla.escribirFraseScroll(puntaje,200);
}
void mostrarGM(){

  pantalla.borrar();
  pantalla.escribirFraseScroll("GM", 100);
}
