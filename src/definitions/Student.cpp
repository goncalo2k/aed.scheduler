#include <iostream>
#include "../headers/Student.h"

Student::Student(int number, string name) {
    this->name = name;
    this->number = number;
}

int Student::getNumber() const {
    return this->number;
}

string Student::getName() const{
    return this->name;
}

void Student::addClass(const string& cl) {
    this->classes.insert(cl);
}

void Student::addCourse(const string& course) {
    this->courses.insert(course);
}

void Student::removeClass(string cl) {
    if (this->classes.find(cl) != this->classes.end()) this->classes.erase(cl);
}

void Student::removeCourse(string course) {
    if (this->courses.find(course) != this->courses.end()) this->courses.erase(course);
}

set<string> Student::getClasses() const {
    return this->classes;
}

set<string> Student::getCourses() const {
    return this->courses;
}