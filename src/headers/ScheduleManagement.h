#ifndef SCHEDULES_SCHEDULEMANAGEMENT_H
#define SCHEDULES_SCHEDULEMANAGEMENT_H

#include <queue>
#include <set>
#include <vector>
#include "Student.h"
#include "class_schedule.h"
#include "Request.h"

using namespace std;

class Schedule_Management {
    private:
    set<Student> students;
    vector<ClassSchedule> schedules;
    queue<Request> requests;

    public:

};


#endif //SCHEDULES_SCHEDULEMANAGEMENT_H
