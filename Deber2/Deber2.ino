/*
  Materia: Sistemas Embebidos
  Nombre: Picuasi Edison
  DEBER 2
  Instrucciones:
  - Estimados estudiantes, realizar el siguiente código y
  solo adjuntar su enlace al repositorio de su cuenta GitHub.
  - Realizar un programa que al presionar el pulsador cada
  vez, se visualiza a cada número primo hasta el 99.
*/


int btn = 7;  //pin 7 configurado como entrada
int A = 8;    //pin 8 conectado al decodificador
int B = 9;    //pin 9 conectado al decodificador
int C = 10;   //pin 10 conectado al decodificador
int D = 11;   //pin 11 conectado al decodificador
int unidades = 13;  //pin de activación display unidades
int decenas = 12;   //pin de activación display decenas
int uni, dec;       //variables
int cambio = 0;     //variable de cambio de estado
int num1 = 0;       //variable de conteo numeros primos
int contador = 0;   //variable de conteo pulsaciones
int i, a;           //variables de evaluacion
void setup() {
  Serial.begin(9600); //Inicializacion Comunicacion Serial
  pinMode(A, OUTPUT); //pin 8 declarado como salida
  pinMode(B, OUTPUT); //pin 9 declarado como salida
  pinMode(C, OUTPUT); //pin 10 declarado como salida
  pinMode(D, OUTPUT); //pin 11 declarado como salida
  pinMode(unidades, OUTPUT);  //pin 13 declarado como salida
  pinMode(decenas, OUTPUT); //pin 12 declarado como salida
  pinMode(btn, INPUT);  //pin 7 declarado como salida
}

void loop() {
  if (digitalRead(btn) == HIGH) { //condicion de activacion
    delay(100);                   //delay antirebotes
    cambio = 1 - cambio;          //cambio de estado
    if (cambio == 1) {            //condicion de activacion
      contador++;                 //incremento de variable
      num1++;                     //incremento de variable
      Serial.println(contador);   //impresion del valor de la variable
    }
  }

  if (num1 == 99) {       //condicion de de reinicio
    num1 = 0;             //reinicia el valor
  }
  primos();               //Llamada a un metodo
}

void primos() {
  a = 0;                        //variable de evaluacion
  for (i = 1; i <= num1; i++)   //condicion de analisis
  {
    if (num1 % i == 0)          //condicion de modulo
      a++;                      //incremento de variable
  }
  if (a == 2) {                 //condicion de comprobacion
    if (num1 < 10) {            //condicion de impresion de unidades
      uni = num1;               //asignacion de valor
      dec = 0;                  //asignacion de valor
    } else {
      dec = num1 / 10;          //asignacion de valor decenas
      uni = num1 - dec * 10;    //asignacion de valor unidades
    }
    digitalWrite(unidades, HIGH);   //encender display de unidades
    digitalWrite(decenas, LOW);     //apagar display de decenas
    segmentos(uni);                 //llamada de metodo
    delay(150);                     //tiempo de visualizacion
    digitalWrite(unidades, LOW);    //apagar display de unidades
    digitalWrite(decenas, HIGH);    //encender display de de  ce nas
    segmentos(dec);                 // llamada de metodo
    delay(150);                     //tiempo de visualizacion

  }
  else
  {
    num1++;                         //incremento de variable
  }
}



void segmentos (int h) {
  //0
  switch (h) {
    case 0:
      digitalWrite(A, LOW);   //Apaga el pin 8
      digitalWrite(B, LOW);   //Apaga el pin 9
      digitalWrite(C, LOW);   //Apaga el pin 10
      digitalWrite(D, LOW);   //Apaga el pin 11
      break;
    //1
    case 1:
      digitalWrite(A, HIGH);   //Enciende el pin 8
      digitalWrite(B, LOW);   //Apaga el pin 9
      digitalWrite(C, LOW);   //Apaga el pin 10
      digitalWrite(D, LOW);   //Apaga el pin 11
      break;
    //2
    case 2:
      digitalWrite(A, LOW);   //Apaga el pin 8
      digitalWrite(B, HIGH);   //Enciende el pin 9
      digitalWrite(C, LOW);     //Apaga el pin 10
      digitalWrite(D, LOW);     //Apaga el pin 11
      break;
    //3
    case 3:
      digitalWrite(A, HIGH);  //Enciende el pin 8
      digitalWrite(B, HIGH);  //Enciende el pin 9
      digitalWrite(C, LOW);   //Apaga el pin 10
      digitalWrite(D, LOW);   //Apaga el pin 11
      break;
    //4
    case 4:
      digitalWrite(A, LOW);   //Apaga el pin 8
      digitalWrite(B, LOW);   //Apaga el pin 9
      digitalWrite(C, HIGH);   //Enciende el pin 10
      digitalWrite(D, LOW);   //Apaga el pin 11
      break;
    //5
    case 5:
      digitalWrite(A, HIGH);  //Enciende el pin 8
      digitalWrite(B, LOW);   //Apaga el pin 9
      digitalWrite(C, HIGH);  //Enciende el pin 10
      digitalWrite(D, LOW);   //Apaga el pin 11
      break;
    //6
    case 6:
      digitalWrite(A, LOW);   //Apaga el pin 8
      digitalWrite(B, HIGH);  //Enciende el pin 9
      digitalWrite(C, HIGH);  //Enciende el pin 10
      digitalWrite(D, LOW);   //Apaga el pin 11
      break;
    //7
    case 7:
      digitalWrite(A, HIGH);  //Enciende el pin 8
      digitalWrite(B, HIGH);  //Enciende el pin 8
      digitalWrite(C, HIGH);  //Enciende el pin 8
      digitalWrite(D, LOW);   //Apaga el pin 8
      break;
    //8
    case 8:
      digitalWrite(A, LOW);   //Apaga el pin 8
      digitalWrite(B, LOW);   //Apaga el pin 9
      digitalWrite(C, LOW);   //Apaga el pin 10
      digitalWrite(D, HIGH);  //Enciende el pin 11
      break;
    //9
    case 9:
      digitalWrite(A, HIGH);  //Enciende el pin 8
      digitalWrite(B, LOW);   //Apaga el pin 9
      digitalWrite(C, LOW);   //Apaga el pin 10
      digitalWrite(D, HIGH);  //Enciende el pin 11
      break;
  }
}
