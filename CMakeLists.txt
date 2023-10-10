cmake_minimum_required(VERSION 3.26)
project(SDL2-app)

set(CMAKE_CXX_STANDARD 17)

#including SDL2 library
set(SDL2_INCLUDE_DIR C:/libs/SDL2/include)
set(SDL2_LIB_DIR C:/libs/SDL2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

#including SDL2 Image library
set(SDL2_IMAGE_INCLUDE_DIR C:/libs/SDL2_image/include)
set(SDL2_IMAGE_LIB_DIR C:/libs/SDL2_image/lib/x64)

include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

#including SDL2 Mixer library
set(SDL2_MIXER_INCLUDE_DIR C:/libs/SDL2_mixer/include)
set(SDL2_MIXER_LIB_DIR C:/libs/SDL2_mixer/lib/x64)

include_directories(${SDL2_MIXER_INCLUDE_DIR})
link_directories(${SDL2_MIXER_LIB_DIR})

set(SOURCE_FILES
        src/main.cpp
)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_mixer)