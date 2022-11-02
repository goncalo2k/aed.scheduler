#ifndef SCHEDULES_CLASS_SCHEDULE_H
#define SCHEDULES_CLASS_SCHEDULE_H

#include <list>
#include "Slot.h"
#include "Class.h"

using namespace std;

class ClassSchedule {
private:
    Class cl;
    list<Slot> scheduleClasses;
public:
    ClassSchedule(Class cl, list<Slot> classes);
    Class getClass(); //Getter da turma
    list<Slot> getClasses(); //Getter da lista de aulas
    void addClass(Slot class_);
    void removeClass(Slot class_);
    void setClass(Class cl); //Setter da turma
    void setClasses(list<Slot> classes); //Setter da lista de aulas
};

#endif
