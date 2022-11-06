
add_library(
    model
    generator.cpp
    generators.cpp
    world.cpp
    )

target_include_directories(
    model
    PUBLIC
    include
    )
