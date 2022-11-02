#include "../headers/Course.h"

Course::Course(string code) {
    this->code = code;
}

string Course::getCode() {
    return this->code;
}

void Course::setCode(string code) {
    this->code = code;
}
