#include<vector>

std::vector<double> operator+(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> res;
    for(int i=0; i<v1.size(); i++)
        res.push_back(v1[i] + v2[i]);
    return res;
}

std::vector<double> operator*(const double& d,const std::vector<double>& v1)
{
    std::vector<double> res;
    for(int i=0; i<v1.size(); i++)
        res.push_back(d*v1[i]);
    return res;
}
