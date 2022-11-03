#include <bits/stdc++.h>


#include "src/headers/Student.h"
#include "src/headers/Class.h"
#include "src/headers/Course.h"

using namespace std;


//
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
void clearScreen();
void wait();
void listMenu(studentSet* students, classSet* classes, courseSet* courses);
void studentsFilters(studentSet* students);
void listStudents(studentSet* students, int op1, int op2, int op3, int op4, int min, int max);
void classesFilters(classSet* classes);
void listClasses(classSet* classes, studentSet* students);
void listCourses(courseSet* courses, studentSet* students);


int main() {
    studentSet students;
    classSet classes;
    courseSet courses;

    readClasses(&classes);
    readCourses(&courses);
    readStudents(&students, &classes, &courses);

    char option = '1';
    while (option != '0') {
        clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Listagens                                     " << endl;
        cout << "  2 -                                               " << endl;
        cout << "  3 -                                               " << endl;
        cout << "  4 -                                               " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Sair                                          " << endl;
        cout << " __________________________________________________ " << endl;
        cout << "  Opcao:";

        cin >> option;

        switch (option) {
            case '1':
                listMenu(&students, &classes, &courses);
                break;
            case '0':
            default:
                break;
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

void clearScreen() {
    cout << string(50, '\n');
}

void wait() {
    cout << endl << "Press any key to continue...";
    cin.get();
    cin.get();
}

void listMenu(studentSet* students, classSet* classes, courseSet* courses) {
    char option = '1';
    while (option != '0') {
        clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Listar estudantes                             " << endl;
        cout << "  2 - Listar turmas                                 " << endl;
        cout << "  3 - Listar unidades curriculares                  " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Voltar                                        " << endl;
        cout << " __________________________________________________ " << endl;
        cout << "  Opcao:";

        cin >> option;

        switch (option) {
            case '1':
                studentsFilters(students);
                break;
            case '2':
                listClasses(classes, students);
                break;
            case '3':
                listCourses(courses, students);
                break;
            case '0':
            default:
                break;
        }
    }
}

void studentsFilters(studentSet* students) {
    clearScreen();

    int op1 = -1, op2 = -1, op3 = -1, op4 = -1;
    int min, max;

    cout << "Ordenar por: Numero (0) | Nome (1)" << endl;
    while (op1 != 0 && op1 != 1) { cout << "Opcao:"; cin >> op1; cout << endl; }

    cout << "Definir intervalo? Nao (0) | Sim (1)" << endl;
    while (op4 != 0 && op4 != 1) { cout << "Opcao:"; cin >> op4; cout << endl; }
    if (op4 == 1) {
        cout << endl << "Intervalo" << endl;
        cout << "Minimo:"; cin >> min;
        cout << "Maximo:"; cin >> max;
    }

    cout << "Ordenacao: Crescente (0) | Decrescente (1)" << endl;
    while (op2 != 0 && op2 != 1) { cout << "Opcao:"; cin >> op2; cout << endl; }

    cout << "Mostrar turmas de cada estudante? Nao (0) | Sim (1)" << endl;
    while (op3 != 0 && op3 != 1) { cout << "Opcao:"; cin >> op3; cout << endl; }

    listStudents(students, op1, op2, op3, op4, min, max);
}

void listStudents(studentSet* students, int op1, int op2, int op3, int op4, int min, int max) {
    clearScreen();

    vector<Student*> v;

    for (auto student : *students) {
        if (op4 == 1) {
            if (student->getNumber() >= min && student->getNumber() <= max) {
                v.push_back(student);
            }
        }

        else {
            v.push_back(student);
        }
    }

    sort(v.begin(), v.end(), [op1, op2](Student* a, Student* b) {
        if (op1 == 0) {
            if (op2 == 0) {
                return a->getNumber() < b->getNumber();
            } else {
                return a->getNumber() > b->getNumber();
            }
        } else {
            if (op2 == 0) {
                return a->getName() < b->getName();
            } else {
                return a->getName() > b->getName();
            }
        }
    });

    for (auto student : v) {
        cout << "  " << student->getNumber() << " - " << student->getName() << endl;
        if (op3 == 1) {
            for (const auto& class_ : student->getClasses()) {
                cout << "    " << class_.first << " - " << class_.second << endl;
            }
        }
    }

    wait();
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
