/*
Métodos Numéricos - Integração Numérica
Método Newton-Cotes: Regra 1/3 de Simpson
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x) exp(x) //questão 1 da lista
#define F(x) (1/x)*exp(x/2) //questão 2 da lista
//#define F(x) (1/(1+x)) //questão 3 da lista

//#define RESULTADO_EXATO 4.500014451138717

double regraUmTercoSimpson(double x0, double xn, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);

int main(int argc, char* argv[])
{
    double x0, xn, numIntervalos, h, integral;
    
    printf("Informe o x0, xn e o número de intervalos: ");
    scanf("%lf %lf %lf", &x0, &xn, &numIntervalos);
    h = ((xn-x0)/numIntervalos);

    printf("\nParametros: x0 = %lf\txn = %lf\t\tnúmero de intervalos = %.0lf\t\th = %.16lf\n\n", x0, xn, numIntervalos, h);

    integral = regraUmTercoSimpson(x0, xn, h);
    printf("\n\t\t\t\t\t-> Resultado da integral = %.16lf\n", integral);
    
    //printf("\n\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(RESULTADO_EXATO, integral));

    return 0;
}

double regraUmTercoSimpson(double x0, double xn, double h) 
{
    double integral = 0.0;
    double i;
    int iteracao = 0, peso;
    
    printf("iterações\t\ti\t\t\t       F(xi)\t\t\t    ci (peso)\t\t    ci * f(xi)\n");
    printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\n", iteracao++, x0, F(x0), 1, F(x0));

    for(i = (x0 + h); i < xn; i += h) {
        if(iteracao % 2 == 0) {
            integral += (2.0*F(i));
            peso = 2;
        }
        else {
            integral += (4.0*F(i));
            peso = 4;
        }
        printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\t\t\n", iteracao++, i, F(i), peso, (peso*F(i)));
    }

    printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\n", iteracao, xn, F(xn), 1, F(xn));

    integral += F(x0) + F(xn);
    integral = integral * (h/3);

    return integral;
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