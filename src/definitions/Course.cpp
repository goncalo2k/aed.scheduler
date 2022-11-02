#include <utility>

#include "../headers/Course.h"

Course::Course(string code) {
    this->code = std::move(code);
}

string Course::getCode() const {
    return this->code;
}

void Course::setCode(string code) {
    this->code = std::move(code);
}

void Course::addClass(const string& cl) {
    this->classes.insert(cl);
}

void Course::removeClass(const string& cl) {
    if (this->classes.find(cl) != this->classes.end()) this->classes.erase(cl);
}

void Course::addStudent(int student) {
    this->students.insert(student);
}

void Course::removeStudent(int student) {
    if (this->students.find(student) != this->students.end()) this->students.erase(student);
}

set<string> Course::getClasses() const {
    return this->classes;
}

set<int> Course::getStudents() const {
    return this->students;
}
