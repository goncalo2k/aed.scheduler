#include <iostream>
#include <utility>
#include "../headers/Student.h"

Student::Student(int number, string name) {
    this->name = std::move(name);
    this->number = number;
}

int Student::getNumber() const {
    return this->number;
}

string Student::getName() const{
    return this->name;
}

void Student::addClass(const pair<string, string>& cl) {
    this->classes.insert(cl);
}

void Student::removeClass(const pair<string, string>& cl) {
    if (this->classes.find(cl) != this->classes.end()) this->classes.erase(cl);
}

set<pair<string, string>> Student::getClasses() const {
    return this->classes;
}

Schedule* Student::getSchedule() const {
    return this->schedule;
}

void Student::setSchedule(Schedule* schedule) {
    this->schedule = schedule;
}

