//
// Created by HyeRyeongSong on 2017. 10. 4..
//

#include <iostream>
#include <cmath>

using namespace std;

double Fuction(double dValue);

int main()
{
    int i = 1;
    double dA = 2.0;
    double dB = 3.0;
    double dfA = 0;
    double dfB = 0;
    double dC = 0;
    double dfC = 0;
    double dStepSize = 0;
    bool bIsA = true; //if Update is a=c --> true

    printf("   %-8s%-8s%-8s%-8s%-9s%-8s%-8s\n", "N" ,"a", "b", "f(a)", "f(b)", "c",
           "f(c)");


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

        printf("   %-3d %3.5f,%3.5f,%3.5f,%3.5f,%3.5f, %3.5f\n", i++, dA, dB, dfA, dfB, dC, dfC);

        if(bIsA)
        {
            dStepSize = abs(dA - dC);
            dA = dC;
            if(dStepSize <= 0.0009)
                break;
        }
        else
        {
            dStepSize = abs(dB - dC);
            dB = dC;
            if(dStepSize <= 0.0009)
                break;

        }
    }

    return 0;
}

double Fuction(double dValue)
{
    return ((dValue * log10(dValue)) - 1);
}
