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
    
    double dYminusMean_square[n];
    double dSt=0;
    double dEquation_square[n];
    double dSr=0;

    double dR;

    cout << "Input variables for X: ";

    for(int i=0; i<n; ++i) {
        cin >> dX[i];
        dSumX += dX[i];
        dX_square[i] = pow(dX[i], 2);
        dSumX_square += dX_square[i];
    }

    cout << "Input variables for Y: ";

    for(int i=0; i<n; ++i) {
        cin >> dY[i];
        dSumY += dY[i];
        dXY[i] = dX[i] * dY[i];
        dSumXY += dXY[i];
    }

    dmeanX = dSumX / n;
    dmeanY = dSumY / n;
    
    dA1 = ((n * dSumXY) - (dSumX * dSumY)) / ((n * dSumX_square) - pow(dSumX, 2));
    dA0 = dmeanY - (dA1 * dmeanX);
    
    for(int i=0; i<n; ++i)
    {
        dYminusMean_square[i] = pow((dY[i] - dmeanY), 2);
        dSt += dYminusMean_square[i];

        dEquation_square[i] = pow((dY[i] - dA0 - (dA1 * dX[i])), 2);
        dSr += dEquation_square[i];
    }

    dR = sqrt(((dSt - dSr) / dSt));

    if(dA1 < 0)
        dR*=(-1);

    cout << "a0 = " << dA0 << endl;
    cout << "a1 = " << dA1 << endl;
    cout << "r = " << dR << endl;

    cout << endl << "thus, y = " << dA0 << " + " << dA1 << "x" << endl;

    return 0;
}


