#ifndef CONFIG_H
#define CONFIG_H

/* Name of package */
#define PROJECT_NAME "${PROJECT_NAME}"

/* Full name of this package */
#define PROJECT_FULL_NAME "${PROJECT_FULL_NAME}"

/* Version */
#define PACKAGE_VERSION = "${PACKAGE_VERSION}"
#define PACKAGE_VERSION_COMPLETE = "${PACKAGE_VERSION_COMPLETE}"

/* Base data directory */
#define DATADIR "${CMAKE_INSTALL_FULL_DATADIR}/${PROJECT_NAME}/"

#endif /* CONFIG_H */ 