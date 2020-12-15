
const float Echo = 6;
const float Trig = 7;
long duracion, distancia;
int dac;
int cont;
int on;
int N, Nk=5;
float den=0,c=0, zj=0;
float myarray[10] = {};
float G[10] = {};
float kernel[]={0.05,0.24,0.4,0.24,0.05};
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

}

void lectura() {
  on++;

  if (on < 11) {
    myarray[on - 1] = distancia;
    G[on-1]=distancia;
    Serial.println(myarray[on - 1]);
  } else if (on==11) {
    N=sizeof(myarray)/sizeof(myarray[0]);
    ////GAUSS
    den=0;
  for (int i = 0; i < Nk; i++){
    den=den+kernel[i];
  }
  
for (int i = 0; i < N-Nk; i++){
for (int i2 = 0; i2 < Nk; i2++){
       c=c+kernel[i2]*myarray[i2+i];
}
    c=c/den;
    G[i+2]=c;
  Serial.print(c);
      Serial.print(",");
   Serial.println(myarray[i+2]);

}
    
  }else if(on==12){
    for(int i=0;i<N;i++){
      dac=map(G[i],0,1023,0,255);
      analogWrite(5,dac);
      delay(10);
      }
    }

}
