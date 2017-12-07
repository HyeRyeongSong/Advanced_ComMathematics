//Created by HyeRyeongSong on 2017. 11. 29..

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cout << "input the value of n: ";
    cin >> n;
    double dX[n];
    double dSumX=0;
    double dY[n];
    double dSumY=0;
    double dX_square[n];
    double dSumX_square=0;
    double dXY[n];
    double dSumXY=0;
    
    double dmeanX;
    double dmeanY;
    double dA0;
    double dA1;
    double a, b;

    cout << "Input variables for X: ";

    for(int i=0; i<n; ++i) {
        cin >> dX[i];
        dX[i] = log10(dX[i]);
        dSumX += dX[i];
        dX_square[i] = pow(dX[i], 2);
        dSumX_square += dX_square[i];
    }

    cout << "Input variables for Y: ";

    for(int i=0; i<n; ++i) {
        cin >> dY[i];
        dY[i] = log10(dY[i]);
        dSumY += dY[i];
        dXY[i] = dX[i] * dY[i];
        dSumXY += dXY[i];
    }

    dmeanX = dSumX / n;
    dmeanY = dSumY / n;
    
    dA1 = ((n * dSumXY) - (dSumX * dSumY)) / ((n * dSumX_square) - pow(dSumX, 2));
    dA0 = dmeanY - (dA1 * dmeanX);
    
    cout << "a0 = " << dA0 << endl;
    cout << "a1 = " << dA1 << endl;

    b = dA0;
    a = pow(10, dA0);

    cout << endl << "thus, y = " << a << "x^" << b<< endl;

    return 0;
}


