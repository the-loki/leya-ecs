cmake_minimum_required(VERSION 3.28)
project(leya_ecs_examples)

add_executable(leya_ecs_examples)
target_sources(leya_ecs_examples PRIVATE main.cpp)

target_link_libraries(leya_ecs_examples PRIVATE leya_ecs)