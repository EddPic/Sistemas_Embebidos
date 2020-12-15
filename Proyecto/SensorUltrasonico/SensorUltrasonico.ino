
const float Echo = 6;
const float Trig = 7;
long duracion, distancia;
int dac;
int cont;
int on;
int N, n;
float xj = 0, xi = 0, zj = 0;
float myarray[10] = {};
float resul[10]={};
void setup() {
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Echo, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Trig, OUTPUT);    // define el pin 7 como salida  (triger)
  attachInterrupt(0, lectura, FALLING);
}

void loop() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  duracion = pulseIn(Echo, HIGH);
  distancia = duracion * 0.034 / 2;        // calcula la distancia en centimetros
  //Serial.println(distancia);

}

void lectura() {
  on++;

  if (on < 11) {
    myarray[on - 1] = distancia;
    Serial.println(myarray[on - 1]);
  } else if (on==11) {
    N=sizeof(myarray)/sizeof(myarray[0]);
    n = (N - 1) / 2;
    for (int i = -n; i <= n; i++) {
      xi = myarray[n + i];
      xj = (i + xi + xj);
    }

    for (int i2 = 0; i2 <= N; i2++) {

      zj = xj / (2 * n + 1);
      resul[i2]=xj;
      Serial.print("Media: ");
      Serial.print(zj);
      Serial.print(",");
      Serial.println(myarray[i2]);
      delay(20);
    }
    zj = 0;
    xj = 0;
    xi = 0;

  }else if(on==12){
    for(int i=0;i<N;i++){
      dac=map(resul[i],0,1023,0,255);
      analogWrite(5,dac);
      delay(10);
      }
    }

}
