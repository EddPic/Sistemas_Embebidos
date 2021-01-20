#include<SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial mySerial(rxPin, txPin);
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

int columna = 0;
int fila = 0;
float numerador;
float denominador;
int n = 14;
float Ex1;
float Ey1;
float Exy1;
float Ex2;
float Ex_2;
float B;
String dato;
int estatura;
float peso;
float A;

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  for (; fila < n; fila++) {
    Ex1 = Ex1 + matriz[fila][0]; //sumatoria
    Ey1 = Ey1 + log(matriz[fila][1]);
    Exy1 = Exy1 + (matriz[fila][0] * log(matriz[fila][1]));
    Ex2 = Ex2 + (pow(matriz[fila][0], 2));
  }
  Ex_2 = pow(Ex1, 2);
  numerador = (n * Exy1) - (Ex1 * Ey1);
  denominador = n * Ex2 - Ex_2;
  B = (numerador / denominador);
  float my1 = Ey1 / n;
  float mx1 = Ex1 / n;
  float Bmx = B * mx1;
  float R = my1 - Bmx;
  A = exp(R);
  Serial.println("Regresion Exponencial:");
  Serial.println("Y = " + String(A, 4) + "*e^" + String(B, 4) + "x");
  Serial.println("Ingrese la estatura:");
}

void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    estatura = dato.toInt();
    mySerial.write(estatura);
    peso = A * exp(B * estatura);
    Serial.println(" ");
    Serial.println("Su peso es: " + String(peso) + "kg o " + String(peso * 2.205) + "lb");
    Serial.println("Ingrese la estatura: ");

  }
}
