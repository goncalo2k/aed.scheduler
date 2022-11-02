#ifndef SCHEDULES_COURSE_H
#define SCHEDULES_COURSE_H

#include <bits/stdc++.h>

using namespace std;

class Course {
    private:
        string code;

    public:
        Course(string code);
        string getCode();
        void setCode(string code);
};


#endif //SCHEDULES_COURSE_H
