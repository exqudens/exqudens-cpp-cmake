cmake_minimum_required(VERSION 3.17)

project(ExqudensCPPCmake)

set(CMAKE_CXX_STANDARD 20)

#--- download example ---

#set(MY_URL "https://raw.githubusercontent.com/exqudens/exqudens-c-study-project-a-grade/master/src/main/cpp/application/model/IntArray.h")
##set(MY_URL "file:///C:/exqudens/cpp/exqudens-c-study-project-a-grade/src/main/cpp/application/model/IntArray.h")
##set(MY_DOWNLOAD_PATH "${PROJECT_SOURCE_DIR}/src/main/cpp/IntArray.h")

##if (NOT EXISTS "${MY_DOWNLOAD_PATH}")
    ##file(DOWNLOAD "${MY_URL}" "${MY_DOWNLOAD_PATH}")
##endif()

#------------------------

set(
        SOURCE_FILES
        src/main/cpp/exqudens/strings.hpp
)

set(
        TEST_FILES
        ${SOURCE_FILES}
        src/test/cpp/tests.hpp
        src/test/cpp/tests.cpp
        src/test/cpp/test_1.hpp
        src/test/cpp/test_2.hpp
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

add_test(NAME test_1_run COMMAND ${CMAKE_PROJECT_NAME}RunTests test_1_run)
add_test(NAME test_2_run COMMAND ${CMAKE_PROJECT_NAME}RunTests test_2_run)

add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME}RunTests
        POST_BUILD
        COMMAND ctest -C $<CONFIGURATION> --output-on-failure
)
