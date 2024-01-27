cmake_minimum_required(VERSION 3.25)

project(cpp-lab-tasks-explorer)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp ${CMAKE_SOURCE_DIR}/main.cpp)

include_directories(${INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
