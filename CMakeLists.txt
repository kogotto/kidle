cmake_minimum_required(VERSION 3.16.3)

project(kidle)

set(
    CMAKE_EXPORT_COMPILE_COMMANDS
    TRUE
    )

add_executable(${PROJECT_NAME}
               main.cpp
               )

target_compile_features(
    kidle PRIVATE cxx_std_23)

add_subdirectory(model)
add_subdirectory(view)

target_link_libraries(${PROJECT_NAME}
                      pthread
                      model
                      view
                      )
