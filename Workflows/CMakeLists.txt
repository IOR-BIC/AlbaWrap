#==========================================================================
# Program:   NewApp
# Module:    CMakeLists.txt
# Language:  CMake
# Date:      $Date: 2021-01-01 12:00:00 $
# Version:   $Revision: 1.0.0.0 $
# Authors:   Nicola Vanella
#==========================================================================
# Copyright (c) BIC-IOR 2021 (https://github.com/IOR-BIC)
#
# This software is distributed WITHOUT ANY WARRANTY; without even
# the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE. See the above copyright notice for more information.
#==========================================================================

PROJECT (albaWrap)

SET(PROJECT_SRCS 
#Workflows.cpp 	Workflows.hpp
appDecl.h
pybind11.cpp
albaWrapLogic.cpp albaWrapLogic.h
workflows.cpp workflows.hpp
)

IF (NOT EXECUTABLE_OUTPUT_PATH)
  SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/ CACHE INTERNAL 
  "Single output directory for building all executables.")
ENDIF (NOT EXECUTABLE_OUTPUT_PATH)


SET(PROJECT_LIBS albaOperations albaGui albaViews albaVME albaInteraction albaService albaVME albaVisualPipes albaOperations vtkALBA)# GPUAPI))

pybind11_add_module(${PROJECT_NAME} ${PROJECT_SRCS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE ${PROJECT_LIBS})

