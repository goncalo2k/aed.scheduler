#include <utility>

#include "../headers/Schedule.h"

Schedule::Schedule(set<Slot> slots) {
    this->slots = std::move(slots);
}

void Schedule::addSlot(const Slot& slot) {
    this->slots.insert(slot);
}

void Schedule::removeSlot(const Slot& slot) {
    if (this->slots.find(slot) != this->slots.end()) this->slots.erase(slot);
}

set<Slot> Schedule::getSlots() const {
    return this->slots;
}

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

