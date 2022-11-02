cmake_minimum_required(VERSION 3.23)
project(schedules)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedules main.cpp src/definitions/Slot.cpp src/headers/Slot.h src/definitions/Student.cpp src/headers/Student.h src/definitions/Class.cpp src/headers/Class.h src/definitions/Request.cpp src/headers/Request.h src/definitions/Course.cpp src/headers/Course.h)
