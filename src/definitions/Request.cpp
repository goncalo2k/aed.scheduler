#include "../headers/Request.h"

Request::Request(int type, Student* student, Class* initialClass, Class* finalClass, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = initialClass;
    this->finalClass = finalClass;
    this->course = course;
}

Request::Request(int type, Student* student, Class* initialClass, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = initialClass;
    this->finalClass = nullptr;
    this->course = course;
}

void Request::process() {
    if (this->type == 1) {
        this->student->removeClass(make_pair(initialClass->getCourse(), initialClass->getCode()));
        initialClass->removeStudent(this->student->getNumber());
        course->removeStudent(this->student->getNumber());
    }

    else if (this->type == 2) {
            
    }
}
