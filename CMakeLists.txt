cmake_minimum_required (VERSION 3.1)
project (long-long-tail)

# Setup compiler
set (CMAKE_CXX_STANDARD 14)

# List source files
set (SOURCES
    src/common/Module.cpp
    src/common/ModulesSequence.cpp
    src/common/Scheduler.cpp
    src/common/Model.cpp
    src/common/View.cpp
    src/common/KeyboardController.cpp
    src/main.cpp)
set (HEADERS
    src/common/Module.h
    src/common/ModulesSequence.h
    src/common/Scheduler.h
    src/common/Model.h
    src/common/View.h
    src/common/KeyboardController.h)

# List external libraries
find_package (SFML 2.5 COMPONENTS graphics REQUIRED)
set (LIBRARIES
    sfml-graphics)

# Link sources and libraries
add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})

