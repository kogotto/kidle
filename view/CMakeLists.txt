
add_library(
    view
    generator.cpp
    generators.cpp
    score.cpp
    world.cpp
    )

target_link_libraries(
    view
    model
    )

target_include_directories(
    view
    PUBLIC
    include
    )
