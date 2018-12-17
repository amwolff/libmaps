cmake_minimum_required(VERSION 3.2.3)

project(libmaps C)

set(CMAKE_C_STANDARD 11)

add_library(libmaps src/map.c src/avl.h src/avl.c)
target_include_directories(libmaps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
