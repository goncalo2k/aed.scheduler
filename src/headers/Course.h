#ifndef SCHEDULES_COURSE_H
#define SCHEDULES_COURSE_H

#include <bits/stdc++.h>

using namespace std;

class Course {
    private:
        string code;
        set<string> classes;

    public:
        Course(string code);
        string getCode() const;
        void setCode(string code);
        void addClass(const string& cl);
        void removeClass(const string& cl);
        set<string> getClasses() const;
};


#endif //SCHEDULES_COURSE_H
