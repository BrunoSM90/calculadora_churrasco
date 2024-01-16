cmake_minimum_required(VERSION 3.26.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Utilities)

add_library(Utilities INTERFACE InputValidator.h)

target_include_directories(Utilities INTERFACE {CMAKE_CURRENT_SOURCE_DIR})