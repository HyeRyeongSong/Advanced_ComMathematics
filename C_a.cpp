//
// Created by HyeRyeongSong on 2017. 10. 12..
//

#include <iostream>
#include <cmath>

using namespace std;

double Function(double dValue);

int main()
{
    int i = 0;
    double dX_previous = -10;
    double dX = -9.8;
    double dX_next = 0;
    double dfX_previous = 0;
    double dfX = 0;
    double dfX_next = 0;

    printf("   %-8s%-8s%-8s%-8s  %-10s %s\n", "N" ,"X_n-1", "X_n", "X_n+1", "f(X_n+1)", "(X_n+1)-(X_n)");


    while(true)
    {
        dfX_previous = Function(dX_previous);
        dfX = Function(dX);
        dX_next = dX - dfX * ((dX - dX_previous) / (dfX - dfX_previous));
        dfX_next = Function(dX_next);

        printf("   %-3d %3.5f, %3.5f, %3.5f, %3.5f, %3.5f\n", i++, dX_previous, dX, dX_next, dfX_next, dX_next-dX);

        if(abs(dX_next-dX) < 0.00001)
        {
            break;
        }
        dX_previous = dX;
        dX = dX_next;
    }

    return 0;
}

double Function(double dValue)
{
    return (pow(dValue, 3) -2 * pow(dValue,2) +1);
}


