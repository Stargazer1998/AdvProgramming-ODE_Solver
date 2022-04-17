#ifndef HEUN_H
#define HEUN_H

#include"ExpSolvers.h"
#include<vector>
#include"MatrixOperations.h"




class Heun : public ExpSolvers
{
private:
    std::vector<double> _y_0;
    std::vector<double> _t;
public:
    Heun( std::vector<double>& y_0,  std::vector<double>& t);
    std::vector<std::vector<double>> Solve() override;
};


#endif
