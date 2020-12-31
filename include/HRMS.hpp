#ifndef HRMS_hpp
#define HRMS_hpp

#include <employee.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class hrms
{
    public:
    void read_from_file_workers();
    void read_from_file_salary();
    void add_new_worker(employee worker);
    void print_workers();
    void new_map();
    void print_map();
    void changeSalary(string employeeId, double salary);
    void add_salary(employee employee, string departmentId, double salary);
    void print_salary();
    void print_sorted_salary();
    void add(employee employee, std::string departmentid, double sal);
    void print_depart(string departmentid);

    private:
    vector <employee> workers;
    map <string,vector<string>> map_workers;
    vector <pair<string,double>>salary; 
};

#endif