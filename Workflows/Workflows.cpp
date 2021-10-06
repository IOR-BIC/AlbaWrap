/*=========================================================================
Program:   NewApp
Module:    NewApp.cpp
Language:  C++
Date:      $Date: 2021-01-01 12:00:00 $
Version:   $Revision: 1.0.0.0 $
Authors:   Nicola Vanella
==========================================================================
Copyright (c) BIC-IOR 2021 (https://github.com/IOR-BIC)

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the above copyright notice for more information.
=========================================================================*/

//Enable This for memory leak detection
//#include <vld.h>

#include "appDefines.h" 
//----------------------------------------------------------------------------
// NOTE: Every CPP file in the APP must include "appDefines.h" as first.
// This force to include Window, wxWidgets and VTK exactly in this order.
//----------------------------------------------------------------------------

#include "workflows.hpp"

#include "albaServiceLocator.h"
#include "albaVMEFactory.h" 
#include "albaOpImporterAnsysCDBFile.h"
#include "albaVMEMesh.h"
#include "albaVMEStorage.h"
#include "albaOpExporterVTK.h"

namespace albaWrap {

	//----------------------------------------------------------------------------
	int albaAnsysCDBtoVTK(char *cdb_file_in, char *vtk_file_out)
	{
		albaVMEStorage *storage = albaVMEStorage::New();
		albaVME *root = (albaVME *)storage->GetRoot();

		albaOpImporterAnsysCDBFile *importer = new albaOpImporterAnsysCDBFile("importer");
		importer->TestModeOn();
		importer->SetFileName(cdb_file_in);
		importer->SetInput(root);
		importer->Import();

		albaVMEMesh *mesh = albaVMEMesh::SafeDownCast(importer->GetInput()->GetFirstChild());
		if (mesh == NULL)
			return 1;

		albaOpExporterVTK *exporter;
		exporter = new albaOpExporterVTK("VTK");
		exporter->TestModeOn();
		exporter->SetInput(mesh);
		exporter->SetFileName(vtk_file_out);
		exporter->SaveVTKData();

		return 0;
	}

}

