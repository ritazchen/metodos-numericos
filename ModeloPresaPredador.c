/*
Métodos Numéricos - Soluções Numéricas de EDOs
Exercício: Modelo Epidemico de COVID-19 (Modelo SIDR) utilizando o método de Euler
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double a = 0.2, b = 0.7, c = 0.4, d = 0.5;

void metodoDeEuler(double x0, double y0, double t0, double tn, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);

int main(int argc, char* argv[])
{
    double x0 = 1; //número de presas inicial
    double y0 = 1; //número de predadores inicial
    double h = .01, yn;
    double t0 = 0, tn = 150; 

    printf("\nParametros: x0 = %lf\ty0 = %lf\t\tt0 = %lf\t\ttn = %lf\t\tth = %lf\n\n", x0, y0, t0, tn, h);

    metodoDeEuler(x0, y0, t0, tn, h);
    printf("Dados gravados com sucesso!\n");

    return 0;
}

void metodoDeEuler(double x0, double y0, double t0, double tn, double h)
{
    FILE* f1 = fopen("dados_presa.txt", "w");
    FILE* f2 = fopen("dados_predador.txt", "w");

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
        x = x0 + (h * (a - (b*y0)) * x0);
        y = y0 + (h * (((-1)*c) + d*x0) * y0);
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
    if(x > 0) {
        return x;
    }
    else {
        return x * (-1);
    }
}