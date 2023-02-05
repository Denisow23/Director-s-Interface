//
// Created by Admin on 11.11.2022.
//

#include "Salary.h"

Salary::Salary(double salary) : salary(salary) {}

double Salary::getSalary() const {
    return salary;
}

void Salary::setSalary(double salary) {
    Salary::salary = salary;
}
