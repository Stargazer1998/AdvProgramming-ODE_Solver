#include<vector>
#include"RHS.h"

std::vector<double> fun(const std::vector<double>& x){
    std::vector<double> y={-x[0]
                          };

    return y;
}
