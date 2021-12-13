#include "SwitchToDSN.h"
#include "..\ApplicationManager.h"
#include "../UI\UI.h"
SwitchToDSN::SwitchToDSN(ApplicationManager* pApp) :Action(pApp)
{
}

SwitchToDSN::~SwitchToDSN(void)
{
}

void  SwitchToDSN::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearWindow();
	pUI->switchtodsn();
	pUI->CreateDesignToolBar();
}
void SwitchToDSN::Undo()
{}

void SwitchToDSN::Redo()
{}

