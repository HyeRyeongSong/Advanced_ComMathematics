//Created by HyeRyeongSong on 2017. 11. 2..

#include<iostream>
#include<cmath>

using namespace std;

double Calculate_x1(double x2, double x3);
double Calculate_x2(double x1, double x3);
double Calculate_x3(double x1, double x2);

double Relaxation_x1(double dValue, double dLambda);
double Relaxation_x2(double dValue, double dLambda);
double Relaxation_x3(double dValue, double dLambda);


int main()
{
    double dArr[3][3];
    int iArr_Max[3] = {0};
    double dD[3] = {0};
    double dX[3] = {0};
    double dRelaxation[3] = {0};
    double dEA[3] = {0};
    double dMax_EA = 0;
    double dLambda = 0;

    for(int i=0; i<3; ++i)
    {
        cout << "Input varibles for matrix A's row number " << i+1 <<": ";
        for(int j=0; j<3; ++j)
        {
            cin >> dArr[i][j];
        }
    }

    cout << "Input varibles for D matrix: " ;

    for(int i=0; i<3; ++i)
    {
        cin >> dD[i];
    }

    for(int i=0; i<3; ++i)
    {
        if(fabs(dArr[i][0]) > fabs(dArr[i][1]) + fabs(dArr[i][2]))
            iArr_Max[0] = i;
        else if(fabs(dArr[i][1]) > fabs(dArr[i][0]) + fabs(dArr[i][2]))
            iArr_Max[1] = i;
        else if(fabs(dArr[i][2]) > fabs(dArr[i][0]) + fabs(dArr[i][1]))
            iArr_Max[2] = i;
    }

    for(int i=0; i<3; ++i)
    {
        //(0, 2) = (2, 0) 처럼 해야돼
        if(iArr_Max[i] != i)
        {
            for (int j = 0; j < 3; ++j) {
                //이 부분에서 swap이 중복되서 일어나는 문제를 해결해야 함!
                swap(dArr[iArr_Max[i]][j], dArr[i][j]);
            }
        }
    }

    for(int i=0; i<3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << dArr[i][j] << " ";
        cout << endl;
    }

    cout << "Input the Lambda Value: ";
    cin >> dLambda;

    while(dMax_EA < 5)
    {

    }

    return 0;
}

double Calculate_x1(double x2, double x3)
{

}
double Calculate_x2(double x1, double x3);
double Calculate_x3(double x1, double x2);

double Relaxation_x1(double dValue, double dLambda);
double Relaxation_x2(double dValue, double dLambda);
double Relaxation_x3(double dValue, double dLambda);
