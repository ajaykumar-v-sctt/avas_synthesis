cmake_minimum_required(VERSION 3.16)
project(jetengine_sample LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEAVY_C_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../c/*.c")

add_executable(jetengine_sample
    main.cpp
    JetEngineSample.cpp
    ../c/HeavyContext.cpp
    ../c/HvHeavy.cpp
    ../c/Heavy_jetengine.cpp
    ${HEAVY_C_SOURCES}
)

target_include_directories(jetengine_sample PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../c")
