#ifndef employee_hpp
#define employee_hpp

#include <iostream>
#include <cstdlib>
#include <cstring>


class employee
{
    public:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentId;
    std::string position;
    void print(int lp);
    employee(std::string ID, std::string NAME, std::string SURNAME, std::string DEPARTMENT, std::string POSITION);
};

#endif