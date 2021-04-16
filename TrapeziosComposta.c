/*
Métodos Numéricos - Integração Numérica
Método Newton-Cotes: Regra dos Trapézios Composta
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x) exp(x) //questão 1 da lista
//#define F(x) (1/x)*exp(x/2) //questão 2 da lista
#define F(x) (1/(1+x)) //questão 3 da lista

double regraDosTrapeziosComposta(double x0, double xn, double h);

int main(int argc, char* argv[])
{
    double x0, xn, numIntervalos, h;
    
    printf("Informe o x0, xn e o número de intervalos: ");
    scanf("%lf %lf %lf", &x0, &xn, &numIntervalos);
    h = ((xn-x0)/numIntervalos);

    printf("\nParametros: x0 = %lf\txn = %lf\t\tnúmero de intervalos = %.0lf\t\th = %.16lf\n\n", x0, xn, numIntervalos, h);

    printf("\n\t\t\t\t\t-> Resultado da integral = %.16lf\n", regraDosTrapeziosComposta(x0, xn, h));

    return 0;
}

double regraDosTrapeziosComposta(double x0, double xn, double h) 
{
    double integral = 0.0;
    double i;
    int iteracao = 0;
    
    printf("iterações\t\ti\t\t\t       F(xi)\t\t\t    ci (peso)\t\t    ci * f(xi)\n");
    printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\n", iteracao++, x0, F(x0), 1, F(x0));

    for(i = (x0 + h); i < xn; i += h) {
        integral += (2.0*F(i));
        printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\t\t\n", iteracao++, i, F(i), 2, (2*F(i)));
    }

    printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\n", iteracao, xn, F(xn), 1, F(xn));

    integral += F(x0) + F(xn);
    integral = integral * (h/2);

    return integral;
}