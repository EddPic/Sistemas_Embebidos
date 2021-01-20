/*

  SISTEMAS EMBEBIDOS
  Picuasi Edison
  DEBER 11
  Realice la regresión lineal exponencial dentro del entorno de Arduino con el conjunto de datos estatura-peso.
  Con esto, ingrese por comunicación serial los nuevos datos de estatura e imprima el pronóstico del peso.

*/

///////////////////////
//Conjunto de datos
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

int columna = 0;  //variable de recorrido
int fila = 0; //variable de recorrido
float numerador;  //variable de B
float denominador;  //variable deB
int n = 14; //tamaño del conjunto de datos
float Ex1;  //variable de sumatoria de X
float Ey1;   //variabl de sumatoria de y
float Exy1;   //variable sumatoria xy
float Ex2;  //variable de potencia
float Ex_2; //variable de potencia
float B;  
String dato;  //variable lectura dato
int estatura; //varaible de resultado
float peso; //variable de resultado
float A;

void setup() {
  Serial.begin(9600);
  for (; fila < n; fila++) {
    Ex1 = Ex1 + matriz[fila][0]; //sumatoria
    Ey1 = Ey1 + log(matriz[fila][1]); //sumatoria
    Exy1 = Exy1 + (matriz[fila][0] * log(matriz[fila][1])); //sumatoria
    Ex2 = Ex2 + (pow(matriz[fila][0], 2));//potenciacion
  }
  Ex_2 = pow(Ex1, 2); //potenciacion
  numerador = (n * Exy1) - (Ex1 * Ey1); //componente de B
  denominador = n * Ex2 - Ex_2; //componente de B
  B = (numerador / denominador);
  float my1 = Ey1 / n;  //promedio
  float mx1 = Ex1 / n;  //promedio
  float Bmx = B * mx1;  
  float R = my1 - Bmx;
  A = exp(R);
  Serial.println("Regresion Exponencial:"); //imprime mensaje
  Serial.println("Y = " + String(A, 4) + "*e^" + String(B, 4) + "x");//imprime el modelo
  Serial.println("Ingrese la estatura:"); //imprime mensaje
}

void loop() {
  if (Serial.available() > 0) { //condicion de lectura
    dato = Serial.readString(); //lectura de dato en serial
    estatura = dato.toInt();  //conversion tipo de dato
    peso = A * exp(B * estatura); //pronostico de peso
    Serial.println(" ");  //imprime mensaje
    Serial.println("Su peso es: " + String(peso) + "kg o " + String(peso * 2.205) + "lb");//imprime mensaje
    Serial.println("Ingrese la estatura: ");  //imprime mensaje
  }
}
