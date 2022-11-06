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
        int getType() const;
        Student* getStudent() const;
        Class* getInitialClass() const;
        Class* getFinalClass() const;
        Course* getCourse() const;
        bool process(const string& fileName);
        bool addProcess(const string& fileName);
        bool removeProcess(const string& fileName);
        bool swapProcess(const string& fileName);
        void file();
};

#endif //SCHEDULES_REQUEST_H
