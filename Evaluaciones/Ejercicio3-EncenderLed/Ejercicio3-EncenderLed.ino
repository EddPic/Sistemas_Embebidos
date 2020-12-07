/*
EJERCICIO 3
ENCENDER LEDS
ARDUINO MEGA
EDISON PICUASI
*/

#include <TimerOne.h>

int contador;
int conversor;
int on = 0;
int st;
int led = 31;
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(21), opciones, FALLING);
  Timer1.initialize(10000000);
  Timer1.attachInterrupt(reloj);
  pinMode(led, OUTPUT);
}


void loop() {
  if (contador == 0 && on == 1) {
    conversor = analogRead(A0);
    conversor = map(conversor, 0, 1023, 1, 10);
    delay(200);
    Serial.println(conversor);
  }
}


void opciones() {
  switch (on) {
    case 0:
      on++;
      Serial.println("Bienvenido");
      Serial.println("Mover Potenciometro");
      break;
    case 1:
      on++;
      contador = conversor;
      Serial.println("Iniciar Funcionamiento");
      st = 1;
      break;
    case 2:
      on = 0;
      Serial.println("Fin del Programa");
      break;
  }
}

void reloj() {
  if (st == 1) {
    contador--;
    digitalWrite(led, HIGH);
    delay(75);
    Serial.println("Contador: "+String(contador + 1));
  }
  if (contador < 0) {
    digitalWrite(led, LOW);
    contador = 0;
    st = 0;
    on = 2;
  }

}
