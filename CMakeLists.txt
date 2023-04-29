cmake_minimum_required(VERSION 3.10)

project(syscall_example)

add_executable(syscall_example src/main.c)

target_link_libraries(syscall_example pthread jsoncpp)
