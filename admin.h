//
// Created by Admin on 10.11.2022.
//

#ifndef LAB5_ADMIN_H
#define LAB5_ADMIN_H

#include "Employee.h"
#include <iostream>
#include "unordered_map"
using namespace std;


class admin: public Employee{
private:
    unordered_map<string, int> equipments;
public:
    void addEquipment(string equipment){
        unordered_map<string, int>::iterator item;
        item = equipments.find(equipment);
        if (item != equipments.end()){
            cout << "���������� ��� � ������!" << endl;
            cout << "�������� ���? Y - ��, N - ���" << endl;
            char vibor;
            cin >> vibor;
            if (vibor == 'Y' || vibor == 'y'){
                    item->second +=1;
            }
            else return;
        } else equipments.insert(make_pair(equipment, 1));
    };

    void delEquipment(string equipment){
        unordered_map<string, int>::iterator item;
        item = equipments.find(equipment);
        if (item == equipments.end()){
            cout << "������� �� ������!" << endl;
            return;
        }else if (item->second > 1){
            item->second -= 1;
        } else {
            equipments.erase(equipment);
        }
    }

    void listInfo() override{
        cout << "���: " << name << " " << fam << " " << patronymic << ";" << endl;
        cout << "���������: ��������� �������������;" << endl;
        cout << "���������� ��� ���������:" << endl;
        for(auto item: equipments){
            cout << item.first << " - " << item.second << " ��." << endl;
        }
    }

    admin(const string &name, const string &fam, const string &patronymic);

    const unordered_map<string, int> &getEquipments() const;

    void setEquipments(const unordered_map<string, int> &equipments);
};


#endif //LAB5_ADMIN_H
