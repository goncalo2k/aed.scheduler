#ifndef SCHEDULES_CLASS_SCHEDULE_H
#define SCHEDULES_CLASS_SCHEDULE_H

#include <list>
#include "Slot.h"
#include "Class.h"

using namespace std;

class ClassSchedule {
private:
    string UCName;
    string UCId;
    list<Slot> scheduleClasses;
public:
    ClassSchedule(string name, string id);
    string getUCName();
    string getUCId();
    list<Slot> getClasses();
    void addClass(Slot class_);
    void removeClass(Slot class_); //REMOVE: TBD
    void setClasses(list<Slot> classes);
};

#endif
