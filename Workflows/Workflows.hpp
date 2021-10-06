/*=========================================================================
Program:   NewApp
Module:    NewApp.h
Language:  C++
Date:      $Date: 2021-01-01 12:00:00 $
Version:   $Revision: 1.0.0.0 $
Authors:   Gianlugi Crimi
==========================================================================
Copyright (c) BIC-IOR 2021 (https://github.com/IOR-BIC)

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the above copyright notice for more information.
=========================================================================*/

#ifndef __ALBAWARP_WORKFLOWS__
#define __ALBAWARP_WORKFLOWS__

#include <functional>
#include <memory>
#include <string>
#include <vector>

//----------------------------------------------------------------------------
// Functions list:
//----------------------------------------------------------------------------
namespace albaWrap {
	int albaAnsysCDBtoVTK(char *cdb_file_in, char *vtk_file_out);

}

#endif 
