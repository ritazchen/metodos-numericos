/*
Métodos Numéricos - Soluções Numéricas de EDOs
Exercício: Modelo Presa-Predador utilizando o método da Quarta Ordem de Runge Kutta
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double a = 0.2, b = 0.7, c = 0.4, d = 0.5;

void quartaRungeKutta(double x0, double y0, double t0, double tn, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);
double F(double t, double x, double y);
double G(double t, double x, double y);
double K1(double t, double x, double y);
double K1C(double t, double x, double y);
double K2(double t, double x, double y, double h);
double K2C(double t, double x, double y, double h);
double K3(double t, double x, double y, double h);
double K3C(double t, double x, double y, double h);
double K4(double t, double x, double y, double h);
double K4C(double t, double x, double y, double h);

int main(int argc, char* argv[])
{
    double x0 = 1; //número de presas inicial
    double y0 = 1; //número de predadores inicial
    double h = .01, yn;
    double t0 = 0, tn = 150; 

    printf("\nParametros: x0 = %lf\ty0 = %lf\t\tt0 = %lf\t\ttn = %lf\t\tth = %lf\n\n", x0, y0, t0, tn, h);

    quartaRungeKutta(x0, y0, t0, tn, h);
    printf("Dados gravados com sucesso!\n");

    return 0;
}

void quartaRungeKutta(double x0, double y0, double t0, double tn, double h)
{
    FILE* f1 = fopen("dados_presa_4RK.txt", "w");
    FILE* f2 = fopen("dados_predador_4RK.txt", "w");

    double i, y = y0, x = x0, t = 0;
    int iteracao = 0;

    //printf("iterações\t\tt (tempo)\t\tx (presas)\t\t   yi (predadores)\n");
    //printf("    %d\t\t     %.16lf\t\t%.16lf\t\t%.16lf\n", iteracao++, t, x, y);
    fprintf(f1, "%lf,%lf;", t, x);
    fprintf(f2, "%lf,%lf;", t, y);
    
    t += h;

    while(t <= tn) {
        x0 = x;
        y0 = y;
        x = x0 + ((h/6.0)*(K1(t,x0,y0) + (2*K2(t,x0,y0,h)) + (2*K3(t,x0,y0,h)) + K4(t,x0,y0,h)));
        y = y0 + ((h/6.0)*(K1C(t,x0,y0) + (2*K2C(t,x0,y0,h)) + (2*K3C(t,x0,y0,h)) + K4C(t,x0,y0,h)));
        fprintf(f1, "%lf,%lf;", t, x);
        fprintf(f2, "%lf,%lf;", t, y);
        //printf("    %d\t\t     %.16lf\t\t%.16lf\t\t%.16lf\n", iteracao++, t, x, y);
        t += h;
    }

    fclose(f1);
    fclose(f2);
}

double erroAbs(double resultadoExato, double integralEncontrada) {
    return Abs(resultadoExato - integralEncontrada);
}

double Abs(double x) {
    if(x >= 0) {
        return x;
    }
    else {
        return x * (-1);
    }
}

double F(double t, double x, double y) {
    return x*(a - (b*y));
}

double G(double t, double x, double y) {
    return y*((((-1)*c) + d*x));
}

double K1(double t, double x, double y) {
    return F(t,x,y);
}

double K1C(double t, double x, double y) {
    return G(t,x,y);
}

double K2(double t, double x, double y, double h) {
    return F((t + (h/2.0)), (x + ((h/2.0)*K1(x,y,h))), (y + ((h/2.0)*K1C(x,y,h))));
}

double K2C(double t, double x, double y, double h) {
    return G((t + (h/2.0)), (x + ((h/2.0)*K1(x,y,h))), (y + ((h/2.0)*K1C(x,y,h))));
}

double K3(double t, double x, double y, double h) {
    return F((t + (h/2.0)), (x + ((h/2.0)*K2(t,x,y,h))), (y + ((h/2.0)*K2C(t,x,y,h))));
}

double K3C(double t, double x, double y, double h) {
    return G((t + (h/2.0)), (x + ((h/2.0)*K2(t,x,y,h))), (y + ((h/2.0)*K2C(t,x,y,h))));
}

double K4(double t, double x, double y, double h) {
    return F((t + h), (x + (h*K3(t,x,y,h))), (y + (h*K3C(t,x,y,h))));
}

double K4C(double t, double x, double y, double h) {
    return G((t + h), (x + (h*K3(t,x,y,h))), (y + (h*K3C(t,x,y,h))));
}