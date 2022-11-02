#include <bits/stdc++.h>

#include "src/headers/Student.h"
#include "src/headers/Class.h"
#include "src/headers/Course.h"

using namespace std;

struct compareStudent {
    bool operator()(Student* s1, Student* s2) const {
        return s1->getNumber() < s2->getNumber();
    }
};

struct compareClass {
    bool operator()(Class* c1, Class* c2) const {
        if (c1->getCourse() == c2->getCourse()) return c1->getCode() < c2->getCode();
        return c1->getCourse() < c2->getCourse();
    }
};

struct compareCourse {
    bool operator()(Course* c1, Course* c2) const {
        return c1->getCode() < c2->getCode();
    }
};


//
typedef set<Student*, compareStudent> studentSet;
typedef set<Class*, compareClass> classSet;
typedef set<Course*, compareCourse> courseSet;


// functions
void readStudents(studentSet* students, classSet* classes, courseSet* courses);
void readClasses(classSet* classes);
void readCourses(courseSet* courses);
void listStudents(studentSet* students);
void listClasses(classSet* classes, studentSet* students);
void listCourses(courseSet* courses, studentSet* students);

int main() {
    studentSet students;
    classSet classes;
    courseSet courses;

    readClasses(&classes);
    readCourses(&courses);
    readStudents(&students, &classes, &courses);
    //listStudents(&students);
    //listClasses(&classes, &students);
    //listCourses(&courses, &students);

    bool flag = true;
    while(flag) {
        cout << " __________________________________________________ " << endl;
        cout << "  1 - Listagens                                     " << endl;
        cout << "  2 -                                               " << endl;
        cout << "  3 -                                               " << endl;
        cout << "  4 -                                               " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Exit                                          " << endl;
        cout << " __________________________________________________ " << endl;

        char option;
        cin >> option;

        switch(option) {
            case '1':
                cout.flush();
                system("cls");
                break;

            case '0':
                flag = false;
                break;
            default:
                flag = true;
                cout << "Invalid option!" << endl;
        }
    }

    return 0;
}


void readStudents(studentSet* students, classSet* classes, courseSet* courses) {
    ifstream file("../schedules/students_classes.csv");

    string line;
    getline(file, line); // skip first line

    while (getline(file, line)) {
        istringstream iss(line);

        int number;
        string name;
        string course;
        string code;

        iss >> number;
        iss.ignore();

        getline(iss, name, ',');
        getline(iss, course, ',');
        iss >> code;

        auto student = new Student(number, name);
        auto it = students->find(student);
        if (it == students->end()) {
            students->insert(student);
            it = students->find(student);
        }

        (*it)->addClass(make_pair(course, code));

        auto class_ = new Class(code, course);
        auto it2 = classes->find(class_);
        if (it2 != classes->end()) {
            (*it2)->addStudent(number);
        }

        auto course_ = new Course(course);
        auto it3 = courses->find(course_);
        if (it3 != courses->end()) {
            (*it3)->addStudent(number);
        }
    }
}

void readClasses(classSet* classes) {
    ifstream file("../schedules/classes.csv");

    string line;
    getline(file, line); // skip first line

    while (getline(file, line)) {
        istringstream iss(line);

        string classCode;
        string courseCode;
        string day;
        float start;
        float end;
        float duration;
        string type;

        getline(iss, classCode, ',');
        getline(iss, courseCode, ',');
        getline(iss, day, ',');

        iss >> start; iss.ignore();
        iss >> duration; iss.ignore();
        iss >> type;

        end = start + duration;

        auto cl = new Class(classCode, courseCode);
        auto it = classes->find(cl);
        if (it == classes->end()) {
            classes->insert(cl);
            it = classes->find(cl);
        }

        (*it)->addSlot(Slot(day, start, end, duration, type));
    }
}


void readCourses(courseSet* courses) {
    ifstream file("../schedules/classes_per_uc.csv");

    string line;
    getline(file, line); // skip first line

    while (getline(file, line)) {
        istringstream iss(line);

        string courseCode;
        string classCode;

        getline(iss, courseCode, ',');
        iss >> classCode;

        auto course = new Course(courseCode);
        auto it = courses->find(course);
        if (it == courses->end()) {
            courses->insert(course);
            it = courses->find(course);
        }

        (*it)->addClass(classCode);
    }
}

void listStudents(studentSet* students) {
    for (auto student : *students) {
        cout << student->getNumber() << " - " << student->getName() << endl;
        for (const auto& s: student->getClasses()) {
            cout << "    " << s.first << " - " << s.second << endl;
        }
    }
}

void listClasses(classSet* classes, studentSet* students) {
    for (auto cl : *classes) {
        cout << cl->getCourse() << " - " << cl->getCode() << endl;
        for (const auto& s: cl->getSlots()) {
            cout << "    " << s.getWeekDay() << " - " << s.getStartTime() << " - " << s.getEndTime() << " - " << s.getDuration() << " - " << s.getType() << endl;
        }

        for (const auto& s: cl->getStudents()) {
            auto it = students->find(new Student(s, ""));
            cout << "    " << (*it)->getNumber() << " - " << (*it)->getName() << endl;
        }
    }
}

void listCourses(courseSet* courses, studentSet* students) {
    for (auto course : *courses) {
        cout << course->getCode() << endl;
        for (const auto& s: course->getClasses()) {
            cout << "    " << s << endl;
        }

        for (const auto& s: course->getStudents()) {
            auto it = students->find(new Student(s, ""));
            cout << "    " << (*it)->getNumber() << " - " << (*it)->getName() << endl;
        }
    }
}