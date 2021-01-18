/*
Picuasi Edison
SISTEMAS EMBEBIDOS
LABORATORIO 3
*/


import processing.serial.*;  //importa libreria
String tecla;  //variable de lectura
Serial port;  //crea el puerto
int cont;  //variable de conteo
ArrayList<Integer> x= new ArrayList<Integer>(), y=new ArrayList<Integer>();  //variable
int ancho=30, alto=30, bs=20, dir=2; //variable de dimension ventana , variable de direccion 
int foodx=12, foody=10;  //variables de comida
int [] dx={0, 0, 1, -1}, dy={1, -1, 0, 0};  //variables de direccion
boolean gameover=false;  //varaible de estado
void setup() {
  size(600, 600);  //establecer dimension de la ventana
  x.add(25);  //añade valor a x
  y.add(25);  //añade valor a y
  port= new Serial(this, "COM10", 9600);  //configura puerto CX
}
void draw() {
  background(255);  //crea y establece el color de fondo
  for (int i=0; i<ancho; i++)
    line(i*bs, 0, i*bs, height);  //estable la cuadricula de la eventana
  for (int i=0; i<alto; i++)
    line(0, i*bs, width, i*bs);  //estable la cuadricula de la eventana
  for (int i=0; i<x.size(); i++) {
    fill(0, 255, 0);  //asigna un color de relleno
    rect(x.get(i)*bs, y.get(i)*bs, bs, bs);  //crear serpiente
  }
  if (!gameover) {
    fill(255, 0, 0);  //asigna color de relleno
    rect(foodx*bs, foody*bs, bs, bs);  //crea la comida
    if (frameCount%25==0) {  //actualizacion de la ventana
      x.add(0, x.get(0)+dx[dir]);  //adjunta datos al array
      y.add(0, y.get(0)+dy[dir]);  //adjunta datos al array
      if (x.get(0)<0||y.get(0)<0||x.get(0)>=ancho||y.get(0)>=alto) {  //condicion limite ventana
        gameover=true;  //cambia de estado
      }
      for (int i=1; i<x.size(); i++) { 
        if (x.get(0)==x.get(i)&&y.get(0)==y.get(i)) {  //condicion de choque 
          gameover=true;  //cambio de estado
        }
      }
      if (x.get(0)==foodx && y.get(0)==foody) {  //condicion de aliemento
        foodx=(int)random(0, ancho);  //asigna posicion en x
        foody=(int)random(0, alto);  //asigna posicion en y
        cont=cont+10;  //incremento de resultado
        println("Puntuacion:"+str(cont));  //imprime mensaje
      } else {
        x.remove(x.size()-1);  //elimina valor del array
        y.remove(y.size()-1);  //elimina valor del array
      }
    }
  } else {
    fill(0);  //asigna un color
    textSize(30);  //establece el tamaño del texto
    textAlign(CENTER);  //establece posicion
    text("GAME OVER - Puntuacion: "+str(cont), width/2, height/2);//imprime texto
    if (keyPressed&&key=='k') {  //condicion de reinicio
      x.clear();  //limpia el array
      y.clear();  //limpia el array
      x.add(25);   //añade valor al array 
      y.add(25);  //añade valor al array
      gameover=false;  //reinicia variable
      cont=0;  //reinicia variable
    }
  }
}
void serialEvent(Serial port) {
  tecla=port.readString();  //lee dato del puerto
  println(tecla);  //imprime mensaje
  switch(tecla) {  //condicion de seleccion
  case "w":
    key='w';  //establece valor de key
    keyPressed();  //llama al metodo
    break;
  case "s":
    key='s';  //establece valor de key
    keyPressed();  //llama al metodo
    break;
  case "a":
    key='a';  //establece valor de key
    keyPressed();  //llama al metodo
    break;
  case "d":
    key='d';  //establece valor de key
    keyPressed();  //llama al metodo
    break;
  case "K":
    key='k';  //establece valor de key
    keyPressed();  //llama al metodo
    break;
  case "L":
    key='l';  //establece valor de key
    keyPressed();  //llama al metodo
    break;
  }
}
void keyPressed() {  
  int newdir = key=='s' ? 0:(key=='w' ? 1:(key=='d' ? 2:(key=='a' ? 3:-1)));
  if (newdir!=-1 &&(x.size()<=1||!(x.get(1)==x.get(0)+dx[newdir]&&y.get(1)==y.get(0)+dy[newdir]))) {
    dir=newdir; //asigna una nueva direccion
  }
}
