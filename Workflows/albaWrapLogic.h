/*=========================================================================

 Program: ALBA (Agile Library for Biomedical Applications)
 Module:  albaWrapLogic.h
 Authors: Nicola Vanella
 
 Copyright (c) BIC
 All rights reserved. See Copyright.txt or


 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef _albaWrapLogic_H
#define _albaWrapLogic_H

#include "albaConfigure.h"
#include "albaAbsLogicManager.h"

#include <vector>

class  albaWrapLogic : public albaAbsLogicManager
{

public:

	enum testFunctions
	{
		FKL_VME_SELECT,
		FKL_VME_ADD,
		FKL_VME_REMOVE,
		FKL_VME_MODIFIED,
		FKL_VME_SHOW,
		FKL_VME_VISUAL_MODE_CHANGED,
		FKL_VME_REMOVED,
		FKL_PRINT_IMAGE
	};

	
	albaWrapLogic();
	~albaWrapLogic();

	// VME
	virtual void VmeSelect(albaVME *vme);

	virtual void VmeSelected(albaVME *vme);

	virtual void VmeShow(albaVME *vme, bool visibility);

	virtual void VmeAdd(albaVME *vme);

	virtual void VmeRemove(albaVME *vme);

	virtual void VmeModified(albaVME* vme);

	virtual void VmeVisualModeChanged(albaVME * vme);

	// Camera
	virtual void CameraUpdate();

	virtual void CameraReset();

	virtual bool IsOperationRunning();
	
	virtual const char* GetMsfFileExtension() override;
	
	virtual void VmeRemoved() override;
	
	virtual void PrintImage(albaVMEImage *img) override;

	virtual albaOpManager * GetOpManager() const override;

	virtual albaViewManager *GetViewManager() override;

	virtual albaProsthesesDBManager * GetProsthesesDBManager() override;

protected:

};
#endif