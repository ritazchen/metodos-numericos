/*
Métodos Numéricos - Integração Numérica
Método Newton-Cotes: Regra dos Trapézios Simples (apenas 1 trapézio)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) pow(x, 2)

#define RESULTADO_EXATO 1/3.0

double regraDosTrapeziosSimples(double x0, double x1, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);

int main(int argc, char* argv[])
{
    double x0, x1, h, integral;
    
    printf("Informe o x0 e x1: ");
    scanf("%lf %lf", &x0, &x1);
    h = x1 - x0;

    printf("\nParametros: x0 = %lf\tx1 = %lf\t\th = %.16lf\n\n", x0, x1, h);
    
    integral = regraDosTrapeziosSimples(x0, x1, h);
    printf("\n\t-> Resultado da integral = %.16lf\n", integral);
    
    printf("\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(RESULTADO_EXATO, integral));
    
    return 0;
}

double regraDosTrapeziosSimples(double x0, double x1, double h) 
{   
    printf("F(x0) = %.16lf\tF(x1) = %.16lf\th/2 = %lf\n", F(x0), F(x1), (h/2));
    return ( (F(x0) + F(x1)) * (h/2) );
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