cmake_minimum_required(VERSION 3.26.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Services)

file(GLOB SOURCES *.h *.cpp)

set(CURRENT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCE_ROOT "${CURRENT_SOURCE_DIR}/..")
set(ENTITIES_FOLDER "${SOURCE_ROOT}/Entities")
set(UTILITIES_FOLDER "${SOURCE_ROOT}/Utilities")

include_directories(
    "${CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/Entities"
    "${CMAKE_SOURCE_DIR}/Utilities"
)

add_library(Services STATIC ${SOURCES})

target_link_libraries(
    Services
    Entities
    Utilities
)