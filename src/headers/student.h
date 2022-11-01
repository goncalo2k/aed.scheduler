#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <string>
#include <vector>
#include <list>
#include "uc_classes.h"

using namespace std;

class Student {
    private:
        string name;
        string id;
        list<UC_Classes> classes;
    public:
        Student(string name, string id, list<UC_Classes> classes);
        string getName();
        string getId();
        void addClass(UC_Classes classes);
        void removeClass(UC_Classes class_); //REMOVE: TBD
        list<UC_Classes> getClasses();
};


#endif //SCHEDULES_STUDENT_H
