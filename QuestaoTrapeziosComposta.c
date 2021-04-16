/*
Métodos Numéricos - Integração Numérica
Método Newton-Cotes: Regra dos Trapézios Composta

Questão 4 da lista (não sei se a resolução tá certa)

gcc -o QTC QuestaoTrapeziosComposta.c
./QTC
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) pow(x,2) //questão 4 da lista
#define RES 1/3.0 //resultado
#define DEC pow(10, -4) //casas decimais iguais a 4, tem que ter o 0.3333 na integral

double regraDosTrapeziosComposta(double x0, double xn, double h);
double calculo(double x0, double xn, double h, double integral);
double Abs(double x);

int main(int argc, char* argv[])
{
    double x0, xn, h;
    
    printf("Informe o x0 e xn: ");
    scanf("%lf %lf", &x0, &xn);
    h = pow(10, -2); //chute

    printf("\nParametros: x0 = %lf\txn = %lf\t\th = %lf\n\n", x0, xn, h);

    printf("\n\t\t\t\t\t-> Resultado da integral = %.16lf\n", regraDosTrapeziosComposta(x0, xn, h));

    return 0;
}

double regraDosTrapeziosComposta(double x0, double xn, double h) 
{
    double integral = 0.0;
    double i, aux = Abs(F(x0) - RES);
    int iteracao = 0;
    
    printf("iterações\t\ti\t\t\t       F(xi)\t\t\t    ci (peso)\t\t    ci * f(xi)\t\t\t  Erro\n");
    printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\t\t%.6lf\n", iteracao++, x0, F(x0), 1, F(x0), aux);

    i = x0 + h;

    do {
        integral += (2.0*F(i));
        aux = Abs(calculo(x0, xn, h, integral) - RES);
        printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\t\t%.6lf\n", iteracao++, i, F(i), 2, (2*F(i)), aux);

        i += h;
    } while(aux > DEC);

    integral = calculo(x0, xn, h, integral);
    aux = Abs(integral - RES);
    printf("    %d\t\t    %lf\t\t\t%.16lf\t\t\t%d\t\t%.16lf\t\t%.6lf\n", iteracao, xn, F(xn), 1, F(xn), aux);

    return integral;
}

double calculo(double x0, double xn, double h, double integral) {
    integral += F(x0) + F(xn);
    integral = integral * (h/2);

    return integral;
}

double Abs(double x) {
    if(x > 0) {
        return x;
    }
    else {
        return x * (-1);
    }
}