#include "ActionCopy.h"
#include "..\ApplicationManager.h"

ActionCopy::ActionCopy(ApplicationManager* pApp) :Action(pApp)
{

}

ActionCopy::~ActionCopy(void)
{
}

void ActionCopy::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();
	pManager->SetCPDComp(pManager->GetCompSEL());
	pManager->GetCPDComp()->GetID();
	pManager->SetIsCut(false);
}


