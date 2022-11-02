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
void readStudents(studentSet* students);
void readClasses(classSet* classes);
void readCourses(courseSet* courses);


int main() {
    studentSet students;
    classSet classes;
    courseSet courses;

    readStudents(&students);
    readClasses(&classes);
    readCourses(&courses);

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

        (*it)->addClass(make_pair(course, cl));
    }
}


void readClasses(classSet* classes) {
    ifstream file("../schedules/classes.csv");

    string line;
    getline(file, line); // skip first line

    while (getline(file, line)) {
        istringstream iss(line);

        string code;
        string course;
        string day;
        int start;
        int end;

        getline(iss, code, ',');
        getline(iss, course, ',');
        getline(iss, day, ',');
        iss >> start;
        iss.ignore();
        iss >> end;

        auto slot = new Slot(day, start, end);
        auto cl = new Class(code, course, *slot);
        classes->insert(cl);
    }
}

void readCourses(courseSet* courses) {

}



