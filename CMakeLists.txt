cmake_minimum_required(VERSION 3.26.0)

project(Main)

set(SOURCES main.cpp)

add_subdirectory(Entities)
add_subdirectory(Services)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(Main Entities Services)

#IGNORE

#O comando abaixo resolve o problema de o Main.cpp esperar um .lib e eu ter feito uma .dll (shared)
#Ele faz com que seja criada a .lib E a .dll
#ref: https://stackoverflow.com/questions/53601141/cmake-generated-vs-project-expecting-lib-instead-of-dll
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)