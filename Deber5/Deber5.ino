/*
  Edison Picuasi
  Deber 5
  Instrucciones:
  Realizar un programa que mediante interrupciones tenga 3 modos:
  Inicio del sistema, giro de motor y fin de programa.
  El giro debe ser ingresado por comunicación serial.

*/
#include <Servo.h>

Servo servo1;   //generar varaiable
int op = 0;     //varaiable de cambio
int on = 0;     //variable de control
int giro = 0;   //variable de control
String dato;    //variable de almacenado
int valor;      //variablde de ejecucion
void setup() {
  Serial.begin(9600); //inicializa CX serial
  attachInterrupt(0, opciones, FALLING);  //configura interrupcion
  servo1.attach(6);   //configura servo
}

void loop() {
  if (on == 1) {//condicion de ejecucion
    if (Serial.available() > 0) { //condicion de ejcucion
      dato = Serial.readString(); //lee el dato
      valor = dato.toInt(); //conversion a entero
      Serial.println(valor);  //imprime msj por serial
    }
  }
  if (giro == 1) {  //condicion de ejecucion
    servo1.write(valor);  //ejcuta movimiento
  }
}

void opciones() {
  switch (op) { //condicion de selecion
    case 0:
      op++;   //incrementa variable
      Serial.println("INICIO DEL SISTEMA"); //imprime msg por serial
      Serial.println("Ingrese el valor de giro:");  //imprime msg por serial
      on = 1; //cambio de estado
      break;
    case 1:
      op++;   //incrementa variable
      Serial.println("GIRO DEL MOTOR"); //imprime msg por serial
      giro = 1;   //cambio de estado
      break;
    case 2:
      op++;   //incrementa variable
      Serial.println("FIN DEL PROGRAMA"); //imprime msg por serial
      op = 0; //reinicia variable
      giro = 0; //reinicia variable
      on = 0;   //reinicia variable
      break;
  }
  Serial.println(on); //imprime msg por serial
}
