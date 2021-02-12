void metodo2(){

  
    pinMode(3, INPUT);
    pinMode(22,INPUT);
     
    if (digitalRead(3) == HIGH) {
          movizquierda();           
    }else{         
          movderecha();    
    }

  
}


void movderecha()
{



 if (digitalRead(3) != HIGH) {

 //  Desplazar texto manualmente hacia la derecha
  pantalla.borrar();
  for(int i=-80; i<30; i++){  
    pantalla.escribirFrase("SECCION A*", i); // Texto, posicion en la pantalla 
          
 if (digitalRead(3) == HIGH) {
  pantalla.borrar();
  i = 30;
 }
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
  }
 }



 if (digitalRead(3) != HIGH) {
 
  guionder();

 }
  
  
 if (digitalRead(3) != HIGH) {
  pantalla.borrar();
  for(int i=-65; i<30; i++){
    pantalla.escribirFrase("GRUPO17", i); // Texto, posicion en la pantalla
     if (digitalRead(3) == HIGH) {
  pantalla.borrar();
  i = 30;
 }
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
  }
 }


 if (digitalRead(3) != HIGH) {

  guionder();
 }



 if (digitalRead(3) != HIGH) {
    pantalla.borrar();
  for(int i=-30; i<30; i++){
    pantalla.escribirFrase("*TP1", i); // Texto, posicion en la pantalla   
     if (digitalRead(3) == HIGH) {
  pantalla.borrar();
  i = 30;
 }
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
  }
 }
}



void movizquierda()
{

  
 if (digitalRead(3) == HIGH) {
      // Desplazar texto manualmente hacia la IZQUIERDA
  pantalla.borrar();
  for(int i = 30; i > -50; i--){
    pantalla.escribirFrase("*TP1", i); // Texto, posicion en la pantalla
     if (digitalRead(3) != HIGH) {
  pantalla.borrar();
  i = -50;
 }
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
  }
 }




 if (digitalRead(3) == HIGH) {
  pantalla.borrar();
  guioniz(); 

 }

if (digitalRead(3) == HIGH) {

  pantalla.borrar();
  for(int i = 30; i > -60; i--){
    pantalla.escribirFrase("GRUPO17", i); // Texto, posicion en la pantalla
     if (digitalRead(3) != HIGH) {
  pantalla.borrar();
  i = -60;
 }
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
  }
}


if (digitalRead(3) == HIGH) {
  pantalla.borrar();
  guioniz();


}


if (digitalRead(3) == HIGH) {
    pantalla.borrar();
  for(int i = 30; i > -75; i--){
    pantalla.escribirFrase("SECCION A*", i); // Texto, posicion en la pantalla
     if (digitalRead(3) != HIGH) {
  pantalla.borrar();
  i = -75;
 }
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
  }
}


}

void guioniz()
{
    pantalla.borrar();
      pantalla.setRow(0, 3, B10000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11100000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11110000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111100);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111110);
      delay(10);    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }      pantalla.borrar();
      pantalla.setRow(0, 3, B11111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B10000000);
      pantalla.setRow(0, 3, B01111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11000000);
      pantalla.setRow(0, 3, B00111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11100000);
      pantalla.setRow(0, 3, B00011111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11110000);
      pantalla.setRow(0, 3, B00001111);
      if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();      
      pantalla.setRow(1, 3, B11111000);
      pantalla.setRow(0, 3, B00000111);
      if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111100);
      pantalla.setRow(0, 3, B00000011);
      if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111110);
      pantalla.setRow(0, 3, B00000001);
     if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111111);
      pantalla.setRow(0, 3, B00000000);
      if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.setRow(1, 3, B01111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00011111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00001111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000011);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000001);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000000);
      if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      
}


void guionder()
{
    pantalla.borrar();
      pantalla.setRow(1, 3, B00000001);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000011);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00000111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00001111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00011111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B00111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B01111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(1, 3, B11111111);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000001);
      pantalla.setRow(1, 3, B11111110);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      } 
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000011);
      pantalla.setRow(1, 3, B11111100);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000111);
      pantalla.setRow(1, 3, B11111000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B00001111);
      pantalla.setRow(1, 3, B11110000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();      
      pantalla.setRow(0, 3, B00011111);
      pantalla.setRow(1, 3, B11100000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B00111111);
      pantalla.setRow(1, 3, B11000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B01111111);
      pantalla.setRow(1, 3, B10000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111111);
      pantalla.setRow(1, 3, B00000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }  
      pantalla.setRow(0, 3, B11111110);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111100);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11111000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11110000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11100000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B11000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B10000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      pantalla.setRow(0, 3, B00000000);
    if (digitalRead(22) == HIGH) {
    delay(10);
    }else {
      delay(500);
      }
      pantalla.borrar();
      
}
