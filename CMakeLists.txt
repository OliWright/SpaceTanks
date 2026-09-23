cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project). The fetching/locating logic now lives in
# the PicoVectorscope framework so projects don't carry their own copy.
include(PicoVectorscope/pico_sdk_import.cmake)

project(SpaceTanks C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        -Wno-psabi
        )

add_executable(${PROJECT_NAME})

include(PicoVectorscope/vectorscope.cmake)
include(PicoVectorscope/extras/extras.cmake)

target_sources(${PROJECT_NAME} PRIVATE
        src/background.cpp
        src/collisions.cpp
        src/enemytanks.cpp
        src/grid.cpp
        src/obstacles.cpp
        src/particles.cpp
        src/player.cpp
        src/projectiles.cpp
        src/radar.cpp
        src/shapes.cpp
        src/spacetanks.cpp
)

# Configure stdio
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

pico_add_extra_outputs(${PROJECT_NAME})
