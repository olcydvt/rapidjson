cmake_minimum_required(VERSION 2.8.12)
project(rapid)



include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(rapid main.cpp)
target_link_libraries(rapid ${CONAN_LIBS})
