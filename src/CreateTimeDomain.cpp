#include<vector>
#include<iostream>
#include"CreateTimeDomain.h"

std::vector<double> create_timeDom(const double& t_end, const double& dt)
{
    const unsigned int  solSize = t_end / dt + 1;
    std::vector<double> timeDom(solSize,0.0);

        for(auto i=0;i<solSize-1; i++){
            timeDom[i+1] = timeDom[i] + dt;
        }

        if( std::abs(timeDom.back() - t_end) < 1e-10 ) return timeDom;
        throw "error";
}

