#include <LiquidCrystal.h>

// === VAR GLOBALES ILUMINACION =====
const int rs=12,en=11,d4=29,d5=27,d6=25,d7=23;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int idHabitacion;
unsigned long tiempoIluminacion = 0;
long intervalo = 4000;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  //lcd.print("hola mundo");
  Serial.begin(9600);

  idHabitacion = 1; // Siempre revisa la primer habitacion
}

void loop() {
  // put your main code here, to run repeatedly:
  control_iluminacion();
}

void control_iluminacion()
{
  if(tiempoIluminacion == 0)
    tiempoIluminacion = millis();
  else if(millis() > tiempoIluminacion + intervalo){
    //Serial.println("Ingreso?");
    tiempoIluminacion = 0;
    idHabitacion++;
    lcd.clear(); // limpiar la pantalla cuando cambia de habitacion
    if(idHabitacion > 4)
      idHabitacion = 1; //reiniciar 
  }

  switch(idHabitacion){

    case 1:{
      if(analogRead(A4) > 15){
        escribir_lcd("Habitacion 1:","Luz Encendida");
         
      }else{
        escribir_lcd("Habitacion 1:","Luz apagada");
      }
    }break; // habitacion 1

    case 2: {
      if(analogRead(A5) > 15){
        escribir_lcd("Habitacion 2:","Luz Encendida");
         
      }else{
        escribir_lcd("Habitacion 2:","Luz apagada");
      }
       
    }break; // habitacion 2

    case 3: {
      if(analogRead(A6) > 15){
        escribir_lcd("Habitacion 3:","Luz Encendida");
         
      }else{
        escribir_lcd("Habitacion 3:","Luz apagada");
      }
       
    }break; // habitacion 3.

    case 4: {
      if(analogRead(A7) > 15){
        escribir_lcd("Habitacion 4:","Luz Encendida");
         
      }else{
        escribir_lcd("Habitacion 4:","Luz apagada");
      }
       
    }break; // habitacion 4
  }//switch

}

void escribir_lcd(const char *msgHabit, const char *msgEstado){
  lcd.setCursor(0,0);
  lcd.print(msgHabit);
  lcd.setCursor(0,1);
  lcd.print(msgEstado);
}
