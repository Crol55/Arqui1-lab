#include "LedControl.h"
#include "juegoSnake.h"


LedControl lc = LedControl(13,11,12,2);

//======== Variables Globales
snake *serpiente;
unsigned long tiempo_snake = 0;
int intervalo = 100; // movimiento del juego
// pines
int pinArriba = 10;
int pinAbajo = 8;
int pinDerecha = 9;
int pinIzquierda = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*1er Matriz*/
  lc.shutdown(0, false);
  lc.setIntensity(0,4);
  lc.clearDisplay(0);
  /*2da Matriz*/
  lc.shutdown(1, false);
  lc.setIntensity(1,4);
  lc.clearDisplay(1);

  //======== Inicializar pines ======  
  pinMode(pinArriba,INPUT); 
  pinMode(pinDerecha,INPUT);
  pinMode(pinAbajo,INPUT);
  pinMode(pinIzquierda,INPUT);
 // ======== Inicializar variables del snake ==========
  direccionM = 'R'; // El movimiento inicial sera hacia la derecha (right)
  serpiente = new snake(); // Unica instancia del snake
}


void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 16; i++)
  {
    if(i <8)
      lc.setColumn(0,i,pantallaSnake[i]);
    else
      lc.setColumn(1,i-8,pantallaSnake[i]);
  }
  
  // leer direccion de movimient
  if(digitalRead(pinArriba) && (direccionM != 'D')){
    direccionM = 'U';// up
  }else if(digitalRead(pinDerecha) && (direccionM != 'L')){
    direccionM = 'R';// Right
  }else if(digitalRead(pinAbajo) && (direccionM != 'U')){
    direccionM = 'D'; // Down
  }else if(digitalRead(pinIzquierda) && (direccionM != 'R')){
    direccionM = 'L'; // Left
  }
  
  if(millis() > tiempo_snake + intervalo){
    tiempo_snake = millis();
    switch(direccionM){ // Que boton pulso
      case 'U':{movArriba(serpiente);}break;
      case 'R':{movDerecha(serpiente);}break;
      case 'D':{movAbajo(serpiente);}break;
      case 'L':{movIzquierda(serpiente);}break;
    }   
  }
  
  //nodo colita = serpiente->getCola();
  //serpiente->update_cuerpo();
  //Serial.println(colita.columna);
  
 /* for(int fila =0; fila <8; fila++)
  {
    for(int col = 0; col <8; col++)
    {
      lc.setLed(0, fila, col, true);
      delay(50);
      lc.setLed(0, fila, col, false);
      delay(50);
    }
  }*/

  /*for(int fila =0; fila <8; fila++)
  {
    for(int col = 0; col <8; col++)
    {
      lc.setLed(1, fila, col, true);
      delay(50);
      lc.setLed(1, fila, col, false);
      delay(50);
    }
  }*/
}
