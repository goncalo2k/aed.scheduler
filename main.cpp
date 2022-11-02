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
        return c1->getUCCode() < c2->getUCCode();
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
void readAll(studentSet* students, classSet* classes, courseSet* courses);
void readStudents(studentSet* students);
void readClasses(classSet* classes);
void readCourses(courseSet* courses);
void listStudents(studentSet* students);
void listClasses(classSet* classes);
//void listCourses(courseSet* courses);


int main() {
    studentSet students;
    classSet classes;
    courseSet courses;

    //readAll(&students, &classes, &courses);
    readStudents(&students);
    listStudents(&students);
    readClasses(&classes);
    //listClasses(&classes);
    //readCourses(&courses);
    //listCourses(&courses);

    cout << " __________________________________________________ " << endl;
    cout << "  1 -                                               " << endl;
    cout << "  2 -                                               " << endl;
    cout << "  3 -                                               " << endl;
    cout << "  4 -                                               " << endl;
    cout << "                                                    " << endl;
    cout << "  0 - Exit                                          " << endl;
    cout << " __________________________________________________ " << endl;

    return 0;
}

void readStudents(studentSet* students) {
    ifstream file("../schedules/students_classes.csv");

    string line;
    getline(file, line); // skip first line

    while (getline(file, line)) {
        istringstream iss(line);

        int number;
        string name;
        string course;
        string cl;

        iss >> number;
        iss.ignore();

        getline(iss, name, ',');
        getline(iss, course, ',');
        iss >> cl;

        auto student = new Student(number, name);
        auto it = students->find(student);
        if (it == students->end()) {
            students->insert(student);
            it = students->find(student);
        }

        (*it)->addCourse(course);
        (*it)->addClass(cl);
    }
}

void readClasses(classSet* classes) {
    ifstream file("../schedules/classes.csv");

    string line;
    getline(file, line); // skip first line
    while (getline(file,line)) {
        istringstream iss(line);

        string classCode;
        string courseCode;
        string weekday;
        string startTime;
        string endTime;
        string classType;

        getline(iss, classCode, ',');
        getline(iss, courseCode, ',');
        getline(iss, weekday, ',');
        getline(iss, startTime, ',');
        getline(iss, endTime, ',');
        getline(iss, classType, ',');

        auto cl = new Class(courseCode, classCode);
        classes->insert(cl);
    }
    
}

void readCourses(courseSet* courses) {

}

void listStudents(studentSet* students) {
    for (auto const& student : *students) {
        cout << student->getNumber() << " - " << student->getName() << endl;
    }
}

