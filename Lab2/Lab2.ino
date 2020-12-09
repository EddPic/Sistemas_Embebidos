/*
MATERIA: SISTEMAS EMBEBIDOS
NOMBRE: EDISON PICUASI
LABORATORIO 2 - SISTEMA DOMOTICO
*/



#include <LiquidCrystal.h>
#include <MsTimer2.h>

LiquidCrystal lcd(27, 26, 25, 24, 23, 22);  //Asiganr pines lcd
int horas = 0;      //variable para la hora
int minutos = 0;    //variable para los minutos
int segundos = 0;   //variable para los segundos
int leds[4] = {31, 30, 29, 28};   //asignar pines de leds
int sensor1 = 35;   //asignar pin sensor 1
int sensor2 = 34;   //asignar pin sensor 2
int sensor3 = 33;   //asignar pin sensor 3
int sensor4 = 32;   //asignar pin sensor4
int opcion;         //variable de cambio de estado
int modo;           //variable cambio de estado
int editar;         //variable de control
int monitoreo;      //variable de control
int on = 0;         //variable de control
int tiempo;         //varaible de incremento
void setup() {
  Serial.begin(9600);   //inicializa CX Serial
  lcd.begin(16, 2);     //asigna leds como salida
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(35, INPUT);   //configurar pin de entrada
  pinMode(34, INPUT);   //configurar pin de entrada
  pinMode(33, INPUT);   //configurar pin de entrada
  pinMode(32, INPUT);   //configurar pin de entrad
  MsTimer2::set(500, reloj);  //configura timer 2
  MsTimer2::start();          //inicializa timer 2
  attachInterrupt(digitalPinToInterrupt(21), opciones, FALLING);  //configura interrupcion 1
  attachInterrupt(digitalPinToInterrupt(20), modos, FALLING);     //configura interrupcion 2
}

void loop() {

}

void reloj() {
  if (minutos < 59) {   //condicion de incremento
    minutos++;          //incrementa variable
  } else {
    minutos = 0;        //reinicia variable
    if (horas < 23) {   //condicion de incremento
      horas++;          //incrementa variable
    } else {
      horas = 0;        //reinica variable
    }
  }

  if (minutos < 10) {   //condicion de impresion
    lcd.setCursor(2, 0);  //posiciona cursor
    lcd.print(":0" + String(minutos));  //imprime en la lcd
  } else {
    lcd.setCursor(2, 0);  //posiciona cursor
    lcd.print(":" + String(minutos)); //imprime en lcd
  }
  if (horas < 10) {     //condicion de impresion
    lcd.setCursor(0, 0);  //posiciona cursor
    lcd.print("0" + String(horas)); //imprime en lcd
  } else {
    lcd.setCursor(0, 0);  //posiciona cursor
    lcd.print(String(horas)); //imprime
  }

  if (on == 1 && modo == 1) { //condicion de ejecucion
    luces(minutos); //llama al metodo
  }
  if (on == 1 && modo == 2) { //condicion de ejecucion
    cambio();   //llama al metodo
  }
  if (on == 1 && monitoreo == 1) {  //condicion de ejecucion
    Serial.println("Sensores activos"); //imprime mensaje por serial
    sensores(); //lama al metodo
  }
}

void opciones() {
  opcion++; //incrementa variable
  Serial.println("OPCION: " + String(opcion));  //imprime mensaje por serial
  switch (opcion) { //condicion de seleccion
    case 1:     //opcion 1
      Serial.println("SISTEMA ENCENDIDO");  //impime msj por serial
      on = 1;   //reinicia variable
      break;
    case 2:     //opcion 2
      Serial.println("SELECCIONE EL MODO DE FUNCIONAMIENTO"); //imprime msj por serial
      on = 0;     //reinicia variable
      tiempo = 0; //reinicia variable
      break;
    case 3:     //opcion 3
      Serial.println("SISTEMA APAGADO");  //imprime msj por serial
      on = 0;   //reinicia variable
      opcion = 0;   //reinicia variable
      break;
  }
}

void modos() {
  if (opcion == 2) {  //condicion de incremento
    modo++; //incrementa variable
  }
  Serial.println("MODO: " + String(modo));  //imprime msj por serial
  switch (modo) {   //condicion de seleccion
    case 1:   //opcion 1
      Serial.println("MODO 1");   //imprime msj por serial
      monitoreo = 0;  //reinicia variable
      break;
    case 2:   //opcion 2
      Serial.println("MODO 2");   //imprime msj por serial
      editar = 1; //reinicia variable
      break;
    case 3:   //opcion 3
      Serial.println("MODO 3");   //imprime mensaje por serial
      editar = 0;   //reinicia variable
      monitoreo = 1;  //cambia de estado
      modo = 0;     //reinicia variable
      break;
  }
}

void luces(int valor) {
  tiempo++; //incrementa variable
  Serial.println("TIEMPO:" + String(tiempo));   //imprime por serial

  if (tiempo < 20) {    //condicion de funcionamiento
    int ledn;   //variable 
    ledn = random(0, 4);  //asigna valor random
    digitalWrite(leds[ledn], HIGH); //enciende leds
  } else {
    for (int i = 0; i < 4; i++) {   //bucle de apagado leds
      digitalWrite(leds[i], LOW);   //apaga leds
    }
  }
}

void cambio() {
  int nminuto;    //variable de cambio
  int nhora;      //variable de cambio
  nhora = analogRead(A0);   //lee el valor del cad
  nminuto = analogRead(A1); //lee el valor de cad
  nhora = map(nhora, 0, 1023, 0, 23); //asigna rango de funcionamiento
  nminuto = map(nminuto, 0, 1023, 0, 59); //asigna rango de funcionamiento
  horas = nhora;      //actualiza el valor
  minutos = nminuto;  //actualiza el valor
  Serial.println("Nueva hora: " + String(horas)); //imprime por serial
  Serial.println("Nuevo minuto: " + String(minutos)); //imprime por serial
}

void sensores() {
  if (digitalRead(sensor1) == HIGH) { //condicon de activacion
    Serial.println("Sensor 1 activado."); //imprime por serial
  }
  if (digitalRead(sensor2) == HIGH) { //condicon de activacion
    Serial.println("Sensor 2 activado."); //imprime por serial
  }
  if (digitalRead(sensor3) == HIGH) { //condicon de activacion
    Serial.println("Sensor 3 activado."); //imprime por serial
  }
  if (digitalRead(sensor4) == HIGH) { //condicon de activacion
    Serial.println("Sensor 4 activado."); //imprime por serial
  }

}
