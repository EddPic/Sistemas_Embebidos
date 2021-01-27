#include <EEPROM.h>
#include <MsTimer2.h>
#include<SoftwareSerial.h>  //IMPORTAR LIBRERIA
#include <avr/sleep.h>  //importar libreria sleep
#include <avr/wdt.h>
#include "datos.h"
#include "KickFilters.h"
#define rxPin 2 //asignar pines de comunicacion
#define txPin 3 //asignar pines de comunicacion

SoftwareSerial mySerial(rxPin, txPin);  //generar el objeto

int fila = 258;
int columna = 5;
int n = 0;
int m = 0;
float potencia;
float raiz;
float etiqueta;
String tipo = "";
float dist_menor = 2500; //agregar una valor mayor fuera del rango
float datos_prueba [5] = {575,121,247,11,3};
/////////////////////////////////
/*      VARIABLES SENSORES     */
uint16_t cad1;
uint16_t cad2;
uint16_t cad3;
const float Echo = 23;
const float Trig = 22;
long duracion, distancia;
///////////////////////////////
/*      VARIABLES DE FILTRADO     */
const uint16_t muestras = 258;
//const float fs = 23.8;
const float fs = 0.5;
//int16_t filtrados1 [muestras] = {0};
//int16_t filtrados2 [muestras] = {0};
//int16_t filtrados3 [muestras] = {0};
//int16_t filtrados4 [muestras] = {0};
//int16_t sensor1[muestras] = {0};
//int16_t sensor2[muestras] = {0};
//int16_t sensor3[muestras] = {0};
//int16_t sensor4[muestras] = {0};
const uint16_t tam = 3;
uint16_t dato[tam] = {0};
uint16_t datofil[tam] = {0};
///////////////////////////////////
/*VARIABLES TIMER*/
int segundos = 0;
void setup() {

  
  pinMode(rxPin, INPUT);  //configura pin
  pinMode(txPin, OUTPUT); //configura pin
    Serial.begin(9600);
    mySerial.begin(9600);
  //  Serial.println("DESPERTO");
  //////////////////////////////////////////////////////////////
  /*                  CONFIGURACION EEPROM                    */
  //  EEPROM.write(0, 0);
  //  EEPROM.write(1, 0);
  //  EEPROM.write(2, 0);
  //  EEPROM.write(3, 0);

  //////////////////////////////////////////////////////////////
  /*                   SENSOR ULTRASONICO                    */
  pinMode(Echo, INPUT);     // define el pin como entrada (echo)
  pinMode(Trig, OUTPUT);    // define el pin como salida  (triger)
  //////////////////////////////////////////////////////////////
  MsTimer2::set(1000, tiempo);
  MsTimer2::start();
  //////////////////////////////////////////////////////////////
  /*           EXTRACCION DE DATOS DE LOS SENSORES            */
  /*for (uint16_t i = 0; i < muestras; i++) {
    //sensor1[i] = matriz[i][0];
    //sensor2[i] = matriz[i][1];
    //sensor3[i] = matriz[i][1];
    //sensor4[i] = matriz[i][1];
    //  Serial.println(sensor1[i]);
    }
  */
  //  for(int i=0;i<tam;i++){
  //    dato[i]=EEPROM.read(i)*4;
  //    Serial.println(dato[i]);
  //    }
  //////////////////////////////////////////////////////////////
  /*               ANALISIS DE FILTRO OPTIMO                 */
  //FILTRO PASA BAJOS
  //KickFilters<int16_t>::lowpass(sensor1, filtrados, muestras, 1, fs);
  //FILTRO PASA ALTOS
  //KickFilters<int16_t>::highpass(sensor1, filtrados, muestras, 1, fs);
  //////////////////////////////////////////////////////////////
  /* float sr;
    float ruido;
    for (uint16_t j = 0; j < muestras; j++) {
     //Serial.println(sensor1[j]); //Use SerialUSB for SparkFun SAMD21 boards
     //Serial.print(","); //Use SerialUSB for SparkFun SAMD21 boards
     //Serial.println(filtrados1[j]); //Use SerialUSB for SparkFun SAMD21 boards
     //Serial.println(); //Use SerialUSB for SparkFun SAMD21 boards
     //delay(25);
     ruido = sensor1[j] - filtrados1[j];
     // Serial.println("RUIDO: "+String(ruido));
     sr = (sensor1[j] / ruido);
     //Serial.println(+"S/R: "+String(sr));
    }
    //  sr = sr / muestras;
    //  Serial.println("S/R: " + String(sr));
  */


}

void loop() {
  //
  //  if (segundos == 0) {
  //    sleep_disable();
  //    delay(250);
  //    ///////////////////////////////////////////
  //    /*      LECTURA SENSORES DE PRESION      */
  //    cad1 = analogRead(A0);
  //    //EEPROM.update(0, cad1/4);
  //    dato[0]=cad1;
  //    Serial.println("Sensor 1: " + String(cad1));
  //
  //    delay(250);
  //    cad2 = analogRead(A1);
  //
  //    dato[1]=cad2;
  //    //EEPROM.update(1, cad2/4);
  //    Serial.println("Sensor 2: " + String(cad2));
  //
  //    delay(250);
  //    cad3 = analogRead(A2);
  //    dato[2]=cad3;
  //    //EEPROM.update(2, cad3/4);
  //    Serial.println("Sensor 3: " + String(cad3));
  //
  //    ///////////////////////////////////////////
  //    /*      LECTURA SENSOR ULTRASONICO      */
  //    delay(250);
  //    digitalWrite(Trig, LOW);
  //    delayMicroseconds(2);
  //    digitalWrite(Trig, HIGH);   // genera el pulso de triger por 10ms
  //    delayMicroseconds(10);
  //    digitalWrite(Trig, LOW);
  //    duracion = pulseIn(Echo, HIGH);
  //    distancia = duracion * 0.0343 / 2;
  //    uint16_t conversion = map(distancia,0,1023,0,30);
  //
  //    dato[3]=conversion;
  //    //EEPROM.update(3, conversion/4);
  //    Serial.println("Sensor 4:"+String(conversion) + "cm");
  //    delay(250);
  //
  //  } else {
  //    set_sleep_mode(SLEEP_MODE_ADC); //configura el modo sleep
  //    sleep_enable();   //habilita el modo sleep
  //  }
  knn();
}


void tiempo() {

  if (segundos < 10) {
    segundos++; //incrementa la variable
    //Serial.println(segundos); //imprime el mensaje
    //wdt_disable();
  }
  if (segundos == 10) {
    // wdt_enable(WDTO_15MS);
    segundos = 0; //reinicia la Variable
    //Serial.println(segundos); //imprime el mensaje
  }
}

void knn() {
  for (; m < fila; m++) {
    for (n = 0; n < columna - 1; n++) {
      potencia = potencia + pow((float)matriz[m][n] - datos_prueba[n], 2);
    }
    raiz = sqrt(potencia);
    potencia = 0;
    //alamacenar l distancia menor
    if (raiz < dist_menor) {
      dist_menor = raiz; //guardo distancia menor de la matriz
      etiqueta = matriz[m][4]; //alamceno valor de la etiqueta de la fila donde la distancia es menor

    }
  }
  switch ((int)etiqueta) {
    case 1:
      tipo = "Posicion 1";
      break;
    case 2:
      tipo = "Posicion 2";
      break;
    case 3:
      tipo = "Posicion 3";
      break;
    case 4:
      tipo = "Posicion 4";
      break;

  }
  Serial.println(tipo);
  if (etiqueta == datos_prueba[4]) {
    Serial.println("ASIGNACION CORRECTA");
    mySerial.write((int)etiqueta);
  } else {

    Serial.println("ASIGNACION INCORRECTA");
  }

}
