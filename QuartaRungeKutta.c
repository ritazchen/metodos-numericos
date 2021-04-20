/*
Métodos Numéricos - Soluções Numéricas de EDOs
Método de Runge-Kutta de 4a ordem
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x,y) -2*y //y' = f(x,y) //exemplo do slide
//#define F(x,y) ((-y) + x + 2) //questão 2
//#define F(x,y) ((pow(x,2)*y - 2)/x) //questão 3
//#define F(x,y) ((6*(pow(x,2))) - (1/(pow(x,2))) + 3) //questão 4
//#define F(x,y) -2*x*(pow(y,2)) //questão 5
//#define F(x,y) x * (sqrt((pow(x,2)) + 5)) //questão 6

#define EXATO(x,y) 1/exp(2*x) //função exata para o exemplo do slide (nem sempre vamos ter essa formula)
//#define EXATO(x,y) ((exp(x*(-1))) + x + 1) //funcao exata da questão 2
//#define EXATO(x,y) 1/((pow(x,2))+2) //funcao exata da questão 5
//#define EXATO(x,y) (1/3.0) * (pow((sqrt((pow(x,2)) + 5)),3)) - 1 //funcao exata da questão 6

double quartaOrdem(double x0, double xn, double y0, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);
double K1(double x, double y, double h);
double K2(double x, double y, double h);
double K3(double x, double y, double h);
double K4(double x, double y, double h);

int main(int argc, char* argv[])
{
    double x0 = 0, xn = 1, y0 = 1, h = 0.2, yn; //exemplo do slide
    //double x0 = 0, xn = 1, y0 = 2, h = 0.1, yn; //questão 1
    //double x0 = 0, xn = 1.50, y0 = 2, h = 0.1, yn; //questão 2
    //double x0 = 1, xn = 2, y0 = 1, h = 0.01, yn; //questão 3
    //double x0 = 10, xn = 16, y0 = 0, h = 0.00001, yn; //questão 4
    //double x0 = 0, xn = 1, y0 = 0.5, h = 0.001, yn; //questão 5
    //double x0 = 2, xn = 3, y0 = 8, h = 0.1, yn; //questão 6
    /*
    printf("Informe o x0, y0, xn e h: ");
    double x0, y0, xn, h, yn;
    scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);
    */
    printf("\nParametros: x0 = %lf\ty0 = %lf\t\txn = %lf\t\th = %lf\n\n", x0, y0, xn, h);

    yn = quartaOrdem(x0,xn,y0,h);
    printf("\n\t\t\t\t\t-> Para x=%.2lf, a solução y eh %.16lf\n", xn, yn);
    
    printf("\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(yn, EXATO(xn,yn)));

    return 0;
}

double quartaOrdem(double x0, double xn, double y0, double h)
{
    //FILE* f = fopen("dados_quarta.txt", "w");

    double i, y = y0, x = x0, X0 = x0;
    int iteracao = 0;

    printf("iterações\t  xi\t\t   yi\t\t   K1\t\t   K2\t\t   K3\t\t   K4\t\t   sol. exata\t\t\t      EA\n");
    printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), K3(x, y, h), K4(x, y, h), EXATO(x,y), 0.0);

    //printf("iterações\t  xi\t\t   yi\t\t   K1\t\t   K2\t\t   K3\t\t   K4\n");
    //printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), K3(x, y, h), K4(x, y, h));
    //fprintf(f, "%lf,%lf;", x, y);

    while(iteracao <= ((xn-X0)/h)) {
        x0 = x;
        y0 = y;
        x = x0 + h;
        y = y0 + ((h/6.0)*(K1(x0,y0,h) + (2*K2(x0,y0,h)) + (2*K3(x0,y0,h)) + K4(x0,y0,h)));
        //fprintf(f, "%lf,%lf;", x, y);
        printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.16lf\t\t%.16lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), K3(x,y,h), K4(x, y, h), EXATO(x,y), erroAbs(y, EXATO(x,y)));
        //printf("    %d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", iteracao++, x, y, K1(x,y,h), K2(x,y,h), K3(x,y,h), K4(x, y, h));
    }

    //fclose(f);
    return y;
}

double erroAbs(double resultadoExato, double integralEncontrada) {
    return Abs(resultadoExato - integralEncontrada);
}

double Abs(double x) {
    if(x >= 0) {
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
