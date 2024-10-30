cmake_minimum_required(VERSION 3.10)
project(OrderManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

find_package(CURL REQUIRED)
find_package(jsoncpp REQUIRED)

add_executable(OrderManagementSystem ${SOURCES})

target_link_libraries(OrderManagementSystem CURL::libcurl jsoncpp_lib)
