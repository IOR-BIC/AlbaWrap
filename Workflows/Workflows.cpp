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

#include "albaWrapLogic.h"
#include "albaServiceLocator.h"
#include "albaVMEFactory.h" 
#include "albaOpImporterAnsysCDBFile.h"
#include "albaVMEMesh.h"
#include "albaVMEStorage.h"
#include "albaOpExporterVTK.h"


wxApp *theApp;

void init()
{
	theApp = new wxApp();  // Instantiate the application class
	theApp->argc = 0;        // set the number of input argument to 0
	theApp->argv = NULL;     // set to NULL the input argument's parameters
	wxTheApp->SetAppName("albaWarp"); // Set the name for the application

																				//NOTE, wxLog produces some memory leaks, set false during test
	wxLog::EnableLogging(true);


	albaWrapLogic *logic = new albaWrapLogic();
	albaServiceLocator::SetLogicManager(logic);
}

void tearDown()
{
	cppDEL(theApp);  // Destroy the application
	wxAppConsole::SetInstance(NULL);
}

namespace albaWrap {

	//----------------------------------------------------------------------------
	int albaAnsysCDBtoVTK(char *cdb_file_in, char *vtk_file_out)
	{
		init();

		albaVMEStorage *storage = albaVMEStorage::New();
		albaVME *root = (albaVME *)storage->GetRoot();

		albaOpImporterAnsysCDBFile *importer = new albaOpImporterAnsysCDBFile("importer");
		importer->TestModeOn();
		importer->SetFileName(cdb_file_in);
		importer->SetInput(root);
		importer->Import();

		albaVMEMesh *mesh = albaVMEMesh::SafeDownCast(importer->GetInput()->GetFirstChild());
		if (mesh == NULL)
		{
			tearDown();
			return 1;
		}
		albaOpExporterVTK *exporter;
		exporter = new albaOpExporterVTK("VTK");
		exporter->TestModeOn();
		exporter->SetInput(mesh);
		exporter->SetFileName(vtk_file_out);
		exporter->SaveVTKData();

		tearDown();
		return 0;
	}

}

