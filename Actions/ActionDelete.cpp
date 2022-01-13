#include "ActionDelete.h"
#include "..\ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
	
}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();

	if (pManager->GetConnSEL())
	{
		int Index = pManager->GetConnSELIndex();
		Connection* SEL = pManager->GetConnSEL();
		pManager->ClearConnList(Index);
		
		int ConnCount = pManager->GetConnCount();
		for (int i = Index;i < ConnCount;i++)
		{
			Connection* ShiftedConn = pManager->GetConnList(i + 1);
			pManager->SetConnList(i, ShiftedConn);
			pManager->DelConnList(i + 1);

		}
		pManager->SetConnSEL(nullptr);
		
	}
	else if (pManager->GetCompSEL())
	{
		int Index = pManager->GetCompSELIndex();
		Component* SEL = pManager->GetCompSEL();
		int CompID = SEL->GetID();
		int ConnCount = pManager->GetConnCount();

		int i = 0;
		while ( i < ConnCount)
		{
			Connection* Conn = pManager->GetConnList(i);
			Component* Comp1 = Conn->GetComp1();
			Component* Comp2 = Conn->GetComp2();
			if (Comp1 == SEL || Comp2 == SEL)
			{
				pManager->ClearConnList(i);

				int ConnCount = pManager->GetConnCount();
				for (int j = i;j < ConnCount;j++)
				{
					Connection* ShiftedConn = pManager->GetConnList(j + 1);
					pManager->SetConnList(j, ShiftedConn);
					pManager->DelConnList(j + 1);

				}
				
				i--;
			}
			ConnCount = pManager->GetConnCount();
			i++;
			
		}

		pManager->ClearCompList(Index);
		int CompCount = pManager->GetCompCount();

		for (int i = Index;i < CompCount;i++)
		{
			Component* ShiftedComp = pManager->GetCompList(i + 1);
			pManager->DelCompList(i);
			pManager->SetCompList(i, ShiftedComp);
			

		}
		pManager->SetCompSEL(nullptr);
	}

}


