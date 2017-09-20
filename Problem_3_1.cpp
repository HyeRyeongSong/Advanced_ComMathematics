//
// Created by HyeRyeongSong on 2017. 9. 14..
//
#include <iostream>
#include <cmath>

using namespace std;

struct Term
{
    double coef;   // coefficient
    int exp; // exponent

    void Integral()
    {
        this->coef = (this->coef) * (this->exp);
        --(this->exp);
        if(this->exp < 0) {
            this->coef = 0;
            this->exp = 0;
        }
    }

};

double Factorial(double dNum);

double CalculateMono(Term term, double value);

double CalculatePoly(Term* terms, double value);

Term* IntegralPoly(Term* terms);


int main()
{
    Term terms[4] = {{25, 3}, {-6, 2}, {7, 1}, {-88, 0}};

    double true_Value = CalculatePoly(terms, 3);

    double Approximation = 0;

    double et;

    int j=0;

    for(j = 0; j<4; ++j)
    {
        Approximation += (CalculatePoly(terms, 1) * pow(3-1,j) / Factorial((double)j));
        et = fabs(true_Value - Approximation) / true_Value * 100;
        printf("j=%2d f(3)= %.3f et = %3.3f %% \n",j,Approximation,et);
        IntegralPoly(terms);
    }

    return 0;
}

double Factorial(double dNum)
{
    if(dNum == 0)
        return 1;
    for(double i=dNum-1; i>0; --i)
        dNum = dNum * i;
    return dNum;
}

double CalculateMono(Term term, double value)
{
    return term.coef * pow(value, term.exp);
}

double CalculatePoly(Term* terms, double value)
{
    double sum = 0;
    for(int i=0; i<4; ++i)
        sum+=CalculateMono(terms[i], value);
    return sum;
}

Term* IntegralPoly(Term* terms)
{
    for(int i=0; i<4; ++i)
        terms[i].Integral();
    return terms;
}