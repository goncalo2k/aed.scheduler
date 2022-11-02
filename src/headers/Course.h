#ifndef SCHEDULES_COURSE_H
#define SCHEDULES_COURSE_H

#include <bits/stdc++.h>

using namespace std;

class Course {
    private:
        string code;
        set<string> classes;
        set<int> students;

    public:
        explicit Course(string code);
        string getCode() const;
        void setCode(string code);
        void addClass(const string& cl);
        void removeClass(const string& cl);
        void addStudent(int student);
        void removeStudent(int student);
        set<string> getClasses() const;
        set<int> getStudents() const;
};


#endif //SCHEDULES_COURSE_H
