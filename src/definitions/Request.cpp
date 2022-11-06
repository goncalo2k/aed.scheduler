#include <utility>

#include "../headers/Request.h"

/**
 * @brief Request::Request
 * Constructor for a request of type 1 - swapping a student from one class to another.
 * Complexity: O(1)
 * @param type - Type of the request - 1.
 * @param student - The student to be swapped.
 * @param initialClass - The class the student is currently in.
 * @param finalClass - The class the student wants to be swapped to.
 * @param course - The course where the swap is being made.
 */
Request::Request(int type, Student* student, string initialClass, string finalClass, Course* course, Class* initialClassPtr, Class* finalClassPtr) {
    this->type = type;
    this->student = student;
    this->initialClass = std::move(initialClass);
    this->finalClass = std::move(finalClass);
    this->course = course;
    this->initialClassPtr = initialClassPtr;
    this->finalClassPtr = finalClassPtr;
}

/**
 * @brief Request::Request
 * Constructor for a request of type 2 or 3 - removing or adding a student from a class.
 * Complexity: O(1)
 * @param type - Type of the request - 2 or 3.
 * @param student - The student to be removed or added.
 * @param initialClass - The class the student wants to be removed from or added to.
 * @param course - The course where the removal or enrollment is being made.
 */
Request::Request(int type, Student* student, string initialClass, Course* course, Class* initialClassPtr) {
    this->type = type;
    this->student = student;
    this->initialClass = std::move(initialClass);
    this->finalClass = "";
    this->course = course;
    this->initialClassPtr = initialClassPtr;
    this->finalClassPtr = nullptr;
}

Request::Request(int type, Student* student, Class* initialClassPtr, Class* finalClassPtr, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = "";
    this->finalClass = "";
    this->course = course;
    this->initialClassPtr = initialClassPtr;
    this->finalClassPtr = finalClassPtr;
}

Request::Request(int type, Student* student, Class* initialClassPtr, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = "";
    this->finalClass = "";
    this->course = course;
    this->initialClassPtr = initialClassPtr;
    this->finalClassPtr = nullptr;
}

/**
 * @brief Request::Request
 * Getter for the type of the request.
 * Complexity: O(1)
 * @return The request type.
 */
int Request::getType() const {
    return this->type;
}


/**
 * @brief Request::getStudent
 * Getter for the student that made the request.
 * Complexity: O(1)
 * @return The student that made the request.
 */
Student* Request::getStudent() const {
    return this->student;
}

/**
 * @brief Request::getInitialClass
 * Getter for the initial class of the request.
  * Complexity: O(1)
 * @return The class where the student is currently enrolled for type 1 requests, the class the student will be added to or removed from in type 2 and 3 requests.
 */
Class* Request::getInitialClass() const {
    return this->initialClassPtr;
}

/**
 * @brief Request::getFinalClass
 * Getter for the final class of the request.
 * Complexity: O(1)
 * @return The class the student wants to be swapped to in type 1 requests, nullptr in type 2 and 3 requests .
 */
Class* Request::getFinalClass() const {
    return this->finalClassPtr;
}

/**
 * @brief Request::getCourse
 * Getter for the course of the request.
 * Complexity: O(1)
 * @return The course where the request is being made.
 */
Course* Request::getCourse() const {
    return this->course;
}

/**
 * @brief Request::process
 * Processes the requests
 * Complexity: O(log n)
 * @param fileName - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::process(const string& fileName) {
    bool success = false;

    if (this->type == 1) {
       success = this->addProcess(fileName);
    }

    else if (this->type == 2) {
        success = this->removeProcess(fileName);
    }

    else {
        success = this->swapProcess(fileName);
    }

    return success;
}

/**
 * @brief Request::addProcess
 * Processes a request of type 1 - adding a student to a class.
 * Complexity: O(log n)
 * @param fileName - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::addProcess(const std::string &fileName) {
    if (this->student->getClasses().find(make_pair(this->course->getCode(), this->initialClass)) != this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is either already enrolled in class " << this->initialClassPtr->getCode() << " or in another class. On the later case, try a swap." << endl;
        this->file();
        return false;
    }

    if (this->student->getClasses().size() >= 6) {
        cout << "Student " << this->student->getNumber() << " is already enrolled in 6 classes." << endl;
        this->file();
        return false;
    }



    if (this->initialClassPtr->getStudents().size() >= 30) {
        cout << "Class " << this->initialClassPtr->getCode() << " is full." << endl;
        this->file();
        return false;
    }


    bool isPossible = true;
    for (const auto& s1 : this->student->getSchedule()->getSlots()) {
        for (const auto &s2: this->initialClassPtr->getSlots()) {
            if (!s1.compatible(&s2)) {
                isPossible = false;
                break;
            }
        }
    }

    if (!isPossible) {
        cout << "Student " << this->student->getNumber() << " has a schedule conflict with class " << this->initialClassPtr->getCode() << "." << endl;
        this->file();
        return false;
    }

    this->student->addClass(make_pair(initialClassPtr->getCourse(), initialClassPtr->getCode()));
    initialClassPtr->addStudent(this->student->getNumber());
    course->addStudent(this->student->getNumber());


    return true;
}

/**
 * @brief Request::removeProcess
 * Processes a request of type 1 - adding a student to a class.
 * Complexity O(log n)
 * @param fileName  - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::removeProcess(const std::string &fileName) {

    this->student->removeClass(make_pair(initialClassPtr->getCourse(), initialClassPtr->getCode()));
    initialClassPtr->removeStudent(this->student->getNumber());
    course->removeStudent(this->student->getNumber());

    return true;

}

/**
 * @brief Request::swapProcess
 * Processes a request of type 1 - adding a student to a class.
 * Complexity: O(log n) ?
 * @param fileName - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::swapProcess(const std::string &fileName) {
    if (this->finalClassPtr->getStudents().size() >= 30) {
        cout << "Class " << this->finalClassPtr->getCode() << " is full." << endl;
        this->file();
        return false;
    }

    if (this->student->getClasses().size() >= 6) {
        cout << "Student " << this->student->getNumber() << " is already enrolled in 6 classes." << endl;
        this->file();
        return false;
    }

    this->student->removeClass(make_pair(initialClassPtr->getCourse(), initialClassPtr->getCode()));
    initialClassPtr->removeStudent(this->student->getNumber());
    course->removeStudent(this->student->getNumber());

    this->student->addClass(make_pair(finalClassPtr->getCourse(), finalClassPtr->getCode()));
    finalClassPtr->addStudent(this->student->getNumber());
    course->addStudent(this->student->getNumber());

    return true;
}

/**
 * @brief Request::file
 * Writes the request to the file.
 * Complexity: O(1)
 */
void Request::file() {
    ofstream file;

    file.open("..//archive//denied_requests.csv");

    if (!file) {
        cout << "Error opening file." << endl;
    } else {
        if (this->type == 3) {
            file << this->type << "," << this->student->getNumber() << "," << this->course->getCode() << ","
                 << this->initialClassPtr->getCode() << "," << this->finalClassPtr->getCode() << endl;
        }
        else {
            file << this->type << "," << this->student->getNumber() << "," << this->course->getCode() << ","
                 << this->initialClassPtr->getCode() << "XXXXXXX" << this->initialClassPtr->getCode() << endl;
            ;
        }
    }

    file.close();
}
