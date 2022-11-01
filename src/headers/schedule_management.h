#ifndef SCHEDULES_SCHEDULE_MANAGEMENT_H
#define SCHEDULES_SCHEDULE_MANAGEMENT_H

#include <queue>
#include <set>
#include <vector>
#include "student.h"
#include "class_schedule.h"
#include "request.h"

using namespace std;

class Schedule_Management {
    private:
    set<Student> students;
    vector<ClassSchedule> schedules;
    queue<Request> requests;

    public:

};


#endif //SCHEDULES_SCHEDULE_MANAGEMENT_H
