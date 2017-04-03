cmake_minimum_required(VERSION 2.8)
project(fluffles)

add_library(libfluffles fluffles.c)
add_executable(fluffles main.c)
target_link_libraries(fluffles libfluffles)
add_subdirectory(test)
