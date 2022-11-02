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
        float getStartTime() const;
        float getEndTime() const;
        float getDuration() const;
        string getType() const;
        void setWeekDay(string day);
        void setStartTime(float startTime);
        void setEndTime(float endTime);
        void setType(string type);

        bool operator<(const Slot& slot) const;
};

#endif