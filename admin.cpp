//
// Created by Admin on 10.11.2022.
//

#include "admin.h"

admin::admin( const string &name, const string &fam, const string &patronymic) : Employee(0, name, "Admin",
                                                                                                        fam,
                                                                                                        patronymic) {}

const unordered_map<string, int> &admin::getEquipments() const {
    return equipments;
}

void admin::setEquipments(const unordered_map<string, int> &equipments) {
    admin::equipments = equipments;
}
