# Basic

## Project
cmake_minimum_required(VERSION 3.12)
project("cpw-dbmanager" VERSION 0.0.1 LANGUAGES CXX)

## Put variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(HEADER "${PROJECT_SOURCE_DIR}/include")

## Build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

## Compiler options
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

## Set up prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
endif()

# Config file
configure_file("${PROJECT_NAME}Config.h.in" "${PROJECT_NAME}Config.h")
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
include_directories(${HEADER})