/*
Métodos Numéricos - Soluções Numéricas de EDOs
Método de Euler
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x,y) -2*y //y' = f(x,y)
#define EXATO(x,y) 1/exp(2*x) //função exata para o exemplo do slide (nem sempre vamos ter essa formula)
//#define EXATO(x,y) (exp(-x) + x + 1) //funcao exata da lista

double metodoDeEuler(double x0, double xn, double y0, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);

int main(int argc, char* argv[])
{
    //double x0 = 0, xn = 1, y0 = 1, h = 0.1;

    printf("Informe o x0, y0, xn e h: ");
    double x0, y0, xn, h, yn;
    scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);

    printf("\nParametros: x0 = %lf\ty0 = %lf\t\txn = %lf\t\th = %lf\n\n", x0, y0, xn, h);

    yn = metodoDeEuler(x0,xn,y0,h);
    printf("\n\t\t\t\t\t-> Para x=%.2lf, a solução y eh %.16lf\n", xn, yn);
    
    printf("\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(yn, EXATO(xn,yn)));

    return 0;
}

double metodoDeEuler(double x0, double xn, double y0, double h)
{

    double i, y = y0, x;
    int iteracao = 0;

    printf("iterações\t\txi\t\t   yi\t\ty' = f(x,y)\t\t   sol. exata\t\t\t\tEA\n");
    printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x0, y0, F(x0,y0), EXATO(x0,y0), 0.0);

    for(x = x0 + h; iteracao <= ((xn-x0)/h); x = x + h) {
        y = y + h*F(x,y);
        printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, F(x,y), EXATO(x,y), erroAbs(y, EXATO(x,y)));
    }

    return y;
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