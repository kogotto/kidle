
add_library(
    models
    generator.cpp
    generators.cpp
    world.cpp
    )

target_include_directories(
    models
    PUBLIC
    include
    )
