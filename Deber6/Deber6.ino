/*
  MATERIA: SISTEMAS EMBEBIDOS
  NOMBRE: Edison Picuasi
  DEBER 6
  INSTRUCCIONES:
  Realizar un reloj con alarma ingresada por comunicación serial.
  Los números sean vistos en displays.

*/
#include <LiquidCrystal.h>
#include <MsTimer2.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  //configura pin lcd
int segundos, minutos, horas; //variables de reloj
int aminutos, ahoras; //variables de alarma
int cambio1, cambio2; //variable de cambio
int on = 0; //variable de control
String palabra; //variable almacena dato
String nminutos, nhoras;  //variable horas , minutos
void setup() {
  Serial.begin(9600); //inicializa CX Serial
  MsTimer2::set(250, reloj);  //configura timer 2
  MsTimer2::start();  //inicializa timer 2
  Serial.println("SISTEMA DE ALARMA");  //imprime msg por CX serial
  Serial.println("Ingrese Alarma");  //imprime msg por CX serial
  Serial.println("Ejemplo:   12:48  ");  //imprime msg por CX serial

}

void loop() {
  if (Serial.available() > 0) {
    palabra = Serial.readStringUntil('.');  //lee el dato
    int tam;  //variable de tamaño
    tam = palabra.length(); //determina el tamaño
    if (tam != 5) {
      Serial.println("Ingreso Incorrecto");  //imprime msg por CX serial
      Serial.println("Ingrese Alarma");  //imprime msg por CX serial
      Serial.println("Ejemplo:   12:48  ");  //imprime msg por CX serial
      on = 0; //reinicia variable
    } else {
      char cambio[tam]; //variable de cambio letra
      palabra.toCharArray(cambio, tam + 1); //alamcena en array
      if (isDigit(cambio[0]) && isDigit(cambio[1]) &&
          isDigit(cambio[3]) && isDigit(cambio[4]) && cambio[2] == ':') {
        nhoras = palabra.substring(0, 2);   //extrae caracteres
        nminutos = palabra.substring(3, 5); //extrae caracteres
        cambio1 = nhoras.toInt(); //almacena valor
        cambio2 = nminutos.toInt(); //almacena valor
        if (cambio1 < 24 && cambio2 < 60) { //condicion de ejecucion
          Serial.println("\n");  //imprime msg por CX serial
          Serial.println("Ingreso Correcto");  //imprime msg por CX serial
          Serial.println("Alarma Ingresada:");  //imprime msg por CX serial
          ahoras = cambio1; //almacena valor
          aminutos = cambio2; //almacena valor
          Serial.println("Horas: " + String(ahoras));  //imprime msg por CX serial
          Serial.println("Minutos: " + String(aminutos));  //imprime msg por CX serial
          on = 1; //cambio de estado
          tam = 0;  //reinicia variable
        } else {
          Serial.println("Ingreso Incorrecto");  //imprime msg por CX serial
          Serial.println("Ingrese Alarma");  //imprime msg por CX serial
          Serial.println("Ejemplo:   12:48  ");  //imprime msg por CX serial
          on = 0; //reinicia variable
        }
      } else {
        Serial.println("Ingreso Incorrecto");  //imprime msg por CX serial
        Serial.println("Ingrese Alarma");  //imprime msg por CX serial
        Serial.println("Ejemplo:   12:48  ");  //imprime msg por CX serial
        on = 0; //reinicia variable
      }
    }
  }

  if (on == 1 && ahoras == horas && aminutos == minutos) {
    Serial.println("Alarma Iniciada");  //imprime msg por CX serial
    delay(1000);  //tiempo de espera
  }
}

void reloj() {
  if (segundos < 59) {  //condicion de incremento
    segundos++; //incrementa variable
  } else {
    segundos = 0; //reinicia variable
    if (minutos < 59) {  //condicion de incremento
      minutos++; //incrementa variable
    } else {
      minutos = 0; //reinicia variable
      if (horas < 23) {  //condicion de incremento
        horas++; //incrementa variable
      } else {
        horas = 0; //reinicia variable
      }
    }
  }

  if (segundos < 10) { //condicion de impresion
    lcd.setCursor(5, 0);  //posiciona cursor
    lcd.print(":0" + String(segundos)); //imprime msg en lcd
  } else {
    lcd.setCursor(5, 0);  //posiciona cursor
    lcd.print(":" + String(segundos)); //imprime msg en lcd
  }
  if (minutos < 10) { //condicion de impresion
    lcd.setCursor(2, 0);  //posiciona cursor
    lcd.print(":0" + String(minutos)); //imprime msg en lcd
  } else {
    lcd.setCursor(2, 0);  //posiciona cursor
    lcd.print(":" + String(minutos)); //imprime msg en lcd
  }
  if (horas < 10) { //condicion de impresion
    lcd.setCursor(0, 0);  //posiciona cursor
    lcd.print("0" + String(horas)); //imprime msg en lcd
  } else {
    lcd.setCursor(0, 0);  //posiciona cursor
    lcd.print(String(horas)); //imprime msg en lcd
  }
}
