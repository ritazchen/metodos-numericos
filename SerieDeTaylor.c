/*
Métodos Numéricos - Soluções Numéricas de EDOs
Método da Série de Taylor

(Não sei se está feito da forma correta, esse caso apenas implementei com duas derivadas e de acordo com o slide)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F1(x,y) (x-y)/x //y' = f(x,y) primeira derivada
#define F2(x,y) y/(pow(x,2)) //y'' segunda derivada
#define DERIVADAS 2
//(...) + defines caso queira e tenha possibilidade de calcular mais derivadas

//#define EXATO(x,y)  //função exata (nem sempre vamos ter essa formula)

double serieTaylor(double x0, double xn, double y0, double h);
double Abs(double x);
double erroAbs(double resultadoExato, double integralEncontrada);
int fat(int n);
double escolheFuncao(int iteracao, double x, double y);

int main(int argc, char* argv[])
{
    //double x0 = 2, xn = 2.1, y0 = 2, h = 0.1, yn;
    
    printf("Informe o x0, y0, xn e h: ");
    double x0, xn, y0, h, yn;
    scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);
    
    printf("\nParametros: x0 = %lf\ty0 = %lf\t\txn = %lf\t\th = %lf\n\n", x0, y0, xn, h);

    yn = serieTaylor(x0,xn,y0,h);
    printf("\n\n-> Para x=%.2lf, a solução y eh %.16lf\n", xn, yn);
    
    //printf("\t\t\t\t\t-> Erro absoluto (EA) = %.16lf\n", erroAbs(yn, EXATO(xn,yn)));

    return 0;
}

double serieTaylor(double x0, double xn, double y0, double h)
{

    double i, y = y0, x = x0, p1, p2;
    int iteracao = 1;

    printf("y = %.4lf ", y);
    for(x = x0 + h; iteracao <= DERIVADAS; x = x + h) {
        //printf("iteracao = %d\ty = %lf\tpow = %lf\tescolheFunc = %lf\tfat = %d\n\n", iteracao, y, pow(h,iteracao), escolheFuncao(iteracao, x0, y), fat(iteracao));
        p1 = pow(h,iteracao) / fat(iteracao);
        p2 = escolheFuncao(iteracao, x0, y);
        printf("+ %.4lf*%.4lf ", p1, p2);
        y += (p1 * p2);
        iteracao++;
    }
    
    printf("= %.16lf ", y);

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

int fat(int n) {
    int i, fat = 1;

    for(i = n; i > 1; i--){
        fat *= i;
    }
    
    return fat;
}

double escolheFuncao(int iteracao, double x, double y) {
    //fazer mais cases caso tenha mais de 2 derivadas
    switch(iteracao) {
        case 1: //chama a funcao da primeira derivada
            return F1(x,y);
        case 2: //chama a funcao da segunda derivada
            return F2(x,y);
        default: 
            return 1;
    }
}