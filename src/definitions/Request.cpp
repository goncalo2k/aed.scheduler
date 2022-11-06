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
Request::Request(int type, Student* student, Class* initialClass, Class* finalClass, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = initialClass;
    this->finalClass = finalClass;
    this->course = course;
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
Request::Request(int type, Student* student, Class* initialClass, Course* course) {
    this->type = type;
    this->student = student;
    this->initialClass = initialClass;
    this->finalClass = nullptr;
    this->course = course;
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
    return this->initialClass;
}

/**
 * @brief Request::getFinalClass
 * Getter for the final class of the request.
 * Complexity: O(1)
 * @return The class the student wants to be swapped to in type 1 requests, nullptr in type 2 and 3 requests .
 */
Class* Request::getFinalClass() const {
    return this->finalClass;
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
 * Complexity: O(1)
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
 * Complexity: O(n² x log n)
 * @param fileName - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::addProcess(const std::string &fileName) {
    if (this->student->getClasses().find(make_pair(this->course->getCode(), this->initialClass->getCode())) != this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is either already enrolled in class " << this->initialClass->getCode() << " or in another class. On the later case, try a swap." << endl;
        this->file();
        return false;
    }

    if (this->student->getClasses().size() >= 6) {
        cout << "Student " << this->student->getNumber() << " is already enrolled in 6 classes." << endl;
        this->file();
        return false;
    }

    if (this->initialClass->getStudents().size() >= 30) {
        cout << "Class " << this->initialClass->getCode() << " is full." << endl;
        this->file();
        return false;
    }


    bool isPossible = true;
    for (const auto& s1 : this->student->getSchedule()->getSlots()) {
        for (const auto &s2: this->initialClass->getSlots()) {
            if (!s1.compatible(&s2)) {
                isPossible = false;
                break;
            }
        }
    }

    if (!isPossible) {
        cout << "Student " << this->student->getNumber() << " has a schedule conflict with class " << this->initialClass->getCode() << "." << endl;
        this->file();
        return false;
    }

    this->student->addClass(make_pair(initialClass->getCourse(), initialClass->getCode()));
    initialClass->addStudent(this->student->getNumber());
    course->addStudent(this->student->getNumber());


    return true;
}

/**
 * @brief Request::removeProcess
 * Processes a request of type 1 - adding a student to a class.
 * Complexity O(log n)?
 * @param fileName  - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::removeProcess(const std::string &fileName) {
    if (this->student->getClasses().find(make_pair(this->course->getCode(), this->initialClass->getCode())) == this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is not enrolled in class " << this->initialClass->getCode() << "." << endl;
        this->file();

        return false;
    }

    else {
        this->student->removeClass(make_pair(initialClass->getCourse(), initialClass->getCode()));
        initialClass->removeStudent(this->student->getNumber());
        course->removeStudent(this->student->getNumber());

        return true;
    }
}

/**
 * @brief Request::swapProcess
 * Processes a request of type 1 - adding a student to a class.
 * Complexity: O(n² x 2 x log n) ?
 * @param fileName - Classes file.
 * @return True if the request was processed successfully, false otherwise.
 */
bool Request::swapProcess(const std::string &fileName) {
    if (this->student->getClasses().find(make_pair(course->getCode(), initialClass->getCode())) == this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is not enrolled in class " << this->initialClass->getCode() << "." << endl;
        this->file();
        return false;
    }

    auto it = find_if(this->student->getClasses().begin(), this->student->getClasses().end(), [&](const pair<string, string>& c) {
        return c.first == this->course->getCode() && c.first == this->finalClass->getCode(); });

    if (it != this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is already enrolled in class " << this->finalClass->getCode() << "." << endl;
        //this->file();
        return false;
    }



    if (this->finalClass->getStudents().size() >= 30) {
        cout << "Class " << this->finalClass->getCode() << " is full." << endl;
        this->file();
        return false;
    }

    if (this->student->getClasses().size() >= 6) {
        cout << "Student " << this->student->getNumber() << " is already enrolled in 6 classes." << endl;
        this->file();
        return false;
    }

    bool isPossible = true;
    set<Slot> slots = this->student->getSchedule()->getSlots();
    slots.erase(this->initialClass->getSlots().begin(), this->initialClass->getSlots().end());
    for (const auto& s1 : slots) {
        for (const auto &s2: this->finalClass->getSlots()) {
            if (!s1.compatible(&s2)) {
                isPossible = false;
                break;
            }
        }
    }

    if (!isPossible) {
        cout << "Student " << this->student->getNumber() << " has a schedule conflict with class " << this->finalClass->getCode() << "." << endl;
        this->file();
        return false;
    }

    this->student->removeClass(make_pair(initialClass->getCourse(), initialClass->getCode()));
    initialClass->removeStudent(this->student->getNumber());
    course->removeStudent(this->student->getNumber());

    this->student->addClass(make_pair(finalClass->getCourse(), finalClass->getCode()));
    finalClass->addStudent(this->student->getNumber());
    course->addStudent(this->student->getNumber());

    return true;
}

/**
 * @brief Request::file
 * Writes the request to the file.
 * Complexity: O(1) ?
 */
void Request::file() {
    ofstream file;

    file.open("..//archive//denied_requests.csv");

    if (!file) {
        cout << "Error opening file." << endl;
    } else {
        if (this->type == 3) {
            file << this->type << "," << this->student->getNumber() << "," << this->course->getCode() << ","
                 << this->initialClass->getCode() << "," << this->finalClass->getCode() << endl;
        }
        else {
            file << this->type << "," << this->student->getNumber() << "," << this->course->getCode() << ","
                 << this->initialClass->getCode() << "XXXXXXX" << this->initialClass->getCode() << endl;
            ;
        }
    }

    file.close();
}
