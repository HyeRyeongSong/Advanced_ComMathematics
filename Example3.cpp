//
// Created by HyeRyeongSong on 2017. 9. 20..
//

#include <iostream>
#include <cmath>

using namespace std;

double Factorial(double dNum);

int main()
{
    double dApproximation = 0;
    double dAbsoluteError = 0;
    double dRelativeError = 0;
    double n;
    cout << "Input the value of n: ";
    cin >> n;
    dApproximation = sqrt(2*M_PI*n) * pow((n / M_E), n);
    dAbsoluteError = Factorial(n) - dApproximation;
    dRelativeError = dAbsoluteError / Factorial(n);
    printf("n = %.0f\nn! = %.0f\n", n, Factorial(n));
    printf("Stirling's approximation = %.6f\n", dApproximation);
    printf("Absolute error = %.6f\n", dAbsoluteError);
    printf("Relative Error = %.6f\n", dRelativeError);
    return 0;
}

double Factorial(double dNum)
{
    if(dNum == 0)
        return 1;
    for(double i=dNum-1; i>0; --i)
        dNum = dNum * i;
    return dNum;
}