#ifndef SCHEDULES_REQUEST_H
#define SCHEDULES_REQUEST_H

#include <string>
#include "Student.h"
#include "Class.h"
#include "Course.h"

using namespace std;

class Request {
    private:
        int type;
        Student* student;
        Class* initialClass;
        Class* finalClass;
        Course* course;

    public:
        Request(int type, Student* student, Class* initialClass, Class* finalClass, Course* course);
        Request(int type, Student* student, Class* initialClass, Course* course);
        void process();
};

#endif //SCHEDULES_REQUEST_H
