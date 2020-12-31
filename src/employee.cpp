#include <employee.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

std::string uppercase(std::string word)
{
    std::string wyraz = word;
     for(int i=0;i<=wyraz.length();i++)
     {
        if(wyraz[i]>=97 && wyraz[i]<=122)
        {
		    wyraz[i]=wyraz[i]-32;
        }
     }
    return wyraz;
}
employee::employee(std::string ID, std::string NAME, std::string SURNAME, std::string DEPARTMENT, std::string POSITION )
{
    id = uppercase(ID);
    name = uppercase(NAME);
    surname = uppercase(SURNAME);
    departmentId = uppercase(DEPARTMENT);
    position = uppercase(POSITION);
}
void employee::print(int lp)
{
    cout <<left<<setw(6)<<lp<<setw(10)<<id<<setw(15)<<name<<setw(15)<<surname<<setw(15)<<departmentId<<setw(15)<<position<<endl;
    cout<<"_____________________________________________________________________________"<<endl;
}