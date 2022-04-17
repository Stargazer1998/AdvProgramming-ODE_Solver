#include<iostream>
#include<cmath>
#include<vector>
#include"RungeKutta.h"
#include"RHS.h"
#include"MatrixOperations.h"
#include"GetSolution.h"

RungeKutta::RungeKutta(std::vector<double>& y_0, std::vector<double>& t)
:_y_0(y_0), _t(t)
{}

std::vector<std::vector<double>> RungeKutta::Solve()
{
    const unsigned int probDim = _y_0.size();
    const unsigned int solSize = _t.size();
    std::vector<std::vector<double>> Sol(solSize,std::vector<double> (probDim,0));
    Sol[0] = _y_0;
    std::vector<double> f1(probDim,0);
    std::vector<double> f2(probDim,0);
    std::vector<double> f3(probDim,0);
    std::vector<double> f4(probDim,0);
    for(int i=0;i<solSize-1;i++)
    {
        f1 = fun(Sol[i]);
        f2 = fun(Sol[i] + 0.5*(_t[i+1]-_t[i])*f1);
        f3 = fun(Sol[i] + 0.5*(_t[i+1]-_t[i])*f2);
        f4 = fun(Sol[i] + (_t[i+1]-_t[i])*f3);
        for(int j=0;j<probDim;j++)
        {
            Sol[i+1][j] = Sol[i][j] + (_t[i+1] - _t[i])*(f1[j] + 2*f2[j] + 2*f3[j] + f4[j])/6;
        }

    }
    return Sol;
}

