cmake_minimum_required(VERSION 3.15)

project(
        IsothermLib
        VERSION 1.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -fassociative-math -freciprocal-math -fno-signed-zeros -fno-trapping-math")

option(BUILD_TESTS "Build test programs" OFF)

add_subdirectory(IsothermLib)


if(NOT BUILD_TESTS)
    message(BUILD_TESTS="${BUILD_TESTS} -> NAO COMPILAR OS TESTES")
    add_subdirectory ("docs")
else()
    message(BUILD_TESTS="${BUILD_TESTS} -> COMPILAR OS TESTES")
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    include(CTest)

    if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
        add_subdirectory(IsothermLibTest)
    endif ()

    enable_testing()

endif(NOT BUILD_TESTS)

unset(BUILD_TESTS CACHE) # <---- this is the important!!
