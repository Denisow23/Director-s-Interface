//
// Created by Admin on 10.11.2022.
//

#ifndef LAB5_ACCOUNTANT_H
#define LAB5_ACCOUNTANT_H
#include "string"
#include "unordered_map"
#include "Employee.h"
#include "security.h"
#include "Director.h"
#include "admin.h"
#include <iostream>
using namespace std;

class accountant: public Employee{
private:
    unordered_map <string, double> salaryOfEmployees;
public:
    void setSalaryOfDirector(Director dir){
        unordered_map<string, double>::iterator job;
        job = salaryOfEmployees.find("Director");
        int count;
        cout << "Сколько часов отработал сотрудник?" << endl;
        cin >> count;
        dir.setSalary((double)(job->second * count));
    }

    void setSalaryOfEmployees(int a, double bet){
        switch (a) {
            case 1: {
                unordered_map<string, double>::iterator employee;
                employee = salaryOfEmployees.find("Security");
                if (employee != salaryOfEmployees.end()){
                    cout << "Должность уже есть в списке!" << endl;
                    cout << "Поменять ставку? Y - да, N - нет" << endl;
                    char vibor;
                    cin >> vibor;
                    if (vibor == 'Y' || vibor == 'y'){
                        salaryOfEmployees.erase(employee);
                        salaryOfEmployees.insert(make_pair("Security", bet));
                        break;
                    }
                    else break;
                }
                salaryOfEmployees.insert(make_pair("Security", bet));
                break;
            }
            case 2: {
                unordered_map<string, double>::iterator employee;
                employee = salaryOfEmployees.find("Accountant");
                if (employee != salaryOfEmployees.end()){
                    cout << "Должность уже есть в списке!" << endl;
                    cout << "Поменять ставку? Y - да, N - нет" << endl;
                    char vibor;
                    cin >> vibor;
                    if (vibor == 'Y' || vibor == 'y'){
                        salaryOfEmployees.erase(employee);
                        salaryOfEmployees.insert(make_pair("Accountant", bet));
                        break;
                    }
                    else break;
                }
                salaryOfEmployees.insert(make_pair("Accountant", bet));
                break;
            }
            case 3: {
                unordered_map<string, double>::iterator employee;
                employee = salaryOfEmployees.find("Admin");
                if (employee != salaryOfEmployees.end()){
                    cout << "Должность уже есть в списке!" << endl;
                    cout << "Поменять ставку? Y - да, N - нет" << endl;
                    char vibor;
                    cin >> vibor;
                    if (vibor == 'Y' || vibor == 'y'){
                        salaryOfEmployees.erase(employee);
                        salaryOfEmployees.insert(make_pair("Admin", bet));
                        break;
                    }
                    else break;
                }
                salaryOfEmployees.insert(make_pair("Admin", bet));
                break;
            }
            case 4: {
                unordered_map<string, double>::iterator emloyee;
                emloyee = salaryOfEmployees.find("Director");
                if (emloyee != salaryOfEmployees.end()){
                    cout << "Должность уже есть в списке!" << endl;
                    cout << "Поменять ставку? Y - да, N - нет" << endl;
                    char vibor;
                    cin >> vibor;
                    if (vibor == 'Y' || vibor == 'y'){
                        salaryOfEmployees.erase(emloyee);
                        salaryOfEmployees.insert(make_pair("Director", bet));
                        break;
                    }
                    else break;
                }
                salaryOfEmployees.insert(make_pair("Director", bet));
                break;
            }
        }
    }

    void setSalaryOfSecurity(security& sec){
        unordered_map<string, double>::iterator job;
        job = salaryOfEmployees.find("Security");
        if (job == salaryOfEmployees.end()){
            cout << "Ставка для сотрудника не установлена. Установить?" << endl;
            cout << "Поменять ставку? Y - да, N - нет" << endl;
            char vibor;
            cin >> vibor;
            if (vibor == 'Y' || vibor == 'y'){
                cout << "Введите ставку:" << endl;
                double bet;
                cin >> bet;
                salaryOfEmployees.insert(make_pair("Security", bet));
            }
            else return;
        }
        int count;
        cout << "Сколько часов отработал сотрудник?" << endl;
        cin >> count;
        sec.setSalary((double)job->second * count);
    }

    void setSalaryOfAdmin(admin& adm){
        unordered_map<string, double>::iterator job;
        job = salaryOfEmployees.find("Admin");
        if (job == salaryOfEmployees.end()){
            cout << "Ставка для сотрудника не установлена. Установить?" << endl;
            cout << "Поменять ставку? Y - да, N - нет" << endl;
            char vibor;
            cin >> vibor;
            if (vibor == 'Y' || vibor == 'y'){
                cout << "Введите ставку:" << endl;
                double bet;
                cin >> bet;
                salaryOfEmployees.insert(make_pair("Admin", bet));
                job = salaryOfEmployees.find("Admin");
            }
            else return;
        }
        int count;
        cout << "Сколько часов отработал сотрудник?" << endl;
        cin >> count;
        adm.setSalary((double)job->second * count);
    }

    void setSalaryOfAccountant(){
        unordered_map<string, double>::iterator job;
        job = salaryOfEmployees.find("Accountant");
        if (job == salaryOfEmployees.end()){
            cout << "Ставка для сотрудника не установлена. Установить?" << endl;
            cout << "Поменять ставку? Y - да, N - нет" << endl;
            char vibor;
            cin >> vibor;
            if (vibor == 'Y' || vibor == 'y'){
                cout << "Введите ставку:" << endl;
                double bet;
                cin >> bet;
                salaryOfEmployees.insert(make_pair("Accountant", bet));
            }
            else return;
        }
        int count;
        cout << "Сколько часов отработал сотрудник?" << endl;
        cin >> count;
        this->setSalary((double)job->second * count);
    }



    void listInfo() override {
        cout << "ФИО: " << name << " " << fam << " " << patronymic << ";" << endl;
        cout << "Должность: Бухгалтер;" << endl;
        cout << "Ставки сотрудников:" << endl;
        for(auto employee: salaryOfEmployees){
            cout << "Сотрудник: " <<  employee.first << " - Ставка: " << employee.second << endl;
        }
    }
    accountant(const string &name, const string &fam, const string &patronymic);

    const unordered_map<string, double> &getSalaryOfEmployees() const;

    void setSalaryOfEmployees(const unordered_map<string, double> &salaryOfEmployees);

};

#endif //LAB5_ACCOUNTANT_H
