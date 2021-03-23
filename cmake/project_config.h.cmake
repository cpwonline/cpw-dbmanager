#ifndef CONFIG_H
#define CONFIG_H

/* Name of package */
#define PROJECT_NAME "${PROJECT_NAME}"

/* Full name of this package */
#define PROJECT_FULL_NAME "${PROJECT_FULL_NAME}"

/* Version */
#define PACKAGE_VERSION "${PACKAGE_VERSION}"
#define PACKAGE_VERSION_COMPLETE "${PACKAGE_VERSION_COMPLETE}"

/* Base data directory */
#define DATADIR "${${PROJECT_NAME}_DATADIR}/"

/* User macros */
#define BUILD_WITH_MARIADB ${_BUILD_WITH_MARIADB}
#define BUILD_WITH_MYSQL ${_BUILD_WITH_MYSQL}
#define BUILD_WITH_SQLITE3 ${_BUILD_WITH_SQLITE3}

#endif /* CONFIG_H */ 