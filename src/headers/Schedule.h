#ifndef SCHEDULES_SCHEDULE_H
#define SCHEDULES_SCHEDULE_H


#include "Slot.h"

class Schedule {
    private:
        set<Slot> slots;

    public:
        Schedule(set<Slot> slots);
        void addSlot(const Slot& slot);
        void removeSlot(const Slot& slot);
        set<Slot> getSlots() const;
        void printSchedule() const;
};

#endif //SCHEDULES_SCHEDULE_H
