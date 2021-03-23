# Build security
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# Language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler options
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0  -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set up prefix
if(_VOID_PREFIX)
	set(CMAKE_INSTALL_PREFIX "" CACHE PATH "..." FORCE)
	set(${PROJECT_NAME}_DATADIR "share")
else()
	if(_ENABLE_INSTALL_TO_TMP)
		set(CMAKE_INSTALL_PREFIX "/tmp/${PROJECT_NAME}" CACHE PATH "..." FORCE)
	else()
		if(NOT CMAKE_INSTALL_PREFIX)
			set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
		endif()
	endif()
	set(${PROJECT_NAME}_DATADIR "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}")
endif()