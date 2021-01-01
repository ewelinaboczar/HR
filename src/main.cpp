#include <employee.hpp>
#include <HRMS.hpp>

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
 
int main()
{
    system("cls");
    bool p=true;
    hrms nowy;
    nowy.read_from_file_workers();
    nowy.read_from_file_salary();
    nowy.new_map();
    while(p)
    {
        try
        {
        cout<<"Wybierz:"<<endl;
        cout<<"0. Koniec"<<endl;
        cout<<"1. Drukowanie wszystkich pracownikow (test kontenera workers)"<<endl;
        cout<<"2. Drukowanie mapy pomiedzy pracownikami a ID departamentu (test kontenera map_workers)"<<endl;
        cout<<"3. Drukowanie pracownikow znajdujacych sie w zadanym departamencie (test metody print_depart)"<<endl;
        cout<<"4. Drukowanie zarobkow pracownikow wraz z ich ID (test metody print_salary)"<<endl;
        cout<<"5. Drukowanie posortowanych zarobkow wraz z danymi pracownikow (test metody print_sorted_salary)"<<endl;
        cout<<"6. Zmiana pensji wybranego pracownika (test metody changeSalary)"<<endl;
        cout<<"7. Dodawanie nowego pracownika wraz z jego wynagrodzeniem (test metody add)"<<endl;
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 0:
            {
                p=false;
                break;
            }
            case 1:
            {
                cout << "Drukowanie wszystkich pracownikow" <<endl;
                nowy.print_workers();
                break;
            }
            case 2:
            {
                cout << "Drukowanie mapy pomiedzy pracownikami a ID departamentu"<<endl;
                nowy.print_map();
                break;
            }
            case 3:
            {
                cout << "Podaj nazwe departamentu z ktorego pracownikow chcesz znalezc:" << endl;
                string dep;
                cin >> dep;
                nowy.print_depart(dep);
                break;
            }
            case 4:
            {
                cout << "Drukowanie zarobkow:" << endl;
                nowy.print_salary();
                break;
            }
            case 5:
            {
                cout << "Drukowanie posortowanych zarobkow pracownikow" << endl;
                nowy.print_sorted_salary();
                break;
            }
            case 6:
            {
                string new_id;
                double new_salary;
                cout << "Podaj ID pracownika ktoremu chcesz zmienic wynagrodzenie:" <<endl;
                cin >> new_id;
                cout << "Podaj nowe wynagrodzenie:" << endl;
                cin >> new_salary;
                nowy.changeSalary(new_id,new_salary);
                break;
            }
            case 7:
            {
                cout << "Dodawanie nowego pracownika" <<endl;
                double new_salary;
                string id,name,surname,depart,position;
                cout << "Podaj id" <<endl;
                cin >> id;
                cout << "Podaj imie" <<endl;
                cin >> name;
                cout << "Podaj nazwisko" <<endl;
                cin >> surname;
                cout << "Podaj ID departamentu" << endl;
                cin >> depart;
                cout << "Podaj pozycje" << endl;
                cin >> position;
                cout << "Podaj pensje" << endl;
                cin >> new_salary;
                employee add_worker(id, name, surname, depart, position);
                nowy.add(add_worker, depart, new_salary);
                nowy.add_new_worker(add_worker);
                break;
            }
            default:
            {
                cout << "Wybierz ponownie" <<endl;
                break;
            }
        }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}