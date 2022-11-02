#include "../headers/class_schedule.h"

ClassSchedule::ClassSchedule(string name, string id) {
    this->UCName = name;
    this->UCId = id;
}

string ClassSchedule::getUCName() {
    return this->UCName;
}

string ClassSchedule::getUCId() {
    return this->UCId;
}

list<Slot> ClassSchedule::getClasses() {
    return this->scheduleClasses;
}

void ClassSchedule::setClasses(list<Slot> classes) {
    this->scheduleClasses = classes;
}

void ClassSchedule::addClass(Slot class_) {
    this->scheduleClasses.push_back(class_);
}

//REMOVE: TBD


