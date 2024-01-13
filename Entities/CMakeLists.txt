cmake_minimum_required(VERSION 3.26.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Entities)

#set(SOURCES Participante.h Participante.cpp Produto.h Produto.cpp)

file(GLOB SOURCES *.h *.cpp)

add_library(Entities STATIC ${SOURCES})