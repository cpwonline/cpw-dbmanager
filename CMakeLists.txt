# Fundamental

cmake_minimum_required(VERSION 3.10)
project("cpw_dbmanager" VERSION 0.0.1)
configure_file(Config.h.in Config.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADER ${CMAKE_SOURCE_DIR}/include)
include_directories(include)
add_subdirectory(src)