#ifndef SCHEDULES_REQUEST_H
#define SCHEDULES_REQUEST_H

#include <string>
#include "Student.h"
#include "Class.h"
#include "Course.h"

using namespace std;

/**
 * @brief Request
 * This class represents a request.
 */
class Request {
    private:
        int type;
        Student* student;
        string initialClass;
        string finalClass;
        Course* course;
        Class* initialClassPtr;
        Class* finalClassPtr;

    public:
        Request(int type, Student* student, string initialClass, string finalClass, Course* course, Class* initialClassPtr, Class* finalClassPtr);
        Request(int type, Student* student, string initialClass, Course* course, Class* initialClassPtr);
        Request(int type, Student* student, Class* initialClassPtr, Class* finalClassPtr, Course* course);
        Request(int type, Student* student, Class* initialClassPtr, Course* course);
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
