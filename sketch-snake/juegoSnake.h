
class nodo{
  public:
  int columna;
  int fila;  
};


class snake{

  private:
  nodo cuerpo_snake[256];
  public:
  int longitud; // longitud del snake
  snake()
  {
    nodo cola = {7,4};
    nodo cabeza = {8,4};
    cuerpo_snake[0] = cola;
    cuerpo_snake[1] = cabeza;
    longitud = 2; // tamaño inicial del snake
  }
  nodo getCola(){
    return cuerpo_snake[0]; // la cola nunca se mueve de posicion.
  }
  nodo getCabeza(){
    return cuerpo_snake[longitud-1]; // retorna la cabeza del snake  
  }
  void setCabeza(nodo nuevo)
  {
    cuerpo_snake[longitud-1] = nuevo;
  }
  void update_cuerpo() // actualiza todo el cuerpo del snake para saber en que posicion va
  {
    //nodo nuevo = {8,4};
    for(int i = 0; i <= longitud-2; i++) // el ciclo no debe iterar la cabeza
    {
      cuerpo_snake[i] = cuerpo_snake[i+1];
    }
  }
};


byte pantallaSnake[16] = {0,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0}; // matriz de 16 * 8, ( vista desde el punto de "BYTES")
char direccionM; // indica la direccion actual del snake (izq,der..etc)


void movDerecha(int colActual, int posBit)
{
  /*// Mover la cabeza a la derecha
  int colSiguiente = colActual +1;
  byte nuevo = pantallaSnake[colSiguiente]; // la columna donde deseamos colocar la nueva cabeza del snake.
  bitWrite(nuevo, posBit, 1 );
  pantallaSnake[colSiguiente] = nuevo;
  // actualizar la cabeza de la snake
  cabezaS[0] = colSiguiente; // solo actualizamos la columna, el bit se queda igual
  // actualizar la cola del snake
  */
}

void borrarCola(int col, int fila) // borrar la cola de snake en la pantalla
{
  byte byteCol = pantallaSnake[col]; // recuperar el byte donde esta la cola 
  bitWrite(byteCol, fila, 0); // borramos el bit 
  pantallaSnake[col] = byteCol; // volvemos a colocar la columna (bytes)
}

void movDerecha(snake *serpiente)
{
  // actualizar la cola del snake
  nodo viejaCola = serpiente->getCola();
  borrarCola(viejaCola.columna, viejaCola.fila); // borrar de la pantalla
  serpiente->update_cuerpo();
  
  nodo cabeza = serpiente -> getCabeza();
  int colSiguiente = cabeza.columna +1;
  byte nuevo = pantallaSnake[colSiguiente]; // la columna donde deseamos colocar la nueva cabeza del snake.
  bitWrite(nuevo, cabeza.fila, 1 );
  pantallaSnake[colSiguiente] = nuevo; //actualizar matriz
  // actualizar la cabeza de la snake
  cabeza.columna = colSiguiente;
  serpiente->setCabeza(cabeza);
  
}

void movArriba(snake *serpiente)
{
  nodo viejaCola = serpiente->getCola();
  borrarCola(viejaCola.columna, viejaCola.fila); // borrar de la pantalla
  serpiente->update_cuerpo();
  
  nodo cabeza = serpiente -> getCabeza();
  byte nuevo = pantallaSnake[cabeza.columna];
  bitWrite(nuevo, cabeza.fila+1, 1);
  pantallaSnake[cabeza.columna] = nuevo; // actualizar la matriz
  cabeza.fila = cabeza.fila +1;
  serpiente-> setCabeza(cabeza);
}

void movAbajo(snake *serpiente)
{
  nodo viejaCola = serpiente->getCola();
  borrarCola(viejaCola.columna, viejaCola.fila); // borrar de la pantalla
  serpiente->update_cuerpo();
  
  nodo cabeza = serpiente -> getCabeza();
  byte nuevo = pantallaSnake[cabeza.columna];
  bitWrite(nuevo, cabeza.fila-1, 1);
  pantallaSnake[cabeza.columna] = nuevo; // actualizar la matriz
  cabeza.fila = cabeza.fila -1;
  serpiente-> setCabeza(cabeza);
}

void movIzquierda(snake *serpiente)
{
  // actualizar la cola del snake
  nodo viejaCola = serpiente->getCola();
  borrarCola(viejaCola.columna, viejaCola.fila); // borrar de la pantalla
  serpiente->update_cuerpo();
  
  nodo cabeza = serpiente -> getCabeza();
  int colSiguiente = cabeza.columna -1;
  byte nuevo = pantallaSnake[colSiguiente]; // la columna donde deseamos colocar la nueva cabeza del snake.
  bitWrite(nuevo, cabeza.fila, 1 );
  pantallaSnake[colSiguiente] = nuevo; //actualizar matriz
  // actualizar la cabeza de la snake
  cabeza.columna = colSiguiente;
  serpiente->setCabeza(cabeza);
  
}
