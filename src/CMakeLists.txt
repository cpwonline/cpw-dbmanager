# Add subdirectories
add_subdirectory(handlers)

# Targets

## Objects libraries

### column
add_library(column OBJECT "column.cc")
target_include_directories(column PUBLIC ${HEADER})
set_target_properties(column PROPERTIES POSITION_INDEPENDENT_CODE 1)

### connection
add_library(connection OBJECT "connection.cc")
target_include_directories(connection PUBLIC ${HEADER})
set_target_properties(connection PROPERTIES POSITION_INDEPENDENT_CODE 1)

### database
add_library(database OBJECT "database.cc")
target_include_directories(database PUBLIC ${HEADER})
set_target_properties(database PROPERTIES POSITION_INDEPENDENT_CODE 1)

### query
add_library(query OBJECT "query.cc")
target_include_directories(query PUBLIC ${HEADER})
set_target_properties(query PROPERTIES POSITION_INDEPENDENT_CODE 1)

### result
add_library(result OBJECT "result.cc")
target_include_directories(result PUBLIC ${HEADER})
set_target_properties(result PROPERTIES POSITION_INDEPENDENT_CODE 1)

### row
add_library(row OBJECT "row.cc")
target_include_directories(row PUBLIC ${HEADER})
set_target_properties(row PROPERTIES POSITION_INDEPENDENT_CODE 1)

### table
add_library(table OBJECT "table.cc")
target_include_directories(table PUBLIC ${HEADER})
set_target_properties(table PROPERTIES POSITION_INDEPENDENT_CODE 1)

### address
add_library(address OBJECT "address.cc")
target_include_directories(address PUBLIC ${HEADER})
set_target_properties(address PROPERTIES POSITION_INDEPENDENT_CODE 1)

### accessdata
add_library(accessdata OBJECT "access_data.cc")
target_include_directories(accessdata PUBLIC ${HEADER})
set_target_properties(accessdata PROPERTIES POSITION_INDEPENDENT_CODE 1)

## Shared and statics libraries

### cpwdbmanager
list(
	APPEND ${PROJECT_NAME}_libraries
	connection
	database
	accessdata
	address
	query
	result
	table
	column
	row
)
if(_BUILD_WITH_MARIADB)
	list(APPEND ${PROJECT_NAME}_libraries mariadbhandler)
elseif(_BUILD_WITH_MYSQL)
	list(APPEND ${PROJECT_NAME}_libraries mysqlhandler)
elseif(_BUILD_WITH_SQLITE3)
	list(APPEND ${PROJECT_NAME}_libraries sqlite3handler)
endif()
add_library(${${PROJECT_NAME}_name} SHARED "cpw_dbmanager.cc")
target_include_directories(${${PROJECT_NAME}_name} PUBLIC ${HEADER} ${PROJECT_BINARY_DIR})
target_link_libraries(${${PROJECT_NAME}_name} PUBLIC ${${PROJECT_NAME}_libraries})