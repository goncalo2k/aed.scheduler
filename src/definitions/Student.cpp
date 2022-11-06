#include <iostream>
#include <utility>
#include "../headers/Student.h"

/**
 * @brief Student::Student
 * This is the Student constructor. It receives the student's number and the student's name. Considers that a student has no schedule or classes associated to it initially.
 * Complexity: O(1)
 * @param number - The student's number.
 * @param name - The student's name.
 */
Student::Student(int number, string name) {
    this->name = std::move(name);
    this->number = number;
}

/**
 * @brief Student::getNumber
 * Getter for the student's number.
 * Complexity: O(1)
 * @return The student's number.
 */
int Student::getNumber() const {
    return this->number;
}

/**
 * @brief Student::getName
 * Getter for the student's name.
 * Complexity: O(1)
 * @return The student's name.
 */
string Student::getName() const{
    return this->name;
}

/**
 * @brief Student::addClass
 * Adds a class to the student's classes.
 * complexity: O(log n)
 * @param cl - The class to be added.
 */
void Student::addClass(const pair<string, string>& cl) {
    this->classes.insert(cl);
}

/**
 * @brief Student::removeClass
 * Removes a class from the student's classes.
 * Complexity: O(log n)
 * @param cl - The class to be removed.
 */
void Student::removeClass(const pair<string, string>& cl) {
    if (this->classes.find(cl) != this->classes.end()) this->classes.erase(cl);
}

/**
 * @brief Student::getClasses
 * Getter for the student's classes.
 * Complexity: O(1)
 * @return The student's classes.
 */
set<pair<string, string>> Student::getClasses() const {
    return this->classes;
}

/**
 * @brief Student::getSchedule
 * Getter for the student's schedule.
 * Complexity: O(1)
 * @return The student's schedule.
 */
Schedule* Student::getSchedule() const {
    return this->schedule;
}

/**
 * @brief Student::setSchedule
 * Setter for the student's schedule.
 * Complexity: O(1)
 * @param schedule - The student's schedule.
 */
void Student::setSchedule(Schedule* schedule) {
    this->schedule = schedule;
}
