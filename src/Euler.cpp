#include<iostream>
#include<cmath>
#include<vector>
#include"Euler.h"
#include"RHS.h"
#include"GetSolution.h"

Euler::Euler(std::vector<double>& y_0, std::vector<double>& t)
:_y_0(y_0), _t(t)
{}

std::vector<std::vector<double>> Euler::Solve()
{

    const unsigned int  probDim = _y_0.size();
    const unsigned int  solSize = _t.size();
    std::vector<std::vector<double>> Sol(solSize, std::vector<double> (probDim,0) );
    Sol[0] = _y_0;
    std::vector<double> f(probDim,0);
    for(int i=0; i<solSize-1; i++)
    {
        f = fun(Sol[i]);
        for(int j=0; j<probDim; j++)
        {
                Sol[i+1][j] = Sol[i][j] + (_t[i+1] - _t[i])*f[j];
        }
    }
        return Sol;
}


