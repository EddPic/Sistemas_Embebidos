/*

  Nombre: Picuasi Edison
  Materia: Sistemas Embebidos

  Realizar un programa de juego de preguntas. Se debe tener mínimo 8 preguntas que deben observarse en orden aleatorio.
  La forma de visualización es por medio de comunicación serial.
  Su respuesta solo debe ser "SI" y "NO" ingresadas de la misma forma por comunicación serial.
  Al final de mostrar solo 5 de las 8 preguntas. Se presentan el puntaje (respuestas acertadas) en un display.

*/
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
int respuestas [] = {1, 0, 0, 1, 1, 0, 1, 1, 1, 0};
int respin[5] = {};
int reordenar[5] = {};
long pregran;
int cont = 0;
int correctas = 0;
boolean ingreso = false;
int resp;
String cadena_leida;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Presione cualquier tecla para iniciar el cuestionario");
  randomSeed(2);
}

void loop() {
  while (Serial.available() == 0) {
    cadena_leida = "";
  }
  do {
    char caracter_leido;
    delay(200);
    caracter_leido = Serial.read();
    cadena_leida += caracter_leido;
  }  while (Serial.available() > 0);
  cadena_leida.toLowerCase();
  if (cadena_leida == "si" || cadena_leida == "no") {
    pregran = random(1, 10);
    ingreso = true;
  } 
  if (ingreso == true) {
    if (cadena_leida == "si") {
      cont++;
      resp = 1;
      if (cont > 1) {
        respin[cont - 2] = resp;
      }
      reordenar[cont - 1] = respuestas[pregran - 1];
      ingreso = false;
    }
    if (cadena_leida == "no") {
      cont++;
      resp = 0;
      if (cont > 1) {
        respin[cont - 2] = resp;
      }
      reordenar[cont - 1] = respuestas[pregran - 1];
      ingreso = false;
    }
    Serial.println("\n");
    preguntas(pregran);
  }
  if (cont >= 6 ) {
    for (int i = 0; i < 5; i++) {
      Serial.println("Ingresados" + String(respin[i]));
    }
    for (int i = 0; i < 5; i++) {
      Serial.println("Reordenados" + String(reordenar[i]));
    }
    for (int i = 0; i < 5; i++) {
      if (respin[i] == reordenar[i]) {

        correctas++;
      }
    }

    lcd.print("R. Bien:" + String(correctas));
    delay(300);
    ingreso = false;
    cont = 0;
    respin[5] = {};
    reordenar[5] = {};
  }


}


void preguntas(int num) {
  switch (num) {
    case 1:
      Serial.println("¿Facebook es una red social?");
      //Si
      break;
    case 2:
      Serial.println("¿El numero de oceanos son 6?");
      //No
      break;
    case 3:
      Serial.println("¿El fundador de Tesla es Jeff Bezos?");
      //No
      break;
    case 4:
      Serial.println("¿La distancia entre la Tierra y la Luna es 384.400 km?");
      //Si
      break;
    case 5:
      Serial.println("¿Quito es la Capital de Ecuador?");
      //Si
      break;
    case 6:
      Serial.println("¿4 es un numero primo?");
      //No
      break;
    case 7:
      Serial.println("¿El rio mas largo del mundo es el Rio Amazonas?");
      //Si
      break;
    case 8:
      Serial.println("¿Michael Jackson esta muerto");
      //Si
      break;
    case 9:
      Serial.println("¿El ornitorrinco es un mamifero?");
      //si
      break;
    case 10:
      Serial.println("¿Ri es una nota musical?");
      //No
      break;
  }
}
