#ifndef SCHEDULES_CLASS_H
#define SCHEDULES_CLASS_H

#include <bits/stdc++.h>

using namespace std;

class Class {
    private:
        string uc_code;
        string class_code;

    public:
        Class(string uc_code, string class_code);
        string getUCCode();
        string getClassCode();
        void setUCCode(string code);
        void setClassCode(string code);
};


#endif //SCHEDULES_CLASS_H
