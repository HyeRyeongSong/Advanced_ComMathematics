//
// Created by HyeRyeongSong on 2017. 11. 2..
//
#include<iostream>

using namespace std;

int main()
{
    double dArr[2][2];
    double dL[2][2] = {0};
    double f21=0;

    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            if(i==j)
                dL[i][j] = 1;
            else
                dL[i][j] = 0;
        }
    }

    for(int i=0; i<2; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<2; ++j)
        {
            cin >> dArr[i][j];
        }
    }


    f21 = dArr[1][0] / dArr[0][0];

    for(int i=0; i<2; ++i)
    {
        dArr[1][i] = dArr[1][i] - dArr[0][i] * f21;
    }

    dL[1][0] = f21;

    cout << "[L] = " <<endl;

    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            cout << dL[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "[U] = " <<endl;

    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            cout << dArr[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}