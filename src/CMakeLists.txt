# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(DEPENDENCY1 REQUIRED gtkmm-3.0)
pkg_search_module(DEPENDENCY2 REQUIRED libmariadb libmysqlclient)

# Targets

## Objects libraries

### objectlibrary
add_library(objectlibrary OBJECT "object_library.cc")
target_include_directories(objectlibrary PUBLIC ${HEADER})
set_target_properties(objectlibrary PROPERTIES POSITION_INDEPENDENT_CODE 1)

## Shared and statics libraries

### library1
add_library(library1 SHARED "library1.cc")
target_include_directories(library1 PUBLIC ${HEADER} ${DEPENDENCY1_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
target_link_libraries(library1 ${DEPENDENCY1_LIBRARIES} objectlibrary)
install(FILES ${HEADER}/library1.h DESTINATION include)
install(TARGETS library1 DESTINATION lib)

### library2
add_library(library2 STATIC "library2.cc")
target_include_directories(library2 PUBLIC ${HEADER} ${DEPENDENCY2_INCLUDE_DIRS})
target_link_libraries(library2 ${DEPENDENCY2_LIBRARIES} objectlibrary)
install(TARGETS library2 DESTINATION lib/{$PROJECT_NAME})

## Main executable
add_executable(${PROJECT_NAME} "main.cc")
target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER})
target_link_libraries(${PROJECT_NAME} PUBLIC library1 library2)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)