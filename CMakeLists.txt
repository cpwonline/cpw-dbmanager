# Basic
cmake_minimum_required(VERSION 3.10)
project("cpw-dbmanager" VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Compiler options
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Config file
configure_file("${PROJECT_NAME}Config.h.in" "${PROJECT_NAME}Config.h")

# Put variables
set(HEADER "${PROJECT_SOURCE_DIR}/include")

# Add subdirectories
add_subdirectory(src tests)
include_directories(${HEADER})


# Set up prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
endif()
