cmake_minimum_required(VERSION 3.26)
project(SDL2_app)

set(CMAKE_CXX_STANDARD 17)

#including SDL2 library
set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(SDL2_app main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
