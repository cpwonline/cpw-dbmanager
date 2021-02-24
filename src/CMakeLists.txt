# Add subdirectories
add_subdirectory(handlers)

# Add and linking libraries
## cpwdbmanager
add_library(cpwdbmanager STATIC "cpw_dbmanager.cc")
target_include_directories(cpwdbmanager PUBLIC ${HEADER})
target_link_libraries(cpwdbmanager PUBLIC connection database mariadbhandler mysqlhandler sqlite3handler)
## column
add_library(column STATIC "column.cc")
target_include_directories(column PUBLIC ${HEADER})
## connection
add_library(connection STATIC "connection.cc")
target_include_directories(connection PUBLIC ${HEADER})
## database
add_library(database STATIC "database.cc")
target_include_directories(database PUBLIC ${HEADER})
## query
add_library(query STATIC "query.cc")
target_include_directories(query PUBLIC ${HEADER})
## result
add_library(result STATIC "result.cc")
target_include_directories(result PUBLIC ${HEADER})
## row
add_library(row STATIC "row.cc")
target_include_directories(row PUBLIC ${HEADER})
## table
add_library(table STATIC "table.cc")
target_include_directories(table PUBLIC ${HEADER})
## address
add_library(address STATIC "address.cc")
target_include_directories(address PUBLIC ${HEADER})
## accessdata
add_library(accessdata STATIC "access_data.cc")
target_include_directories(accessdata PUBLIC ${HEADER})

# Install rules
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)
install(TARGETS cpwdbmanager DESTINATION lib)
install(FILES "include/cpw_dbmanager.h" DESTINATION include)