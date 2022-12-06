cmake_minimum_required(VERSION 3.12)
project(SI)

add_library(${PROJECT_NAME} SHARED src/SiPrinter.cpp src/SiPrinterExtended.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED OFF)
