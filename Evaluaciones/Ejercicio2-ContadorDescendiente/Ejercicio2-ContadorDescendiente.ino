/*
EJERCICIO 2
CONTADOR DESCENDIENTE
ARDUINO MEGA
EDISON PICUASI
*/


#include <LiquidCrystal.h>
#include <MsTimer2.h>

LiquidCrystal lcd(27, 26, 25, 24, 23, 22);
int contador;
int conversor;
int on = 0;
int st;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  MsTimer2::set(1000, reloj);
  attachInterrupt(digitalPinToInterrupt(21), opciones, FALLING);
  MsTimer2::start();
}

void loop() {
  if (contador == 0 && on == 1) {
    conversor = analogRead(A0);
    conversor = map(conversor, 0, 1023, 10, 20);
    delay(200);
    //  Serial.println(conversor);
  }

  //  Serial.println(on);
}

void opciones() {
  switch (on) {
    case 0:
      on++;
      Serial.println("Mover Potenciometro");
//      Serial.println(on);
      break;
    case 1:
      on++;
      contador = conversor;
      Serial.println("Inicia Decremento");
//      Serial.println(on);
      st = 1;
      break;
    case 2:
      on = 0;
      Serial.println("Reiniciar Contador");
//      Serial.println(on);
      break;
  }
}
void reloj() {
  if (st == 1) {
//    MsTimer2::start();
    contador--;
    Serial.println("Timer: "+contador+1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(contador+1);
  }
  if(contador<0){
    contador=0;
    st=0;
    on=2;
    }
}
