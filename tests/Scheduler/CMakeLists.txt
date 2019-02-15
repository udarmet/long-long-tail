cmake_minimum_required (VERSION 3.1)
project (long-long-tail-tests-scheduler)

# Setup compiler
set (CMAKE_CXX_STANDARD 14)

# List source files
set (SOURCES
    ../../src/common/scheduler/Module.cpp
    ../../src/common/scheduler/ModulesSequence.cpp
    ../../src/common/scheduler/Scheduler.cpp
    main.cpp)
set (HEADERS
    ../../src/common/scheduler/Module.h
    ../../src/common/scheduler/ModulesSequence.h
    ../../src/common/scheduler/Scheduler.h)

# Link sources and libraries
add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})

