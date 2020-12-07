/*
EJERCICIO 1
CODIGO MORSE
ARDUINO MEGA
EDISON PICUASI
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(27, 26, 25, 24, 23, 22);
String palabra, code;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  if (Serial.available() > 0) {
    palabra = Serial.readString();
    palabra.toLowerCase();
    Serial.println(palabra);
    int tam;
    tam = palabra.length();
    char vector[tam];
    palabra.toCharArray(vector, tam + 1);
    for (int i = 0; i < tam; i++) {
      morse(vector[i]);

    }

    Serial.println(code);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(code);
  }
  palabra="";
  code="";
}

void morse(char letra) {
  switch (letra) {
    case 'a':
      code = code + " o- ";
      break;
    case 'b':
      code = code + "-ooo ";
      break;
    case 'c':
      code = code + "-o-o ";
      break;
    case 'd':
      code = code + "--o ";
      break;
    case 'e':
      code = code + "o ";
      break;
    case 'f':
      code = code + "oo-o ";
      break;
    case 'g':
      code = code + "--o ";
      break;
    case 'h':
      code = code + "oooo ";
      break;
    case 'i':
      code = code + "oo ";
      break;
    case 'j':
      code = code + "o--- ";
      break;
    case 'k':
      code = code + "-o- ";
      break;
    case 'l':
      code = code + "o-oo ";
      break;
    case 'm':
      code = code + "-- ";
      break;
    case 'n':
      code = code + "-o ";
      break;
    case 'o':
      code = code + "--- ";
      break;
    case 'p':
      code = code + "o--o ";
      break;
    case 'q':
      code = code + "--o- ";
      break;
    case 'r':
      code = code + "o-o ";
      break;
    case 's':
      code = code + "ooo ";
      break;
    case 't':
      code = code + "- ";
      break;
    case 'u':
      code = code + "oo- ";
      break;
    case 'v':
      code = code + "ooo- ";
      break;
    case 'w':
      code = code + "o-- ";
      break;
    case 'x':
      code = code + "-oo- ";
      break;
    case 'y':
      code = code + "-o-- ";
      break;
    case 'z':
      code = code + "--oo ";
      break;
      
    case '1':
      code = code + "o---- ";
      break;
    case '2':
      code = code + "oo--- ";
      break;
    case '3':
      code = code + "ooo-- ";
      break;
    case '4':
      code = code + "oooo- ";
      break;
    case '5':
      code = code + "ooooo ";
      break;
    case '6':
      code = code + "-oooo ";
      break;
    case '7':
      code = code + "--ooo ";
      break;
    case '8':
      code = code + "---oo ";
      break;
    case '9':
      code = code + "----o ";
      break;
    case '0':
      code = code + "----- ";
      break;
  }
}
