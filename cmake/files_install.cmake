# Install files

## Header files
install(
	FILES 
		${HEADER}/access_data.h
		${HEADER}/address.h
		${HEADER}/column.h
		${HEADER}/connection.h
		${HEADER}/cpw_dbmanager.h
		${HEADER}/database.h
		${HEADER}/query.h
		${HEADER}/result.h
		${HEADER}/row.h
		${HEADER}/table.h
	DESTINATION 
		${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
install(
	FILES 
		${HEADER}/handlers/mariadb_handler.h
		${HEADER}/handlers/mysql_handler.h
		${HEADER}/handlers/sqlite3_handler.h
	DESTINATION 
		${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/handlers
)
## Libraries
install(
	TARGETS 
		${PROJECT_NAME}_name
	DESTINATION 
		${CMAKE_INSTALL_LIBDIR}
)

## Docs files
install(
	FILES 
		${PROJECT_SOURCE_DIR}/README.md
		${PROJECT_SOURCE_DIR}/CODE_OF_CONDUCT.md
		${PROJECT_SOURCE_DIR}/LICENSE
		${PROJECT_SOURCE_DIR}/PULL_REQUEST_TEMPLATE.md
	DESTINATION
		${CMAKE_INSTALL_DOCDIR}
)

## Share files
install(
	FILES ${PROJECT_BINARY_DIR}/share/${${PROJECT_NAME}_name}.pc
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)