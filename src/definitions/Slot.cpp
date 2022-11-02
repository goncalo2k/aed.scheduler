#include "../headers/Slot.h"

Slot::Slot(string weekday, string startTime, string endTime, string type, int duration) {
    this->weekday = weekday;
    this->startTime = startTime;
    this->endTime = endTime;
    this->type = type;
    this->duration = duration;
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
