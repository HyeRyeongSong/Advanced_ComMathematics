//Created by HyeRyeongSong on 2017. 11. 2..

#include<iostream>

using namespace std;

int main()
{
    double dArr[4][4];
    double dL[4][4] = {0};
    double f21=0, f31=0, f32=0, f41=0, f42=0, f43=0;
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            if(i==j)
                dL[i][j] = 1;
            else
                dL[i][j] = 0;
        }
    }
    for(int i=0; i<4; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<4; ++j)
        {
            cin >> dArr[i][j];
        }
    }
    f21 = dArr[1][0] / dArr[0][0];
    f31 = dArr[2][0] / dArr[0][0];
    f41 = dArr[3][0] / dArr[0][0];
    for(int i=0; i<4; ++i)
    {
        dArr[1][i] = dArr[1][i] - dArr[0][i] * f21;
        dArr[2][i] = dArr[2][i] - dArr[0][i] * f31;
        dArr[3][i] = dArr[3][i] - dArr[0][i] * f41;
    }
    f32 = dArr[2][1] / dArr[1][1];
    f42 = dArr[3][1] / dArr[1][1];
    for(int i=1; i<4; ++i)
    {
        dArr[2][i] = dArr[2][i] - dArr[1][i] * f32;
        dArr[3][i] = dArr[3][i] - dArr[1][i] * f42;
    }
    f43 = dArr[3][2] / dArr[2][2];
    for(int i=2; i<4; ++i)
    {
        dArr[3][i] = dArr[3][i] - dArr[2][i] * f43;
    }
    dL[1][0] = f21;
    dL[2][0] = f31;
    dL[2][1] = f32;
    dL[3][0] = f41;
    dL[3][1] = f42;
    dL[3][2] = f43;
    cout << "[L] = " <<endl;
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            printf("%.5f  ", dL[i][j]);
        }
        cout << endl;
    }
    cout << "[U] = " <<endl;
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            printf("%.5f  ", dArr[i][j]);
        }
        cout << endl;
    }
    return 0;
}