#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <bits/stdc++.h>

using namespace std;

class Student {
    private:
        int number;
        string name;
        set<string> classes;
        set<string> courses;

    public:
        Student(int number, string name);
        int getNumber() const;
        string getName() const;
        void addClass(const string& cl);
        void addCourse(const string& course);
        void removeClass(string cl);
        void removeCourse(string course);
        set<string> getClasses() const;
        set<string> getCourses() const;
};

#endif //SCHEDULES_STUDENT_H
