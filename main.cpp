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
    cout << "Лабораторная работа 5. Денисов Д.А. Группа А-17-21" << endl;
    string name, fam, patronymic;
    cout << "Авторизуйтесь как директор:" << endl;
    cout << "Имя: ";
    cin >> name;
    cout << "Фамилия: ";
    cin >> fam;
    cout << "Отчество: ";
    cin >> patronymic;
    cout << "Авторизован пользователь: " << endl;
    Director director(name, fam, patronymic);
    director.listInfo();

    cout << "Авторизуйте своего бухгалтера:" << endl;
    cout << "Имя: ";
    cin >> name;
    cout << "Фамилия: ";
    cin >> fam;
    cout << "Отчество: ";
    cin >> patronymic;
    cout << "Авторизован пользователь: ";
    accountant Accountant(name, fam, patronymic);
    Accountant.listInfo();

    int vibor = 1;
    while (vibor == 1 || vibor == 2 || vibor == 3 || vibor == 4 || vibor == 5 || vibor == 6 || vibor == 7) {
        cout << "1 - принять сотрудника; 2 - уволить сотрудника; 3 - дать указание бухгалтеру; "
                "4 - просмотреть список сотрудников; 5 - найти сотрудника по ФИО и должности; 6 - управлять списками устройств,"
                " закрпеленных за системными администраторами; 7 - Просмотреть обмундирование охраны или нажмите любую другю кнопку ждя выхода" << endl;
        cout << "Выберите действие:" << endl;
            cin >> vibor;
        switch (vibor) {
            case 1: {
                cout << "Введите имя сотрудника" << endl;
                cin >> name;
                cout << "Введите фамилию сотрудника" << endl;
                cin >> fam;
                cout << "Введите отчество сотрудника" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                cout << "Выберете должность сотрудника:" << endl;
                cout << "1 - системный администратор, 2 - охранник" << endl;
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
                    cout << "Выберете предмет охранника" << endl;
                    cout << "1 - пистолет, 2 - ружье, 3 - дубинка, 4 - электрошокер" << endl;
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
                    cout << "Введен неверный код сотрудника!" << endl;
                }
                break;
            }
            case 2: {
                cout << "Введите имя сотрудника" << endl;
                cin >> name;
                cout << "Введите фамилию сотрудника" << endl;
                cin >> fam;
                cout << "Введите отчество сотрудника" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                cout << "Выберете должность сотрудника:" << endl;
                cout << "1 - системный администратор, 2 - охранник" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2) )){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                if (choice == 1) {
                    director.dismissalOfAdmin(Fio);
                    cout << "Сотрудник уволен!" << endl;
                } else if (choice == 2) {
                    director.dismissalOfSecure(Fio);
                    cout << "Сотрудник уволен!" << endl;
                } else {
                    cout << "Неверный код сотрудника!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Выберите действие которое необходимо произвести секретарю:" << endl;
                cout << "1 - установить ставку для должностей; 2 - установить зарплату конкретному сотруднику  или нажмите любую другю кнопку ждя выхода" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2) )){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                switch (choice) {
                    case 1: {
                        cout << "Ставку для какого сотрудника ввести: " << endl;
                        cout << "1 - охранник, 2 - секретарь, 3 - сисАдмин, 4 - директор" << endl;
                        int a;
                        while (!(cin >> a) && ((a != 1) && (a != 2) && (a != 3) && (a != 4))){
                            cout << "Input error!" << endl;
                            cin.clear();
                            fflush(stdin);
                        }
                        cout << "Введите ставку:" << endl;
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
                        cout << "Зарплату какого сотрудника изменить: " << endl;
                        cout << "1 - охранник, 2 - сисАдмин, 3 - секретарь, 4 - директор" << endl;
                        int a;
                        while (!(cin >> a) && ((a != 1) && (a != 2) && (a != 3) && (a != 4))){
                            cout << "Input error!" << endl;
                            cin.clear();
                            fflush(stdin);
                        };
                        switch (a) {
                            case 1 : {
                                cout << "Введите имя сотрудника, которому необходимо изменить зарплату:" << endl;
                                cout << "Введите имя сотрудника" << endl;
                                cin >> name;
                                cout << "Введите фамилию сотрудника" << endl;
                                cin >> fam;
                                cout << "Введите отчество сотрудника" << endl;
                                cin >> patronymic;
                                string Fio = name + fam + patronymic;
                                Accountant.setSalaryOfSecurity(director.findSecure(Fio));
                                break;
                            }
                            case 2 : {
                                cout << "Введите имя сотрудника, которому необходимо изменить зарплату:" << endl;
                                cout << "Введите имя сотрудника" << endl;
                                cin >> name;
                                cout << "Введите фамилию сотрудника" << endl;
                                cin >> fam;
                                cout << "Введите отчество сотрудника" << endl;
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
                        cout << "Зарплата изменена!" << endl;
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
                cout << "Охрана:" << endl;
                for (auto employee: director.getSecurities()) {
                    employee.second.listInfo();
                }
                cout << "_____________________________" << endl;
                cout << "Сис админы:" << endl;
                for (auto employee: director.getAdmins()) {
                    employee.second.listInfo();
                }
                break;
            }
            case 5: {
                cout << "Введите имя сотрудника" << endl;
                cin >> name;
                cout << "Введите фамилию сотрудника" << endl;
                cin >> fam;
                cout << "Введите отчество сотрудника" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                cout << "Выберете должность сотрудника:" << endl;
                cout << "1 - системный администратор, 2 - охранник, 3 - бухгалтер, 4 - директор" << endl;
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
                    } else cout << "Неверное имя!" << endl;
                } else if (choice == 4) {
                    director.listInfo();
                }
                break;
            }
            case 6: {
                cout << "1 - посмотреть список, 2 - изменить список" << endl;
                int choice;
                while (!(cin >> choice) && ((choice != 1) && (choice != 2))){
                    cout << "Input error!" << endl;
                    cin.clear();
                    fflush(stdin);
                }
                if (choice == 1) {
                    cout << "Введите имя сотрудника" << endl;
                    cin >> name;
                    cout << "Введите фамилию сотрудника" << endl;
                    cin >> fam;
                    cout << "Введите отчество сотрудника" << endl;
                    cin >> patronymic;
                    string Fio = name + fam + patronymic;
                    director.findAdmin(Fio).listInfo();
                } else if (choice == 2) {
                    cout << "Введите имя сотрудника" << endl;
                    cin >> name;
                    cout << "Введите фамилию сотрудника" << endl;
                    cin >> fam;
                    cout << "Введите отчество сотрудника" << endl;
                    cin >> patronymic;
                    string Fio = name + fam + patronymic;
                    cout << "1 - добавить, 2 - удалить" << endl;
                    int a;
                    cin >> a;
                    if (a == 1) {
                        cout << "Что добавить?" << endl;
                        string eq;
                        cin >> eq;
                       // admin adm1 = director.findAdmin(Fio);
                        director.findAdmin(Fio).addEquipment(eq);
                        cout << "kf" << endl;
                    } else if (a == 2) {
                        cout << "Что удалить?" << endl;
                        string eq;
                        cin >> eq;
                        director.findAdmin(Fio).delEquipment(eq);
                    }
                }
                break;
            }
            case 7: {
                cout << "Введите имя сотрудника" << endl;
                cin >> name;
                cout << "Введите фамилию сотрудника" << endl;
                cin >> fam;
                cout << "Введите отчество сотрудника" << endl;
                cin >> patronymic;
                string Fio = name + fam + patronymic;
                director.findSecure(Fio).listInfo();
                break;
            }
            default: break;
        }
    }
}


