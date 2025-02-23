#=========================================================================
# Program:   AssemblerPro
# Module:    CMakeLists.txt
# Language:  CMake
# Date:      $Date: 2021-01-01 12:00:00 $
# Version:   $Revision: 1.0.0.0 $
# Authors:   Nicola Vanella, Gianluigi Crimi
#==========================================================================
# Copyright (c) BIC-IOR 2021 (https://github.com/IOR-BIC)
#
# This software is distributed WITHOUT ANY WARRANTY; without even
# the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE. See the above copyright notice for more information.
#=========================================================================*/

SET (CMAKE_BACKWARDS_COMPATIBILITY "2.4" CACHE INTERNAL "This project is for CMake 2.4")
CMAKE_MINIMUM_REQUIRED(VERSION 2.4) 

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
	cmake_policy(SET CMP0048 NEW)
endif(COMMAND cmake_policy)

PROJECT (albaWrap)

#-----------------------------------------------------------------------------
# This enables support for Visual Studio: Edit & Continue, OpenMP, and parallel compilation
#-----------------------------------------------------------------------------
IF (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
	#Add OpenMP Support
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")

	#Add support for Edit & Continue
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI")
	IF (NOT ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 17.0)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
		SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SAFESEH:NO")
	ENDIF (NOT ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 17.0)
ENDIF (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)

# Create the header to configure the classes.
CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/appDefines.h.in 
							 ${PROJECT_BINARY_DIR}/appDefines.h 
							 @ONLY)

#-----------------------------------------------------------------------------
# This define the APP_SUBPROJECT macro
#-----------------------------------------------------------------------------
INCLUDE (${albaWrap_SOURCE_DIR}/CMakeModules/APPConfigMacro.cmake)

#-----------------------------------------------------------------------------
# Where to place output binaries
#-----------------------------------------------------------------------------
SET (LIBRARY_OUTPUT_PATH ${albaWrap_BINARY_DIR}/bin/ CACHE INTERNAL
     "Single output directory for building all libraries.")

SET (EXECUTABLE_OUTPUT_PATH ${albaWrap_BINARY_DIR}/bin/ CACHE INTERNAL 
     "Single output directory for building all executables.")

MARK_AS_ADVANCED(LIBRARY_OUTPUT_PATH)

FIND_PATH(MANUAL_HTML_DIR APP/APP_help.html)

#-----------------------------------------------------------------------------
# Options for APP building
#-----------------------------------------------------------------------------
OPTION(BUILD_SHARED_LIBS "Build with shared libraries." 0)
MARK_AS_ADVANCED (BUILD_SHARED_LIBS)

OPTION(BUILD_TESTING "Build the testing tree." OFF)

#-----------------------------------------------------------------------------
# Find required libraries
#-----------------------------------------------------------------------------

INCLUDE("${PROJECT_SOURCE_DIR}/CMakeModules/FindALBA.cmake")
INCLUDE("${ALBA_BINARY_PATH}/ALBAConfig.cmake")

# Find ALBA library
IF(ALBA_FOUND)
	
  INCLUDE("${ALBA_USE_FILE}")
  
	# IF(APP_BUILD_DLL)
    # SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /FORCE:MULTIPLE")
	  # SET(APP_BUILD_DLL 1)
	# ELSE(APP_BUILD_DLL)
      SET(APP_BUILD_DLL 0)
	# ENDIF (RAPP_BUILD_DLL)
    
  # Add single dirs to inclusion path
  INCLUDE_DIRECTORIES(BEFORE ".")
  INCLUDE_DIRECTORIES(${albaWrap_BINARY_DIR})
  INCLUDE_DIRECTORIES(${albaWrap_SOURCE_DIR}/Workflows)
  
  add_subdirectory(pybind11)
  SUBDIRS (Workflows)
  # Configuring Doxygen documentation 
   
  SUBDIRS (Documentation)
  
  # Export Build settings and library dependencies
  INCLUDE(CMakeExportBuildSettings)
  
  CMAKE_EXPORT_BUILD_SETTINGS(
    ${albaWrap_BINARY_DIR}/APPBuildSettings.cmake)
  
  export(TARGETS FILE ${albaWrap_BINARY_DIR}/APPLibraryDepends.cmake)
	
  CONFIGURE_FILE(
    ${albaWrap_SOURCE_DIR}/CMakeInput/APPConfig.cmake.in
    ${albaWrap_BINARY_DIR}/APPConfig.cmake
  @ONLY IMMEDIATE)
  
  CONFIGURE_FILE(
    ${albaWrap_SOURCE_DIR}/CMakeInput/APPUse.cmake.in
    ${albaWrap_BINARY_DIR}/APPUse.cmake
  @ONLY IMMEDIATE)
  
  #-----------------------------------------------------------------------------
  # Testing stuff
  #-----------------------------------------------------------------------------
  IF(BUILD_TESTING)
    
    MESSAGE("variable albaWrap_SOURCE_DIR = " ${albaWrap_SOURCE_DIR})
    FIND_PATH(APP_DATA_ROOT "TestingDataRoot.txt" "${albaWrap_SOURCE_DIR}/Testing/UnitTestsData" "${albaWrap_SOURCE_DIR}/../TestingData" "${albaWrap_SOURCE_DIR}/../mmData/TestingData" "${albaWrap_SOURCE_DIR}/../../TestingData"  DOC "Test data repository")
    ENABLE_TESTING()
      
    # where will executable tests be written ?
    IF (EXECUTABLE_OUTPUT_PATH)
        SET (CXX_TEST_PATH ${EXECUTABLE_OUTPUT_PATH})
    ELSE (EXECUTABLE_OUTPUT_PATH)
        SET (CXX_TEST_PATH .)
    ENDIF (EXECUTABLE_OUTPUT_PATH)
      
    SUBDIRS (Testing)
    
  ENDIF(BUILD_TESTING)
  
ELSE (ALBA_FOUND)
  MESSAGE (FATAL_ERROR "ALBA library not found, cannot build application!!")
ENDIF (ALBA_FOUND)

#-----------------------------------------------------------------------------
# APP deploy stuff.  
#-----------------------------------------------------------------------------

# This is specific for NSIS Nullsoft Installer that runs currently under Windows only and Parabuild.
# An APP_VERSION variable is created to gather versioning information
IF (WIN32)
    
  # Installer useful values
  SET(APP_EXECUTABLE_OUTPUT_PATH "${EXECUTABLE_OUTPUT_PATH}/Release/" CACHE PATH "Source directory for APP executable. This is used by the installer to find the executable.")
  
  STRING(REPLACE "/" "\\" APP_EXECUTABLE_OUTPUT_PATH_WIN ${APP_EXECUTABLE_OUTPUT_PATH})
  SET(APP_EXECUTABLE_OUTPUT_PATH_WIN ${APP_EXECUTABLE_OUTPUT_PATH_WIN} CACHE INTERNAL "get the executable from this directory")
  
  # MESSAGE("variable value = " ${APP_EXECUTABLE_OUTPUT_PATH})
  # MESSAGE("variable value = " ${APP_EXECUTABLE_OUTPUT_PATH_WIN})
  
  # Test for environment variable reading
  # MESSAG# "$ENV{PATH}")

  # Automatic values from parabuild created temporary environment variable
  SET(BUILD_NUMBER $ENV{BUILD_NUMBER} CACHE INTERNAL "build number")
  
  # Create the main version variable:
  SET(APP_VERSION "Build_${BUILD_NUMBER}" CACHE INTERNAL "big version identifier concatenating other identifier")
  
  # MESSAGE("variable value = " ${APP_VERSION})
    
  # Config installer file
  # Set the installer directory variable
  SET(APP_INSTALLER_DIR ${PROJECT_SOURCE_DIR}/Installer)
  # Convert it to Windows format
  STRING (REPLACE "/" "\\" APP_INSTALLER_DIR_WIN ${APP_INSTALLER_DIR} )
  # MESSAGE("variable APP_INSTALLER_DIR_WIN = " ${APP_INSTALLER_DIR_WIN})
  
  # Installer executable will be written to this directory
  SET(APP_INSTALLER_EXECUTABLE_OUTPUT_DIR ${APP_EXECUTABLE_OUTPUT_PATH} CACHE PATH "the installer executable will be written to this directory ")
  # Convert it to Windows format  
  STRING(REPLACE "/" "\\" APP_INSTALLER_EXECUTABLE_OUTPUT_DIR_WIN ${APP_INSTALLER_EXECUTABLE_OUTPUT_DIR})
  SET(APP_INSTALLER_EXECUTABLE_OUTPUT_DIR_WIN ${APP_INSTALLER_EXECUTABLE_OUTPUT_DIR_WIN} CACHE INTERNAL "get the executable  from this directory")
  # MESSAGE("variable APP_INSTALLER_EXECUTABLE_OUTPUT_DIR_WIN = " ${APP_INSTALLER_EXECUTABLE_OUTPUT_DIR_WIN})
  
  # Installer Configuration
ENDIF (WIN32)