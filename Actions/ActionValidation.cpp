#include "ActionValidation.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"

ActionValidation::ActionValidation(ApplicationManager* pApp) :Action(pApp)
{
}

ActionValidation::~ActionValidation(void)
{
}

bool ActionValidation::IsSeriesLoop()
{
	UI* pUI = pManager->GetUI();
	int Count = pManager->GetCompCount();
	for (int i = 0; i < Count; i++)
	{
		Component* Comp = pManager->GetCompList(i);
		if (Comp->GetTerm1_conn_count() != 1 || Comp->GetTerm2_conn_count() != 1)
		{
			return false;  //not valid
		}
		else if (Comp->GetTerm1_conn_count() == 1 && Comp->GetTerm2_conn_count() == 1)
		{
			  
			pUI->PrintMsg("Circit with one series loop");
			return true;
		}
	}
}

bool ActionValidation::IsConnected()
{
	int CompCount = pManager->GetCompCount();
	int ConnCount = pManager->GetConnCount();
	int ID1;
	int ID2;
	UI* pUI = pManager->GetUI();

	if (ConnCount == CompCount && ConnCount > 2)
	{ 
		for (int i = 0; i < ConnCount; i++)
		{
			Connection* Conn = pManager->GetConnList(i);
			ID1 = Conn->GetComp1()->GetID();
			ID2 = Conn->GetComp2()->GetID();

			for (int j = i+1; j < ConnCount; j++)
			{
				Connection* ComparedConn = pManager->GetConnList(j);
				int ComparedID1 = ComparedConn->GetComp1()->GetID();
				int ComparedID2 = ComparedConn->GetComp2()->GetID();

				if ((ID1 == ComparedID2 || ID1 == ComparedID1)  && (ID2 == ComparedID2 || ID2 == ComparedID1))
				{
					return false;
				}
			}
			
			pUI->PrintMsg("Circit is fully connected");
			return true;
		}
		
	}
	else if (ConnCount == CompCount && ConnCount == 2)
	{
		Connection* Conn = pManager->GetConnList(0);
		ID1 = Conn->GetComp1()->GetID();
		ID2 = Conn->GetComp2()->GetID();

		Connection* ComparedConn = pManager->GetConnList(1);
		int ComparedID1 = ComparedConn->GetComp1()->GetID();
		int ComparedID2 = ComparedConn->GetComp2()->GetID();

		if ((ID1 == ComparedID2 || ID1 == ComparedID1) && (ID2 == ComparedID2 || ID2 == ComparedID1))
		{
			
			pUI->PrintMsg("Circit is totally connected");
			return true;
		}
	}
}

	

bool ActionValidation::Isground()
{
	UI* pUI = pManager->GetUI();
	int Count = pManager->GetCompCount();
	int Cground = 0;
	for (int i = 0; i < Count; i++)
	{
		Component* Comp = pManager->GetCompList(i);
		 if (Comp->GetCompType() == "GROUND")
		{
			 Cground = Cground + 1;
		}
	}
	if (Cground != 1)
		return false; // not valid
	if (Cground == 1)
	{

		pUI->PrintMsg("Circit has only 1 ground");
		return true; // valid
	}
}


void ActionValidation::Execute()
{
	UI* pUI = pManager->GetUI();
	if ( IsSeriesLoop()   && IsConnected() && Isground())
	{
		pUI->PrintMsg("Circit is Validated");
		pManager->SetIsValid(true);
		
	}
	else  pManager->SetIsValid(false);
}

void ActionValidation::Undo()
{}

void ActionValidation::Redo()
{}