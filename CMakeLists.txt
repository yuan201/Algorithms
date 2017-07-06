cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-std=gnu++11") #Turn on C++11 support

set(FILES_TO_TEST sort.cpp dnc.cpp)
set(UTILITIES utility.cpp)
set(UNIT_TESTS_SORT test_sort.cpp)
set(UNIT_TESTS_DNC test_dnc.cpp)
set(MAIN_FILE main.cpp)

add_subdirectory(googletest)
include_directories(googletest/include)
include_directories(.)
add_library(codeToTest ${FILES_TO_TEST})
add_library(utility ${UTILITIES})

add_executable(proj ${MAIN_FILE})
target_link_libraries(proj codeToTest utility)

add_executable(sort-test ${UNIT_TESTS_SORT})
target_link_libraries(sort-test gtest gtest_main rt pthread codeToTest utility)

add_executable(dnc-test ${UNIT_TESTS_DNC})
target_link_libraries(dnc-test gtest gtest_main rt pthread codeToTest utility)
