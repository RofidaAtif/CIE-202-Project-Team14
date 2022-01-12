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

	UI* pUI = pManager->GetUI();
	pManager->ExecuteAction(Validate);
	if (pManager->GetIsValid())
	{


		pUI->ClearWindow();
		pUI->switchtosim();
		pUI->CreateSimulationToolBar();
	}
}

void SwitchToSIM::Undo()
{}

void SwitchToSIM::Redo()
{}

