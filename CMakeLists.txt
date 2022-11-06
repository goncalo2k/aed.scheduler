cmake_minimum_required(VERSION 3.23)
project(schedules)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedules main.cpp src/definitions/Slot.cpp src/headers/Slot.h src/definitions/Student.cpp src/headers/Student.h src/definitions/Class.cpp src/headers/Class.h src/definitions/Request.cpp src/headers/Request.h src/definitions/Course.cpp src/headers/Course.h src/definitions/Schedule.cpp src/headers/Schedule.h src/definitions/MenuHandler.cpp src/headers/MenuHandler.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)