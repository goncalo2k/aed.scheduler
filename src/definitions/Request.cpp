#include "../headers/Request.h"

/**
 * @brief Request::Request
 * Constructor for a request of type 1 - swapping a student from one class to another.
 * @param type - Type of the request - 1.
 * @param student - The student to be swapped.
 * @param initialClass - The class the student is currently in.
 * @param finalClass - The class the student wants to be swapped to.
 * @param course - The course where the swap is being made.
 */
Request::Request(int type, Student* student, Class* initialClass, Class* finalClass, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = initialClass;
    this->finalClass = finalClass;
    this->course = course;
}

/**
 * @brief Request::Request
 * Constructor for a request of type 2 - removing a student from a class.
 * @param type - Type of the request - 2.
 * @param student - The student to be removed.
 * @param initialClass - The class the student wants to be removed from.
 * @param course - The course where the removal is being made.
 */
Request::Request(int type, Student* student, Class* initialClass, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = initialClass;
    this->finalClass = nullptr;
    this->course = course;
}

/**
 * @brief Request::process
 * This method processes the request, depending on its type.
 */
void Request::process() {
    if (this->type == 1) {
        this->student->removeClass(make_pair(initialClass->getCourse(), initialClass->getCode()));
        initialClass->removeStudent(this->student->getNumber());
        course->removeStudent(this->student->getNumber());
    }

    else if (this->type == 2) {
            
    }
}
