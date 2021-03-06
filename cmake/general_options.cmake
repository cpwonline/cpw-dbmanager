# General options

## Complete options
option(_ENABLE_ALL "Enable every option" OFF)
option(_ENABLE_FAST "Enable every option" OFF)

## Individual options
option(_ENABLE_TESTING "Enable testing with Google Test" OFF)
option(_ENABLE_CONAN "Enable Conan package manager" OFF)
option(_ENABLE_DOXYGEN "Enable Doxygen documentation" OFF)
option(_ENABLE_VERBOSE "Enable verbose output" OFF)
option(_ENABLE_CCACHE "Enable ccache to speed up the build time" OFF)
option(_ENABLE_CPPCHECK "Enable cppcheck to verify the sources syntax" OFF)
option(_VOID_PREFIX "The prefix is null" OFF)
option(_ENABLE_INSTALL_TO_TMP "The prefix is /tmp" OFF)

## Project options
option(_BUILD_WITH_MARIADB "Build using MariaDB handlers" 1)
option(_BUILD_WITH_MYSQL "Build using MySQL handlers" 0)
option(_BUILD_WITH_SQLITE3 "Build using SQLite3 handlers" 0)

# Handling options

## Complete

if(_ENABLE_COMPLETE)
	set(_ENABLE_TESTING ON)
	set(_ENABLE_CONAN ON)
	set(_ENABLE_DOXYGEN ON)
	set(_ENABLE_VERBOSE ON)
	set(_ENABLE_CCACHE ON)
	set(_ENABLE_CPPCHECK ON)
	set(_VOID_PREFIX ON)
	set(_ENABLE_INSTALL_TO_TMP ON)
endif()

## Individuals

if(_ENABLE_FAST)
	set(_ENABLE_TESTING ON)
	set(_ENABLE_VERBOSE ON)
	set(_ENABLE_CCACHE ON)
	set(_VOID_PREFIX ON)
endif()

if(_ENABLE_VERBOSE)
	set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

if(_ENABLE_CCACHE)
	find_program(CCACHE_FOUND ccache)
	
	if(CCACHE_FOUND)
		set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
		set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
		message("ccache OK")
	else()
		message(FATAL_ERROR "ccache not found. It can't speed up the builds'")
	endif()
endif()

if(_ENABLE_CPPCHECK)
	find_program(CPPCHECK_FOUND cppcheck)
	
	if(CPPCHECK_FOUND)
		set(CMAKE_CXX_CPPCHECK "cppcheck")
		list(
			APPEND CMAKE_CXX_CPPCHECK
			"--language=c++"
			"--enable=warning,style"
			"--inconclusive"
			"--inline-suppr"
		)
		message("CppCheck OK")
	else()
		message(FATAL_ERROR "CppCheck not found. It can't check sources'")
	endif()
endif()

## Project
if(_BUILD_WITH_MYSQL)
	set(_BUILD_WITH_MARIADB 0)
	set(_BUILD_WITH_MYSQL 1)
	set(_BUILD_WITH_SQLITE3 0)
	set(${PROJECT_NAME}_DEPENDENCIES mysql)
	set(${PROJECT_NAME}_name ${PROJECT_NAME}-mysql)
elseif(_BUILD_WITH_SQLITE3)
	set(_BUILD_WITH_MARIADB 0)
	set(_BUILD_WITH_MYSQL 0)
	set(_BUILD_WITH_SQLITE3 1)
	set(${PROJECT_NAME}_DEPENDENCIES sqlite3)
	set(${PROJECT_NAME}_name ${PROJECT_NAME}-sqlite3)
elseif(_BUILD_WITH_MARIADB)
	set(_BUILD_WITH_MARIADB 1)
	set(_BUILD_WITH_MYSQL 0)
	set(_BUILD_WITH_SQLITE3 0)
	set(${PROJECT_NAME}_DEPENDENCIES mariadb)
	set(${PROJECT_NAME}_name ${PROJECT_NAME}-mariadb)
endif()