CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

#set(CMAKE_C_COMPILER /usr/bin/gcc-6)
#set(CMAKE_CXX_STANDARD /usr/bin/g++-6)

project(lab05)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include(~/libs/dlib/dlib/cmake)

add_executable(lab05 main.cpp)

target_link_libraries(lab05 dlib::dlib)
