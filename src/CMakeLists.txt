set(
	CPW_DBMANAGER_SRC
	cpw_dbmanager.cc
	"${HEADER}/cpw_dbmanager.h"
)
add_library(
	"cpw-dbmanager" SHARED ${CPW_DBMANAGER_SRC}
)

