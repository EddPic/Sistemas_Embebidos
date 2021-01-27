import processing.serial.*;
import ddf.minim.*;
import controlP5.*;

ControlP5 cp5;
PImage img1, img2, img3, img4;
Minim postura1;
Minim postura2;
Minim postura3;
Minim postura4;
Serial port;
int dato;
int p=0;
//int dato2=3;
void setup() {
  size(1000, 600);
  background(255);

   port=new Serial(this, "COM10", 9600);
  cp5=new ControlP5(this);
  img1=loadImage("Posture1.png");
  img2=loadImage("Posture2.png");
  img3=loadImage("Posture3.png");
  img4=loadImage("Posture4.png");
  postura1=new Minim(this);
  postura2=new Minim(this);
  postura3=new Minim(this);
  postura4=new Minim(this);
  //port=new Serial(this, "COM10", 9600);
  cp5.addButton("Leer")
    .setPosition(100, 400)
    .setSize(150, 80)
    .setColorBackground(#F70744)
    .setColorActive(#E5E500)
    .setColorForeground(#00E5B5);
}

void draw() {

  textSize(20);
  fill(0);
  text("SISTEMAS EMBEBIDOS", 50, 50);
  text("PROYECTO", 50, 80);
  text("Picuasi Edison", 50, 120);
  
  switch(dato) {
  case 1:

    textSize(30);
    fill(0);
    text("Posicion 1", 600, 50);
    imageMode(CENTER);
    image(img1, 700, 300, 400, 400);
    break;
  case 2:
    textSize(30);
    fill(0);
    text("Posicion 2", 600, 50);
    imageMode(CENTER);
    image(img2, 700, 300, 400, 400);
    break;
  case 3:
    textSize(30);
    fill(0);
    text("Posicion 3", 600, 50);
    imageMode(CENTER);
    image(img3, 700, 300, 400, 400);
    break;
  case 4:
    textSize(30);
    fill(0);
    text("Posicion 4", 600, 50);
    imageMode(CENTER);
    image(img4, 700, 300, 400, 400);
    break;
  }
  
}

public void Abrir() {
  //dato=port.read();
  print(dato);
  p=1;
}

void serialEvent(Serial port) {
  p=0;
  dato=port.read();
}
