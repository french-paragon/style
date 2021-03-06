cmake_minimum_required(VERSION 2.8.9)
project(Style)

#cross compilation
unset(MXE_CROSS_COMPILE)
if (CMAKE_CROSS_COMPILING AND CMAKE_SYSTEM_NAME STREQUAL Windows)
    set(MXE_CROSS_COMPILE 1)
    add_definitions(-DCROSS_COMPILE_MXE)
endif (CMAKE_CROSS_COMPILING AND CMAKE_SYSTEM_NAME STREQUAL Windows)

#set (CMAKE_CXX_STANDARD 11) # we use C++ version 11
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

#Qt

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)

ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#prog outputs
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#libs directory

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
link_directories(${CMAKE_BINARY_DIR}/libs)

add_subdirectory(libs)
add_subdirectory(prog)

#copy important files

configure_file(${CMAKE_SOURCE_DIR}/LICENSE ${CMAKE_BINARY_DIR}/LICENSE COPYONLY)
