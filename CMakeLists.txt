# Basic

## Project
cmake_minimum_required(VERSION 3.12)
project("cpw-dbmanager" LANGUAGES CXX)
include(cmake/general_options.cmake)
include(cmake/build_settings.cmake)
include(cmake/conan.cmake)

## Version
set(${PROJECT_NAME}_VERSION_MAYOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)
set(${PROJECT_NAME}_VERSION_PATCH 11)
set(${PROJECT_NAME}_VERSION_SUFFIX "-Alpha")

## Put variables
set(HEADER ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_FULL_NAME "CPW DBManager")
set(
	PACKAGE_VERSION 
	${${PROJECT_NAME}_VERSION_MAYOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}
)
set(
	PACKAGE_VERSION_COMPLETE
	${PACKAGE_VERSION}${${PROJECT_NAME}_VERSION_SUFFIX}
)

# Config file
include(GNUInstallDirs)
configure_file(${PROJECT_SOURCE_DIR}/cmake/project_config.h.cmake ${PROJECT_NAME}Config.h)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(share)

# Testing
if(_ENABLE_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()

include(cmake/doxygen.cmake)
include(cmake/files_install.cmake)
include(cmake/print_informations.cmake)