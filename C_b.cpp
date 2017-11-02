//Created by HyeRyeongSong on 2017. 11. 2..

#include<iostream>
using namespace std;
int main()
{
    double dArr[3][3];
    double dL[3][3] = {0};
    double f21=0, f31=0, f32 = 0;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            if(i==j)
                dL[i][j] = 1;
            else
                dL[i][j] = 0;
        }
    }
    for(int i=0; i<3; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<3; ++j)
        {
            cin >> dArr[i][j];
        }
    }
    f21 = dArr[1][0] / dArr[0][0];
    f31 = dArr[2][0] / dArr[0][0];
    for(int i=0; i<3; ++i)
    {
        dArr[1][i] = dArr[1][i] - dArr[0][i] * f21;
        dArr[2][i] = dArr[2][i] - dArr[0][i] * f31;
    }
    f32 = dArr[2][1] / dArr[1][1];
    for(int i=1; i<3; ++i)
    {
        dArr[2][i] = dArr[2][i] - dArr[1][i] * f32;
    }
    dL[1][0] = f21;
    dL[2][0] = f31;
    dL[2][1] = f32;
    cout << "[L] = " <<endl;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            printf("%.5f  ", dL[i][j]);
        }
        cout << endl;
    }
    cout << "[U] = " <<endl;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            printf("%.5f  ", dArr[i][j]);
        }
        cout << endl;
    }
    return 0;
}