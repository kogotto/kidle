cmake_minimum_required(VERSION 3.16.3)

project(kidle)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME}
               main.cpp
               curse.cpp)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
