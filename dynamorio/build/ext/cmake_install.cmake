# Install script for directory: /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/exports")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/ext/lib64/release" TYPE DIRECTORY PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/lib64/release/" FILES_MATCHING REGEX "/[^/]*\\.debug$" REGEX "/[^/]*\\.pdb$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drx/cmake_install.cmake")
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drcontainers/cmake_install.cmake")
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil/cmake_install.cmake")
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr/cmake_install.cmake")
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drwrap/cmake_install.cmake")
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drsyms/cmake_install.cmake")
  INCLUDE("/home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drgui/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

