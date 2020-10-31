cmake_minimum_required(VERSION 3.17)

project(ExqudensCPPCmake)

set(CMAKE_CXX_STANDARD 20)

# main

add_subdirectory(src/main/cpp/exqudens/cpp/cmake/util)

add_library(Strings src/main/cpp/exqudens/cpp/cmake/util/Strings.cpp)

#add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# test

add_subdirectory(src/test/cpp/exqudens/cpp/cmake/util)

add_executable(${CMAKE_PROJECT_NAME}StringsTest src/test/cpp/exqudens/cpp/cmake/util/main.cpp)

target_link_libraries(
        ${CMAKE_PROJECT_NAME}StringsTest
        PUBLIC
        Strings
)
