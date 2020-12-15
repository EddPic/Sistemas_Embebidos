//tamaño de las señales

#define tam_sig 101
#define tam_imp 6

extern double ecg_100Hz[tam_sig];
extern double Impulse_response[tam_imp];
double output[tam_sig + tam_imp];
double output_signal[tam_sig];
void convolution(double *sig_in, double *sig_out, double *imp, int sig_tam, int imp_tam);
void moving_average(double *sig_in, double *output_signal, int sig_tam, int filter);
void plot_signal(void);
void setup() {
  Serial.begin(9600);
}

void loop() {
  convolution((double*)&ecg_100Hz[0], (double *)&output[0], (double *)&Impulse_response[0],
              (int)tam_sig, (int)tam_imp);
  moving_average((double*)&ecg_100Hz[0], (double *)&output_signal[0], (int) tam_sig, 11);
  plot_signal();
  delay(100);
}

//////FILTROS FIR////////
void convolution(double *sig_in, double *sig_out, double *imp, int sig_tam, int imp_tam) {
  int i, j;
  for (i = 0; i < (sig_tam + imp_tam); i++) {
    sig_out[i] = 0;
  }
  for (i = 0; i < sig_tam; i++) {
    for (j = 0; j < imp_tam; j++) {
      sig_out[i + j] = sig_out[i + j] + sig_in[i] * imp[j];
    }
  }

}
////////////Suavizado de la señal/////////////


void moving_average(double *sig_in, double *output_signal, int sig_tam, int filter) {
  int i, j;
  for (i = floor(filter / 2); i < sig_tam - floor(filter / 2) - 1; i++) {
    output_signal[i] = 0;
    for (j = -floor(filter / 2); j < floor(filter / 2); j++) {
      output_signal[i] = output_signal[i] + sig_in[i + j];
    }
    output_signal[i] = output_signal[i] / filter;
  }

}


void plot_signal(void) {
  int i;
  for (i = 0; i < tam_sig; i++) {
    analogWrite(5, ecg_100Hz[i]); //
    analogWrite(4, output_signal[i]);
    analogWrite(3, output[i]);
    delay(5);
  }

}
