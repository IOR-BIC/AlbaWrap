/*=========================================================================

 Program: ALBA (Agile Library for Biomedical Applications)
 Module:  albaWrapLogic.cpp
 Authors: Nicola Vanella
 
 Copyright (c) BIC
 All rights reserved. See Copyright.txt or


 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "albaWrapLogic.h"
#include "albaVME.h"

//-------------------------------------------------------------------------
albaWrapLogic::albaWrapLogic()
{
	
}

//-------------------------------------------------------------------------
albaWrapLogic::~albaWrapLogic()
{
}

// VME ////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------
void albaWrapLogic::VmeSelect(albaVME *vme)
{
}
//-------------------------------------------------------------------------
void albaWrapLogic::VmeSelected(albaVME *vme){}
//-------------------------------------------------------------------------
void albaWrapLogic::VmeShow(albaVME *vme, bool visibility)
{
}
//-------------------------------------------------------------------------
void albaWrapLogic::VmeAdd(albaVME *vme)
{
}
//-------------------------------------------------------------------------
void albaWrapLogic::VmeRemove(albaVME *vme)
{
	vme->ReparentTo(NULL);
}
//-------------------------------------------------------------------------
void albaWrapLogic::VmeModified(albaVME* vme)
{
}

//-------------------------------------------------------------------------
void albaWrapLogic::VmeVisualModeChanged(albaVME * vme)
{
}

// Camera /////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------
void albaWrapLogic::CameraUpdate(){}
//-------------------------------------------------------------------------
void albaWrapLogic::CameraReset(){}


// UTILS /////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
bool albaWrapLogic::IsOperationRunning() { return false; }

//----------------------------------------------------------------------------
const char* albaWrapLogic::GetMsfFileExtension()
{
	return "alba";
}

//----------------------------------------------------------------------------
void albaWrapLogic::VmeRemoved()
{
}

//----------------------------------------------------------------------------
void albaWrapLogic::PrintImage(albaVMEImage *img)
{
}

//----------------------------------------------------------------------------
albaOpManager * albaWrapLogic::GetOpManager() const
{
	return NULL;
}

//----------------------------------------------------------------------------
albaViewManager * albaWrapLogic::GetViewManager()
{
	return NULL;
}

//----------------------------------------------------------------------------
albaProsthesesDBManager * albaWrapLogic::GetProsthesesDBManager()
{
	return NULL;
}
