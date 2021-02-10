#include <MatrizLed.h>


MatrizLed pantalla;

void setup()
{
  pantalla.begin(13, 11, 12, 2);
  pantalla.rotar(true);

}

  
void loop() { 


 
  
 //  Desplazar texto manualmente hacia la derecha
  pantalla.borrar();
  for(int i=-80; i<30; i++){
    pantalla.escribirFrase("SECCION A*", i); // Texto, posicion en la pantalla
    delay(10);
  }


  guionder();
  
  
  pantalla.borrar();
  for(int i=-65; i<30; i++){
    pantalla.escribirFrase("GRUPO17", i); // Texto, posicion en la pantalla
    delay(10);
  }


  guionder();


    pantalla.borrar();
  for(int i=-30; i<30; i++){
    pantalla.escribirFrase("*TP1", i); // Texto, posicion en la pantalla
    delay(10);
  }




    // Desplazar texto manualmente hacia la IZQUIERDA
  pantalla.borrar();
  for(int i = 30; i > -50; i--){
    pantalla.escribirFrase("*TP1", i); // Texto, posicion en la pantalla
    delay(10);
  }

  pantalla.borrar();
  guioniz(); 

  pantalla.borrar();
  for(int i = 30; i > -60; i--){
    pantalla.escribirFrase("GRUPO17", i); // Texto, posicion en la pantalla
    delay(10);
  }

  pantalla.borrar();
  guioniz();

    pantalla.borrar();
  for(int i = 30; i > -75; i--){
    pantalla.escribirFrase("SECCION A*", i); // Texto, posicion en la pantalla
    delay(10);
  }


}

void guioniz()
{
    pantalla.borrar();
      pantalla.setRow(0, 3, B10000000);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11000000);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11100000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11110000);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111000);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111100);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111110);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B10000000);
      pantalla.setRow(0, 3, B01111111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11000000);
      pantalla.setRow(0, 3, B00111111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11100000);
      pantalla.setRow(0, 3, B00011111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11110000);
      pantalla.setRow(0, 3, B00001111);
      delay(10);
      pantalla.borrar();      
      pantalla.setRow(1, 3, B11111000);
      pantalla.setRow(0, 3, B00000111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111100);
      pantalla.setRow(0, 3, B00000011);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111110);
      pantalla.setRow(0, 3, B00000001);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111111);
      pantalla.setRow(0, 3, B00000000);
      delay(500);
      pantalla.setRow(1, 3, B01111111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00111111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00011111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00001111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000111);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000011);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000001);
      delay(10);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000000);
      delay(10);
      pantalla.borrar();
      
}


void guionder()
{
    pantalla.borrar();
      pantalla.setRow(1, 3, B00000001);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000011);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000111);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00001111);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00011111);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B00111111);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B01111111);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111111);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000001);
      pantalla.setRow(1, 3, B11111110);
      delay(500);   
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000011);
      pantalla.setRow(1, 3, B11111100);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000111);
      pantalla.setRow(1, 3, B11111000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B00001111);
      pantalla.setRow(1, 3, B11110000);
      delay(500);
      pantalla.borrar();      
      pantalla.setRow(0, 3, B00011111);
      pantalla.setRow(1, 3, B11100000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B00111111);
      pantalla.setRow(1, 3, B11000000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B01111111);
      pantalla.setRow(1, 3, B10000000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111111);
      pantalla.setRow(1, 3, B00000000);
      delay(500);
      
      pantalla.setRow(0, 3, B11111110);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111100);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11110000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11100000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B11000000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B10000000);
      delay(500);
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000000);
      delay(500);
      pantalla.borrar();
      
}


