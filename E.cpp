//Created by HyeRyeongSong on 2017. 11. 16..

#include<iostream>
#include<cmath>

using namespace std;

class E
{
private:
    double dArr[2][2];
    double dX[2];
    double dResult[2];
    int iIteration;
    double dLambda;
public:

    E()
    {
        for(int i=0; i<2; ++i)
        {
            dResult[i] = 0;
        }
    }

    void InputVaribles()
    {
        for(int i=0; i<2; ++i)
        {
            cout << "Input varibles for matrix A's row number " << i+1 <<": ";
            for(int j=0; j<2; ++j)
            {
                cin >> dArr[i][j];
            }
        }

        cout << "Input varibles for initial X matrix: " ;

        for(int i=0; i<2; ++i)
        {
            cin >> dX[i];
        }

        cout << "Input the size of the iteration: ";
        cin >> iIteration;

    }

    void Calculate_row1()
    {
        dResult[0] = dArr[0][0] * dX[0] + dArr[0][1] * dX[1];
    }

    void Calculate_row2()
    {
        dResult[1] = dArr[1][0] * dX[0] + dArr[1][1] * dX[1];
    }

    void Mange()
    {
        InputVaribles();

        for(int i=0; i<iIteration; ++i)
        {
            Calculate_row1();
            Calculate_row2();
            dX[0] = dResult[0];
            dX[1] = dResult[1];
            cout << "Iteration " << i+1 << endl;
            printf("%3.5f\n%3.5f\n\n", dResult[0], dResult[1]);
        }

        dX[0] = dResult[0] / dResult[0];
        dX[1] = dResult[1] / dResult[0];

        Calculate_row1();
        Calculate_row2();

        dLambda = (dResult[0] * dX[0] + dResult[1] * dX[1]) / (dX[0]*dX[0] + dX[1]*dX[1]);

        cout << "dominant eigenvalue of matrix A: " << dLambda <<endl;
    }

};

int main()
{
    E e;

    e.Mange();

    return 0;
}

