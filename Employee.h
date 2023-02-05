//
// Created by Admin on 11.11.2022.
//

#ifndef LAB5_EMPLOYEE_H
#define LAB5_EMPLOYEE_H
#include "string"
#include "Salary.h"
#include "FIO.h"

using namespace std;



class Employee : public Salary, public FIO{
    string jobTitle;
public:
    Employee(double salary, const string &name, const string &jobTitle, const string &fam, const string &patronymic);
    virtual void listInfo(){
        return;
    }
    const string getJobTitle() const {
        return jobTitle;
    }
};


#endif //LAB5_EMPLOYEE_H
