cmake_minimum_required(VERSION 3.21)
project(SolidRefactoringLab9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest CONFIG REQUIRED)

add_executable(SolidRefactoringDemo
    src/main.cpp
    src/GildedRose.cpp
)
target_include_directories(SolidRefactoringDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_executable(GildedRoseTests
    tests/test_gilded_rose.cpp
    src/GildedRose.cpp
)
target_include_directories(GildedRoseTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(GildedRoseTests PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(GildedRoseTests)
