#include "ActionSelection.h"
#include "..\ApplicationManager.h"

using namespace std;

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
	Component* CompSlct = nullptr;
	Connection* ConnSlct = nullptr;
	for (int i = 0;i < Compcount;i++)
	{
		Component* pComp = pManager->GetCompList(i);
		Component* Temp = pComp->CompSelect(Sx, Sy);
		if (Temp)
		{
			CompSlct = Temp;
		}

	}
	for (int i = 0;i < Conncount;i++)
	{
		Connection* pConn = pManager->GetConnList(i);
		Connection* Temp = pConn->ConnSelect(Sx, Sy);
		if (Temp)
		{
			ConnSlct = Temp;
		}
	}

	pManager->SetCompSEL(CompSlct);
	pManager->SetConnSEL(ConnSlct);

	pManager->UpdateInterface();


	if (CompSlct || ConnSlct)
	{

	pUI->PrintMsg("enter el to edit label or ev to edit value");
	string ACT = pUI->GetSrting();
	pUI->ClearStatusBar();

	if (CompSlct)
	{
		
		
		

		if (ACT =="el")
		{
			pManager->ExecuteAction(EDIT_CompLabel);
			string Lbl = CompSlct->GetLabel();
			pUI->PrintMsg(Lbl);
			
		}
		else if (ACT == "ev")
		{
			pManager->ExecuteAction(EDIT_CompValue);
			double value = CompSlct->GetValue();
			
			pUI->PrintMsg(to_string(value));

		}
		else
		{
			string Lbl = CompSlct->GetLabel();
			pUI->PrintMsg(Lbl);
		}
	}
	else
	{
		if (ACT == "el")
		{
			pManager->ExecuteAction(EDIT_ConnLabel);

		}

		else if (ACT == "ev")
		{
			pManager->ExecuteAction(EDIT_ConnTerm);

		}
		else
		{
			string Lbl = ConnSlct->GetLabel();
			pUI->PrintMsg(Lbl);
		}

	}
	}
	else
	{
		pUI->ClearStatusBar();
	}
}

