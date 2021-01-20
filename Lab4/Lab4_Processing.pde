import processing.serial.*;
import org.gicentre.utils.stat.*;  
XYChart scatterplot;
XYChart tendenciaplot;
XYChart ntendenciaplot;
Serial puerto;

int columna=0;
int fila=0;
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
int i=0;
float tendencia;
float axispeso;
float axisestatura;
int filas2=0;
int columnas2=0;
int conteo;
float [] Xntendencia=new float[20];
float [] Yntendencia=new float[20];

//////////////////////////////////
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
  size(1100, 500);  
  background(255);
  textSize(25);
  fill(0);
  text("Picuasi Edison", width/2, 20);
  puerto =new Serial(this, "COM15", 9600);
  textFont(createFont("Arial", 11), 11);
  scatterplot = new XYChart(this);
  tendenciaplot =new XYChart(this);
  ntendenciaplot =new XYChart(this);
  float[] Estatura  = new float[matriz.length-1];
  float[] Peso = new float[matriz.length-1];
  float [] Xtendencia=new float[20];
  float [] Ytendencia=new float[20];
  for (int i=0; i<matriz.length-1; i++)
  {
    Estatura[i]=matriz[i][0];
    Peso[i]=matriz[i][1];
  }

  for (; fila<n; fila++) {
    Ex1=Ex1+matriz[fila][0];  //sumatoria
    Ey1=Ey1+log(matriz[fila][1]);
    Exy1=Exy1+(matriz[fila][0]*log(matriz[fila][1]));
    Ex2=Ex2+(pow(matriz[fila][0], 2));
  }
  Ex_2=pow(Ex1, 2);
  numerador=(n*Exy1)-(Ex1*Ey1);
  denominador=n*Ex2-Ex_2;
  B=(numerador/denominador);
  float my1=Ey1/n;
  float mx1=Ex1/n;
  float Bmx=B*mx1;
  float R=my1-Bmx;
  A=exp(R);

  for (i=160; i<180; i++) {
    Xtendencia[i-160]=i;
    Ytendencia[i-160]=A*exp(B*(i));
  }

  scatterplot.setData(Estatura, Peso);
  scatterplot.showXAxis(true); 
  scatterplot.showYAxis(true); 
  scatterplot.setXFormat("###,###cm");
  scatterplot.setXAxisLabel("EStatura");
  scatterplot.setYAxisLabel("Peso");
  scatterplot.setPointColour(color(255, 0, 0, 100));
  scatterplot.setPointSize(10);
  tendenciaplot.setData(Xtendencia, Ytendencia);
  tendenciaplot.showXAxis(true); 
  tendenciaplot.showYAxis(true); 
  tendenciaplot.setXFormat("###,###cm");
  tendenciaplot.setXAxisLabel("Estatura");
  tendenciaplot.setYAxisLabel("Peso");
  tendenciaplot.setPointColour(color(0, 255, 0, 100));
  tendenciaplot.setPointSize(10);
}

void serialEvent(Serial puerto) {
  conteo++;
  estatura=puerto.read();
  peso=A*exp(B*estatura);
  print("Estatura: "+str(estatura));
  println(" -- Peso: "+str(peso));
}

void draw() {
  background(255);
  textSize(12);
  fill(0);
  text("Picuasi Edison", width/2, 20);
  textSize(12);
  fill(0);
  textAlign(CENTER);
  text("Regression Exponencial", width/2, 40);
  scatterplot.draw(10, 110, 300, 300);
  tendenciaplot.draw(340, 120, 300, 300);
  if (conteo>0) {
    Xntendencia[conteo-1]=estatura;
    Yntendencia[conteo-1]=peso;
    ntendenciaplot.setData(Xntendencia, Yntendencia);

  }
    ntendenciaplot.showXAxis(true); 
    ntendenciaplot.showYAxis(true); 
    ntendenciaplot.setXFormat("###,###cm");
    ntendenciaplot.setXAxisLabel("Estatura");
    ntendenciaplot.setYAxisLabel("Peso");
    ntendenciaplot.setPointColour(color(0, 0, 255, 100));
    ntendenciaplot.setPointSize(10);
  ntendenciaplot.draw(700, 120, 300, 300);
}
