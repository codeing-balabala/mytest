cmake_minimum_required(VERSION 3.0)
project(my_test)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb3")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
# add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)

target_link_libraries(${PROJECT_NAME} pthread)