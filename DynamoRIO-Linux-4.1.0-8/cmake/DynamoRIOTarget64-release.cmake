#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
SET(CMAKE_IMPORT_FILE_VERSION 1)

# Compute the installation prefix relative to this file.
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "dynamorio" for configuration "Release"
SET_PROPERTY(TARGET dynamorio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(dynamorio PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/release/libdynamorio.so.4.1"
  IMPORTED_SONAME_RELEASE "libdynamorio.so.4.1"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS dynamorio )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_dynamorio "${_IMPORT_PREFIX}/lib64/release/libdynamorio.so.4.1" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drinjectlib" for configuration "Release"
SET_PROPERTY(TARGET drinjectlib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drinjectlib PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "drdecode"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libdrinjectlib.so"
  IMPORTED_SONAME_RELEASE "libdrinjectlib.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drinjectlib )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drinjectlib "${_IMPORT_PREFIX}/lib64/libdrinjectlib.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drdecode" for configuration "Release"
SET_PROPERTY(TARGET drdecode APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drdecode PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "ASM;C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/release/libdrdecode.a"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drdecode )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drdecode "${_IMPORT_PREFIX}/lib64/release/libdrdecode.a" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drconfiglib" for configuration "Release"
SET_PROPERTY(TARGET drconfiglib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drconfiglib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libdrconfiglib.so"
  IMPORTED_SONAME_RELEASE "libdrconfiglib.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drconfiglib )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drconfiglib "${_IMPORT_PREFIX}/lib64/libdrconfiglib.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drcontainers" for configuration "Release"
SET_PROPERTY(TARGET drcontainers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drcontainers PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrcontainers.a"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drcontainers )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drcontainers "${_IMPORT_PREFIX}/ext/lib64/release/libdrcontainers.a" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drutil" for configuration "Release"
SET_PROPERTY(TARGET drutil APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drutil PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drmgr"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrutil.so"
  IMPORTED_SONAME_RELEASE "libdrutil.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drutil )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drutil "${_IMPORT_PREFIX}/ext/lib64/release/libdrutil.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drsyms" for configuration "Release"
SET_PROPERTY(TARGET drsyms APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drsyms PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "dynamorio"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrsyms.so"
  IMPORTED_SONAME_RELEASE "libdrsyms.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drsyms )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drsyms "${_IMPORT_PREFIX}/ext/lib64/release/libdrsyms.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drwrap" for configuration "Release"
SET_PROPERTY(TARGET drwrap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drwrap PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrwrap.so"
  IMPORTED_SONAME_RELEASE "libdrwrap.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drwrap )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drwrap "${_IMPORT_PREFIX}/ext/lib64/release/libdrwrap.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drx" for configuration "Release"
SET_PROPERTY(TARGET drx APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drx PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrx.so"
  IMPORTED_SONAME_RELEASE "libdrx.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drx )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drx "${_IMPORT_PREFIX}/ext/lib64/release/libdrx.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "drmgr" for configuration "Release"
SET_PROPERTY(TARGET drmgr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(drmgr PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drx"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrmgr.so"
  IMPORTED_SONAME_RELEASE "libdrmgr.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drmgr )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drmgr "${_IMPORT_PREFIX}/ext/lib64/release/libdrmgr.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "bbcov" for configuration "Release"
SET_PROPERTY(TARGET bbcov APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(bbcov PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/lib64/release/libbbcov.so"
  IMPORTED_SONAME_RELEASE "libbbcov.so"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS bbcov )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_bbcov "${_IMPORT_PREFIX}/tools/lib64/release/libbbcov.so" )

# Make sure the targets which have been exported in some other 
# export set exist.

# Import target "bbcov2lcov" for configuration "Release"
SET_PROPERTY(TARGET bbcov2lcov APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(bbcov2lcov PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/bin64/bbcov2lcov"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS bbcov2lcov )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_bbcov2lcov "${_IMPORT_PREFIX}/tools/bin64/bbcov2lcov" )

# Loop over all imported files and verify that they actually exist
FOREACH(target ${_IMPORT_CHECK_TARGETS} )
  FOREACH(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    IF(NOT EXISTS "${file}" )
      MESSAGE(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    ENDIF()
  ENDFOREACH()
  UNSET(_IMPORT_CHECK_FILES_FOR_${target})
ENDFOREACH()
UNSET(_IMPORT_CHECK_TARGETS)

# Cleanup temporary variables.
SET(_IMPORT_PREFIX)

# Commands beyond this point should not need to know the version.
SET(CMAKE_IMPORT_FILE_VERSION)
