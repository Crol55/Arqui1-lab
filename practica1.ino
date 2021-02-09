#include <MatrizLed.h>


MatrizLed pantalla;

void setup()
{
  pantalla.begin(13, 11, 12, 2);
  pantalla.rotar(true);

}

  
void loop() { 

  
  // Desplazar texto manualmente hacia la derecha
 // pantalla.borrar();
  //for(int i=-230; i<30; i++){
   // pantalla.escribirFrase("*TP1 - GRUPO17 - SECCION A*", i); // Texto, posicion en la pantalla
   // delay(10);
 // }


    // Desplazar texto manualmente hacia la IZQUIERDA
  pantalla.borrar();
  for(int i = 30; i > -220; i--){
    pantalla.escribirFrase("*TP1  GRUPO17  SECCION A*", i); // Texto, posicion en la pantalla
    delay(10);
  }

}
