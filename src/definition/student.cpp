#include "../headers/student.h"

Student::Student(string name, string id, list<UC_Classes> classes) {
    this->name = name;
    this->id = id;
    this->classes = classes;
}

string Student::getName() {
    return this->name;
}

string Student::getId() {
    return this->id;
}

void Student::addClass(UC_Classes class_) {
    this->classes.push_back(class_);
}

//REMOVE: TBD

list<UC_Classes> Student::getClasses() {
    return this->classes;
}