#include <utility>

#include "../headers/Schedule.h"

/**
 * @brief Schedule::Schedule
 * Constructor of the Schedule class
 * Complexity: O(1)
 * @param slots - The slots of the schedule.
 */
Schedule::Schedule(set<Slot> slots) {
    this->slots = std::move(slots);
}

/**
 * @brief Schedule::addSlot
 * This method adds a slot to the schedule.
 * Complexity: O(1)
 * @param slot - The slot to be added to the schedule.
 */
void Schedule::addSlot(const Slot& slot) {
    this->slots.insert(slot);
}

/**
 * @brief Schedule::removeSlot
 * This method removes a slot from the schedule.
 * Complexity: O(log n)
 * @param slot - The slot to be removed from the schedule.
 */
void Schedule::removeSlot(const Slot& slot) {
    if (this->slots.find(slot) != this->slots.end()) this->slots.erase(slot);
}

/**
 * @brief Schedule::getSlots
 * Getter for the schedule's slots.
 * Complexity: O(1)
 * @return The schedule's slots.
 */
set<Slot> Schedule::getSlots() const {
    return this->slots;
}

/**
 * @brief Schedule::printSchedule
 * This method prints the schedule.
 * Complexity: O(n²)
 */
void Schedule::printSchedule() const {
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (auto& day : v) {
        cout << day << ": " << endl << "    | ";
        for (auto& slot : this->slots) {
            if (slot.getWeekDay() == day) {
                cout << slot.getStartTime() << " - " << slot.getEndTime() << " " << slot.getType() << " | ";
            }
        }
        cout << endl;
    }
}

