# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(MYSQL REQUIRED libmysqlclient libmariadb)
pkg_search_module(SQLITE3 REQUIRED sqlite3)

# Targets

## Objects libraries

### mariadbhandler
add_library(mariadbhandler OBJECT "mariadb_handler.cc")
target_include_directories(mariadbhandler PUBLIC ${HEADER})
target_link_libraries(mariadbhandler PUBLIC database)
set_target_properties(mariadbhandler PROPERTIES POSITION_INDEPENDENT_CODE 1)

### mysqlhandler
add_library(mysqlhandler OBJECT "mysql_handler.cc")
target_include_directories(mysqlhandler PUBLIC ${HEADER})
target_link_libraries(mysqlhandler PUBLIC database)
set_target_properties(mysqlhandler PROPERTIES POSITION_INDEPENDENT_CODE 1)

### sqlite3handler
add_library(sqlite3handler OBJECT "sqlite3_handler.cc")
target_include_directories(sqlite3handler PUBLIC ${HEADER})
target_link_libraries(sqlite3handler PUBLIC database)
set_target_properties(sqlite3handler PROPERTIES POSITION_INDEPENDENT_CODE 1)