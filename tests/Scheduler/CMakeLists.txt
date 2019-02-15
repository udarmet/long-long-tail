cmake_minimum_required (VERSION 3.1)
project (long-long-tail-tests-Scheduler)

# Setup compiler
set (CMAKE_CXX_STANDARD 14)

# List source files
set (SOURCES
    ../../src/common/Module.cpp
    ../../src/common/ModulesSequence.cpp
    ../../src/common/Scheduler.cpp
    main.cpp)
set (HEADERS
    ../../src/common/Module.h
    ../../src/common/ModulesSequence.h
    ../../src/common/Scheduler.h)

# Link sources and libraries
add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})

