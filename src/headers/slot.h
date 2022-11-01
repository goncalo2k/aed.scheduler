

#ifndef SLOT_H
#define SLOT_H

#include <string>

using namespace std;
class Slot {
    private:
        string weekday;
        string startTime;
        string endTime;
        string type;
        int duration;
    public:
        Slot(string day, string time, string room);
        string getWeekDay();
        string getStartTime();
        string getEndTime();
        string getType();
        int getDuration();
        void setWeekDay(string day);
        void setStartTime(string startTime);
        void setEndTime(string endTime);
        void setType(string type);
};


#endif
