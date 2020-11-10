cmake_minimum_required(VERSION 3.17)

project(ExqudensCPPCmake)

set(CMAKE_CXX_STANDARD 20)

#--- download example 1 ---

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG        release-1.8.0
#)
#FetchContent_MakeAvailable(googletest)

#message(STATUS "googletest include dir: ${googletest_SOURCE_DIR}/include")

#include_directories(${googletest_SOURCE_DIR}/googletest/include)
#add_executable(Google_Tests_run src/test/cpp/google_test_1.cpp)
#target_link_libraries(Google_Tests_run gtest gtest_main)

#--------------------------

#--- download example 2 ---

#--------------------------

#--- download example 3 ---

#set(MY_URL "https://raw.githubusercontent.com/exqudens/exqudens-c-study-project-a-grade/master/src/main/cpp/application/model/IntArray.h")
##set(MY_URL "file:///C:/exqudens/cpp/exqudens-c-study-project-a-grade/src/main/cpp/application/model/IntArray.h")
##set(MY_DOWNLOAD_PATH "${PROJECT_SOURCE_DIR}/src/main/cpp/IntArray.h")

##if (NOT EXISTS "${MY_DOWNLOAD_PATH}")
    ##file(DOWNLOAD "${MY_URL}" "${MY_DOWNLOAD_PATH}")
##endif()

#--------------------------

set(
        SOURCE_FILES
        src/main/cpp/exqudens/strings.hpp
)

set(
        TEST_FILES
        ${SOURCE_FILES}
        src/test/cpp/tests.hpp
        src/test/cpp/tests.cpp
        src/test/cpp/assertions.hpp
        src/test/cpp/exqudens/test_strings.hpp
)

add_executable(
        ${CMAKE_PROJECT_NAME}RunAllTests
        ${SOURCE_FILES}
        ${TEST_FILES}
        src/test/cpp/run_all_tests.cpp
)

enable_testing()

add_executable(
        ${CMAKE_PROJECT_NAME}RunTests
        ${TEST_FILES}
        src/test/cpp/run_tests.cpp
)

add_test(exqudens_test_strings_test_1 ${CMAKE_PROJECT_NAME}RunTests exqudens_test_strings_test_1)
add_test(exqudens_test_strings_test_2 ${CMAKE_PROJECT_NAME}RunTests exqudens_test_strings_test_2)
add_test(exqudens_test_strings_test_3 ${CMAKE_PROJECT_NAME}RunTests exqudens_test_strings_test_3)
add_test(exqudens_test_strings_test_4 ${CMAKE_PROJECT_NAME}RunTests exqudens_test_strings_test_4)
add_test(exqudens_test_strings_test_5 ${CMAKE_PROJECT_NAME}RunTests exqudens_test_strings_test_5)
add_test(exqudens_test_strings_test_6 ${CMAKE_PROJECT_NAME}RunTests exqudens_test_strings_test_6)

add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME}RunTests
        POST_BUILD
        COMMAND ctest -C $<CONFIGURATION> --output-on-failure
)
