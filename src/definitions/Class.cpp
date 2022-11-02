#include "../headers/Class.h"

Class::Class(string uc_code, string class_code) {
    this->uc_code = uc_code;
    this->class_code = class_code;
}

string Class::getUCCode() {
    return this->uc_code;
}

string Class::getClassCode() {
    return this->class_code;
}

void Class::setUCCode(string code) {
    this->uc_code = code;
}

void Class::setClassCode(string code) {
    this->class_code = code;
}
