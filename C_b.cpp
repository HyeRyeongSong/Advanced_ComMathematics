//
// Created by HyeRyeongSong on 2017. 10. 12..
//

#include <iostream>
#include <cmath>

using namespace std;

double Function(double dValue);
void SecantMethod(double x0, double x1);

int main()
{
    SecantMethod(0.0, 1.8);
    SecantMethod(0.6, 2.2);
    SecantMethod(0.6, 1.8);
    SecantMethod(2.0, 2.6);
    SecantMethod(0.2, 1.2);
    SecantMethod(0.6, 1.2);
    SecantMethod(0.0, 2.2);

    return 0;
}

double Function(double dValue)
{
    return 3*dValue + sin(dValue) - pow(M_E, dValue);
}

void SecantMethod(double x0, double x1)
{
    int i = 0;
    double dX_previous = x0;
    double dX = x1;
    double dX_next = 0;
    double dfX_previous = 0;
    double dfX = 0;
    double dfX_next = 0;

    printf("  %-5s%-7s%-8s%-8s  %-10s %s\n", "N" ,"X_n-1", "X_n", "X_n+1", "f(X_n+1)", "(X_n+1)-(X_n)");


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

    cout << "The root of x = " << dX << endl;
    cout << "---------------------------------------------------------\n";
}



