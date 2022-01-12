#include "ActionCut.h"
#include "..\ApplicationManager.h"

ActionCut::ActionCut(ApplicationManager* pApp) :Action(pApp)
{

}

ActionCut::~ActionCut(void)
{
}

void ActionCut::Execute()
{
	if (pManager->GetCompSEL())
	{
		pManager->SetCPDComp(pManager->GetCompSEL());
		pManager->SetCutID(pManager->GetCompSEL()->GetID());
		pManager->SetIsCut(true);
		pManager->ExecuteAction(DEL);
	}

}


