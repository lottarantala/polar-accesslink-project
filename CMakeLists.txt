cmake_minimum_required(VERSION 3.10.0)
project(polar-accesslink-project VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(polar-accesslink-project main.cpp AccesslinkData.cpp)

file(COPY ${CMAKE_SOURCE_DIR}/accesslink_information.json DESTINATION ${CMAKE_BINARY_DIR})

include(CTest)
enable_testing()

