//
// Created by goncalo2k on 06-11-2022.
//

#ifndef SCHEDULES_MENUHANDLER_H
#define SCHEDULES_MENUHANDLER_H


#include "Course.h"
#include "Class.h"
#include "Request.h"

using namespace std;

/**
 * @brief compareStudent
 * Allows to compare two students by their numbers.
 */
struct compareStudent {
    bool operator()(Student* s1, Student* s2) const {
        return s1->getNumber() < s2->getNumber();
    }
};

/**
 * @brief compareClass
 * Allows to compare two classes by their codes.
 */
struct compareClass {
    bool operator()(Class* c1, Class* c2) const {
        if (c1->getCourse() == c2->getCourse()) return c1->getCode() < c2->getCode();
        return c1->getCourse() < c2->getCourse();
    }
};

/**
 * @brief compareCourse
 * Allows to compare two courses by their codes.
 */
struct compareCourse {
    bool operator()(Course* c1, Course* c2) const {
        return c1->getCode() < c2->getCode();
    }
};

typedef set<Student*, compareStudent> studentSet;
typedef set<Class*, compareClass> classSet;
typedef set<Course*, compareCourse> courseSet;
typedef queue<Request*> requestQueue;
typedef vector<Request*> requestVector;

/**
 * @brief Class
 * This class represents the Menu Handler.
 */
class MenuHandler {
    public:
        void readStudents(studentSet* students, classSet* classes, courseSet* courses);
        void readClasses(classSet* classes);
        void readCourses(courseSet* courses);
        void readDeniedRequests(requestVector* deniedRequests);
        void readEnrollRequest(requestQueue* requests, studentSet* students, classSet* classes, courseSet* courses);
        void readLeaveRequest(requestQueue* requests, studentSet* students, classSet* classes, courseSet* courses);
        void readSwapRequest(requestQueue* requests, studentSet* students, classSet* classes, courseSet* courses);
        void clearScreen();
        void wait();
        void listMenu(studentSet* students, classSet* classes, courseSet* courses);
        void requestsMenu(requestQueue* requests, studentSet* students, classSet* classes, courseSet* courses);
        void studentsFilters(studentSet* students);
        void listStudents(studentSet* students, int op1, int op2, int op3, int op4, int op5, int min, int max, int n);
        void classesFilters(classSet* classes, studentSet* students);
        void listClasses(classSet* classes, studentSet* students, int op1, int op2, int op3);
        void coursesFilters(courseSet* courses, studentSet* students);
        void listCourses(courseSet* courses, studentSet* students, int op1, int op2, int op3);
        void listDeniedRequests(requestVector* deniedRequests);
        void scheduleView(studentSet* students, classSet* classes);
        void studentSchedule(studentSet* students, classSet* classes);
        void classSchedule(classSet* classes);
        void requestProcessing(requestQueue* requests, requestVector* deniedRequests);
};


#endif //SCHEDULES_MENUHANDLER_H
