#ifndef CONFIG_H
#define CONFIG_H

/* Name of package */
#define PACKAGE "${PROJECT_NAME}"

/* Full name of this package */
#define PACKAGE_NAME "${PROJECT_FULL_NAME}"

/* Version */
#define PACKAGE_VERSION_MAYOR = "${${PROJECT_NAME}_VERSION_MAYOR}"
#define PACKAGE_VERSION_MINOR = "${${PROJECT_NAME}_VERSION_MINOR}"
#define PACKAGE_VERSION_PATCH = "${${PROJECT_NAME}_VERSION_PATCH}"
#define PACKAGE_VERSION_SUFFIX = "${${PROJECT_NAME}_VERSION_SUFFIX}"

/* Base data directory */
#define PACKAGE_DATADIR "${CMAKE_INSTALL_PREFIX}/share"

#endif /* CONFIG_H */ 