#include"GetSolution.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>

void save_Sol(const std::vector<std::vector<double>>& Sol,const std::string& SolverName)
{
  std::ofstream SolutionFile;
  SolutionFile.open (SolverName+".txt");
   for(auto& row:Sol){
        for(auto& elem:row){
            SolutionFile<<elem<<" ";
        }
        SolutionFile<<"\n";
    }
  SolutionFile.close();
}

void print_Sol(std::vector<std::vector<double>>& Sol)
{
    for(auto& row:Sol){
        for(auto& elem:row){
            std::cout<<elem<<" ";
        }
        std::cout<<"\n";
    }

}

