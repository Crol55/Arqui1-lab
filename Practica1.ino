#include <LedControl.h>

#include <MatrizLed.h>
#include "juegoSnake.h"

MatrizLed pantalla;
const char text[29] = "*TP1 - GRUPO 17 - SECCION A*";
int pin5 = 5;
int pin4 = 4;
int pin3 = 3;
int pin22 = 22;
int pin24 = 24;
int tiempoTranscurrido;
/* ---------------------------- Code snake ---------------------------*/

LedControl lc = LedControl(13, 11, 12, 2);

//======== Variables Globales
// snake
snake *serpiente;
unsigned long tiempo_snake = 0;
int intervalo = 875; // movimiento del juego
long randomNumber;

// pines
int pinArriba = 10;
int pinAbajo = 8;
int pinDerecha = 9;
int pinIzquierda = 7;
// var del programa
char modo_juego; // m:mensaje, s:snake
/* ---------------------------- ------------ ---------------------------*/

void setup()
{
  Serial.begin(9600);
  /*1er Matriz*/
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
  /*2da Matriz*/
  lc.shutdown(1, false);
  lc.setIntensity(1, 4);
  lc.clearDisplay(1);
  //======== Inicializar pines ======
  tiempoTranscurrido = 0;
  pinMode(pin5, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin22, INPUT);
  pinMode(pin24, INPUT);
  pinMode(pinArriba, INPUT);
  pinMode(pinDerecha, INPUT);
  pinMode(pinAbajo, INPUT);
  pinMode(pinIzquierda, INPUT);
  pantalla.begin(13, 11, 12, 2);
  pantalla.rotar(true);

  // ======== Inicializar variables del snake ==========
  direccionM = 'R';        // El movimiento inicial sera hacia la derecha (right)
  serpiente = new snake(); // Unica instancia del snake
                           // ======== Inicializar variables del programa =======
  modo_juego = 'm';        // Inicia en modo mensaje.
}

void loop()
{
  //start();
  if (digitalRead(pin24))
  {
    if (tiempoTranscurrido == 0)
      tiempoTranscurrido = millis(); // Momento exacto donde se presiono el boton
    if (tiempoTranscurrido != 0)
    {
      int t2 = millis();
      if (((t2 - tiempoTranscurrido) / 1000) >= 3)
        startSnake();
    }
  }
  else
  {
    start();
  }
}
void start()
{
  //Start snake
  //if (digitalRead(pin24) == HIGH)
  //{
  // startSnake();
  // }
  if (digitalRead(pin24) == LOW)
  {
    //Entrada #1
    if (digitalRead(pin5) == HIGH and digitalRead(pin4) == LOW)
    {
      pantalla.encender();
      //fucion 0 - 1
      if (digitalRead(pin3) == LOW)
      {
        //Cambio de velocidad
        if (digitalRead(pin22) == LOW)
        {
          sentencesScroll(0);
        }
        else
        {
          sentencesScroll(1);
        }
      }
      else
      {
        //Cambio de velocidad
        if (digitalRead(pin22) == LOW)
        {
          setSentecesStatic(0);
        }
        else
        {
          setSentecesStatic(1);
        }
      }

      //Entrada #2
    }
    else if (digitalRead(pin4) == HIGH and digitalRead(pin5) == LOW)
    {
      metodo2();
    }
    else if (digitalRead(pin4) == LOW and digitalRead(pin5) == LOW)
    {

      pantalla.apagar();
    }
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

void startSnake()
{
  // put your main code here, to run repeatedly:
  if (modo_juego == 'm')
  {
    if (millis() > 1000)
    {
      modo_juego = 's';
      randomSeed(millis()); // para que los enemigos sean RANDOM
    }
  }
  else
  {
    for (int i = 0; i < 16; i++)
    {
      if (i < 8)
        lc.setColumn(0, i, pantallaSnake[i]);
      else
        lc.setColumn(1, i - 8, pantallaSnake[i]);
    }

    // leer direccion de movimient
    if (digitalRead(pinArriba) && (direccionM != 'D'))
      direccionM = 'U'; // up
    else if (digitalRead(pinDerecha) && (direccionM != 'L'))
      direccionM = 'R'; // Right
    else if (digitalRead(pinAbajo) && (direccionM != 'U'))
      direccionM = 'D'; // Down
    else if (digitalRead(pinIzquierda) && (direccionM != 'R'))
      direccionM = 'L'; // Left

    if (millis() > tiempo_snake + intervalo)
    {

      tiempo_snake = millis();
      int estado = 0; // 0:El juego sigue normal, 1:Generar vida/comida, 2:El jugador perdio
      switch (direccionM)
      { // Que boton pulso
      case 'U':
      {
        estado = movVertical(serpiente, 'U');
      }
      break;
      case 'R':
      {
        estado = movHorizontal(serpiente, 'R');
      }
      break;
      case 'D':
      {
        estado = movVertical(serpiente, 'D');
      }
      break;
      case 'L':
      {
        estado = movHorizontal(serpiente, 'L');
      }
      break; //estado = movHorizontal(serpiente,'L'); movIzquierda(serpiente);
      }
      switch (estado)
      {
      case 1:
      {

        colocar_vida(serpiente);   // implica que comio
        intervalo = intervalo - 5; // incrementar la velocidad del snake
      }
      break;
      case 2:
      { // perdio el juego
        Serial.println("Terminar juego");
        //Serial.println(serpiente->get_comidaIngerida());
        // Si desea volver a jugar debemos reiniciar todas las variables de snake y luego retornar al mensaje.
        serpiente = new snake();
        reiniciar_snake();
        modo_juego = 'm';
      }
      break;
      }
    }
  }
}

/* ---------------------- ---------------------------------- ----------------------------- */
void metodo2()
{

  if (digitalRead(3) == HIGH)
  {
    movizquierda();
  }
  else
  {
    movderecha();
  }
}

void movderecha()
{

  if (digitalRead(3) != HIGH)
  {

    //  Desplazar texto manualmente hacia la derecha
    pantalla.borrar();
    for (int i = -80; i < 30; i++)
    {
      pantalla.escribirFrase("SECCION A*", i); // Texto, posicion en la pantalla

      if (digitalRead(3) == HIGH)
      {
        pantalla.borrar();
        i = 30;
      }
      if (digitalRead(22) == HIGH)
      {
        delay(10);
      }
      else
      {
        delay(500);
      }
    }
  }

  if (digitalRead(3) != HIGH)
  {

    guionder();
  }

  if (digitalRead(3) != HIGH)
  {
    pantalla.borrar();
    for (int i = -65; i < 30; i++)
    {
      pantalla.escribirFrase("GRUPO17", i); // Texto, posicion en la pantalla
      if (digitalRead(3) == HIGH)
      {
        pantalla.borrar();
        i = 30;
      }
      if (digitalRead(22) == HIGH)
      {
        delay(10);
      }
      else
      {
        delay(500);
      }
    }
  }

  if (digitalRead(3) != HIGH)
  {

    guionder();
  }

  if (digitalRead(3) != HIGH)
  {
    pantalla.borrar();
    for (int i = -30; i < 30; i++)
    {
      pantalla.escribirFrase("*TP1", i); // Texto, posicion en la pantalla
      if (digitalRead(3) == HIGH)
      {
        pantalla.borrar();
        i = 30;
      }
      if (digitalRead(22) == HIGH)
      {
        delay(10);
      }
      else
      {
        delay(500);
      }
    }
  }
}

void movizquierda()
{

  if (digitalRead(3) == HIGH)
  {
    // Desplazar texto manualmente hacia la IZQUIERDA
    pantalla.borrar();
    for (int i = 30; i > -50; i--)
    {
      pantalla.escribirFrase("*TP1", i); // Texto, posicion en la pantalla
      if (digitalRead(3) != HIGH)
      {
        pantalla.borrar();
        i = -50;
      }
      if (digitalRead(22) == HIGH)
      {
        delay(10);
      }
      else
      {
        delay(500);
      }
    }
  }

  if (digitalRead(3) == HIGH)
  {
    pantalla.borrar();
    guioniz();
  }

  if (digitalRead(3) == HIGH)
  {

    pantalla.borrar();
    for (int i = 30; i > -60; i--)
    {
      pantalla.escribirFrase("GRUPO17", i); // Texto, posicion en la pantalla
      if (digitalRead(3) != HIGH)
      {
        pantalla.borrar();
        i = -60;
      }
      if (digitalRead(22) == HIGH)
      {
        delay(10);
      }
      else
      {
        delay(500);
      }
    }
  }

  if (digitalRead(3) == HIGH)
  {
    pantalla.borrar();
    guioniz();
  }

  if (digitalRead(3) == HIGH)
  {
    pantalla.borrar();
    for (int i = 30; i > -75; i--)
    {
      pantalla.escribirFrase("SECCION A*", i); // Texto, posicion en la pantalla
      if (digitalRead(3) != HIGH)
      {
        pantalla.borrar();
        i = -75;
      }
      if (digitalRead(22) == HIGH)
      {
        delay(10);
      }
      else
      {
        delay(500);
      }
    }
  }
}

void guioniz()
{
  pantalla.borrar();
  pantalla.setRow(0, 3, B10000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11100000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11110000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111100);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111110);
  delay(10);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B10000000);
  pantalla.setRow(0, 3, B01111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11000000);
  pantalla.setRow(0, 3, B00111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11100000);
  pantalla.setRow(0, 3, B00011111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11110000);
  pantalla.setRow(0, 3, B00001111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11111000);
  pantalla.setRow(0, 3, B00000111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11111100);
  pantalla.setRow(0, 3, B00000011);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11111110);
  pantalla.setRow(0, 3, B00000001);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11111111);
  pantalla.setRow(0, 3, B00000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.setRow(1, 3, B01111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00011111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00001111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000011);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000001);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
}

void guionder()
{
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000001);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000011);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00000111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00001111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00011111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B00111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B01111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(1, 3, B11111111);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00000001);
  pantalla.setRow(1, 3, B11111110);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00000011);
  pantalla.setRow(1, 3, B11111100);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00000111);
  pantalla.setRow(1, 3, B11111000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00001111);
  pantalla.setRow(1, 3, B11110000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00011111);
  pantalla.setRow(1, 3, B11100000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00111111);
  pantalla.setRow(1, 3, B11000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B01111111);
  pantalla.setRow(1, 3, B10000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111111);
  pantalla.setRow(1, 3, B00000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.setRow(0, 3, B11111110);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111100);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11111000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11110000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11100000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B11000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B10000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
  pantalla.setRow(0, 3, B00000000);
  if (digitalRead(22) == HIGH)
  {
    delay(10);
  }
  else
  {
    delay(500);
  }
  pantalla.borrar();
}
void mostrarpuntaje(int puntaje){

  pantalla.borrar();
  pantalla.escribirFraseScroll(puntaje,200);
}
void mostrarGM(){

  pantalla.borrar();
  pantalla.escribirFraseScroll("GM", 100);
}
