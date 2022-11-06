#include <utility>

#include "../headers/Course.h"

/**
 * @brief Course::Course
 * This is the Course constructor. It receives the course code. Considers that a course has no students or classes associated to it initially.
 * Complexity: O(1) ?
 * @param code The code of the course.
 */
Course::Course(string code) {
    this->code = std::move(code);
}

/**
 * @brief Course::getCode
 * Getter for the course code.
 * Complexity: O(1) ?
 * @return The course code.
 */
string Course::getCode() const {
    return this->code;
}

/**
 * @brief Course::setCode
 * Setter for the course code.
 * Complexity: O(1) ?
 * @param code - The new course code.
 */
void Course::setCode(string code) {
    this->code = std::move(code);
}

/**
 * @brief Course::addClass
 * This method adds a class to the course's class set.
 * Complexity: O(1) ?
 * @param cl - The class to be added to the course.
 */
void Course::addClass(const string& cl) {
    this->classes.insert(cl);
}

/**
 * @brief Course::removeClass
 * This method removes a class from the course's class set.
 * Complexity: O(log n) ?
 * @param cl - The class to be removed from the course.
 */
void Course::removeClass(const string& cl) {
    if (this->classes.find(cl) != this->classes.end()) this->classes.erase(cl);
}

/**
 * @brief Course::addStudent
 * This method adds a student to the course's student set.
 * Complexity: O(1) ?
 * @param student - The student to be added to the course.
 */
void Course::addStudent(int student) {
    this->students.insert(student);
}

/**
 * @brief Course::removeStudent
 * This method removes a student from the course's student set.
 * Complexity: O(log n) ?
 * @param student - The student to be removed from the course.
 */
void Course::removeStudent(int student) {
    if (this->students.find(student) != this->students.end()) this->students.erase(student);
}

/**
 * @brief Course::getClasses
 * Getter for the course's class set.
 * Complexity: O(1) ?
 * @return The course' class set.
 */
set<string> Course::getClasses() const {
    return this->classes;
}

/**
 * @brief Course::getStudents
 * Getter for the course's student set.
 * Complexity: O(1) ?
 * @return The course' student set.
 */
set<int> Course::getStudents() const {
    return this->students;
}
