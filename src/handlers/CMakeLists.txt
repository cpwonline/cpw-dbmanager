# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)

# Targets

## Objects libraries

if(_BUILD_WITH_MARIADB)
	### mariadbhandler
	add_library(mariadbhandler OBJECT "mariadb_handler.cc")
	pkg_search_module(MARIADB REQUIRED libmariadb)
	target_include_directories(mariadbhandler PUBLIC ${HEADER} ${MARIADB_INCLUDE_DIRS})
	set_target_properties(mariadbhandler PROPERTIES POSITION_INDEPENDENT_CODE 1)
	target_link_libraries(mariadbhandler PUBLIC ${MARIADB_LIBRARIES})
elseif(_BUILD_WITH_MYSQL)
	### mysqlhandler
	add_library(mysqlhandler OBJECT "mysql_handler.cc")
	#pkg_search_module(MYSQL REQUIRED libmysqlclient)
	target_include_directories(mysqlhandler PUBLIC ${HEADER})
	set_target_properties(mysqlhandler PROPERTIES POSITION_INDEPENDENT_CODE 1)
elseif(_BUILD_WITH_SQLITE3)
	### sqlite3handler
	add_library(sqlite3handler OBJECT "sqlite3_handler.cc")
	pkg_search_module(SQLITE3 REQUIRED sqlite3)
	target_include_directories(sqlite3handler PUBLIC ${HEADER})
	set_target_properties(sqlite3handler PROPERTIES POSITION_INDEPENDENT_CODE 1)
endif()