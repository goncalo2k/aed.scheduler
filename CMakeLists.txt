cmake_minimum_required(VERSION 3.23)
project(schedules)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedules main.cpp src/definition/slot.cpp src/headers/slot.h src/definition/student.cpp src/headers/student.h src/definition/uc_classes.cpp src/headers/uc_classes.h src/definition/class_schedule.cpp src/headers/class_schedule.h src/definition/schedule_management.cpp src/headers/schedule_management.h src/definition/request.cpp src/headers/request.h)
