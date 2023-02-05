//
// Created by Admin on 10.11.2022.
//

#ifndef LAB5_DIRECTOR_H
#define LAB5_DIRECTOR_H

#include <iostream>
#include "string"
#include "unordered_map"
#include "Employee.h"
#include "security.h"
#include "admin.h"
using namespace std;

class Director : public Employee{
private:
    unordered_map <string, Employee> employees;
    unordered_map <string, admin> admins;
    unordered_map <string, security> securities;

public:
    void securityAcceptance(string name, security sec){
        securities.insert(make_pair(name, sec));
    }

    void adminAcceptance(string name, admin adm){
        admins.insert(make_pair(name, adm));
    }


    void dismissalOfAdmin(string name){
        unordered_map<string, admin>::iterator adm;
        adm = admins.find(name);
        if (adm == admins.end()){
            cout << "Сотрудник не найден!" << endl;
            return;
        }
        admins.erase(adm);
    }

    void dismissalOfSecure(string name){
        unordered_map<string, security>::iterator secure;
        secure = securities.find(name);
        if (secure == securities.end()){
            cout << "Сотрудник не найден!" << endl;
            return;
        }
        securities.erase(secure);
    }


    security& findSecure(string name){
        unordered_map<string, security>::iterator sec;
        sec = securities.find(name);
        if (sec == securities.end()){
            cout << "Сотрудник не найден!" << endl;
            security adm1 = security("null", "null", "null", SHOTGUN);
            return adm1;
           // return NULL;
        }
        return sec->second;
    }

    admin& findAdmin(string name){
        unordered_map<string, admin>::iterator adm;
        adm = admins.find(name);
        if (adm == admins.end()){
            cout << "Сотрудник не найден!" << endl;
            admin adm1 = admin("null", "null", "null");
            return adm1;

        }

        return adm->second;
    }


    void listInfo(){
        cout << "ФИО: " << name << " " << fam << " " << patronymic << ";" << endl;
        cout << "Должность: директор;" << endl;
        cout << "Сотрудники в подчинении:" << endl;
        for(auto employee: employees){
            cout << "ФИО: " <<  employee.first << " - Должность: " << employee.second.getJobTitle() <<
            " - Зарплата: " << employee.second.getSalary() << endl;
        }
    }

    const unordered_map<string, Employee> &getEmployees() const {
        return employees;
    }



    Director(const string &name, const string &fam, const string &patronymic);

    const unordered_map<string, admin> &getAdmins() const {
        return admins;
    }

    const unordered_map<string, security> &getSecurities() const {
        return securities;
    }


};


#endif //LAB5_DIRECTOR_H
