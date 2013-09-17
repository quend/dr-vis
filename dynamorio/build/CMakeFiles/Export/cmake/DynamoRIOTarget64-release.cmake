#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dynamorio" for configuration "Release"
set_property(TARGET dynamorio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dynamorio PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/release/libdynamorio.so.4.1"
  IMPORTED_SONAME_RELEASE "libdynamorio.so.4.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS dynamorio )
list(APPEND _IMPORT_CHECK_FILES_FOR_dynamorio "${_IMPORT_PREFIX}/lib64/release/libdynamorio.so.4.1" )

# Import target "drinjectlib" for configuration "Release"
set_property(TARGET drinjectlib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drinjectlib PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "drdecode"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libdrinjectlib.so"
  IMPORTED_SONAME_RELEASE "libdrinjectlib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drinjectlib )
list(APPEND _IMPORT_CHECK_FILES_FOR_drinjectlib "${_IMPORT_PREFIX}/lib64/libdrinjectlib.so" )

# Import target "drdecode" for configuration "Release"
set_property(TARGET drdecode APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drdecode PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "ASM;C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/release/libdrdecode.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS drdecode )
list(APPEND _IMPORT_CHECK_FILES_FOR_drdecode "${_IMPORT_PREFIX}/lib64/release/libdrdecode.a" )

# Import target "drconfiglib" for configuration "Release"
set_property(TARGET drconfiglib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drconfiglib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libdrconfiglib.so"
  IMPORTED_SONAME_RELEASE "libdrconfiglib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drconfiglib )
list(APPEND _IMPORT_CHECK_FILES_FOR_drconfiglib "${_IMPORT_PREFIX}/lib64/libdrconfiglib.so" )

# Import target "drx" for configuration "Release"
set_property(TARGET drx APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drx PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrx.so"
  IMPORTED_SONAME_RELEASE "libdrx.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drx )
list(APPEND _IMPORT_CHECK_FILES_FOR_drx "${_IMPORT_PREFIX}/ext/lib64/release/libdrx.so" )

# Import target "drcontainers" for configuration "Release"
set_property(TARGET drcontainers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drcontainers PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrcontainers.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS drcontainers )
list(APPEND _IMPORT_CHECK_FILES_FOR_drcontainers "${_IMPORT_PREFIX}/ext/lib64/release/libdrcontainers.a" )

# Import target "drutil" for configuration "Release"
set_property(TARGET drutil APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drutil PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drmgr"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrutil.so"
  IMPORTED_SONAME_RELEASE "libdrutil.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drutil )
list(APPEND _IMPORT_CHECK_FILES_FOR_drutil "${_IMPORT_PREFIX}/ext/lib64/release/libdrutil.so" )

# Import target "drmgr" for configuration "Release"
set_property(TARGET drmgr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drmgr PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drx"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrmgr.so"
  IMPORTED_SONAME_RELEASE "libdrmgr.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drmgr )
list(APPEND _IMPORT_CHECK_FILES_FOR_drmgr "${_IMPORT_PREFIX}/ext/lib64/release/libdrmgr.so" )

# Import target "drwrap" for configuration "Release"
set_property(TARGET drwrap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drwrap PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrwrap.so"
  IMPORTED_SONAME_RELEASE "libdrwrap.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drwrap )
list(APPEND _IMPORT_CHECK_FILES_FOR_drwrap "${_IMPORT_PREFIX}/ext/lib64/release/libdrwrap.so" )

# Import target "drsyms" for configuration "Release"
set_property(TARGET drsyms APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(drsyms PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "dynamorio"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/ext/lib64/release/libdrsyms.so"
  IMPORTED_SONAME_RELEASE "libdrsyms.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drsyms )
list(APPEND _IMPORT_CHECK_FILES_FOR_drsyms "${_IMPORT_PREFIX}/ext/lib64/release/libdrsyms.so" )

# Import target "bbcov" for configuration "Release"
set_property(TARGET bbcov APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bbcov PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/lib64/release/libbbcov.so"
  IMPORTED_SONAME_RELEASE "libbbcov.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS bbcov )
list(APPEND _IMPORT_CHECK_FILES_FOR_bbcov "${_IMPORT_PREFIX}/tools/lib64/release/libbbcov.so" )

# Import target "bbcov2lcov" for configuration "Release"
set_property(TARGET bbcov2lcov APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bbcov2lcov PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/bin64/bbcov2lcov"
  )

list(APPEND _IMPORT_CHECK_TARGETS bbcov2lcov )
list(APPEND _IMPORT_CHECK_FILES_FOR_bbcov2lcov "${_IMPORT_PREFIX}/tools/bin64/bbcov2lcov" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
