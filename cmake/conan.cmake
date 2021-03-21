if(_ENABLE_CONAN)
	list(APPEND CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR})
	list(APPEND CMAKE_PREFIX_PATH ${PROJECT_BINARY_DIR})
	if(NOT EXISTS "${PROJECT_BINARY_DIR}/conan.cmake")
		message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
		file(
			DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
			"${PROJECT_BINARY_DIR}/conan.cmake"
			TLS_VERIFY ON
		)
	endif()

	include(${PROJECT_BINARY_DIR}/conan.cmake)

	conan_cmake_configure(
		REQUIRES poco/1.9.4
		GENERATORS cmake_find_package
	)

	conan_cmake_autodetect(settings)

	conan_cmake_install(
		PATH_OR_REFERENCE .
		BUILD missing
		REMOTE conan-center
		SETTINGS ${settings}
	)

	message("Conan OK")
endif()