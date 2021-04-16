#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) pow(x, 2)

double regraDosTrapeziosSimples(double x0, double x1, double h);

int main(int argc, char* argv[])
{
    double x0, x1;
    
    printf("Informe o x0, x1: ");
    scanf("%lf %lf", &x0, &x1);

    printf("Resultado da integral = %lf\n", regraDosTrapeziosSimples(x0, x1, (x1-x0)));

    return 0;
}

double regraDosTrapeziosSimples(double x0, double x1, double h) 
{   
    printf("Parametros:\nx0 = %lf\t\tx1 = %lf\t\th = %lf\n", x0, x1, h);
    printf("F(x0) = %lf\tF(x1) = %lf\th/2 = %lf\n", F(x0), F(x1), (h/2));
    return ( (F(x0) + F(x1)) * (h/2) );
}