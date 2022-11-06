#include <utility>

#include "../headers/Class.h"

/**
 * @brief Class::Class
 * This is the Class constructor. It receives the class code and the course code. Considers that a course has no students or slots associated to it initially.
 * Complexity: O(1)
 * @param code - The code of the class.
 * @param course - The course of the class.
 */
Class::Class(string code, string course) {
    this->code= std::move(code);
    this->course = std::move(course);
}

/**
 * @brief Class::getCode
 * Setter for the class code.
 * Complexity: O(1)
 * @param code - The code of the class.
 */
void Class::setCode(const string& code) {
    this->code = code;
}

/**
 * @brief Class::setCourse
 * Setter for the class course.
 * Complexity: O(1)
 * @param course - The course of the class.
 */
void Class::setCourse(const string& course) {
    this->course = course;
};

/**
 * @brief Class::getCode
 * Getter for the class code.
 * Complexity: O(1)
 * @return The class code.
 */
string Class::getCode() const {
    return this->code;
}

/**
 * @brief Class:getCourse
 * Getter for the class course.
 * Complexity: O(1)
 * @return The course code of the class.
 */
string Class::getCourse() const {
    return this->course;
}

/**
 * @brief Class::addStudent
 * @param student - The student to be added to the class.
 * This method adds a student to the class' student list.
 * Complexity: O(1)
 */
void Class::addStudent(int student) {
    this->students.insert(student);
}

/**
 * @brief Class::removeStudent
 * @param student - The student to be removed from the class.
 * This method removes a student from the class' student list.
 * Complexity: O(log n)
 */
void Class::removeStudent(int student) {
    if (this->students.find(student) != this->students.end()) this->students.erase(student);
}

/**
 * @brief Class::getStudents
 * This method returns the class' student set.
 * Complexity: O(1)
 * @return The class' student set.
 */
set<int> Class::getStudents() const {
    return this->students;
}

/**
 * @brief Class::addSlot
 * @param slot - The slot to be added to the class.
 * This method adds a slot to the class' slot set - basically, classes from all of this class' courses.
 * Complexity: O(log n)
 */
void Class::addSlot(const Slot& slot) {
    this->slots.insert(slot);
}

/**
 * @brief Class::removeSlot
 * @param slot - The slot to be removed from the class.
 * This method removes a slot from the class' slot set - basically, classes from all of this class' courses.
 * Complexity: O(log n)
 */
void Class::removeSlot(const Slot& slot) {
    if (this->slots.find(slot) != this->slots.end()) this->slots.erase(slot);
}

/**
 * @brief Class::getSlots
 * Getter for the class' slot set.
 * Complexity: O(1)
 * @return The class' slot set.
 */
set<Slot> Class::getSlots() const {
    return this->slots;
}