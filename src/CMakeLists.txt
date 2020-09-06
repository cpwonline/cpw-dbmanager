set(
	cpw_dbmanager_src
	cpw_dbmanager.cc
	"${HEADER}/cpw_dbmanager.h"
)
add_library(
	"cpw-dbmanager" SHARED cpw_dbmanager_src
)

