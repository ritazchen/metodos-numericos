/*
Métodos Numéricos - Soluções Numéricas de EDOs
Método de Euler
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x,y) -2*y //y' = f(x,y) //exemplo do slide
//#define F(x,y) ((-y) + x + 2) //questão 2
//#define F(x,y) ((pow(x,2)*y - 2)/x) //questão 3
//#define F(x,y) ((6*(pow(x,2))) - (1/(pow(x,2))) + 3) //questão 4
//#define F(x,y) -2*x*(pow(y,2)) //questão 5
#define F(x,y) x * (sqrt((pow(x,2)) + 5)) //questão 6

//#define EXATO(x,y) 1/exp(2*x) //função exata para o exemplo do slide (nem sempre vamos ter essa formula)
//#define EXATO(x,y) ((exp(-x)) + x + 1) //funcao exata da questão 2
//#define EXATO(x,y) 1/((pow(x,2))+2) //funcao exata da questão 5
#define EXATO(x,y) (1/3.0) * (pow((sqrt((pow(x,2)) + 5)),3)) - 1 //funcao exata da questão 6

double metodoDeEuler(double x0, double xn, double y0, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);

int main(int argc, char* argv[])
{
    double x0 = 2, xn = 3, y0 = 8, h = .01, yn;
    /*
    printf("Informe o x0, y0, xn e h: ");
    double x0, y0, xn, h, yn;
    scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);
    */
    printf("\nParametros: x0 = %lf\ty0 = %lf\t\txn = %lf\t\th = %lf\n\n", x0, y0, xn, h);

    yn = metodoDeEuler(x0,xn,y0,h);
    printf("\n\t\t\t\t\t-> Para x=%.2lf, a solução y eh %.16lf\n", xn, yn);
    
    printf("\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(yn, EXATO(xn,yn)));

    return 0;
}

double metodoDeEuler(double x0, double xn, double y0, double h)
{
    //FILE* f = fopen("dados_euler.txt", "w");

    double i, y = y0, x = x0;
    int iteracao = 0;

    //printf("iterações\t\txi\t\t   yi\t\ty' = f(x,y)\t\t   sol. exata\t\t\t\tEA\n");
    //printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x0, y0, F(x0,y0), EXATO(x0,y0), 0.0);
    
    printf("iterações\t\txi\t\t   yi\t\ty' = f(x,y)\n");
    printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\n", iteracao++, x, y, F(x,y));
    //fprintf(f, "%lf,%lf;", x, y);

    for(x = x0 + h; iteracao <= ((xn-x0)/h); x = x + h) {
        y = y + h*F(x,y);
        //fprintf(f, "%lf,%lf;", x, y);
        //printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, F(x,y), EXATO(x,y), erroAbs(y, EXATO(x,y)));
        printf("    %d\t\t     %.5lf\t\t%.5lf\t\t%.5lf\n", iteracao++, x, y, F(x,y));
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