#include "../headers/class_schedule.h"

ClassSchedule::ClassSchedule(Class cl, list<Slot> classes) {
    this->cl = cl;
    this->scheduleClasses = classes;
}

Class ClassSchedule::getClass() {
    return this->cl;
}

list<Slot> ClassSchedule::getClasses() {
    return this->scheduleClasses;
}

void ClassSchedule::setClass(Class cl) {
    this->cl = cl;
}

void ClassSchedule::setClasses(list<Slot> classes) {
    this->scheduleClasses = classes;
}

void ClassSchedule::addClass(Slot cl) {
    this->scheduleClasses.push_back(cl);
}
