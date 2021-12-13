#include "SwitchToSIM.h"
#include "..\ApplicationManager.h"
#include "../UI\UI.h"
SwitchToSIM::SwitchToSIM(ApplicationManager* pApp) :Action(pApp)
{
}

SwitchToSIM::~SwitchToSIM(void)
{
}

void  SwitchToSIM::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearWindow();
	pUI->switchtosim();
	pUI->CreateSimulationToolBar();
}

void SwitchToSIM::Undo()
{}

void SwitchToSIM::Redo()
{}

