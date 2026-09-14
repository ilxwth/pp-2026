cmake_minimum_required(VERSION 3.20)

project(lw_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (MSVC)
    add_compile_options(/utf-8)
endif()


add_executable(lw_1 main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(lw_1 PRIVATE Threads::Threads)