//Created by HyeRyeongSong on 2017. 11. 16..

#include<iostream>
#include<cmath>

using namespace std;

class D_2
{
private:
    double dArr[3][3];
    double dD[3];
    double dPreX[3];
    double dX[3];
    double dEA[3];
    double dMaxEA;
public:

    D_2()
    {
        for(int i=0; i<3; ++i)
        {
            dD[i] = 0;
            dX[i] = 0;
            dEA[i] = 0;
        }

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

    }

    void Calculate_x1()
    {
        dX[0] = (dD[0] - dArr[0][1]*dX[1] - dArr[0][2]*dX[2]) / dArr[0][0];
    }

    void Calculate_x2()
    {
        dX[1] = (dD[1] - dArr[1][0]*dX[0] - dArr[1][2]*dX[2]) / dArr[1][1];
    }

    void Calculate_x3()
    {
        dX[2] = (dD[2] - dArr[2][0]*dX[0] - dArr[2][1]*dX[1]) / dArr[2][2];
    }

    void CalculateEA_1()
    {
        dEA[0] = fabs(((dX[0] - dPreX[0]) / dX[0]) * 100);
    }

    void CalculateEA_2()
    {
        dEA[1] = fabs(((dX[1] - dPreX[1]) / dX[1]) * 100);
    }

    void CalculateEA_3()
    {
        dEA[2] = fabs(((dX[2] - dPreX[2]) / dX[2]) * 100);
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

        printf("value       ea           Max ea\n\n");

        cout << "Iteration 0" << endl;

        for(int i=0; i<3; ++i)
        {
            printf("%-3.5f \n", dX[i]);
        }

        cout << endl;

        while(dMaxEA > 5)
        {
            cout << "Iteration " << iIteration++ << endl;
            dPreX[0] = dX[0];
            Calculate_x1();
            CalculateEA_1();
            printf("%3.5f       %3.5f\n", dX[0], dEA[0]);

            dPreX[1] = dX[1];
            Calculate_x2();
            CalculateEA_2();
            printf("%3.5f       %3.5f\n", dX[1], dEA[1]);

            dPreX[2] = dX[2];
            Calculate_x3();
            CalculateEA_3();
            dMax_EA();
            printf("%3.5f       %3.5f       %3.5f\n\n", dX[2], dEA[2], dMaxEA);
        }
    }

};

int main()
{
    D_2 d3;

    d3.Mange();

    return 0;
}

