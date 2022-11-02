#include <utility>

#include "../headers/Class.h"

Class::Class(string code, string course) {
    this->code= std::move(code);
    this->course = std::move(course);
}

string Class::getCode() const {
    return this->code;
}

string Class::getCourse() const {
    return this->course;
}

void Class::addStudent(int student) {
    this->students.insert(student);
}

void Class::removeStudent(int student) {
    if (this->students.find(student) != this->students.end()) this->students.erase(student);
}

set<int> Class::getStudents() const {
    return this->students;
}

void Class::addSlot(const Slot& slot) {
    this->slots.insert(slot);
}

void Class::removeSlot(const Slot& slot) {
    if (this->slots.find(slot) != this->slots.end()) this->slots.erase(slot);
}

set<Slot> Class::getSlots() const {
    return this->slots;
}