/*


  Realice un sistema que codifique las vocales en palabras
  ingresadas por comunicación serial.
  Este mensaje se ingresa por comunicación serial en el
  master, este envía al esclavo para que realice la codificación
  por comunicación I2C.
  Luego, lo envía al master por el mismo medio y se muestra el
  resultado en una LCD en el master. La codificación es:



  a=@

  e=#

  i= !

  o = *

  u= $



  Ejemplo: CARRO = C@RR*

*/

#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
String dato, entrada, recepci;
int tam, i;
void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Ingrese palabra");
}

void loop() {
  ///////////////////////////////
  //TRANSMISION
  if (Serial.available() > 0) {
    char dato = Serial.read();
    Wire.beginTransmission(4);
    Wire.write(dato);
    Wire.endTransmission();
  }
  decoder();
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print(recepci);
delay(200);
}
///////////////////////////////
//RECEPCION
void receiveEvent(int bytes) {
  while (Wire.available()) {
    char recep = Wire.read();
    entrada += recep;
  }
}

void requestEvent() {

}
//////////////////////////////

void decoder() {
  tam=entrada.length();
  char vector[tam-1];
  entrada.toCharArray(vector, tam);
  for (i = 0; i < tam; i++) {
    switch (vector[i]) {
      case '@':
        vector[i] = '@';
        break;
      case '#':
        vector[i] = '#';
        break;
      case '!':
        vector[i] = '!';
        break;
      case '*':
        vector[i] = '*';
        break;
      case '$':
        vector[i] = '$';
        break;
    }
    recepci += vector[i];
  }
  entrada = "";
}
