cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(clib)

set(CMAKE_C_FLAGS "-g -Wall -std=c89")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall -std=c89")
set(CMAKE_C_FLAGS_RELEASE "-Wall -std=c89")

# library
file(GLOB_RECURSE LIB_FILES 
    stdinread.c stdinread.h common.h 
    container/* 
    mem/* 
    except/*
    atom/*)
add_library(clib ${LIB_FILES})

# test project
include_directories(${PROJECT_SOURCE_DIR} testcase)
file(GLOB_RECURSE TEST_FILES testcase/main.c testcase/test/* testcase/unity/*)
add_executable(maintest ${TEST_FILES})
target_link_libraries(maintest clib)
