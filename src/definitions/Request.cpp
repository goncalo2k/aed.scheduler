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
 * Constructor for a request of type 2 - removing or adding a student from a class.
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

int Request::getType() const {
    return this->type;
}

Student* Request::getStudent() const {
    return this->student;
}

Class* Request::getInitialClass() const {
    return this->initialClass;
}

Class* Request::getFinalClass() const {
    return this->finalClass;
}

Course* Request::getCourse() const {
    return this->course;
}
/**
 * @brief Request::process
 * This method processes the request, depending on its type.
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
    }

    return true;
}

bool Request::swapProcess(const std::string &fileName) {
    if (this->student->getClasses().find(make_pair(course->getCode(), initialClass->getCode())) == this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is not enrolled in class " << this->initialClass->getCode() << "." << endl;
        this->file();
        return false;
    }

    if (this->student->getClasses().find(make_pair(course->getCode(), finalClass->getCode())) != this->student->getClasses().end()) {
        cout << "Student " << this->student->getNumber() << " is already enrolled in class " << this->finalClass->getCode() << "." << endl;
        this->file();
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

    this->student->addClass(make_pair(initialClass->getCourse(), initialClass->getCode()));
    initialClass->addStudent(this->student->getNumber());
    course->addStudent(this->student->getNumber());

    return true;
}

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
