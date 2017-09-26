//
// Created by HyeRyeongSong on 2017. 9. 26..
//

#include <iostream>
#include <cmath>

using namespace std;

double Fuction(double dValue);

int main()
{
    double dA = 3.0;
    double dB = 4.0;
    double dfA = 0;
    double dfB = 0;
    double dC = 0;
    double dfC = 0;
    double dStepSize = 0;
    bool bIsA = true; //if Update is a=c --> true
    double dError = 0;

    printf("   %-8s%-8s%-8s%-9s%-8s%-8s%-8s%-9s\n", "a", "b", "f(a)", "f(b)", "c",
           "f(c)", "Update", "step size");


    while(true)
    {
        dfA = Fuction(dA);
        dfB = Fuction(dB);
        dC = ((dA * dfB) - (dB * dfA)) / (dfB - dfA);
        dfC = Fuction(dC);
        if(dfC < 0)
        {
            if(dfA < 0)
                bIsA = true;
            else
                bIsA = false;
        }
        else if(dfC > 0)
        {
            if(dfA > 0)
                bIsA = true;
            else
                bIsA = false;
        }

        printf("%3.5f,%3.5f,%3.5f,%3.5f,%3.5f, %3.5f", dA, dB, dfA, dfB, dC, dfC);

        if(bIsA)
        {
            dStepSize = abs(dA - dC);
            dA = dC;
            cout << "   a = c   ";
            printf("%3.5f\n", dStepSize);
            if(dStepSize < 0.001)
                break;
        }
        else
        {
            dStepSize = abs(dB - dC);
            dB = dC;
            cout << "   b = c   ";
            printf("%3.5f\n", dStepSize);
            if(dStepSize < 0.001)
                break;

        }
    }

    return 0;
}

double Fuction(double dValue)
{
    return (pow(M_E, -dValue) * ((3.2 * sin(dValue) - 0.5 * cos(dValue))));
}
