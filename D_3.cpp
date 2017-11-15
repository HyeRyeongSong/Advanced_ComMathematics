//Created by HyeRyeongSong on 2017. 11. 2..

#include<iostream>
#include<cmath>

using namespace std;

<<<<<<< HEAD
class D_3
{
private:
    double dArr[3][3];
    double dD[3];
    double dPreRelax[3];
    double dX[3];
    double dRelaxation[3];
    double dEA[3];
    double dLambda;
    double dMaxEA;
public:

    D_3()
    {
        for(int i=0; i<3; ++i)
        {
            dD[i] = 0;
            dPreRelax[i] = 0;
            dX[i] = 0;
            dRelaxation[i] = 0;
            dEA[i] = 0;
        }

        dLambda = 0;
        dMaxEA = 100;
    }

    void InputVaribles()
    {
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

        cout << "Input the Lambda Value: ";
        cin >> dLambda;
    }

    void Calculate_x1()
    {
        dX[0] = (dD[0] - dArr[0][1]*dRelaxation[1] - dArr[0][2]*dRelaxation[2]) / dArr[0][0];
    }

    void Calculate_x2()
    {
        dX[1] = (dD[1] - dArr[1][0]*dRelaxation[0] - dArr[1][2]*dRelaxation[2]) / dArr[1][1];
    }

    void Calculate_x3()
    {
        dX[2] = (dD[2] - dArr[2][0]*dRelaxation[0] - dArr[2][1]*dRelaxation[1]) / dArr[2][2];
    }


    void Relaxation_x1()
    {
        dRelaxation[0] = (dLambda*dX[0]) + ((1-dLambda)*dRelaxation[0]);
    }
    void Relaxation_x2()
    {
        dRelaxation[1] = (dLambda*dX[1]) + ((1-dLambda)*dRelaxation[1]);
    }
    void Relaxation_x3()
    {
        dRelaxation[2] = (dLambda*dX[2]) + ((1-dLambda)*dRelaxation[2]);
    }

    void CalculateEA_1()
    {
        dEA[0] = fabs(((dRelaxation[0] - dPreRelax[0]) / dRelaxation[0]) * 100);
    }

    void CalculateEA_2()
    {
        dEA[1] = fabs(((dRelaxation[1] - dPreRelax[1]) / dRelaxation[1]) * 100);
    }

    void CalculateEA_3()
    {
        dEA[2] = fabs(((dRelaxation[2] - dPreRelax[2]) / dRelaxation[2]) * 100);
    }

    void dMax_EA()
    {
        dMaxEA = max(dEA[0], dEA[1]);
        dMaxEA = max(dEA[2], dMaxEA);
    }

    void Mange()
    {
        int iIteration = 1;

        InputVaribles();

        printf("value     relaxation       ea           Max ea\n\n");

        cout << "Iteration 0" << endl;

        for(int i=0; i<3; ++i)
        {
            printf("%-3.5f \n", dX[i]);
        }

        cout << endl;

        while(dMaxEA > 5)
        {
            cout << "Iteration " << iIteration++ << endl;
            dPreRelax[0] = dRelaxation[0];
            Calculate_x1();
            Relaxation_x1();
            CalculateEA_1();
            printf("%3.5f    %-3.5f       %3.5f\n", dX[0], dRelaxation[0], dEA[0]);

            dPreRelax[1] = dRelaxation[1];
            Calculate_x2();
            Relaxation_x2();
            CalculateEA_2();
            printf("%3.5f    %-3.5f       %3.5f\n", dX[1], dRelaxation[1], dEA[1]);

            dPreRelax[2] = dRelaxation[2];
            Calculate_x3();
            Relaxation_x3();
            CalculateEA_3();
            dMax_EA();
            printf("%3.5f    %-3.5f       %3.5f       %3.5f\n\n", dX[2], dRelaxation[2], dEA[2], dMaxEA);
        }
    }

};

int main()
{
    D_3 d3;

    d3.Mange();

    return 0;
}

=======
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
>>>>>>> 4aa3b579c115ceb46ad73aef75772a9218449baf
