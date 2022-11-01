#ifndef SCHEDULES_UC_CLASSES_H
#define SCHEDULES_UC_CLASSES_H

#include <string>

using namespace std;

class UC_Classes {
    private:
        string uc_code;
        string class_code;
    public:
        UC_Classes(string uc_code, string class_code);
        string getUCCode();
        string getClassCode();
        void setUCCode(string code);
        void setClassCode(string code);
};


#endif //SCHEDULES_UC_CLASSES_H
