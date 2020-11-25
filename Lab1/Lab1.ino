/*
PICUASI EDISON
SISTEMAS EMBEBIDOS
LABORATORIO 1
*/

#include <Key.h>               //Incluir Libreria Keypad
#include <Keypad.h>       
#include <LiquidCrystal.h>      //Incluir libreria del LCD
LiquidCrystal lcd (27, 26, 25, 24, 23, 22);   //declarar la variable y pines del lcd
const byte fila = 4;            //Declarar variable y el numero de filas
const byte columna = 4;         //Declarar variable y el numero de columnas

char keys[fila][columna] = {    //matriz de caracteres
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '#', '0', '*', 'D' }
};

const byte rowPins[fila] = { 35, 34, 33, 32 };        //Asignar los pines para las filas
const byte colPins[columna] = { 31, 30, 29, 28 };     //Asignar los pines para las columnas

Keypad teclado = Keypad(makeKeymap(keys), rowPins, colPins, fila, columna);

int k = 0 ;           //variable de conteo
int tam = 0;          //variable tamano del vector
int contador = 0;     //variable de conteo
int estado = 0;       //variable de cambio de estado
int asignar = 0;      //varaible de conteo
char comprobar[7];    //variable contraseña ingresada
char *pass1[] = {"Carlos Velez ", "cv900813", "NO"};      //Variable de datos usuario 1
char *pass2[] = {"Andres Juares ", "aj881112", "NO"};     //Variable de datos usuario 2
char *pass3[] = {"Javier Andrade ", "ja890109", "NO"};    //Variable de datos usuario 3
char *pass4[] = {"Edison Picuasi ", "ep950710", "NO"};    //Variable de datos usuario 4
String item, texto;     //variable de almacenado
int num = 0;            //variable de conteo
char key2;              //varaible de cambio de estado
char key;               //varaible ingreso de dato
String dato;

void setup() {
  Serial.begin(9600);   //inicializar CX Serial
  lcd.begin(16, 2);     //inicializar lcd 16x2
}

void loop() {
  if (Serial.available() > 0) {       //condicion de ingreso de dato por serial
    dato = Serial.readString();       //asignar el dato a la variable
    dato.toLowerCase();               //conversion a minusculas
  
  if (dato == pass1[1]) {             //condicion de verificacion de contraseña
    Serial.println("");               //imprime mensaje
    Serial.println("Correcto 1");     //imprime mensaje
    dato = "";                        //reinicia la variable
    pass1[2] = "SI";                  //almacena estado
    texto = (" BIENVENIDO " + String(pass1[0]));  //Asigna y extrae dato de usuario
    rotar();                          //llama al metodo
  } else if (dato == pass2[1]) {      //condicion de verificacion de contraseña
    Serial.println("");               //imprime mensaje
    Serial.println("Correcto 2");     //imprime mensaje
    dato = "";                        //reinicia la variable
    pass2[2] = "SI";                  //almacena estado
    texto = (" BIENVENIDO " + String(pass2[0]));  //Asigna y extrae dato de usuario
    rotar();                          //llama al metodo
  }
  else if (dato == pass3[1]) {        //condicion de verificacion de contraseña
    Serial.println("");               //imprime mensaje
    Serial.println("Correcto 3");     //imprime mensaje
    dato = "";                        //reinicia la variable
    pass3[2] = "SI";                  //almacena estado
    texto = (" BIENVENIDO " + String(pass3[0]));  //Asigna y extrae dato de usuario
    rotar();                          //llama al metodo
  }
  else if (dato == pass4[1]) {        //condicion de verificacion de contraseña
    Serial.println("");               //imprime mensaje
    Serial.println("Correcto 4");     //imprime mensaje
    dato = "";                        //reinicia la variable
    pass4[2] = "SI";                  //almacena estado
    texto = (" BIENVENIDO " + String(pass4[0]));  //Asigna y extrae dato de usuario
    rotar();                          //llama al metodo
  }else{
    Serial.println("");               //imprime mensaje
    Serial.println("Incorrecto");     //imprime mensaje
    dato = "";                        //reinicia la variable
    }

  }


  char key = teclado.getKey();        //variable de ingreso de dato
  if (key) {                          //condicion de ingreso de daro
    if (asignar <= 2) {               //condicion de lectura de letras
      if (key != key2) {              //condicion de cambio de ingreso
        contador = 0;                 //reinicia variable
        asignar++;                    //incrementa el valor de la variable
      }
      key2 = key;                     //asigna cambio de estado-valor
      letras(key);                    //llama al metodo
    }
  }

  if (asignar > 2) {                    //condicion ingreso de numeros
    if (key) {                          //condicion de ingreso de dato
      if (num <= 6) {                   //condicion de acceso
        num++;                          //incrementa valor
        lcd.setCursor(num + 1, 0);      //Posicionar cursor
        lcd.print(key);                 //Imprime dato 
        comprobar[num + 1] = key;       //almacena el dato
      }
    }
  }
  if (key == '#') {                     //condicion de verificacion
    lcd.clear();                        //limpia la pantalla
    lcd.setCursor(0, 0);                //Posiciona el cursor
    for (int i = 0; i < 8; i++) {       //ciclo de recorrido
      item += comprobar[i];             //extrae y asigna el dato
    }
    //Carlos Velez
    if (item == pass1[1]) {             //Condicion de verificacion
      Serial.println("correcto");       //imprime mensaje
      pass1[2] = "SI";                  //almacena el estado
      num = 0;                          //reinicia la variable
      asignar = 0;                      //reinicia la variable
      contador = 0;                     //reinicia la variable
      item = "";                        //reinicia la variable
      texto = " BIENVENIDO " + String(pass1[0]);  //asigna y extrae dato del usuario
      rotar();                          //llama al metodo
      //Andres Juares
    } else if (item == pass2[1]) {      //Condicion de verificacion
      Serial.println("correcto");       //imprime mensaje
      pass2[2] = "SI";                  //almacena el estado
      num = 0;                          //reinicia la variable
      asignar = 0;                      //reinicia la variable
      contador = 0;                     //reinicia la variable
      item = "";                        //reinicia la variable
      texto = " BIENVENIDO " + String(pass2[0]);  //asigna y extrae dato del usuario
      rotar();                          //llama al metodo
    }
    //Javier Andrade
    else if (item == pass3[1]) {      //Condicion de verificacion
      Serial.println("correcto");     //imprime mensaje
      pass3[2] = "SI";                //almacena el estado
      num = 0;                        //reinicia la variable
      asignar = 0;                    //reinicia la variable
      contador = 0;                   //reinicia la variable
      item = "";                      //reinicia la variable
      texto = (" BIENVENIDO " + String(pass3[0]));  //asigna y extrae dato del usuario
      rotar();                        //llama al metodo
    }
    //Edison Picuasi
    else if (item == pass4[1]) {      //Condicion de verificacion
      Serial.println("correcto");     //imprime mensaje
      pass4[2] = "SI";                //almacena el estado
      num = 0;                        //reinicia la variable
      asignar = 0;                    //reinicia la variable
      contador = 0;                   //reinicia la variable
      item = "";                      //reinicia la variable
      texto = " BIENVENIDO " + String(pass4[0]);  //asigna y extrae dato del usuario
      rotar();                        //llama al metodo
    } else {
      Serial.println("incorrecto");   //imprime mensaje
      num = 0;                        //reinicia la variable
      asignar = 0;                    //reinicia la variable
      contador = 0;                   //reinicia la variable
      item = "";                      //reinicia la variable
    }

  }

  if (key == '*') {                                               //condicion de verificacion
    Serial.println("NOMBRE           ASISTENCIA");                //imprime mensaje
    Serial.println(String(pass1[0]) + " | " + String(pass1[2]));  //imprime mensaje
    Serial.println(String(pass2[0]) + " | " + String(pass2[2]));  //imprime mensaje
    Serial.println(String(pass3[0]) + " | " + String(pass3[2]));  //imprime mensaje
    Serial.println(String(pass4[0]) + " | " + String(pass4[2]));  //imprime mensaje
    num = 0;          //reinicia variable
    asignar = 0;      //reinicia variable
    contador = 0;     //reinicia variable
    item = "";        //reinicia variable
  }
}

void letras(char letra) {           //metodo de conversion a letras
  switch (letra) {                  //ciclo
    case '1':                     
      contador++;                   //incrementa contador
      if (contador == 1) {          //condicion de verificacion
        letra = 'a';                //asigna el dato
      }
      else if (contador == 2) {     //condicion de verificacion
        letra = 'b';                //asigna el dato
      }
      else if (contador == 3) {     //condicion de verificacion
        letra = 'c';                //asigna el dato
        contador = 0;               //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;

    case '2':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'd';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'e';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'f';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '3':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'g';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'h';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'i';              //asigna el dato
        contador = 0;             //reinicia variable
      }
      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '4':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'j';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'k';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'l';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '5':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'm';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'n';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'ñ';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '6':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'o';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'p';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'q';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '7':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'r';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 's';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 't';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '8':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'u';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'v';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'w';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
    case '9':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'x';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'y';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'z';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      break;
  }
}


void rotar() {
  tam = texto.length();           //almacena el tamaño de la variable
  for (int i = tam; i > 0 ; i--)  //ciclo de recorrido
  {
    String tex = texto.substring(i - 1);    //asigna el dato
    lcd.clear();            //limpia el lcd
    lcd.setCursor(0, 0);    //posiciona el cursor
    lcd.print(tex);         //imprime el dato
    lcd.setCursor(k, 0);    //posiciona el cursor
    lcd.print(texto);       //imprime el dato
    delay(300);             //tiempo de espera
    if (k < 16)             //condicion de comprobacion
      k++;                  //incrementa el valor de la variable
    else
      k = 16;               //reinicia variable
  }
  lcd.clear();              //limpia el lcd
  k = 0;                    //reinicia variable
  tam = 0;                  //reinicia variable
  texto = "";               //reinicia variable
}
