#include <bits/stdc++.h>


#include "src/headers/Student.h"
#include "src/headers/Class.h"
#include "src/headers/Course.h"

using namespace std;


/**
 * @brief CompareStudent
 * Allows to compare two students by their numbers.
 */
struct compareStudent {
    bool operator()(Student* s1, Student* s2) const {
        return s1->getNumber() < s2->getNumber();
    }
};

/**
 * @brief CompareClass
 * Allows to compare two classes by their codes.
 */
struct compareClass {
    bool operator()(Class* c1, Class* c2) const {
        if (c1->getCourse() == c2->getCourse()) return c1->getCode() < c2->getCode();
        return c1->getCourse() < c2->getCourse();
    }
};

/**
 * @brief CompareCourse
 * Allows to compare two courses by their codes.
 */
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
void classesFilters(classSet* classes, studentSet* students);
void listClasses(classSet* classes, studentSet* students, int op1, int op2, int op3);
void coursesFilters(courseSet* courses, studentSet* students);
void listCourses(courseSet* courses, studentSet* students, int op1, int op2, int op3);
void scheduleView(studentSet* students, classSet* classes);
void scheduleManagement(studentSet* students, classSet* classes, courseSet* courses);
void requestsMenu(studentSet* students, classSet* classes, courseSet* courses);

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
        cout << "  2 - Visualizacao de horarios                      " << endl;
        cout << "  3 - Gestao de horarios                            " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Sair                                          " << endl;
        cout << " __________________________________________________ " << endl;
        cout << "  Opcao:";

        cin >> option;

        switch (option) {
            case '1':
                listMenu(&students, &classes, &courses);
                break;
            case '2':
                scheduleView(&students, &classes);
                break;
            case '3':
                scheduleManagement(&students, &classes, &courses);
                break;
            default:
                break;
        }
    }

    return 0;
}

/**
 * @brief readStudents
 * Reads the students from the file "students_classes.csv" and adds them to the respective set, as well as their classes and the courses they're enrolled in.
 * @param students - Set of students - read from the files.
 * @param classes - Set of classes read from the files.
 * @param courses - Set of courses read from the files.
 */
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

/**
 * @brief readClasses
 * Reads the classes from the file "classes.csv" and adds them to the respective  set.
 * @param classes - Set of classes read from the files.
 */
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

/**
 * @brief readCourses
 * Reads the courses from the file "classes_per_uc.csv" and adds them to the respective set.
 * @param courses - Set of courses read from the files.
 */
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

/**
 * @brief clearScreen
 * Clears the screen.
 */
void clearScreen() {
    cout << string(50, '\n');
}

/**
 * @brief wait
 * Waits for the user to press any key.
 */
void wait() {
    cout << endl << "Press any key to continue...";
    cin.get();
    cin.get();
}

/**
 * @brief listMenu
 * Displays the list menu.
 * @param students - Set of students read from the files.
 * @param classes - Set of classes read from the files.
 * @param courses - Set of courses read from the files.
 */
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
                classesFilters(classes, students);
                break;
            case '3':
                coursesFilters(courses, students);
                break;
            default:
                break;
        }
    }
}

/**
 * @brief studentsFilters
 * Handles all the users' options when listing students.
 * @param students - Set of students read from the files.
 */
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

    wait();
}

/**
 * @listStudents
 * Lists all the students in the set, correctly filtered, according to studentFilters.
 * @param students - Set of students read from the files.
 * @param op1 - Option 1 - manages how the students will be displayed: either by name or by number.
 * @param op2 - Option 2 - manages the order of the students: either ascending or descending.
 * @param op3 - Option 3 - manages whether the classes of each student will be displayed or not.
 * @param op4 - Option 4 - manages whether all the students will be displayed or just a part of them.
 * @param min - Lower bound of the interval for option 4.
 * @param max - Upper bound of the interval for option 4.
 */
void listStudents(studentSet* students, int op1, int op2, int op3, int op4, int min, int max) {
    clearScreen();

    vector<Student*> v;

    if (op4 == 1) {
        for (auto student : *students) {
            if (student->getNumber() >= min && student->getNumber() <= max) {
                v.push_back(student);
            }
        }

    }

    else {
        for (auto student : *students) {
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
}

/**
 * @brief classesFilters
 * Handles all the users' options when listing classes.
 * @param classes - Set of classes read from the files.
 * @param students - Set of students read from the files.
 */
void classesFilters(classSet* classes, studentSet* students) {
    clearScreen();

    int op1 = -1, op2 = -1, op3 = -1, op4 = -1;

    cout << "Ordenar por: Codigo (0) | Ocupacao (1)" << endl;
    while (op1 != 0 && op1 != 1) { cout << "Opcao:"; cin >> op1; cout << endl; }

    cout << "Ordenacao: Crescente (0) | Decrescente (1)" << endl;
    while (op2 != 0 && op2 != 1) { cout << "Opcao:"; cin >> op2; cout << endl; }

    cout << "Mostrar alunos de cada turma? Nao (0) | Sim (1)" << endl;
    while (op3 != 0 && op3 != 1) { cout << "Opcao:"; cin >> op3; cout << endl; }

    listClasses(classes, students, op1, op2, op3);

    wait();
}

/**
 * @brief listClasses
 * Lists all the classes in the set, correctly filtered, according to classFilters.
 * @param classes - Set of classes read from the files.
 * @param students - Set of students read from the files.
 * @param op1 - Option 1 - manages how the classes will be displayed: either by code or by occupation.
 * @param op2 - Option 2 - manages the order of the classes: either ascending or descending.
 * @param op3 - Option 3 - manages whether the students of each class will be displayed or not.
 */
void listClasses(classSet* classes, studentSet* students, int op1, int op2, int op3) {
    clearScreen();

    vector<Class*> v;

    for (auto cl : *classes) {
        v.push_back(cl);
    }

    sort(v.begin(), v.end(), [op1, op2](Class* a, Class* b) {
        if (op1 == 0) {
            if (op2 == 0) {
                return a->getCode() < b->getCode();
            } else {
                return a->getCode() > b->getCode();
            }
        } else {
            if (op2 == 0) {
                return a->getStudents().size() < b->getStudents().size();
            } else {
                return a->getStudents().size() > b->getStudents().size();
            }
        }
    });


    for (auto cl : v) {
        cout << "  " << cl->getCourse() << " - " << cl->getCode() << endl;
        if (op3 == 1) {
            for (const auto& s: cl->getStudents()) {
                auto it = students->find(new Student(s, ""));
                cout << "    " << (*it)->getNumber() << " - " << (*it)->getName() << endl;
            }
        }
    }

    wait();
}

/**
 * courseFilters
 * Handles all the users' options when listing courses.
 * @param courses - Set of courses read from the files.
 * @param students - Set of students read from the files.
 */
void coursesFilters(courseSet *courses, studentSet *students) {
    clearScreen();

    int op1 = -1, op2 = -1, op3 = -1;

    cout << "Ordenacao (por ocupacao): Crescente (0) | Decrescente (1)" << endl;
    while (op1 != 0 && op1 != 1) { cout << "Opcao:"; cin >> op1; cout << endl; }

    cout << "Mostrar turmas de cada unidade curricular? Nao (0) | Sim (1)" << endl;
    while (op2 != 0 && op2 != 1) { cout << "Opcao:"; cin >> op2; cout << endl; }

    cout << "Mostrar estudantes de cada unidade curricular? Nao (0) | Sim (1)" << endl;
    while (op3 != 0 && op3 != 1) { cout << "Opcao:"; cin >> op3; cout << endl; }

    listCourses(courses, students, op1, op2, op3);

    wait();
}

/**
 * @brief listCourses
 * Lists all the courses in the set, correctly filtered, according to courseFilters.
 * @param courses - Set of courses read from the files.
 * @param students - Set of students read from the files.
 * @param op1 - Option 1 - manages the order of the courses: either ascending or descending.
 * @param op2 - Option 2 - manages whether the classes of each course will be displayed or not.
 * @param op3 - Option 3 - manages whether the students of each course will be displayed or not.
 */
void listCourses(courseSet* courses, studentSet* students, int op1, int op2, int op3) {
    clearScreen();

    vector<Course*> v;

    for (auto course : *courses) {
        v.push_back(course);
    }

    sort(v.begin(), v.end(), [op1](Course* a, Course* b) {
        if (op1 == 0) {
            return a->getStudents().size() < b->getStudents().size();
        } else {
            return a->getStudents().size() > b->getStudents().size();
        }
    });

    for (auto course : v) {
        cout << "  " << course->getCode() << endl;
        if (op2 == 1) {
            for (const auto& class_ : course->getClasses()) {
                cout << "    " << class_ << endl;
                if (op3 == 1) {
                    for (const auto& student : course->getStudents()) {
                        auto it = students->find(new Student(student, ""));
                        cout << "        " << (*it)->getNumber() << " - " << (*it)->getName() << endl;
                    }
                }
            }
        }
    }
}

//falta comentar em condicoes a partir daqui

/**
 * @brief scheduleFilters
 * DAWSDAWDWA
 * @param students
 * @param classes
 */
void scheduleView(studentSet* students, classSet* classes) {
    clearScreen();

    auto it1 = students->end();
    while (it1 == students->end()) {
        int number;
        cout << "Introduza o numero de estudante:";
        cin >> number; cout << endl;
        it1 = students->find(new Student(number, ""));
    }

    set<Slot> slots;
    for (const auto &cl: (*it1)->getClasses()) {
        auto it2 = classes->find(new Class(cl.second, cl.first));
        for (const auto &slot: (*it2)->getSlots()) {
            slots.insert(slot);
        }
    }

    (*it1)->setSchedule(new Schedule(slots));
    (*it1)->getSchedule()->printSchedule();

    wait();
}

void scheduleManagement(studentSet* students, classSet* classes, courseSet* courses) {
    char option = '1';
    while (option != '0') {
        clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Visualizar o horario de um aluno              " << endl;
        cout << "  2 - Visualizar o horario de uma turma             " << endl;
        cout << "  3 - Pedir uma troca                               " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Sair                                          " << endl;
        cout << " __________________________________________________ " << endl;
        cout << "  Opcao:";

        cin >> option;

        switch (option) {
            case '1':
                scheduleView(students, classes);
                break;
            case '2':
                scheduleView(students, classes);
                break;
            case '3':
                requestsMenu(students, classes, courses);
                break;
            default:
                break;
        }
    }
}

void requestsMenu(studentSet* students, classSet* classes, courseSet* courses) {
    char option = '1';
    while (option != '0') {
        clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Troca de turma                                " << endl;
        cout << "  2 - Remocao de uma turma                          " << endl;
        cout << "  3 - Atribuicao de uma turma                       " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Sair                                          " << endl;
        cout << " __________________________________________________ " << endl;
        cout << "  Opcao:";

        cin >> option;

        switch (option) {
            case '1':
                scheduleView(students, classes);
                break;
            case '2':
                scheduleView(students, classes);
                break;
            case '3':

                break;
            default:
                break;
        }
    }
}