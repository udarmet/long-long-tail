cmake_minimum_required (VERSION 3.1)
project (long-long-tail)

# Find external libraries
find_package (SFML 2.5 COMPONENTS graphics REQUIRED)

# Link sources and libraries
add_executable (${PROJECT_NAME} src/main.cpp)
target_link_libraries (${PROJECT_NAME} sfml-graphics)

