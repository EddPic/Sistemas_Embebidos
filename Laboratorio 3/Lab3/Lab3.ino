/*
Picuasi Edison
SISTEMAS EMBEBIDOS
LABORATORIO 3
*/


int up = 9;   //variable de pin de entrada
int down = 8; //variable de pin de entrada
int left = 7; //variable de pin de entrada
int right = 6;  //variable de pin de entrada
int SELECT = 5; //variable de pin de entrada
int START = 4;  //variable de pin de entrada
void setup() {
  Serial.begin(9600); //inicia cx serial
  pinMode(up, INPUT); //configura pin
  pinMode(down, INPUT); //configura pin
  pinMode(left, INPUT); //configura pin
  pinMode(right, INPUT);  //configura pin
  pinMode(SELECT, INPUT); //configura pin
  pinMode(START, INPUT);  //configura pin
}

void loop() {
  if (digitalRead(up) == HIGH) {    //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("w");  //envia dato por CX Serial
  }
  if (digitalRead(down) == HIGH) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("s");  //envia dato por CX Serial
  }
  if (digitalRead(left) == HIGH) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("a");  //envia dato por CX Serial
  }
   if (digitalRead(right) == HIGH) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("d");  //envia dato por CX Serial
  }
  if (digitalRead(START) == HIGH) { //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("K");  //envia dato por CX Serial
  }
    if (digitalRead(SELECT) == HIGH) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("L");  //envia dato por CX Serial
  }
}
