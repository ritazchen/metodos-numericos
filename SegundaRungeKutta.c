/*
Métodos Numéricos - Soluções Numéricas de EDOs
Método de Runge-Kutta de 2a ordem
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x,y) -2*y //y' = f(x,y)
//#define F(x,y) ((-y) + x + 2) //questão 2 
//#define F(x,y) ((6*(pow(x,2))) - (1/(pow(x,2))) + 3) //questão 4
#define F(x,y) x * (sqrt((pow(x,2)) + 5)) //questão 6

//#define EXATO(x,y) 1/exp(2*x) //função exata para o exemplo do slide (nem sempre vamos ter essa formula)
//#define EXATO(x,y) ((exp(-x)) + x + 1) //funcao exata da questão 2
#define EXATO(x,y) (1/3.0) * (pow((sqrt((pow(x,2)) + 5)),3)) - 1 //funcao exata da questão 6

double segundaOrdem(double x0, double xn, double y0, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);
double K1(double x, double y, double h);
double K2(double x, double y, double h);

int main(int argc, char* argv[])
{
    double x0 = 2, xn = 3, y0 = 8, h = .01, yn;
    /*
    printf("Informe o x0, y0, xn e h: ");
    double x0, y0, xn, h, yn;
    scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);
    */
    printf("\nParametros: x0 = %lf\ty0 = %lf\t\txn = %lf\t\th = %lf\n\n", x0, y0, xn, h);

    yn = segundaOrdem(x0,xn,y0,h);
    printf("\n\t\t\t\t\t-> Para x=%.2lf, a solução y eh %.16lf\n", xn, yn);
    
    printf("\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(yn, EXATO(xn,yn)));

    return 0;
}

double segundaOrdem(double x0, double xn, double y0, double h)
{
    //FILE* f = fopen("dados_segunda.txt", "w");

    double i, y = y0, x = x0;
    int iteracao = 0;

    //printf("iterações\t  xi\t\t   yi\t\t   K1\t\t   K2\t\t   sol. exata\t\t\t      EA\n");
    //printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), EXATO(x,y), 0.0);

    printf("iterações\t  xi\t\t   yi\t\t   K1\t\t   K2\n");
    printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h));
    //fprintf(f, "%lf,%lf;", x, y);

    for(x = x0 + h; iteracao <= ((xn-x0)/h); x = x + h) {
        y = y + K1(x, y, h) + K2(x, y, h);
        //fprintf(f, "%lf,%lf;", x, y);
        //printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), EXATO(x,y), erroAbs(y, EXATO(x,y)));
        printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h));
    }

    //fclose(f);
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
    return (F(x, y) * (h/2));
}

double K2(double x, double y, double h) {
  return (F(x + h, (y + (h * F(x,y))))) * (h/2);
}
