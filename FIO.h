//
// Created by Admin on 11.11.2022.
//

#ifndef LAB5_FIO_H
#define LAB5_FIO_H
#include "string"
using namespace std;

class FIO {
protected:
    string name, fam, patronymic;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getFam() const;

    void setFam(const string &fam);

    const string &getPatronymic() const;

    void setPatronymic(const string &patronymic);

    FIO(const string &name, const string &fam, const string &patronymic);

};


#endif //LAB5_FIO_H
