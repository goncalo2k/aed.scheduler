#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <bits/stdc++.h>
#include "Schedule.h"

using namespace std;

/**
 * @brief Student
 * This class represents a student.
 */
class Student {
    private:
        int number;
        string name;
        set<pair<string, string>> classes;
        Schedule* schedule;

    public:
        Student(int number, string name);
        int getNumber() const;
        string getName() const;
        void addClass(const pair<string, string>& cl);
        void removeClass(const pair<string, string>& cl);
        set<pair<string, string>> getClasses() const;
        Schedule* getSchedule() const;
        void setSchedule(Schedule* schedule);
};

#endif //SCHEDULES_STUDENT_H
