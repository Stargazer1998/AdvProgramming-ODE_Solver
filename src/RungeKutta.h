#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H
#include<vector>
#include"ExpSolvers.h"


class RungeKutta : public ExpSolvers
{
private:
    std::vector<double> _y_0;
    std::vector<double> _t;
public:
    RungeKutta(std::vector<double>& y_0, std::vector<double>& t);
    std::vector<std::vector<double>> Solve() override;
};

#endif
