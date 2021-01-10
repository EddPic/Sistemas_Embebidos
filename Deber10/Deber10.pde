/*
SISTEMAS EMBEBIDOS
 Picuasi Edison
 
 Realice una interfaz que permita mover una esfera por toda la pantalla mediante teclas.
 
 */
int movey=600/2;  //variable de posicion
int movex=900/2;  //variable de posicion
void setup() {
  size(900, 600);  //asignar tamaño de la ventana
  background(#050505);  //asignar color de fondo
}

void draw() {
  background(#050505);  //generar un fondo en cada cambio
  ellipse(movex, movey, 50, 50);  //generar una elipse en cada ejecucion
}
void keyPressed() {
  println(key);  //imprimir la letra presionada
  println(movey);  //imprimer el valor de la posicion en y
  println(movex);  //imprimer el valor de la posicion en x

  //Movimiento hacia arriba
  if (key=='w') {    //condicion de presion
    movey=movey-10;  //decremento del valor de posicion en y
    if (movey<0) {  //condicion de limite
      movey=0;  //limite de posicion en y
    }
    fill(random(0, 250), random(0, 250), random(0, 250));  //asignar un color aleatorio
  }
  //Movimiento hacia abajo
  if (key=='s') {  //condicion de presion
    movey=movey+10;  //incremento del valor de posicion en y
    if (movey>600) {//condicion de limite en y
      movey=600;  //limite de posicion
    }
    fill(random(0, 250), random(0, 250), random(0, 250));  //asignar un color aleatorio
  }
  //Movimiento hacia la izquierda
  if (key=='a') {  //condicion de presion
    movex=movex-10;  //decremento del valor de posicion en x
    if (movex<0) {  //condicion de limite
      movex=0;  //limite de posicion en x
    }
    fill(random(0, 250), random(0, 250), random(0, 250));  //asignar un color aleatorio
  }
  //Movimiento hacia la derecha
  if (key=='d') {  //condicion de presion
    movex=movex+10;  //incremento del valor de posicion en x
    if (movex>900) {  //condicion de limite
      movex=900;  //limite de posicion en x
    }
    fill(random(0, 250), random(0, 250), random(0, 250));  //asignar un color aleatorio
  }
}
