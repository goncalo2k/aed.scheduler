#include "../headers/slot.h"

Slot::Slot(string day, string time, string room) {
    string weekday = day;
    string startTime = time;
    string endTime = room;
}

string Slot::getWeekDay() {
    return weekday;
}

string Slot::getStartTime() {
    return startTime;
}

string Slot::getEndTime() {
    return endTime;
}

string Slot::getType() {
    return type;
}

int Slot::getDuration() {
    return duration;
}

void Slot::setWeekDay(string day) {
weekday = day;
}

void Slot::setStartTime(string startTime) {
startTime = startTime;
}

void Slot::setEndTime(string endt) {
endTime = endTime;
}

void Slot::setType(string type) {
type = type;
}
