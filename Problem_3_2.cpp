//
// Created by HyeRyeongSong on 2017. 9. 14..
//

#include <iostream>
#include <cmath>

using namespace std;

struct Term
{
    double coef;   // coefficient
    double exp; // exponent

    void Integral()
    {
        this->coef = (this->coef) * (this->exp);
        (this->exp)-=1;
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
    Term terms[5] = {{-0.1, 4}, {-0.15, 3}, {-0.5, 2}, {-0.25, 1}, {1.2, 0}};

    double true_Value = CalculatePoly(terms, 1);

    double Approximation = 0;

    double et;


    for(int j = 0; j<5; ++j)
    {
        Approximation += (CalculatePoly(terms, 0) * pow(1-0,j) / Factorial((double)j));
        et = fabs(true_Value - Approximation) / true_Value * 100;
        printf("j=%2d f(1)= %.3f et = %3.3f %% \n",j,Approximation,et);
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
    for(int i=0; i<5; ++i)
        sum+=CalculateMono(terms[i], value);
    return sum;
}

Term* IntegralPoly(Term* terms)
{
    for(int i=0; i<5; ++i)
        terms[i].Integral();
    return terms;
}