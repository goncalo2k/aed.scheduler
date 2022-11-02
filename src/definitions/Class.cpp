#include "../headers/Class.h"

Class::Class() {
    this->courseCode = "";
    this->classCode = "";
}

Class::Class(string courseCode, string classCode) {
    this->courseCode = courseCode;
    this->classCode = classCode;
}

string Class::getUCCode() {
    return this->courseCode;
}

string Class::getClassCode() {
    return this->classCode;
}

void Class::setUCCode(string code) {
    this->courseCode = code;
}

void Class::setClassCode(string code) {
    this->classCode = code;
}
