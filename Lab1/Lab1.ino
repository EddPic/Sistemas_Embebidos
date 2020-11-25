/*
PICUASI EDISON
SISTEMAS EMBEBIDOS
LABORATORIO 1
*/

#include <Key.h>          
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (27, 26, 25, 24, 23, 22);
const byte fila = 4;
const byte columna = 4;

char keys[fila][columna] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '#', '0', '*', 'D' }
};

const byte rowPins[fila] = { 35, 34, 33, 32 };
const byte colPins[columna] = { 31, 30, 29, 28 };

Keypad teclado = Keypad(makeKeymap(keys), rowPins, colPins, fila, columna);

int k = 0 ;
int tam = 0;
int contador = 0;
int estado = 0;
int asignar = 0;
char comprobar[7];
char *pass1[] = {"Carlos Velez ", "cv900813", "NO"};
char *pass2[] = {"Andres Juares ", "aj881112", "NO"};
char *pass3[] = {"Javier Andrade ", "ja890109", "NO"};
char *pass4[] = {"Edison Picuasi ", "ep950710", "NO"};
String item, texto;
int num = 0;
char key2;
char key;
String dato;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    dato.toLowerCase();
  
  if (dato == pass1[1]) {
    Serial.println("");
    Serial.println("Correcto 1");
    dato = "";
    pass1[2] = "SI";
    texto = (" BIENVENIDO " + String(pass1[0]));
    rotar();
  } else if (dato == pass2[1]) {
    Serial.println("");
    Serial.println("Correcto 2");
    dato = "";
    pass2[2] = "SI";
    texto = (" BIENVENIDO " + String(pass2[0]));
    rotar();
  }
  else if (dato == pass3[1]) {
    Serial.println("");
    Serial.println("Correcto 3");
    dato = "";
    pass3[2] = "SI";
    texto = (" BIENVENIDO " + String(pass3[0]));
    rotar();
  }
  else if (dato == pass4[1]) {
    Serial.println("");
    Serial.println("Correcto 4");
    dato = "";
    pass4[2] = "SI";
    texto = (" BIENVENIDO " + String(pass4[0]));
    rotar();
  }else{
    Serial.println("");
    Serial.println("Incorrecto");
    dato = "";
    }

  }


  char key = teclado.getKey();
  if (key) {
    if (asignar <= 2) {
      if (key != key2) {
        contador = 0;
        asignar++;
      }
      key2 = key;
      letras(key);
    }
  }

  if (asignar > 2) {
    if (key) {
      if (num <= 6) {
        num++;
        lcd.setCursor(num + 1, 0);
        lcd.print(key);
        comprobar[num + 1] = key;
      }
    }
  }
  if (key == '#') {
    lcd.clear();
    lcd.setCursor(0, 0);
    for (int i = 0; i < 8; i++) {
      item += comprobar[i];
    }
    //Carlos Velez
    if (item == pass1[1]) {
      Serial.println("correcto");
      pass1[2] = "SI";
      num = 0;
      asignar = 0;
      contador = 0;
      item = "";
      texto = " BIENVENIDO " + String(pass1[0]);
      rotar();
      //Andres Juares
    } else if (item == pass2[1]) {
      Serial.println("correcto");
      pass2[2] = "SI";
      num = 0;
      asignar = 0;
      contador = 0;
      item = "";
      texto = " BIENVENIDO " + String(pass2[0]);
      rotar();
    }
    //Javier Andrade
    else if (item == pass3[1]) {
      Serial.println("correcto");
      pass3[2] = "SI";
      num = 0;
      asignar = 0;
      contador = 0;
      item = "";
      texto = (" BIENVENIDO " + String(pass3[0]));
      rotar();
    }
    //Edison Picuasi
    else if (item == pass4[1]) {
      Serial.println("correcto");
      pass4[2] = "SI";
      num = 0;
      asignar = 0;
      contador = 0;
      item = "";
      texto = " BIENVENIDO " + String(pass4[0]);
      rotar();
    } else {
      Serial.println("incorrecto");
      num = 0;
      asignar = 0;
      contador = 0;
      item = "";
    }

  }

  if (key == '*') {
    Serial.println("NOMBRE           ASISTENCIA");
    Serial.println(String(pass1[0]) + " | " + String(pass1[2]));
    Serial.println(String(pass2[0]) + " | " + String(pass2[2]));
    Serial.println(String(pass3[0]) + " | " + String(pass3[2]));
    Serial.println(String(pass4[0]) + " | " + String(pass4[2]));
    num = 0;
    asignar = 0;
    contador = 0;
    item = "";
  }
}

void letras(char letra) {
  switch (letra) {
    case '1':
      contador++;
      if (contador == 1) {
        letra = 'a';
      }
      else if (contador == 2) {
        letra = 'b';
      }
      else if (contador == 3) {
        letra = 'c';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;

    case '2':
      contador++;
      if (contador == 1) {
        letra = 'd';
      }
      else if (contador == 2) {
        letra = 'e';
      }
      else if (contador == 3) {
        letra = 'f';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '3':
      contador++;
      if (contador == 1) {
        letra = 'g';
      }
      else if (contador == 2) {
        letra = 'h';
      }
      else if (contador == 3) {
        letra = 'i';
        contador = 0;
      }
      comprobar[asignar - 1] = letra;
      //      Serial.println(letra);
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '4':
      contador++;
      if (contador == 1) {
        letra = 'j';
      }
      else if (contador == 2) {
        letra = 'k';
      }
      else if (contador == 3) {
        letra = 'l';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      //      Serial.println(letra);
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '5':
      contador++;
      if (contador == 1) {
        letra = 'm';
      }
      else if (contador == 2) {
        letra = 'n';
      }
      else if (contador == 3) {
        letra = 'ñ';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '6':
      contador++;
      if (contador == 1) {
        letra = 'o';
      }
      else if (contador == 2) {
        letra = 'p';
      }
      else if (contador == 3) {
        letra = 'q';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      //      Serial.println(letra);
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '7':
      contador++;
      if (contador == 1) {
        letra = 'r';
      }
      else if (contador == 2) {
        letra = 's';
      }
      else if (contador == 3) {
        letra = 't';
      }

      comprobar[asignar - 1] = letra;
      //      Serial.println(letra);
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '8':
      contador++;
      if (contador == 1) {
        letra = 'u';
      }
      if (contador == 2) {
        letra = 'v';
      }
      if (contador == 3) {
        letra = 'w';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      //      Serial.println(letra);
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
    case '9':
      contador++;
      if (contador == 1) {
        letra = 'x';
      }
      else if (contador == 2) {
        letra = 'y';
      }
      else if (contador == 3) {
        letra = 'z';
        contador = 0;
      }

      comprobar[asignar - 1] = letra;
      //      Serial.println(letra);
      lcd.setCursor(asignar - 1, 0);
      lcd.print(letra);
      break;
  }
}


void rotar() {
  tam = texto.length();
  for (int i = tam; i > 0 ; i--)
  {
    String tex = texto.substring(i - 1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(tex);
    lcd.setCursor(k, 0);
    lcd.print(texto);
    delay(300);
    if (k < 16)
      k++;
    else
      k = 16;
  }
  lcd.clear();
  k = 0;
  tam = 0;
  texto = "";
}
