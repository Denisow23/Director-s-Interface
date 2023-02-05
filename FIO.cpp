//
// Created by Admin on 11.11.2022.
//

#include "FIO.h"

FIO::FIO(const string &name, const string &fam, const string &patronymic) : name(name), fam(fam),
                                                                            patronymic(patronymic) {}

const string &FIO::getName() const {
    return name;
}

void FIO::setName(const string &name) {
    FIO::name = name;
}

const string &FIO::getFam() const {
    return fam;
}

void FIO::setFam(const string &fam) {
    FIO::fam = fam;
}

const string &FIO::getPatronymic() const {
    return patronymic;
}

void FIO::setPatronymic(const string &patronymic) {
    FIO::patronymic = patronymic;
}
