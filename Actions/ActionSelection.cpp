#include "ActionSelection.h"
#include "..\ApplicationManager.h"

ActionSelection::ActionSelection(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelection::~ActionSelection(void)
{
}

void ActionSelection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	Sx = pUI->GetX();
	Sy = pUI->GetY();
	int Compcount = pManager->GetCompCount();
	int Conncount = pManager->GetConnCount();
	for (int i = 0;i < Compcount;i++)
	{
		Component* pComp = pManager->GetCompList(i);
		pComp->CompSelect(Sx, Sy);
	}
	for (int i = 0;i < Conncount;i++)
	{
		Connection* pConn = pManager->GetConnList(i);
		pConn->ConnSelect(Sx, Sy);
	}




}

