
add_library(
    view
    curse.cpp
    generator.cpp
    generators.cpp
    score.cpp
    world.cpp
    )

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(
    view
    ${CURSES_LIBRARIES}
    model
    )

target_include_directories(
    view
    PUBLIC
    include
    )
