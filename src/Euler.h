#ifndef EULER_H
#define EULER_H

#include <iostream>
#include "ExpSolvers.h"
#include <vector>
#include "RHS.h"

class Euler : public ExpSolvers
{
private:
    std::vector<double> _y_0;
    std::vector<double> _t;
public:

    Euler(std::vector<double>& y_0, std::vector<double>& t);
    std::vector<std::vector<double>> Solve() override;
};

#endif

