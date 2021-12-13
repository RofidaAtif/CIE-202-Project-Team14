#include "ActionSave.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSave::~ActionSave(void)
{
}
void ActionSave::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	

	file.open("savefile\\savefile.txt", ios::out);
	
	
	int CompCnt = pManager->GetCompCount();
	int ConnCnt = pManager->GetConnCount();
	file << to_string(CompCnt)<<endl;
	for (int i = 0; i < CompCnt; i++)
	{
		Component* pComp = pManager->GetCompList(i);
		pComp->SaveFile(file);
	}

	file <<"Connections"<< endl << to_string(ConnCnt) << endl;
	for (int i = 0; i < ConnCnt; i++)
	{
		Connection* pConn = pManager->GetConnList(i);
		Component* Comp1 = pConn->GetComp1();
		Component* Comp2 = pConn->GetComp2();
		int ID1 = Comp1->GetID();
		int ID2 = Comp2->GetID();

		pConn->SaveFile(file,ID1,ID2);
	}

	pUI->PrintMsg("Saved ");
	


}
void ActionSave::Undo()
{}

void ActionSave::Redo()
{}
