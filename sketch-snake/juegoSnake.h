
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
  void insertar(int col, int fila){
    nodo nuevo = {col, fila};
    cuerpo_snake[longitud] = nuevo; // insertamos una nueva cabeza al snake
    longitud++; // crece el snake
  }
  
};


byte pantallaSnake[16] = {0,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0}; // matriz de 16 * 8, ( vista desde el punto de "BYTES")
char direccionM; // indica la direccion actual del snake (izq,der..etc)


byte set_vida_enColumna(byte columna_libre) // Busca el espacio vacio en la columna con espacio libre
{
  int vacio;
  for(int f = 0; f < 8; f++) // Iterar en las filas para buscar pos vacia.
  {
     vacio = bitRead(columna_libre,f); // buscar en cada posicion
     if(vacio == 0) // si encuentra un espacio vacio, debe colocar 1 (vida) y actualizar la columna
     {
         bitWrite(columna_libre,f,1); // modificamos la columna
        // pantallaSnake[i] = columna; //Agregamos la columna modificada
         break; // salir del for de filas
     }
  }
  return columna_libre; // retornamos la columna modificada
}

void colocar_vida(snake *serpiente)
{
    nodo cabeza = serpiente->getCabeza();
    int col;
    col = cabeza.columna;
// ==== Buscar una columna libre =====
    //int col_libre = -1;
// 1) Primero buscar un espacio libre usando random...
    randomSeed((cabeza.columna + cabeza.fila));
    int randomNumber = random(0,16);
    //Serial.println(randomNumber);
    byte col_random = pantallaSnake[randomNumber];
    
    if(col_random != 255){ // implica que la columna random que selecciono, no esta ocupada completamente
      //col_libre = randomNumber;
      byte nueva_columna = set_vida_enColumna(col_random);
      pantallaSnake[randomNumber] = nueva_columna;
      
    }else if(col > 8){ // colocar mas a la izquierda (ya que random no funciono)
      
      for(int i =0; i < 16; i ++){ // buscar espacio vacio
        byte columna = pantallaSnake[i];
        if(columna != 255)// hay espacio
        {
          byte nueva_columna = set_vida_enColumna(columna);
          pantallaSnake[i] = nueva_columna;
          break;
        }
      }
    }else{ // colocar mas a la derecha
      
      for(int i = 15; i >= 0; i --){ // buscar espacio vacio
        byte columna = pantallaSnake[i];
        if(columna != 255)// hay espacio
        {
          byte nueva_columna = set_vida_enColumna(columna);
          pantallaSnake[i] = nueva_columna;
          break;
        }
      }
    }
}




void borrarCola(int col, int fila) // borrar la cola de snake en la pantalla
{
  byte byteCol = pantallaSnake[col]; // recuperar el byte donde esta la cola 
  bitWrite(byteCol, fila, 0); // borramos el bit 
  pantallaSnake[col] = byteCol; // volvemos a colocar la columna (bytes)
}


bool movHorizontal(snake *serpiente, char dir) // dir = Right/Left
{
  bool colision = false; // para indicar si colisiono
  //===0) Determinar si debe moverse a la derecha o a la izquierda
  int d;
  if(dir == 'R') d = 1;
  else d = -1;
  //== 1) Recuperar cabeza y columna siguiente a donde se movera.
  nodo cabeza = serpiente -> getCabeza();
  int colSiguiente = cabeza.columna + d; // -1: izquierda, +1 Derecha
  if(colSiguiente>15)Serial.println("Murio");
  byte nuevo = pantallaSnake[colSiguiente]; // la columna donde deseamos colocar la nueva cabeza del snake.
  //== 2) Verificar si hubo colision ( vida o a si mismo)
  if( bitRead(nuevo,cabeza.fila) ){
    serpiente->insertar(colSiguiente, cabeza.fila);
    bitWrite(nuevo, cabeza.fila, 1 );
    pantallaSnake[colSiguiente] = nuevo; //actualizar matriz 
    colision = true;
       
  }else{ // movimiento sin colision
    // actualizar la cola del snake
    nodo viejaCola = serpiente->getCola();
    borrarCola(viejaCola.columna, viejaCola.fila); // borrar de la pantalla
    serpiente->update_cuerpo();
    bitWrite(nuevo, cabeza.fila, 1 );
    pantallaSnake[colSiguiente] = nuevo; //actualizar matriz
    // actualizar la cabeza de la snake
    cabeza.columna = colSiguiente;
    serpiente->setCabeza(cabeza);
  } 
  return colision;
}


bool movVertiacal(snake *serpiente, char dir)
{
  bool colision = false; // para indicar si colisiono
  nodo cabeza = serpiente -> getCabeza();
  byte nuevo = pantallaSnake[cabeza.columna];
  int fila_sig;
  if(dir == 'U')
    fila_sig = cabeza.fila+1;
  else 
  fila_sig = cabeza.fila-1;
  
  if(bitRead(nuevo,fila_sig)){ // detectar colision
    
    serpiente->insertar(cabeza.columna, fila_sig);
    bitWrite(nuevo, fila_sig, 1 );
    pantallaSnake[cabeza.columna] = nuevo; //actualizar matriz 
    colision = true;
    
  }else{
    nodo viejaCola = serpiente->getCola();
    borrarCola(viejaCola.columna, viejaCola.fila); // borrar de la pantalla
    serpiente->update_cuerpo();

    nuevo = pantallaSnake[cabeza.columna];
    bitWrite(nuevo, fila_sig, 1);
    pantallaSnake[cabeza.columna] = nuevo; // actualizar la matriz
    cabeza.fila = fila_sig;
    serpiente-> setCabeza(cabeza); 
  }
  return colision;
}
/*
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
  
}*/


/*
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
*/
