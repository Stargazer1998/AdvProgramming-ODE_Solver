#ifndef EXPSOLVERS_H
#define EXPSOLVERS_H

class ExpSolvers
{

public:

    virtual std::vector<std::vector<double>> Solve()=0;

    virtual ~ExpSolvers() = default;


};


#endif
