cmake_minimum_required(VERSION 3.5)

project(simple_game LANGUAGES CXX)

FILE(GLOB_RECURSE LibFiles "include/*.h")
add_custom_target(_simple_game_include SOURCES ${LibFiles})

file(GLOB_RECURSE Sources "source/*.cpp")

if(MSVC)
    add_compile_options(/bigobj)
endif(MSVC)

add_executable(simple_game ${Sources})

target_include_directories(simple_game PUBLIC
                            "${PROJECT_SOURCE_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
)
