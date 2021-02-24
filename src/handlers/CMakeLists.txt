# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(MYSQL REQUIRED libmysqlclient libmariadb)
pkg_search_module(SQLITE3 REQUIRED sqlite3)

# Add and linking libraries
## mariadbhandler
add_library(mariadbhandler STATIC "mariadb_handler.cc")
target_include_directories(mariadbhandler PUBLIC ${HEADER})
target_link_libraries(mariadbhandler PUBLIC database)
## mysqlhandler
add_library(mysqlhandler STATIC "mysql_handler.cc")
target_include_directories(mysqlhandler PUBLIC ${HEADER})
target_link_libraries(mysqlhandler PUBLIC database)
## sqlite3handler
add_library(sqlite3handler STATIC "sqlite3_handler.cc")
target_include_directories(sqlite3handler PUBLIC ${HEADER})
target_link_libraries(sqlite3handler PUBLIC database)