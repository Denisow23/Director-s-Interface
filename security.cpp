//
// Created by Admin on 10.11.2022.
//

#include "security.h"

SpecialMeans security::getSpecialMeans() const {
    return specialMeans;
}

security::security(const string &name, const string &fam, const string &patronymic,
                   SpecialMeans specialMeans) : Employee(0, name, "Secure", fam, patronymic), specialMeans(specialMeans) {}

void security::setSpecialMeans(SpecialMeans specialMeans) {
    security::specialMeans = specialMeans;
}
