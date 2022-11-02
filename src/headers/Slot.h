#ifndef SLOT_H
#define SLOT_H

#include <bits/stdc++.h>

using namespace std;

class Slot {
private:
    string weekday;
    float startTime;
    float endTime;
    float duration;
    string type;

public:
    Slot(string day, float startTime, float endTime, float duration, string type);
    string getWeekDay() const;
    string getStartTime() const;
    string getEndTime() const;
    string getType() const;
    int getDuration() const;
    void setWeekDay(string day);
    void setStartTime(string startTime);
    void setEndTime(string endTime);
    void setType(string type);
};

#endif