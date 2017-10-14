//
// Created by HyeRyeongSong on 2017. 10. 12..
//

#include <iostream>
#include <cmath>

using namespace std;

double Function(double dValue);

double IntegralFunction(double dValue);

int main()
{
    int i = 0;
    double dX = 3.8;
    double dfX = 0;
    double df_prime_X = 0;
    double dX_next = 0;

    printf("   %-8s%-8s%-8s%-8s  %-10s\n", "N" ,"X_n", "f(X_n)", "f'(X_n)", "X_n+1");


    while(true)
    {
        dfX = Function(dX);
        df_prime_X = IntegralFunction(dX);
        dX_next = dX - (dfX / df_prime_X);

        printf("   %-3d %3.5f, %3.5f, %3.5f, %3.5f\n", i++, dX, dfX, df_prime_X, dX_next);

        if(abs(dX_next-dX) < 0.00005)
        {
            break;
        }
        dX = dX_next;
    }

    return 0;
}

double Function(double dValue)
{
    return (0.6*pow(dValue,4)-7.533333*pow(dValue,3)+29.9*pow(dValue, 2)-37.966667*dValue+5);
}

double IntegralFunction(double dValue)
{
    return (0.6*4*pow(dValue,3)-7.533333*3*pow(dValue,2)+29.9*2*pow(dValue, 1)-37.966667);
}


