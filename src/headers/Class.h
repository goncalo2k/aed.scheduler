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
        explicit Class(string code, string course);
        string getCode() const;
        string getCourse() const;
        void addStudent(int student);
        void removeStudent(int student);
        set<int> getStudents() const;
        void addSlot(const Slot& slot);
        void removeSlot(const Slot& slot);
        set<Slot> getSlots() const;
        void setCode(const string& code);
        void setCourse(const string& course);
};

#endif //SCHEDULES_CLASS_H
