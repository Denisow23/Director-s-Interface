//
// Created by Admin on 10.11.2022.
//

#ifndef LAB5_SECURITY_H
#define LAB5_SECURITY_H


#include "Employee.h"
#include <iostream>

enum SpecialMeans{
    TRUNCHEON,
    PISTOL,
    STUN_GUN,
    SHOTGUN
};

class security : public Employee{
private:
public:
    security(const string &name, const string &fam, const string &patronymic, SpecialMeans specialMeans);

    SpecialMeans getSpecialMeans() const;

    void setSpecialMeans(SpecialMeans specialMeans);

    void listInfo() override{
        cout << "���: " << name << " " << fam << " " << patronymic << ";" << endl;
        cout << "���������: ��������;" << endl;
        cout << "��������������:";
        if (this->getSpecialMeans() == TRUNCHEON){
            cout << "�������" << endl;
        } else if (this->getSpecialMeans() == PISTOL){
            cout << "��������" << endl;
        } else if (this->getSpecialMeans() == STUN_GUN) {
            cout << "������������" << endl;
        } else if (this->getSpecialMeans() == SHOTGUN) {
            cout << "�����" << endl;
        }
    }

private:
    SpecialMeans specialMeans;

};



#endif //LAB5_SECURITY_H
