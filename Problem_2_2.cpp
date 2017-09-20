#include <iostream>
#include <cmath>

double Factorial(double dNum);

int main()
{
    double x = 0.3 * M_PI;
    double es = 0.5e-06;
    double ea = 100;

    //approximation
    double cos_Previous = 1.0;
    double cos_Current;

    //term counter
    int j = 1;

    printf("j=%2.0d cos(x)= %1.10f\n", j, cos_Previous);

    while(ea > es)
    {
        cos_Current = cos_Previous + (pow(-1,j) * pow(x,2*j) / Factorial(j*2));
        ea = fabs(cos_Current -cos_Previous) / cos_Current * 100;
        printf("j=%2d cos(x)= %1.10f ea = %1.1e \n",++j,cos_Current,ea);
        cos_Previous = cos_Current;
    }
    return 0;
}

double Factorial(double dNum)
{
    for(double i=dNum-1; i>0; --i)
        dNum = dNum * i;
    return dNum;
}