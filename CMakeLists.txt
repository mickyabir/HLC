cmake_minimum_required(VERSION 3.27)
project(HLC)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE __HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h)

add_executable(hlc main.cpp ${__HEADER_FILES})

target_include_directories(hlc
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include)