#ifndef SCHEDULES_CLASS_H
#define SCHEDULES_CLASS_H

#include <bits/stdc++.h>

using namespace std;

class Class {
    private:
        string courseCode;
        string classCode;

    public:
        Class(string courseCode, string classCode);

    Class();

    string getUCCode();
        string getClassCode();
        void setUCCode(string code);
        void setClassCode(string code);
};


#endif //SCHEDULES_CLASS_H
