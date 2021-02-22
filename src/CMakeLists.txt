# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(MYSQL REQUIRED libmysqlclient libmariadb)
pkg_search_module(SQLITE3 REQUIRED sqlite3)

# Add and linking libraries
## cpwdbmanager
add_library(cpwdbmanager SHARED "cpw_dbmanager.cc")
target_include_directories(cpwdbmanager PUBLIC ${HEADER})
## column
add_library(column SHARED "column.cc")
target_include_directories(column PUBLIC ${HEADER})
## connection
add_library(connection SHARED "connection.cc")
target_include_directories(connection PUBLIC ${HEADER})
## database
add_library(database SHARED "database.cc")
target_include_directories(database PUBLIC ${HEADER})
## mariadb_handler
add_library(mariadb_handler SHARED "mariadb_handler.cc")
target_include_directories(mariadb_handler PUBLIC ${HEADER})
## mysql_handler
add_library(mysql_handler SHARED "mysql_handler.cc")
target_include_directories(mysql_handler PUBLIC ${HEADER})
## query
add_library(query SHARED "query.cc")
target_include_directories(query PUBLIC ${HEADER})
## result
add_library(result SHARED "result.cc")
target_include_directories(result PUBLIC ${HEADER})
## row
add_library(row SHARED "row.cc")
target_include_directories(row PUBLIC ${HEADER})
## sqlite3handler
add_library(sqlite3handler SHARED "sqlite3_handler.cc")
target_include_directories(sqlite3handler PUBLIC ${HEADER})
## table
add_library(table SHARED "table.cc")
target_include_directories(table PUBLIC ${HEADER})
## url
add_library(url SHARED "url.cc")
target_include_directories(url PUBLIC ${HEADER})
## user
add_library(user SHARED "user.cc")
target_include_directories(user PUBLIC ${HEADER})

# Install rules
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)
install(TARGETS cpwdbmanager DESTINATION lib)
install(FILES "include/cpw_dbmanager.h" DESTINATION include)