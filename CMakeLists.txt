cmake_minimum_required (VERSION 3.1)
project (long-long-tail)

# Setup compiler
set (CMAKE_CXX_STANDARD 14)

# List source files
set (SOURCES
    src/common/scheduler/Module.cpp
    src/common/scheduler/ModulesSequence.cpp
    src/common/scheduler/Scheduler.cpp
    src/common/model/Model.cpp
    src/common/view/View.cpp
    src/common/controller/KeyboardController.cpp
    src/main.cpp)
set (HEADERS
    src/common/scheduler/Module.h
    src/common/scheduler/ModulesSequence.h
    src/common/scheduler/Scheduler.h
    src/common/model/Model.h
    src/common/view/View.h
    src/common/controller/KeyboardController.h)

# List external libraries
find_package (SFML 2.5 COMPONENTS graphics REQUIRED)
set (LIBRARIES
    sfml-graphics)

# Link sources and libraries
add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})

