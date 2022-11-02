#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <bits/stdc++.h>

using namespace std;

class Student {
    private:
        int number;
        string name;
        set<pair<string, string>> classes;

    public:
        Student(int number, string name);
        int getNumber() const;
        string getName() const;
        void addClass(const pair<string, string>& cl);
        void removeClass(const pair<string, string>& cl);
        set<pair<string, string>> getClasses() const;
};

#endif //SCHEDULES_STUDENT_H
