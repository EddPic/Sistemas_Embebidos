/*
Picuasi Edison
SISTEMAS EMBEBIDOS
LABORATORIO 4
*/

#include<SoftwareSerial.h>  //IMPORTAR LIBRERIA

#define rxPin 2 //asignar pines de comunicacion
#define txPin 3 //asignar pines de comunicacion

SoftwareSerial mySerial(rxPin, txPin);  //generar el objeto
//conjunto de datos estatura-peso
int matriz [14][2] = {
  {170, 67},
  {180, 80},
  {170, 65},
  {178, 75},
  {160, 55},
  {163, 60},
  {165, 63},
  {170, 70},
  {164, 62},
  {176, 77},
  {164, 60},
  {170, 76},
  {170, 56},
  {168, 60},
};

///////////////////////

int columna = 0;//variable de recorrido
int fila = 0;//variable de recorrido
float numerador;  //variable de B
float denominador;  //variable de B
int n = 14; //tamaño del conjunto de datos
float Ex1;  //variable de sumatoria de X
float Ey1;  //variable de sumatoria de y
float Exy1;//variable de sumatoria de Xy
float Ex2;  //variable de potenciacion
float Ex_2; //variable de potenciacion
float B;
String dato;
int estatura;
float peso;
float A;

void setup() {
  pinMode(rxPin, INPUT);  //configura pin
  pinMode(txPin, OUTPUT); //configura pin
  Serial.begin(9600);//inicializa CX serial
  mySerial.begin(9600); //inicializa CX Serial 2
  for (; fila < n; fila++) {
    Ex1 = Ex1 + matriz[fila][0]; //sumatoria
    Ey1 = Ey1 + log(matriz[fila][1]); //sumatoria
    Exy1 = Exy1 + (matriz[fila][0] * log(matriz[fila][1]));//sumatoria
    Ex2 = Ex2 + (pow(matriz[fila][0], 2));//potenciacion
  }
  Ex_2 = pow(Ex1, 2);//potenciacion
  numerador = (n * Exy1) - (Ex1 * Ey1); //componente de B
  denominador = n * Ex2 - Ex_2; //componente de B
  B = (numerador / denominador);
  float my1 = Ey1 / n;  //promedio
  float mx1 = Ex1 / n;  //promedio
  float Bmx = B * mx1;  //variable auxiliar
  float R = my1 - Bmx;  //variable auxiliar
  A = exp(R);
  Serial.println("Regresion Exponencial:");//Imprime mensaje
  Serial.println("Y = " + String(A, 4) + "*e^" + String(B, 4) + "x");//imprime mensaje
  Serial.println("Ingrese la estatura:");//imprime mensaje
}

void loop() {
  if (Serial.available() > 0) { //condicion lectura serial
    dato = Serial.readString(); //lee el valor en CX serial
    estatura = dato.toInt();//converion de tipo de dato
    mySerial.write(estatura);//envia dato por serial
    peso = A * exp(B * estatura);//pronostica peso
    Serial.println(" ");//imprime mensaje
    Serial.println("Su peso es: " + String(peso) + "kg o " + String(peso * 2.205) + "lb");//imprime mensaje
    Serial.println("Ingrese la estatura: ");//imprime mensaje

  }
}
