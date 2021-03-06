# Basic

## Project
cmake_minimum_required(VERSION 3.12)
project("cpw-dbmanager" LANGUAGES CXX)

## Version
set(${PROJECT_NAME}_VERSION_MAYOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 0)
set(${PROJECT_NAME}_VERSION_PATCH 1)
set(${PROJECT_NAME}_VERSION_SUFFIX "-Alpha")

## Put other variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(HEADER "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_FULL_NAME "CPW DBManager")
set(
	PACKAGE_VERSION 
	${${PROJECT_NAME}_VERSION_MAYOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}${${PROJECT_NAME}_VERSION_SUFFIX}
)

## Build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

## Compiler options
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

## Set up prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
endif()

# Config file
include(GNUInstallDirs)
configure_file("${PROJECT_NAME}Config.h.cmake" "${PROJECT_NAME}Config.h")
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)

# Add subdirectories
add_subdirectory(src)
include_directories(${HEADER})

# Testing
if(${PROJECT_NAME}_ENABLE_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()

# Information Summary

# project info
message(STATUS "PROJECT_NAME:                 ${PROJECT_NAME}")
message(STATUS "PROJECT_FULL_NAME:            ${PROJECT_FULL_NAME}")
message(STATUS "PACKAGE_VERSION:              ${PACKAGE_VERSION}")
message(STATUS "ENABLE_TESTING:               ${${PROJECT_NAME}_ENABLE_TESTING}")

# cmake info
message(STATUS "CMAKE_INSTALL_LIBDIR:         ${CMAKE_INSTALL_LIBDIR}")
message(STATUS "CMAKE_SYSTEM_NAME:            ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_VERSION:         ${CMAKE_SYSTEM_VERSION}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR:       ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_CXX_COMPILER:           ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_BUILD_TYPE:             ${CMAKE_BUILD_TYPE}")

if(WIN32)
message(STATUS "CMAKE_PREFIX_PATH:            ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_FIND_LIBRARY_PREFIXES:  ${CMAKE_FIND_LIBRARY_PREFIXES}")
message(STATUS "CMAKE_FIND_LIBRARY_SUFFIXES:  ${CMAKE_FIND_LIBRARY_SUFFIXES}")
endif()

if(WIN32)
message(STATUS "HAVE_MINGW64:                 ${HAVE_MINGW64}")
message(STATUS "MINGW_PATH:                   ${MINGW_PATH}")
message(STATUS "MINGW_ARCH:                   ${MINGW_ARCH}")
message(STATUS "MINGW_ARCH_PATH:              ${MINGW_ARCH_PATH}")
endif()