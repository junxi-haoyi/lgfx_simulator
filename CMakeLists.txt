cmake_minimum_required(VERSION 3.0.0)
project(lgfx_simulator VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_definitions(-DLGFX_SDL)

file(GLOB Target_Files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CMAKE_CONFIGURE_DEPENDS
    *.cpp
    ./src/*.cpp
    ./LovyanGFX/src/lgfx/Fonts/efont/*.c
    ./LovyanGFX/src/lgfx/Fonts/IPA/*.c
    ./LovyanGFX/src/lgfx/utility/*.c
    ./LovyanGFX/src/lgfx/v1/*.cpp
    ./LovyanGFX/src/lgfx/v1/misc/*.cpp
    ./LovyanGFX/src/lgfx/v1/panel/Panel_Device.cpp
    ./LovyanGFX/src/lgfx/v1/panel/Panel_FrameBufferBase.cpp
    ./LovyanGFX/src/lgfx/v1/platforms/sdl/*.cpp
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/LovyanGFX S)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(lgfx_simulator ${Target_Files})

target_include_directories(${PROJECT_NAME} PUBLIC "./LovyanGFX/src/")

find_package(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} -lpthread ${SDL2_LIBRARIES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
