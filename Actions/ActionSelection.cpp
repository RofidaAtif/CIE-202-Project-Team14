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
	int count = pManager->GetCount();
	for (int i = 0;i < count;i++)
	{
		Component* pC = pManager->GetCompList(i);
		pC->Select(Sx, Sy);
	}




}

