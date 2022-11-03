#include <utility>

#include "../headers/Slot.h"

Slot::Slot(string weekday, float startTime, float endTime, float duration, string type) {
    this->weekday = std::move(weekday);
    this->startTime = startTime;
    this->endTime = endTime;
    this->duration = duration;
    this->type = std::move(type);
}

string Slot::getWeekDay() const {
    return this->weekday;
}

float Slot::getStartTime() const {
    return this->startTime;
}

float Slot::getEndTime() const {
    return this->endTime;
}

float Slot::getDuration() const {
    return this->duration;
}

string Slot::getType() const {
    return this->type;
}

bool Slot::operator<(const Slot& slot) const {
    return this->startTime < slot.startTime;
}



