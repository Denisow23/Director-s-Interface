#include <iostream>
#include "accountant.h"
#include "Director.h"
#include "security.h"
#include "Salary.h"
#include "admin.h"
#include "windows.h"
using namespace std;

int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "Russian");
    std::system("chcp 1251");
    cout << "������������ ������ 5. ������� �.�. ������ �-17-21" << endl;
    string name, fam, patronymic;
    cout << "������������� ��� ��������:" << endl;
    cout << "���: ";
    cin >> name;
    cout << "�������: ";
    cin >> fam;
    cout << "��������: ";
    cin >> patronymic;
    cout << "����������� ������������: " << endl;
    Director director(name, fam, patronymic);
    director.listInfo();

    cout << "����������� ������ ����������:" << endl;
    cout << "���: ";
    cin >> name;
    cout << "�������: ";
    cin >> fam;
    cout << "��������: ";
    cin >> patronymic;
    cout << "����������� ������������: ";
    accountant Accountant(name, fam, patronymic);
    Accountant.listInfo();

    int vibor = 1;
    while (vibor == 1 || vibor == 2 || vibor == 3 || vibor == 4 || vibor == 5 || vibor == 6 || vibor == 7) {
        cout << "1 - ������� ����������; 2 - ������� ����������; 3 - ���� �������� ����������; "
                "4 - ����������� ������ �����������; 5 - ����� ���������� �� ��� � ���������; 6 - ��������� �������� ���������,"
                " ������������ �� ���������� ����������������; 7 - ����������� �������������� ������ ��� ������� ����� ����� ������ ��� ������" << endl;
        cout << "�������� ��������:" << endl;
            cin >> vibor;
        switch (vibor) {
            case 1: {
                cout << "������� ��� ����������" << endl;
                cin >> name;
                cout << "������� ������� ����������" << endl;
                cin >> fam;
                cout << "������� �������� ����������" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                cout << "�������� ��������� ����������:" << endl;
                cout << "1 - ��������� �������������, 2 - ��������" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2) )){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                if (choice == 1) {
                    admin Admin(name, fam, patronymic);
                    director.adminAcceptance(Fio, Admin);
                } else if (choice == 2) {
                    cout << "�������� ������� ���������" << endl;
                    cout << "1 - ��������, 2 - �����, 3 - �������, 4 - ������������" << endl;
                    int a;
                    while (!(cin >> a) && ((a != 1) && (a != 2) && (a != 3) && (a != 4))){
                        cout << "Input error!" << endl;
                        cin.clear();
                        fflush(stdin);
                    }
                    switch (a) {
                        case 1: {
                            security Security(name, fam, patronymic, SpecialMeans::PISTOL);
                            director.securityAcceptance(Fio, Security);
                            break;
                        }
                        case 2: {
                            security Security(name, fam, patronymic, SpecialMeans::SHOTGUN);
                            director.securityAcceptance(Fio, Security);
                            break;
                        }
                        case 3: {
                            security Security(name, fam, patronymic, SpecialMeans::TRUNCHEON);
                            director.securityAcceptance(Fio, Security);
                            break;
                        }
                        case 4: {
                            security Security(name, fam, patronymic, SpecialMeans::STUN_GUN);
                            director.securityAcceptance(Fio, Security);
                            break;
                        }
                    }
                } else {
                    cout << "������ �������� ��� ����������!" << endl;
                }
                break;
            }
            case 2: {
                cout << "������� ��� ����������" << endl;
                cin >> name;
                cout << "������� ������� ����������" << endl;
                cin >> fam;
                cout << "������� �������� ����������" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                cout << "�������� ��������� ����������:" << endl;
                cout << "1 - ��������� �������������, 2 - ��������" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2) )){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                if (choice == 1) {
                    director.dismissalOfAdmin(Fio);
                    cout << "��������� ������!" << endl;
                } else if (choice == 2) {
                    director.dismissalOfSecure(Fio);
                    cout << "��������� ������!" << endl;
                } else {
                    cout << "�������� ��� ����������!" << endl;
                }
                break;
            }
            case 3: {
                cout << "�������� �������� ������� ���������� ���������� ���������:" << endl;
                cout << "1 - ���������� ������ ��� ����������; 2 - ���������� �������� ����������� ����������  ��� ������� ����� ����� ������ ��� ������" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2) )){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                switch (choice) {
                    case 1: {
                        cout << "������ ��� ������ ���������� ������: " << endl;
                        cout << "1 - ��������, 2 - ���������, 3 - ��������, 4 - ��������" << endl;
                        int a;
                        while (!(cin >> a) && ((a != 1) && (a != 2) && (a != 3) && (a != 4))){
                            cout << "Input error!" << endl;
                            cin.clear();
                            fflush(stdin);
                        }
                        cout << "������� ������:" << endl;
                        double bet;
                        while (!(cin >> bet) && ((bet < 0))){
                            cout << "Input error!" << endl;
                            cin.clear();
                            fflush(stdin);
                        }
                        Accountant.setSalaryOfEmployees(a, bet);
                        break;
                    }
                    case 2: {
                        cout << "�������� ������ ���������� ��������: " << endl;
                        cout << "1 - ��������, 2 - ��������, 3 - ���������, 4 - ��������" << endl;
                        int a;
                        while (!(cin >> a) && ((a != 1) && (a != 2) && (a != 3) && (a != 4))){
                            cout << "Input error!" << endl;
                            cin.clear();
                            fflush(stdin);
                        };
                        switch (a) {
                            case 1 : {
                                cout << "������� ��� ����������, �������� ���������� �������� ��������:" << endl;
                                cout << "������� ��� ����������" << endl;
                                cin >> name;
                                cout << "������� ������� ����������" << endl;
                                cin >> fam;
                                cout << "������� �������� ����������" << endl;
                                cin >> patronymic;
                                string Fio = name + fam + patronymic;
                                Accountant.setSalaryOfSecurity(director.findSecure(Fio));
                                break;
                            }
                            case 2 : {
                                cout << "������� ��� ����������, �������� ���������� �������� ��������:" << endl;
                                cout << "������� ��� ����������" << endl;
                                cin >> name;
                                cout << "������� ������� ����������" << endl;
                                cin >> fam;
                                cout << "������� �������� ����������" << endl;
                                cin >> patronymic;
                                string Fio = name + fam + patronymic;
                                Accountant.setSalaryOfAdmin(director.findAdmin(Fio));
                                break;
                            }
                            case 3: {
                                Accountant.setSalaryOfAccountant();
                                break;
                            }
                            case 4: {
                                Accountant.setSalaryOfDirector(director);
                                break;
                            }
                            default: break;
                        }
                        cout << "�������� ��������!" << endl;
                        break;
                    }
                }
                break;
            }
            case 4: {
                cout << "_____________________________" << endl;
                director.listInfo();
                cout << "_____________________________" << endl;
                Accountant.listInfo();
                cout << "_____________________________" << endl;
                cout << "������:" << endl;
                for (auto employee: director.getSecurities()) {
                    employee.second.listInfo();
                }
                cout << "_____________________________" << endl;
                cout << "��� ������:" << endl;
                for (auto employee: director.getAdmins()) {
                    employee.second.listInfo();
                }
                break;
            }
            case 5: {
                cout << "������� ��� ����������" << endl;
                cin >> name;
                cout << "������� ������� ����������" << endl;
                cin >> fam;
                cout << "������� �������� ����������" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                cout << "�������� ��������� ����������:" << endl;
                cout << "1 - ��������� �������������, 2 - ��������, 3 - ���������, 4 - ��������" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4))){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                if (choice == 1) {
                    admin adm = director.findAdmin(Fio);
                    adm.listInfo();
                } else if (choice == 2) {
                    security sec = director.findSecure(Fio);
                    sec.listInfo();
                } else if (choice == 3) {
                    if (Accountant.getName().compare(name) == 0) {
                        Accountant.listInfo();
                    } else cout << "�������� ���!" << endl;
                } else if (choice == 4) {
                    director.listInfo();
                }
                break;
            }
            case 6: {
                cout << "1 - ���������� ������, 2 - �������� ������" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2))){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                if (choice == 1) {
                    cout << "������� ��� ����������" << endl;
                    cin >> name;
                    cout << "������� ������� ����������" << endl;
                    cin >> fam;
                    cout << "������� �������� ����������" << endl;
                    cin >> patronymic;
                    string Fio = name + fam + patronymic;
                    director.findAdmin(Fio).listInfo();
                } else if (choice == 2) {
                    cout << "������� ��� ����������" << endl;
                    cin >> name;
                    cout << "������� ������� ����������" << endl;
                    cin >> fam;
                    cout << "������� �������� ����������" << endl;
                    cin >> patronymic;
                    string Fio = name + fam + patronymic;
                    cout << "1 - ��������, 2 - �������" << endl;
                    int a;
                    cin >> a;
                    if (a == 1) {
                        cout << "��� ��������?" << endl;
                        string eq;
                        cin >> eq;
                       // admin adm1 = director.findAdmin(Fio);
                        director.findAdmin(Fio).addEquipment(eq);
                        cout << "kf" << endl;
                    } else if (a == 2) {
                        cout << "��� �������?" << endl;
                        string eq;
                        cin >> eq;
                        director.findAdmin(Fio).delEquipment(eq);
                    }
                }
                break;
            }
            case 7: {
                cout << "������� ��� ����������" << endl;
                cin >> name;
                cout << "������� ������� ����������" << endl;
                cin >> fam;
                cout << "������� �������� ����������" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                director.findSecure(Fio).listInfo();
                break;
            }
            default: break;
        }
    }
}


