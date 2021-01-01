#include <employee.hpp>
#include <HRMS.hpp>

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class WrongOpenFile : public exception
{
    virtual const char *what() const throw()
    {
        return "Exeption2: Blad otwarcia pliku";
    }
};

/* Czytanie z pliku gotowych 10 pracowników */
void hrms::read_from_file_workers()
{
    fstream plik1;
    plik1.open("Workers.txt");
    if(plik1.good())
    {
        while(!plik1.eof())
        {
            string name, id, surname, depertment, position;
            getline(plik1, id);
            getline(plik1, name);
            getline(plik1, surname);
            getline(plik1, depertment);
            getline(plik1, position);
            workers.push_back(employee{id, name, surname, depertment, position});
        }
    }
    else
    {
        throw WrongOpenFile();
    }
    plik1.close();
}

/* Czytanie z pliku pensji */
void hrms::read_from_file_salary()
{
    fstream plik2;
    plik2.open("salary.txt");
    if(plik2.good())
    {
        while(!plik2.eof())
        {
            string ID;
            double sal;
            plik2>>ID;
            plik2>>sal;
            salary.push_back(make_pair(ID,sal));
        }
    }
    else
    {
        throw WrongOpenFile();
    }
    plik2.close();
}

/* Dodawanie nowego pracownika na koniec pliku */
void hrms::add_new_worker(employee worker) 
{
    //workers.push_back(worker);
    fstream plik3;
    fstream plik5;
    plik3.open("Workers.txt", std::ios::app);
    plik5.open("salary.txt", std::ios::app);
    if(plik3.good())
    {
        plik3 << endl;
        plik3 << worker.id << endl;
        plik3 << worker.name << endl;
        plik3 << worker.surname << endl;
        plik3 << worker.departmentId << endl;
        plik3 << worker.position;
    }
    else throw WrongOpenFile();
    if(plik5.good())
    {
        plik5 << endl;
        plik5 << worker.id;
    }
    else throw WrongOpenFile();
    plik5.close();
    plik3.close();
}

/* Drukowanie pracowników z konteneru (workers)*/
void hrms::print_workers()
{
    int number =1;
    cout <<left<<setw(6)<< "Lp"<<setw(10)<< "ID"<<setw(15)<<"Imie"<<setw(15)<<"Nazwisko"<<setw(15)<<"Department"<<setw(15)<<"Position"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    for(int i=0;i<workers.size();i++)
    {
        workers[i].print(number);
        number++;
    }
}

/* Tworzenie konteneru (map_workers) */
void hrms::new_map()
{
    for(int i=0;i<workers.size();i++)
    {
        map_workers[workers[i].departmentId].push_back(workers[i].id);
    }
}

/* Drukowanie konteneru (map_workers) */
void hrms::print_map()
{
    int how_many = map_workers.size();
    map<string, vector <string>>::iterator it = map_workers.begin();
    cout<<setw(10)<<"DEPARTMENT"<<setw(10)<<"ID"<<endl;
    cout<<"--------------------------------"<<endl;
    for(int i=0; i<how_many; i++)
    {
        string depart = it->first;
        for(int j=0; j <map_workers[it->first].size(); j++)
        {
            cout << setw(10)<<depart <<setw(10)<< map_workers[depart][j] << endl;
        }
        *it++;
    }
}

/* Dodawanie i drukowanie pracowników wraz z wynagrodzeniem */
void hrms::print_salary()
{
    int size_of_vector=salary.size();
    cout<<size_of_vector<<endl;
    cout <<left<<setw(6)<< "ID"<<setw(15)<<"Imie"<<setw(15)<<"Nazwisko"<<setw(15)<<"Department"<<setw(15)<<"Position"<<setw(15)<<"Pensja" <<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<size_of_vector;i++)
    {
        string actual_id=salary[i].first;
        int k;
        for(k=0; workers[k].id!=actual_id; ++k);
        
        cout <<left<<setw(6)<<actual_id<<setw(15)<<workers[k].name<<setw(15)<<workers[k].surname<<setw(15)<<workers[k].departmentId<<setw(15)<<workers[k].position<<setw(15)<<salary[i].second<<endl;
        cout<<"_______________________________________________________________________________________"<<endl;
    }
}

/* Sortowanie pracowników od najniższej pensji do najwyższej */
void hrms::print_sorted_salary()
{
    sort(salary.begin(), salary.end(), [](auto &left, auto &right) { return left.second < right.second; });
    print_salary();
}

/* Dodawanie nowego pracownika do kontenerów */
void hrms::add(employee employee, std::string departmentid, double sal)
{
    fstream plik5;
    plik5.open("salary.txt", std::ios::app);

    workers.push_back(employee);
    map_workers[workers[workers.size() - 1].departmentId].push_back(workers[workers.size() - 1].id);
    salary.push_back(make_pair(employee.id,sal));

    if(plik5.good())
    {
        plik5 << endl;
        plik5 << sal;
    }
    else throw WrongOpenFile();
    plik5.close();
}

/* Drukowanie pracownikow z danego departamentu */
void hrms::print_depart(string departmentid)
{
    int how_many = map_workers[departmentid].size();
    cout<<"Ilosc pracownikow w: "<<departmentid<<" = "<<how_many<<endl;
    cout<<setw(10)<<"DEPARTMENT"<<setw(10)<<"ID"<<endl;
    cout<<"___________________________________________"<<endl;
    for(int i=0; i<how_many; i++)
    {
        std::cout <<setw(10)<< departmentid <<setw(10)<< map_workers[departmentid][i] << '\n';
    }
}

/* Zmiana wynagrodzenia */
void hrms::changeSalary(string enmployeeId, double sal)
{
    int size_of_vector=salary.size();
    for(int i=0;i<size_of_vector;i++)
    {
        string actualid=salary[i].first;
        if(actualid==enmployeeId)
        {
            salary[i].second=sal;
        }
    }
}
