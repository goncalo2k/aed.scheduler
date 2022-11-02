#ifndef SCHEDULES_CLASS_H
#define SCHEDULES_CLASS_H

#include <bits/stdc++.h>

#include "Student.h"
#include "Slot.h"

using namespace std;

class Class {
    private:
        string code;
        string course;
        set<int> students;
        set<Slot> slots;

    public:
        Class(string code, string course);
        string getCode() const;
        string getCourse() const;
        void addStudent(const Student& student);
        void removeStudent(const Student& student);
        set<int> getStudents() const;
        void addSlot(const Slot& slot);
        void removeSlot(const Slot& slot);
        set<Slot> getSlots() const;
};

#endif //SCHEDULES_CLASS_H
