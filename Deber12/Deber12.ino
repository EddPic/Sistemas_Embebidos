/*

  Codificar su propia versión de algoritmo k-NN o bayesiano a su elección.
  Este código debe aplicarse en su examen final.

*/
#include "datos.h"  //incluye el dataset
#define CO 5  // tamaño dataset
#define FI 87 //tamaño

double prueba[CO] = {5.9, 3, 5.1, 1.8, 3.0};  //datos de prueba
double sumatoria; //variable sumatoria euclidiana
double resultado;//variable sumatoria euclidiana
String clase = "";//variable mensaje
String clase2 = "";//variable mensaje
double tipo;//variable de seleccion tipo
double tipo2;//variable de seleccion tipo
double distancia = 2500;  //desborde
double distancia1 = 2500;  //desborde
double res1;  //variable forma coseno
double xy;  //variable forma coseno
double x1;  //variable forma coseno
double y1;  //variable forma coseno
double man; //variable forma manhattan
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < FI; i++) {
    for (int j = 0; j < CO; j++) {
      //////////////////////////////////////////////////////////
      //Forma Euclidiana
      sumatoria = pow(matriz[i][j] - prueba[j], 2) + sumatoria;
      ///////////////////////////////////////////////////////////
      //Forma similaridad Coseno
      xy = ( matriz[i][j] * prueba[j]) + xy;//sumatoria de x*y
      x1 = pow(matriz[i][j], 2) + x1; //sumatoria x1^2
      y1 = pow(prueba[j], 2) + y1;  //sumatoria y1^2

      //Serial.println(xy);
      //Serial.println(x1);
      //Serial.println(y1);
      ////////////////////////////////////////////////////////////
      //Forma Manhattan

      man = (abs(matriz[i][j] - prueba[j])) + man; //sumatoria |xi-yi|


      ///////////////////////////////////////////////////////////
    }

    res1 = xy / ((sqrt(x1)) * (sqrt(y1)));  //resultado forma coseno
    resultado = sqrt(sumatoria);   //resultado forma euclidiana

    Serial.println("COSENO: " + String(res1));  //impresion resultado
    Serial.println("EUCLI: " + String(resultado));  //impresion resultado
    Serial.println("MAN: " + String(man / 2)); //impresion resultado
    sumatoria = 0;  //reinicia variable
    man = 0;  //reinicia variable
    xy = 0; //reinicia variable
    x1 = 0; //reinicia variable
    y1 = 0; //reinicia variable

    if (resultado < distancia) {//asignacion de tipo
      distancia = resultado;
      tipo = matriz[i][4];
      Serial.println("tipo1: " + String(tipo));//imprime msj
    }
    if (man / 2 < distancia1) {//asignacion de tipo
      distancia1 = man / 2;
      tipo2 = matriz[i][4];
      Serial.println("tipo2: " + String(tipo2));//imprime msj
    }
  }
  switch ((int)tipo) {
    case 1:
      clase = "setosa";//imprime msj
      break;
    case 2:
      clase = "versicolor";//imprime msj
      break;
    case 3:
      clase = "Virginica";//imprime msj
      break;

  }
   switch ((int)tipo2) {
    case 1:
      clase2 = "setosa";//imprime msj
      break;
    case 2:
      clase2 = "versicolor";//imprime msj
      break;
    case 3:
      clase2 = "virginica";//imprime msj
      break;

  }
  Serial.println(clase);
  if (tipo == prueba[CO - 1]) {
    Serial.println("ASIGNACION CORRECTA");//imprime msj
  } else {

    Serial.println("ASIGNACION INCORRECTA");//imprime msj
  }

}

void loop() {


}
