/*
Picausi Edison
SISTEMAS EMBEBIDOS
LABORATORIO 4

*/

import processing.serial.*;  //importar libreria
import org.gicentre.utils.stat.*;  //importar libreria
XYChart scatterplot;  //crear el objeto
XYChart tendenciaplot;  //crear el onjeto
XYChart ntendenciaplot;  //crear el onjeto
Serial puerto;  //crear puerto

int columna=0;  //variable de recorrido
int fila=0;  //variabl de recorrido
float numerador;  //componbente de B
float denominador;  //componente de B
int n = 14;  //tamaño del conjunto de datos
float Ex1;  //sumatoria de x
float Ey1;  //sumatoria de y
float Exy1;  //sumatoria de xy
float Ex2;  //potenciacion de x
float Ex_2;  //potenciacion de x
float B;
String dato;  //variable de lectura de dato
int estatura;  //variable de la respuesta del modelo
float peso;  //variable respuesta del modelo
float A;  //variable auxiliar
int i=0;  //variable de conteo
float tendencia;  //variable e incremento
float axispeso;  //variable tamaño de ejey
float axisestatura;  //variable tamaño de eje x
int filas2=0;
int columnas2=0;
int conteo;   //variabl de conteo
float [] Xntendencia=new float[20];  //array de valores en x
float [] Yntendencia=new float[20];  //array de valores en y

//////////////////////////////////
//conjunto de datos
int [][] matriz  = {
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
//////////////////////////////////
void setup() {
  size(1100, 500);  //determina el tamaño de la ventan
  background(255);  //asigna un color de fondo
  textSize(25);  //asigna el tamaño de letra
  fill(0);  //el color de linea
  text("Picuasi Edison", width/2, 20);  //establece mensaje
  puerto =new Serial(this, "COM15", 9600);  //genera el puerto COM
  textFont(createFont("Arial", 11), 11);  //asigna un tamaño de letra al fondo
  scatterplot = new XYChart(this);  //crea objeto
  tendenciaplot =new XYChart(this);  //crea objeto
  ntendenciaplot =new XYChart(this);//crea objeto
  float[] Estatura  = new float[matriz.length-1];  //array de valores en x
  float[] Peso = new float[matriz.length-1];//array de valores en y
  float [] Xtendencia=new float[20];//array de valores en x
  float [] Ytendencia=new float[20];//array de valores en y
  for (int i=0; i<matriz.length-1; i++)
  {
    Estatura[i]=matriz[i][0];  //alamacena valor en el vector
    Peso[i]=matriz[i][1];  //alamacena valor en el vector
  }

  for (; fila<n; fila++) {
    Ex1=Ex1+matriz[fila][0];  //sumatoria
    Ey1=Ey1+log(matriz[fila][1]);  //sumatoria
    Exy1=Exy1+(matriz[fila][0]*log(matriz[fila][1]));  //sumatoria
    Ex2=Ex2+(pow(matriz[fila][0], 2));  //potenciacion
  }
  Ex_2=pow(Ex1, 2);  //potenciacion
  numerador=(n*Exy1)-(Ex1*Ey1);  //componente de B
  denominador=n*Ex2-Ex_2;  //componente de B
  B=(numerador/denominador);
  float my1=Ey1/n;  //variable auxiliar promedio
  float mx1=Ex1/n;  //variable auxiliar promedio
  float Bmx=B*mx1;  //variable auxiliar
  float R=my1-Bmx;  //variable auxiliar
  A=exp(R);

  for (i=160; i<180; i++) {
    Xtendencia[i-160]=i;  //asigna valor
    Ytendencia[i-160]=A*exp(B*(i));  //asigna valor
  }

  scatterplot.setData(Estatura, Peso); //genera la grafica
  scatterplot.showXAxis(true); //visualizar ejes
  scatterplot.showYAxis(true);   //visualizar ejes
  scatterplot.setXFormat("###,###cm");  //asigna una etiqueta
  scatterplot.setXAxisLabel("EStatura");  //asigna una etiqueta
  scatterplot.setYAxisLabel("Peso");  //asigna una etiqueta
  scatterplot.setPointColour(color(255, 0, 0, 100));  //establece color y opacidad
  scatterplot.setPointSize(10);  //estable tamaño de los puntos
  tendenciaplot.setData(Xtendencia, Ytendencia);  //genera la grafica
  tendenciaplot.showXAxis(true); //visualizar ejes
  tendenciaplot.showYAxis(true); //visualizar ejes
  tendenciaplot.setXFormat("###,###cm"); //asigna una etiqueta
  tendenciaplot.setXAxisLabel("Estatura"); //asigna una etiqueta
  tendenciaplot.setYAxisLabel("Peso"); //asigna una etiqueta
  tendenciaplot.setPointColour(color(0, 255, 0, 100));//establece color y opacidad
  tendenciaplot.setPointSize(10);//estable tamaño de los puntos
}

void serialEvent(Serial puerto) {
  conteo++;
  estatura=puerto.read();
  peso=A*exp(B*estatura);
  print("Estatura: "+str(estatura));
  println(" -- Peso: "+str(peso));
}

void draw() {
  background(255);  //genera el fondo
  textSize(12);//establece el tamaño
  fill(0);//asigna color
  text("Picuasi Edison", width/2, 20);  //asigna texto y ubicacion
  textSize(12);  //asigna tamaño 
  fill(0);  //asigna color
  textAlign(CENTER);  //alinea texto de salida
  text("Regression Exponencial", width/2, 40);  //genera el texto y la ubicacion
  scatterplot.draw(10, 110, 300, 300);//genera la grafica
  tendenciaplot.draw(340, 120, 300, 300);  //genera la grafica
  if (conteo>0) {
    Xntendencia[conteo-1]=estatura;  //asigna valores
    Yntendencia[conteo-1]=peso;  //asigna valorea
    ntendenciaplot.setData(Xntendencia, Yntendencia);//genera la grafica

  }
    ntendenciaplot.showXAxis(true); //visualizar ejes
    ntendenciaplot.showYAxis(true); //visualizar ejes
    ntendenciaplot.setXFormat("###,###cm");//asigna una etiqueta
    ntendenciaplot.setXAxisLabel("Estatura");//asigna una etiqueta
    ntendenciaplot.setYAxisLabel("Peso");//asigna una etiqueta
    ntendenciaplot.setPointColour(color(0, 0, 255, 100));//establece color y opacidad
    ntendenciaplot.setPointSize(10);//estable tamaño de los puntos
  ntendenciaplot.draw(700, 120, 300, 300);//genera la grafica
}

