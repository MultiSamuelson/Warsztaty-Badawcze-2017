cmake_minimum_required(VERSION 3.9)

project(lab_4)

include_directories("~/libs/dlib")

set(SOURCE_FILES main.cpp)

add_executable(lab4 ${SOURCE_FILES})
