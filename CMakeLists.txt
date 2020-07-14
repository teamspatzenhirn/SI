cmake_minimum_required(VERSION 3.12)
project(SI)

add_library(${PROJECT_NAME} SHARED SiPrinter.cpp SiPrinterExtended.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED OFF)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -mtune=native -march=native)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -O0 -ggdb)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -O3)
endif ()
