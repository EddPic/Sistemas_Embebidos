/*
Materia: Sistemas Embebidos
Nombre: Edison Picuasi
DEBER 1
Instrucciones:
Estimados estudiantes, realizar el siguiente codigo y solo adjuntar en enlace de su repositorio en GitHub.
Realizar un programa que accione mediante 4 switchs a un juego de luces diferente. Es decir.
sw3   sw2  sw1  sw0
0        0       0        1            Juego 1
0        0       1        0            Juego 2
0        1       0        0            Juego 3
1        0       0        0            Juego 4

Juego #1
Se usan 6 leds, de los cuales se encienden los pares por 10 ocasiones
Juego #2
Se usan 6 leds, de los cuales se encienden los impartes por 10 ocasiones
Juego #3
Se encienden secuencialmente cada uno ellos (flexible a su criterio)
Juego #4
Su propio diseño de juego.

*/
int leds[6] = {8, 9, 10, 11, 12, 13};   //asignacion de pines leds
int sws[4] = {2, 3, 4, 5};              //asignacion de pines switchs
int opcion = 0;                         //variable de seleccion
void setup() {
  Serial.begin(9600);                   //inicializacion comunicacion serial
  for (int i = 0; i < 6; i++) {         //ciclo de configuracion de salidas
    pinMode(leds[i], OUTPUT);           //configuracion de pines como salida
  }
  for (int j = 0; j < 4; j++) {         //ciclo de configuracion de entradas
    pinMode(sws[j], INPUT);             //configuracion de pines de entrada
  }
}

void loop() {
  //condicion de comprobacion
  if (digitalRead(2) == HIGH && digitalRead(3) == LOW &&
      digitalRead(4) == LOW && digitalRead(5) == LOW) {
    Serial.println("INICIA JUEGO 1");   //impresion de mensaje serial
    opcion = 1;                         //asigna un valor a la variable
    juegos();                           //llamada de metodo
  }
//condicion de comprobacion
  if (digitalRead(2) == LOW && digitalRead(3) == HIGH &&
      digitalRead(4) == LOW && digitalRead(5) == LOW) {
    Serial.println("INICIA JUEGO 2");   //impresion de mensaje serial
    opcion = 2;                         //asigna un valor a la variable
    juegos();                           //llamada de metodo
  }
//condicion de comprobacion
  if (digitalRead(2) == LOW && digitalRead(3) == LOW &&
      digitalRead(4) == HIGH && digitalRead(5) == LOW) {
    Serial.println("INICIA JUEGO 3");   //impresion de mensaje serial
    opcion = 3;                         //asigna un valor a la variable
    juegos();                           //llamada de metodo
  }
//condicion de comprobacion
  if (digitalRead(2) == LOW && digitalRead(3) == LOW &&
      digitalRead(4) == LOW && digitalRead(5) == HIGH) {
    Serial.println("INICIA JUEGO 4");   //impresion de mensaje serial
    opcion = 4;                         //asigna un valor ala variable
    juegos();                           //llamada de metodo
  }


}

void juegos() {
  switch (opcion) {
    case 1:
      for (int k = 0; k < 10; k++) {  //ciclo de repeticion
        Serial.println(k);            //impresion del contador
        digitalWrite(9, HIGH);        //encender led
        digitalWrite(11, HIGH);       //encender led
        digitalWrite(13, HIGH);       //encender led
        delay(300);                   //tiempo de visualizacion
        digitalWrite(9, LOW);         //apagar led
        digitalWrite(11, LOW);        //apagar led
        digitalWrite(13, LOW);        //apagar led
        delay(300);                   //tiempo de visualizacion
      }
      opcion = 0;                     //reinicio de variable
      break;
    case 2:
      for (int k = 0; k < 10; k++) {  //ciclo de repeticion
        Serial.println(k);            //impresion del contador
        digitalWrite(8, HIGH);        //encender led
        digitalWrite(10, HIGH);       //encender led
        digitalWrite(12, HIGH);       //encender led
        delay(300);                   //tiempo de visualizacion
        digitalWrite(8, LOW);         //apagar led
        digitalWrite(10, LOW);        //apagar led
        digitalWrite(12, LOW);        //apagar led
        delay(300);                   //timepo de visualizacion
      }
      opcion = 0;                     //reinicio de variable
      break;
    case 3:
      for (int k = 0; k < 6; k++) {   //ciclo de secuencia incremento
        Serial.println(k);            //impresion de mensaje serial
        digitalWrite(leds[k], HIGH);  //encender leds
        delay(300);                   //tiempo de visualizacion
      }
      for (int k = 5; k >= 0; k--) {  //ciclo de secuencia decremento
        Serial.println(k);            //impresion de mensaje serial
        digitalWrite(leds[k], LOW);   //apagar leds
        delay(300);                   //tiempo de visualizacion
      }
      break;
    case 4:
      int aleatorio = random(0, 6);         //variable de numero aleatorio
      digitalWrite(leds[aleatorio], HIGH);  //encender led
      delay(300);                           //timepo de visualizacion
      digitalWrite(leds[aleatorio], LOW);   //apagar led
      break;
    default:
      opcion = 0;                           //reinicio de variable
  }
}
