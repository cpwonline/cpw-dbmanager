# Fundamental

cmake_minimum_required(VERSION 3.10)
project("cpw-dbmanager" VERSION 0.0.1)
configure_file(Config.h.in Config.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(HEADER ${CMAKE_SOURCE_DIR}/include)
include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)

target_include_directories(
	${PROJECT_NAME} PUBLIC
	"${PROJECT_BINARY_DIR}"
)