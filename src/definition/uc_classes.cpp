#include "../headers/uc_classes.h"

UC_Classes::UC_Classes(string uc_code, string class_code) {
    this->uc_code = uc_code;
    this->class_code = class_code;
}

string UC_Classes::getUCCode() {
    return this->uc_code;
}

string UC_Classes::getClassCode() {
    return this->class_code;
}

void UC_Classes::setUCCode(string code) {
    this->uc_code = code;
}

void UC_Classes::setClassCode(string code) {
    this->class_code = code;
}