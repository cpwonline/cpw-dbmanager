set(
	connection_src
	connection.cc
	"${HEADER}/connection.h"
)
set(
	handle_database_src
	handle_database.cc
	"${HEADER}/handle_database.h"
)
set(
	mysql_handler_src
	mysql_handler.cc
	"${HEADER}/mysql_handler.h"
)
set(
	sqlite3_handler_src
	sqlite3_handler.cc
	"${HEADER}/sqlite3_handler.h"
)
set(
	cpw_dbmanager_src
	cpw_dbmanager.cc
	"${HEADER}/cpw_dbmanager.h"
)

include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(DATABASE REQUIRED libmysqlclient libmariadb)
pkg_search_module(SQLITE3 REQUIRED sqlite3)

include_directories(${DATABASE_INCLUDE_DIRS} ${SQLITE3_INCLUDE_DIRS})
link_directories(${DATABASE_LIBRARY_DIRS} ${SQLITE3_LIBRARY_DIRS})

add_library(connection SHARED ${connection_src})
add_library(handle_database SHARED ${handle_database_src})
add_library(mysql_handler SHARED ${mysql_handler_src})
add_library(sqlite3_handler SHARED ${sqlite3_handler_src})
add_library(${PROJECT_NAME} SHARED ${cpw_dbmanager_src})

target_link_libraries(mysql_handler PUBLIC ${DATABASE_LIBRARIES} ${handle_database})
target_link_libraries(sqlite3_handler PUBLIC ${SQLITE3_LIBRARIES} ${handle_database})
target_link_libraries(connection PUBLIC ${handle_database} ${mysql_handler} ${sqlite3_handler})
target_link_libraries(${PROJECT_NAME} PUBLIC ${connection})