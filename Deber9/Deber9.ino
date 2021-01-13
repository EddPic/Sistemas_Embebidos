/*
  Edison Picuasi
  Sistemas Embebidos

  Deber 9

  Realice un programa que mediante un conversor análogo-digital se
  configure el tiempo de reinicio del perro guardián (tiempos seleccionados
  por el usuario).
  Envíe mensajes por comunicación serial validando todo el proceso.

*/
#include <avr/wdt.h>  //incluir libreria de WatchDog
int cad, rango; //variables de lectura y conversion del CAD
String confirmacion = ""; //variable de confirmacion
void setup() {
  Serial.begin(9600); //Inicializar Comunicacion Serial
  wdt_disable();  //Desahibiltar WatchDog
  Serial.println("INICIO SISTEMA"); //Imprimir mensaje
}

void loop() {
  cad = analogRead(A0); //Realiza lectura del CAD
  rango = map(cad, 0, 1023, 0, 9);  //Conversion del Valor de CAD
  Serial.println(rango);  //Imprime mensaje
  delay(1000);  //Retarda la lectura del CAD
  if (Serial.available() > 0) { //Verifica si existe un valor en CX Serial
    confirmacion = Serial.readString(); //Lee el dato
    if (confirmacion == "ok") { //verifica si el dato es correcto
      Serial.println("Inicia WatchDog");  //Imprime mensaje
      switch (rango) {  //verifica la conversion
        case 0:
          wdt_enable(WDTO_15MS);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 15MS" ); //Imprime mensaje
          break;
        case 1:
          wdt_enable(WDTO_30MS);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 30MS" ); //Imprime mensaje
          break;
        case 2:
          wdt_enable(WDTO_60MS);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 60MS" ); //Imprime mensaje
          break;
        case 3:
          wdt_enable(WDTO_120MS); //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 120MS" );  //Imprime mensaje
          break;
        case 4:
          wdt_enable(WDTO_250MS); //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 250MS" );  //Imprime mensaje
          break;
        case 5:
          wdt_enable(WDTO_500MS); //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 500MS" );  //Imprime mensaje
          break;
        case 6:
          wdt_enable(WDTO_1S);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 1S" ); //Imprime mensaje
          break;
        case 7:
          wdt_enable(WDTO_2S);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 2S" ); //Imprime mensaje
          break;
        case 8:
          wdt_enable(WDTO_4S);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 4S" ); //Imprime mensaje
          break;
        case 9:
          wdt_enable(WDTO_8S);  //Configura el tiempo del WatchDog
          Serial.println("Tiempo Seleccionado: 8S" ); //Imprime mensaje
          break;
      }
    } else {

      Serial.println("Escriba ok para iniciar WatchDog"); //Imprime mensaje
    }
  }
}
