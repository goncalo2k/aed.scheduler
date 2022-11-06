#include <bits/stdc++.h>

#include "src/headers/MenuHandler.h"
#include "src/headers/Schedule.h"

using namespace std;


/**
 * @brief main
 * Reads classes, courses, students and denied requests from files.
 * Shows the main menu.
 * @return 0
 */
int main() {
    auto menuHandler = new MenuHandler();

    studentSet students;
    classSet classes;
    courseSet courses;

    menuHandler->readClasses(&classes);
    menuHandler->readCourses(&courses);
    menuHandler->readStudents(&students, &classes, &courses);

    requestQueue requests;
    requestVector deniedRequests;

    menuHandler->readDeniedRequests(&deniedRequests);

    char option = '1';

    while (option != '0') {
        menuHandler->clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Listing                                       " << endl;
        cout << "  2 - Schedule view                                 " << endl;
        cout << "  3 - Request submission                            " << endl;
        cout << "                                                    " << endl;
        cout << "  4 - Request processing                            " << endl;
        cout << "  5 - Archived requests                             " << endl;
        cout << "                                                    " << endl;
        cout << "  0 - Exit                                          " << endl;
        cout << " __________________________________________________ " << endl;
        cout << "  Option:";

        cin >> option;

        switch (option) {
            case '1':
                menuHandler->listMenu(&students, &classes, &courses);
                break;
            case '2':
                menuHandler->scheduleView(&students, &classes);
                break;
            case '3':
                menuHandler->requestsMenu(&requests,&students, &classes, &courses);
                break;
            case '4':
                menuHandler->requestProcessing(&requests, &deniedRequests);
                break;
            case '5':
                menuHandler->listDeniedRequests(&deniedRequests);
                break;
            case '0':
                break;
            default:
                cout << "  Invalid option!" << endl;
                menuHandler->wait();
                break;
        }
    }

    return 0;
}

