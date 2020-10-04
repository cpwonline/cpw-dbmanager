include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(GTEST REQUIRED gtest)
include_directories(${GTEST_INCLUDE_DIRS} ${DATABASE_INCLUDE_DIRS} ${SQLITE3_INCLUDE_DIRS})
link_directories(GTEST_LIBRARY_DIRS ${DATABASE_LIBRARY_DIRS} ${SQLITE3_LIBRARY_DIRS})

add_executable(test_gen test_gen.cc)

target_link_libraries(
	test_gen PUBLIC
	${GTEST_LIBRARIES}
	"cpw-dbmanager" 
	connection
	handle_database
	mysql_handler
	sqlite3_handler
)