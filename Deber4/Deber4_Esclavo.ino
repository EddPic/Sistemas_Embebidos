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
String salida, transmi;
int tam, tam2;
int j = 0;
int i = 0;

void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
  coder();
  transmision();
}

void receiveEvent(int bytes) {
  while (Wire.available()) {
    char dato = Wire.read();
    salida += dato;
  }
}

void requestEvent() {

}

void coder() {
  tam = salida.length() + 1;
  char vector[tam];
  salida.toCharArray(vector, tam);
  for (i = 0; i < tam - 1; i++) {
    switch (vector[i]) {
      case 'a':
        vector[i] = '@';
        break;
      case 'e':
        vector[i] = '#';
        break;
      case 'i':
        vector[i] = '!';
        break;
      case 'o':
        vector[i] = '*';
        break;
      case 'u':
        vector[i] = '$';
        break;
    }
    transmi += vector[i];
  }
  salida = "";
}

void transmision() {
  Serial.println(transmi);
  tam2 = transmi.length() + 1;
  char vector2[tam2];
  transmi.toCharArray(vector2, tam2);
  for (j = 0; j < tam2 - 1; j++) {
    Serial.write(vector2[j]);
    Wire.beginTransmission(4);
    Wire.write(vector2[j]);
    Wire.endTransmission();
  }
}
