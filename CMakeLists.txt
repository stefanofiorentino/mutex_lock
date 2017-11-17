cmake_minimum_required(VERSION 3.8)
project(mutex_lock)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)

enable_testing()
add_test(MainTest Test)

set(SOURCE_FILES run.cpp include/mutex_lock.h include/run.h)
add_library(mutex_lock ${SOURCE_FILES})