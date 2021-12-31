#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}
void ActionLoad::Execute()
{
	//Get a Pointer to the user Interfaces
	int ComponentCount = pManager->GetCompCount();
	int ConnectionCount = pManager->GetConnCount();
	for (int i = 0; i < ComponentCount; i++)
		pManager->ClearCompList(i);
	for (int i = 0; i < ConnectionCount; i++)
		pManager->ClearConnList(i);
	
	

	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();
	int compHeight = pUI->getCompHeight();
	int compWidth = pUI->getCompWidth();



	file.open("savefile\\savefile.txt", ios::in);
	if (file.fail())
	{
		pUI->PrintMsg("file not found!");
	}
	else
	{
		string SCompCount,Type,SID,LBL,SValue,SGFX1,SGFX2,conn,SConnCount,SConnID1,SConnID2;
		int ID, GFX1, GFX2,ConnID1,ConnID2;
		double Value;
		file >> SCompCount;
		stringstream SCmC(SCompCount); //convert the string to a double 
		int CompCount;
		SCmC >> CompCount;
		for (int i = 0;i < CompCount;i++)
		{
			file >> Type>>SID>>LBL>>SValue>>SGFX1>>SGFX2;
			stringstream sid(SID); //convert the string to a double 
			sid >> ID;

			stringstream sval(SValue); //convert the string to a double 
			sval >> Value;

			stringstream sg1(SGFX1); //convert the string to a double 
			sg1 >> GFX1;

			stringstream sg2(SGFX2); //convert the string to a double 
			sg2 >> GFX2;

			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = GFX1;
			pGInfo->PointsList[0].y = GFX2;
			pGInfo->PointsList[1].x = GFX1 + compWidth;
			pGInfo->PointsList[1].y = GFX2 + compHeight ;

			if (Type == "RES")
			{
				Resistor* pR = new Resistor(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pR);
			}
			else if (Type == "BLB")
			{
				Lamp* pR = new Lamp(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pR);
			}
			else if (Type == "SWT")
			{
				Switch* pR = new Switch(pGInfo, ID, LBL);
				pManager->AddComponent(pR);
			}
			else if (Type == "BAT")
			{
				Battery* pR = new Battery(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pR);
			}
			else if (Type == "BUZZER")
			{
				Buzzer* pR = new Buzzer(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pR);
			}
			else if (Type == "FUSE")
			{
				Fuse* pR = new Fuse(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pR);
			}
			else if (Type == "GROUND")
			{
				Ground* pR = new Ground(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pR);
			}



		}
		file >> conn;
		if (conn == "Connections")
		{
			file >> SConnCount;
			stringstream SCnC(SCompCount); //convert the string to a double 
			int ConnCount;
			SCnC >> ConnCount;
			int i = 1;
			while (file >> SConnID1 >> SConnID2)
			{
				stringstream sid1(SConnID1); //convert the string to a double 
				sid1 >> ConnID1;
				stringstream sid2(SConnID2); //convert the string to a double 
				sid2 >> ConnID2;
				Component* comp1 = pManager->GetCompList(ConnID1 - 1);
				Component* comp2 = pManager->GetCompList(ConnID2 - 1);
				string LBL = "Connection " + to_string(i++);


				GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp


				if (comp1 != nullptr && comp2 != nullptr)
				{
					int compWidth = pUI->getCompWidth();
					int compHeight = pUI->getCompHeight();
					int x1 = comp1->getCompCenterX(pUI);
					int x2 = comp2->getCompCenterX(pUI);
					int y1 = comp1->getCompCenterY(pUI);
					int y2 = comp2->getCompCenterY(pUI);

					if (x1 > x2) {
						pGInfo->PointsList[0].x = x2 + (compWidth / 2);
						pGInfo->PointsList[0].y = y2;
						pGInfo->PointsList[1].x = x1 - (compWidth / 2);
						pGInfo->PointsList[1].y = y1;
					}
					else if (x2 > x1) {
						pGInfo->PointsList[0].x = x1 + compWidth / 2;
						pGInfo->PointsList[0].y = y1;
						pGInfo->PointsList[1].x = x2 - compWidth / 2;
						pGInfo->PointsList[1].y = y2;
					}

					Connection* pC = new Connection(pGInfo, LBL, comp1, comp2);

					pManager->AddConnection(pC);
				}
				
			}
		}
	}




}
void ActionLoad::Undo()
{}

void ActionLoad::Redo()
{}
