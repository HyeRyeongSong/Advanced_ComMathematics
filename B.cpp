//
// Created by HyeRyeongSong on 2017. 9. 21..
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
    bool bIsA = true; //if Update is a=c --> true
    double dError = 0;

    while(true)
    {
        dfA = Fuction(dA);
        dfB = Fuction(dB);
        dC = (dA + dB) / 2;
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

        printf("a : %3.5f, b : %3.5f, f(a) : %3.5f, f(b) : %3.5f, c = (a+b)/2 : %3.5f, "
                       "f(c) : %3.5f ", dA, dB, dfA, dfB, dC, dfC);

        if(bIsA)
        {
            dA = dC;
            cout << "Update: a=c ";
        }
        else
        {
            dB = dC;
            cout << "Update: a=b ";
        }

        printf("new b - a: %3.5f\n", abs(dB - dA));

        if(abs(dB -dA) < 0.001)
            break;
    }

    return 0;
}

double Fuction(double dValue)
{
    return (pow(M_E, dValue) * ((3.2 * sin(dValue) - 0.5 * cos(dValue))));
}