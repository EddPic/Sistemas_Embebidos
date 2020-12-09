/*
  MATERIA: SISTEMAS EMBEBIDOS
  NOMBRE: Edison Picuasi
  DEBER 7
  INSTRUCCIONES:
  Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM.
  Como estado inicial, la contraseña es de 4 dígitos que son: 4563.

*/
#include <EEPROM.h>
String palabra;   //varaiable de almacenado
char cambio[5];   //variable de asignacion
int on = 0;       //variable de control
void setup() {
  Serial.begin(9600); //inicializa Cx serial
  /*
    EEPROM.write(0,4);  //almacena valor en eeprom
    EEPROM.write(1,5);  //almacena valor en eeprom
    EEPROM.write(2,6);  //almacena valor en eeprom
    EEPROM.write(3,3);  //almacena valor en eeprom
  */

  for (int i = 0; i < 4; i++) {
    Serial.println( "Valor Almacenado en " + String(i) + " es: " + String(EEPROM.read(i)));  //imprime msg por serial
  }
  Serial.println("-----------------");  //imprime msg por serial
  Serial.println("SISTEMA DE CONTRASENA");  //imprime msg por serial
  Serial.println("Para Validar Ingrese");  //imprime msg por serial
  Serial.println("Ejemplo:   1425V  ");  //imprime msg por serial
  Serial.println("Para Actualizar Ingrese");  //imprime msg por serial
  Serial.println("Ejemplo:   1425A  ");  //imprime msg por serial
  Serial.println("-----------------");  //imprime msg por serial
}

void loop() {

  if (Serial.available() > 0) {
    palabra = Serial.readStringUntil('.');  //almacena dato de ingreso
    int tam;  //variable
    tam = palabra.length();   //determina el tamaño
    if (tam != 5) { //condicion de funcionamiento

      Serial.println("-----------------");  //imprime msg por serial
      Serial.println("Ingreso Incorrecto");  //imprime msg por serial
      Serial.println("-----------------");  //imprime msg por serial
      Serial.println("Para Validar Ingrese");  //imprime msg por serial
      Serial.println("Ejemplo:   1425V  ");  //imprime msg por serial
      Serial.println("Para Actualizar Ingrese");  //imprime msg por serial
      Serial.println("Ejemplo:   1425A  ");  //imprime msg por serial
      Serial.println("-----------------");  //imprime msg por serial
    } else {
      palabra.toCharArray(cambio, tam + 1); //almacena en array
      //condicion de ejecucion - cambio de contraseña
      if (isDigit(cambio[0]) && isDigit(cambio[1]) &&
          isDigit(cambio[2]) && isDigit(cambio[3]) && cambio[4] == 'A'&on == 1) {
        EEPROM.update(0, (int)cambio[0] - 48);  //actualiza valor de eeprom
        EEPROM.update(1, (int)cambio[1] - 48);  //actualiza valor de eeprom
        EEPROM.update(2, (int)cambio[2] - 48);  //actualiza valor de eeprom
        EEPROM.update(3, (int)cambio[3] - 48);  //actualiza valor de eeprom
        Serial.println('\n');  //imprime msg por serial
        for (int i = 0; i < 4; i++) {
          Serial.println( "Valor Ingresado en " + String(i) + " es: " + String(EEPROM.read(i)));    //imprime msg por serial
        }
        on = 0;   //reinicia variable
        //condicion de ejecucion - verificar contraseña
      } else if (isDigit(cambio[0]) && isDigit(cambio[1]) &&
                 isDigit(cambio[2]) && isDigit(cambio[3]) && cambio[4] == 'V') {
        //verifica contraseña
        if (cambio[0] - 48 == EEPROM.read(0) && cambio[1] - 48 == EEPROM.read(1) &&
            cambio[2] - 48 == EEPROM.read(2) && cambio[3] - 48 == EEPROM.read(3)) {
          Serial.println('\n');  //imprime msg por serial
          Serial.println("+++++++++++++++++++");  //imprime msg por serial
          Serial.println("CONTRASENA CORRECTA");  //imprime msg por serial
          Serial.println("+++++++++++++++++++");  //imprime msg por serial
          on = 1;   //cambio de estado
        } else {
          Serial.println('\n');  //imprime msg por serial
          Serial.println("###################");  //imprime msg por serial
          Serial.println("CONTRASENA INCORRECTA");  //imprime msg por serial
          Serial.println("###################");  //imprime msg por serial
        }
      } else {
        Serial.println('\n');  //imprime msg por serial
        Serial.println("-----------------");  //imprime msg por serial
        Serial.println("Ingreso Incorrecto");  //imprime msg por serial
        Serial.println("-----------------");  //imprime msg por serial
        Serial.println("Para Validar Ingrese");  //imprime msg por serial
        Serial.println("Ejemplo:   1425V  ");  //imprime msg por serial
        Serial.println("Para Actualizar Ingrese");  //imprime msg por serial
        Serial.println("Ejemplo:   1425A  ");  //imprime msg por serial
        Serial.println("-----------------");  //imprime msg por serial
      }

    }
  }

}
