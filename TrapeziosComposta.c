#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (1/x)*exp(x/2)

double regraDosTrapeziosComposta(double x0, double xn, double h);

int main(int argc, char* argv[])
{
    double x0, xn, numIntervalos, h;
    
    printf("Informe o x0, xn e o número de intervalos: ");
    scanf("%lf %lf %lf", &x0, &xn, &numIntervalos);
    h = ((xn-x0)/numIntervalos);

    printf("Parametros:\nx0 = %lf\t\txn = %lf\t\tnum = %lf\t\th = %lf\n\n", x0, xn, numIntervalos, h);

    printf("\nResultado da integral = %.15lf\n", regraDosTrapeziosComposta(x0, xn, h));

    return 0;
}

double regraDosTrapeziosComposta(double x0, double xn, double h) 
{
    double integral = 0.0;
    double i;

    for(i = (x0 + h); i < xn; i += h) {
        integral += F(i);
        printf("i = %lf\t\tF(%lf) = %lf\t\tIntegral = %lf\n", i, i, F(i), integral);
    }

    integral = 2.0*integral;    
    printf("\t\t\t\t\t\t\tIntegral * 2.0 = %lf\n", integral);

    integral += F(x0) + F(xn);
    printf("F(x0) = %lf\tF(xn) = %lf\t\tIntegral = %lf\n", F(x0), F(xn), integral);  
    
    return integral * (h/2);
}