#include <utility>

#include "../headers/Slot.h"

/**
 * @brief Slot::Slot
 * Constructor for the Slot class.
 * @param weekday - The day of the week the class represented by the slot is on.
 * @param startTime - The time the class represented by the slot starts.
 * @param endTime - The time the class represented by the slot ends.
 * @param duration - The duration of the class represented by the slot.
 * @param type - The type of the class represented by the slot - either T or TP.
 */
Slot::Slot(string weekday, float startTime, float endTime, float duration, string type) {
    this->weekday = std::move(weekday);
    this->startTime = startTime;
    this->endTime = endTime;
    this->duration = duration;
    this->type = std::move(type);
}

/**
 * @brief Slot::getWeekDay
 * Getter for the weekday the slot is in.
 * @return The weekday the slot is in.
 */
string Slot::getWeekDay() const {
    return this->weekday;
}

/**
 * @brief Slot::getStartTime
 * Getter for the slot's start time.
 * @return The slot's start time.
 */
float Slot::getStartTime() const {
    return this->startTime;
}

/**
 * @brief Slot::getEndTime
 * Getter for the slot's end time.
 * @return The slot's end time.
 */
float Slot::getEndTime() const {
    return this->endTime;
}

/**
 * @brief Slot::getDuration
 * Getter for the slot's duration.
 * @return The slot's duration.
 */
float Slot::getDuration() const {
    return this->duration;
}

/**
 * @brief Slot::getType
 * Getter for the slot's type.
 * @return The slot's type.
 */
string Slot::getType() const {
    return this->type;
}

/**
 * @brief Slot::operator <
 * Overloaded operator < for the Slot class.
 * @param slot - The slot to compare to.
 * @return True if the slot is before the other slot, false otherwise.
 */
bool Slot::operator<(const Slot& slot) const {
    return this->startTime < slot.startTime;
}



