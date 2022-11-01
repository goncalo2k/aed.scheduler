#ifndef SCHEDULES_REQUEST_H
#define SCHEDULES_REQUEST_H

#include <string>

using namespace std;

class Request {
    private:
        string type;
        string student_id;
        string uc_code;
        string initial_class_code;
        string final_class_code;
    public:
        Request(string type, string student_id, string uc_code, string initial_class_code, string final_class_code);
        string getType();
        string getStudentId();
        string getUCCode();
        string getInitialClassCode();
        string getFinalClassCode();
        void setType(string type);
        void setStudentId(string id);
        void setUCCode(string code);
        void setInitialClassCode(string code);
        void setFinalClassCode(string code);
};


#endif //SCHEDULES_REQUEST_H
