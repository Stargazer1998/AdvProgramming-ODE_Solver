#include<iostream>
#include<cmath>
#include<vector>
#include<memory>
#include<fstream>
#include"ExpSolvers.h"
#include"Euler.h"
#include"Heun.h"
#include"RungeKutta.h"
#include"RHS.h"
#include"CreateTimeDomain.h"
#include"GetSolution.h"
#include"TestFunction.h"


int main(){
    double t_end;
    double dt;
    double input;
    std::vector<double> y0 = {};
    std::cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////\n       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Welcome to Explicit Solver ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n///////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
    std::cout<<"Have you already defined your RHS function in RHS.cpp file ?\n";




    std::cout<<"If you have done so, there are a few more parameters you need to set:\n*End Time\n*Time Step\n";
    std::cout<<"Enter the End Time:  ";
    std::cin>>t_end;
    std::cout<<"Enter the time step:  ";
    std::cin>>dt;

    std::vector<double> timeDomain;
    try { timeDomain = create_timeDom(t_end,dt); }
    catch (...) {std::cout<<"Inputs are not compatible ! Using the given inputs, it is not possible to reach exatcly the desired end time !"<<std::endl;}

    std::size_t probSize;
    double y;
    std::cout<<"Almost done! You need to define your initial condition(s) as well. In case you're working with higher order ODE initial conditions must be defined as array.Enter how many initial conditions your ODE need: ";

    std::cin>>probSize;
    for(int i = 1; i<=probSize; i++)
    {
        std::cout<<i<<". value: ";
        std::cin>>y;
        y0.push_back(y);
    }




    std::unique_ptr<ExpSolvers> s;
    std::vector<std::vector<double>> AppSolution;


    std::cout << "Please tell which solver you want to use: \n 1) Euler \n 2) Heun \n 3) Runge Kutta \n";
    int solver_num;
    std::cin>>solver_num;


    switch(solver_num){
        case (1):
        {
            s = std::make_unique<Euler>(y0,timeDomain);
            AppSolution = s->Solve();
            //test function provided in the code is specific to the example which is provided in the code. It cannot be used for other functions!
            Test_Exp(AppSolution, timeDomain); 
            save_Sol(AppSolution,"Euler");
            break;
        }




        case (2):
        {
                s = std::make_unique<Heun>(y0,timeDomain);
                AppSolution = s->Solve();
                Test_Exp(AppSolution, timeDomain);
                save_Sol(AppSolution,"Heun");
                break;

        }

        case (3):
        {
                s = std::make_unique<RungeKutta>(y0,timeDomain);
                AppSolution = s->Solve();
                Test_Exp(AppSolution, timeDomain);
                save_Sol(AppSolution,"RungeKutta");
                break;
        }

    }








}
