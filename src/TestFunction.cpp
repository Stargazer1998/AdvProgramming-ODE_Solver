#include<iostream>
#include<array>
#include<vector>
#include<cmath>


void Test_Exp(std::vector<std::vector<double>>& app_sol,
              std::vector<double>& t
              )
{
    double error=0;
    size_t count = 0;
    //initialize the error !
    for(auto& row:app_sol){
        for(auto& elem:row){
            if(std::abs(elem - std::exp( -t[count] ) )  > error)
                error = std::abs(elem - std::exp( -t[count] ));
        }
        count++;
    }

    //0.0001 --> taken as a trashold value, which is purely depends on the application,
    //user may change it !
    if(error > 0.001){
        std::cout<<"Desired trashold can not be achived with the given input :(\nIt seems that there is a wrong with your time steps, try to deacrese it ! \nobtained error:"<<error<<"\n";
    }

    else
    {
        std::cout<<"Good news, you reached desired error trashold, it seems that you're going well ! \nobtained error:"<<error<<"\n";

    }

}
