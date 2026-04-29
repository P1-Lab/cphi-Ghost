cmake_minimum_required(VERSION 3.16)
project(cphi_ghost_firmware)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compile Options for RK3588 (ARMv8-A / Neon Optimization)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    add_compile_options(-march=armv8-a+crypto+crc+dotprod -O3)
endif()

# Find Dependencies
find_package(Threads REQUIRED)

# Include Directories
include_directories(
    src 
    src/dsp 
    src/hardware
)

# Define the LADSPA Plugin for VGL-1
add_library(vgl1_ladspa SHARED
    src/dsp/vgl1_filters.c
)
set_target_properties(vgl1_ladspa PROPERTIES PREFIX "")
target_link_libraries(vgl1_ladspa m)

# Define the Main Ghost Daemon
add_executable(ghost-daemon 
    src/main.cpp
    src/service/ghost-daemon.cpp
)

target_link_libraries(ghost-daemon 
    Threads::Threads 
    m 
    gpiod  # Requires libgpiod-dev for physical switch polling
)

# Installation paths for PostmarketOS
install(TARGETS ghost-daemon DESTINATION /usr/bin)
install(TARGETS vgl1_ladspa DESTINATION /usr/lib/ladspa)
