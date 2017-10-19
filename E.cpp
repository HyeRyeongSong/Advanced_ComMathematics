//
// Created by HyeRyeongSong on 2017. 10. 19..
//

#include<iostream>

using namespace std;

double SearchDeterminant(double dArray[][4]);
void SearchByCramer(double dArray[][4], double dDeterminant, double* dAnswer);

int main()
{
    double dArray[3][4];
    double * dAnswer = new double[3];
    double dDeterminant;
    for(int i=0; i<3; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<4; ++j)
        {
            cin >> dArray[i][j];
        }
    }
    
    dDeterminant = SearchDeterminant(dArray);
    //determinant가 zero이면 error message 출력하고 끝내야 함
    if(dDeterminant == 0) //-69
    {
        cout << "The determinant is zero.\nThus, there is no solution\n";
        return 0;
    }
    else
    {
        SearchByCramer(dArray, dDeterminant, dAnswer);
    }

    cout << "det(A) = " << dDeterminant << endl;

    for(int i=0; i<3; ++i)
    {
        cout << "x" << i+1 <<" = " << dAnswer[i] <<endl;
    }

    return 0;
}

double SearchDeterminant(double dArray[][4])
{
    double A[3];
    double dDeterminant;
    A[0] = dArray[1][1] * dArray[2][2] - dArray[1][2] * dArray[2][1];
    A[1] = dArray[1][0] * dArray[2][2] - dArray[1][2] * dArray[2][0];
    A[2] = dArray[1][0] * dArray[2][1] - dArray[1][1] * dArray[2][0];
    dDeterminant = dArray[0][0] * A[0] - dArray[0][1] * A[1] + dArray[0][2] * A[2];
    return dDeterminant;
}

void SearchByCramer(double dArray[][4], double dDeterminant, double* dAnswer)
{
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            swap(dArray[j][i], dArray[j][3]);
        }

        dAnswer[i] = SearchDeterminant(dArray) / dDeterminant;

        for(int j=0; j<3; ++j)
        {
            swap(dArray[j][i], dArray[j][3]);
        }
    }
}

