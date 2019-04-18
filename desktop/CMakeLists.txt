cmake_minimum_required (VERSION 3.1)
project (long-long-tail-desktop)

# Setup compiler
set (CMAKE_CXX_STANDARD 14)

# Set root directory
set (ROOT ..)

# List source files
set (SOURCES
    src/main.cpp)
set (HEADERS
    )

# List external libraries
find_package (SFML 2.5 COMPONENTS graphics REQUIRED)
set (LIBRARIES
    sfml-graphics)

# Link sources and libraries
add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})
target_include_directories (${PROJECT_NAME} PUBLIC ${ROOT})
