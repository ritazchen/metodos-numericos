/*
Métodos Numéricos - Soluções Numéricas de EDOs
Método de Runge-Kutta de 4a ordem
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x,y) -2*y //y' = f(x,y)

#define EXATO(x,y) 1/exp(2*x) //função exata para o exemplo do slide (nem sempre vamos ter essa formula)
//#define EXATO(x,y) (exp(-x) + x + 1) //funcao exata da lista

double quartaOrdem(double x0, double xn, double y0, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);
double K1(double x, double y, double h);
double K2(double x, double y, double h);
double K3(double x, double y, double h);
double K4(double x, double y, double h);

int main(int argc, char* argv[])
{
    //double x0 = 0, xn = 1, y0 = 1, h = 0.2, yn;
    
    printf("Informe o x0, y0, xn e h: ");
    double x0, y0, xn, h, yn;
    scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);

    printf("\nParametros: x0 = %lf\ty0 = %lf\t\txn = %lf\t\th = %lf\n\n", x0, y0, xn, h);

    yn = quartaOrdem(x0,xn,y0,h);
    printf("\n\t\t\t\t\t-> Para x=%.2lf, a solução y eh %.16lf\n", xn, yn);
    
    printf("\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(yn, EXATO(xn,yn)));

    return 0;
}

double quartaOrdem(double x0, double xn, double y0, double h)
{

    double i, y = y0, x = x0;
    int iteracao = 0;

    printf("iterações\t\t   xi\t\t\t   yi\t\t\tK1\t\t\t\tK2\t\t\t\tK3\t\t\tK4\t\t\t    sol. exata\t\t\t\t   EA\n");
    printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), K3(x, y, h), K4(x, y, h), EXATO(x,y), 0.0);

    for(x = x0 + h; iteracao <= ((xn-x0)/h); x = x + h) {
        y = y + ((h/6)*(K1(x,y,h) + (2*K2(x,y,h)) + (2*K3(x,y,h)) + K4(x,y,h)));
        printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), K3(x,y,h), K4(x, y, h), EXATO(x,y), erroAbs(y, EXATO(x,y)));
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

double K1(double x, double y, double h) {
    return F(x,y);
}

double K2(double x, double y, double h) {
    return F((x + (h/2.0)), (y + ((h*K1(x,y,h))/2.0)));
}

double K3(double x, double y, double h) {
    return F((x + (h/2.0)), (y + ((h*K2(x,y,h))/2.0)));
}

double K4(double x, double y, double h) {
    return F((x + h), (y + (h*K3(x,y,h))));
}
