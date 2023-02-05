//
// Created by Admin on 10.11.2022.
//

#include "accountant.h"



const unordered_map<string, double> &accountant::getSalaryOfEmployees() const {
    return salaryOfEmployees;
}

void accountant::setSalaryOfEmployees(const unordered_map<string, double> &salaryOfEmployees) {
    accountant::salaryOfEmployees = salaryOfEmployees;
}

accountant::accountant(const string &name, const string &fam, const string &patronymic) : Employee(
        40000, name, "Accountant", fam, patronymic) {}




