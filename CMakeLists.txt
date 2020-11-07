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

set(SOURCE_FILES
        src/main/cpp/exqudens/strings.hpp)

set(TEST_FILES
        ${SOURCE_FILES}
        src/test/cpp/main.cpp)

add_executable(${CMAKE_PROJECT_NAME}Test ${TEST_FILES})
