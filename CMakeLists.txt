cmake_minimum_required(VERSION 3.2.3)
project(libmaps C)
add_library(libmaps src/common_bst.c src/common_avl.c)
target_include_directories(libmaps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)