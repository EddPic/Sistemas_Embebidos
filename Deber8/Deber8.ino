
/*
  Picuasi Edison
  Sistemas Embebidos

  DEBER 8

  Realizar un código que el sistema se reinicia cada minuto,
  active el conversor análogo-digital realice una lectura y
  vuelve el sistema a un modo sleep.

*/

#include <avr/sleep.h>  //importar libreria sleep
#include <avr/wdt.h>  //importar libreria WatchDog
#include <MsTimer2.h> //importar libreria Timer 2
int segundos = 0; //variable de conteo
int cad = 0;  //variable del CAD

void setup() {
  Serial.begin(9600); //incializa Comunicacion Serial
  Serial.println("INICIO"); //Imprime mensaje
  MsTimer2::set(1000, tiempo); //Configura el Timer 2
  MsTimer2::start();  //inicializa Timer 2
}

void loop() {
 
  if (segundos == 0) {  //Realiza verificacion
    sleep_disable();  //desactiva el modo sleep
    cad = analogRead(A0); //realiza lectura del CAD
    Serial.println(cad);  //Imprime mensaje
    delay(100); //retrasa la lectura del CAD
  } else {
    set_sleep_mode(SLEEP_MODE_ADC); //configura el modo sleep
    sleep_enable();   //habilita el modo sleep
  }
}

void tiempo() {
  if (segundos < 59) {  
    segundos++; //incrementa la variable
    Serial.println(segundos); //imprime el mensaje
    wdt_disable();  //Desactiva WatchDog
  } else {
    wdt_enable(WDTO_15MS);  //habilita WatchDog
    segundos = 0; //reinicia la Variable
    Serial.println(segundos); //imprime el mensaje
  }
}
