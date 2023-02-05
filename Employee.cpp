//
// Created by Admin on 11.11.2022.
//

#include "Employee.h"

Employee::Employee(double salary, const string &name, const string &jobTitle, const string &fam, const string &patronymic) : Salary(salary),
                                                                                                     FIO(name, fam,
                                                                                                         patronymic) {this->jobTitle = jobTitle;}
