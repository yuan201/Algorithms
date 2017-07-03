cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-std=gnu++11") #Turn on C++11 support

set(FILES_TO_TEST sort.cpp)
set(UNIT_TESTS test_sort.cpp)
set(MAIN_FILE main.cpp)

add_subdirectory(googletest)
include_directories(googletest/include)
include_directories(.)
add_library(codeToTest ${FILES_TO_TEST})

add_executable(proj ${MAIN_FILE})
target_link_libraries(proj codeToTest)

add_executable(unit-test ${UNIT_TESTS})
target_link_libraries(unit-test gtest gtest_main rt pthread codeToTest)
