cmake_minimum_required(VERSION 3.28)
project(leya_ecs)

set(CMAKE_CXX_STANDARD 20)

add_library(leya_ecs INTERFACE)

target_include_directories(leya_ecs INTERFACE "${CMAKE_SOURCE_DIR}/include")

add_subdirectory(examples)