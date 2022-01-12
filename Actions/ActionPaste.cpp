#include "ActionPaste.h"
#include "..\ApplicationManager.h"
#include"..\Components\Resistor.h"
#include"..\Components\Battery.h"
#include"..\Components\Switch.h"
#include"..\Components\Buzzer.h"
#include"..\Components\Fuse.h"
#include"..\Components\Ground.h"
#include"..\Components\Lamp.h"
#include"..\Components\Module.h"

ActionPaste::ActionPaste(ApplicationManager* pApp) :Action(pApp)
{

}

ActionPaste::~ActionPaste(void)
{
}

void ActionPaste::Execute()
{
	
	if (pManager->GetCPDComp())
	{
		UI* pUI = pManager->GetUI();

		//Print Action Message
		pUI->PrintMsg("click the point to paste the component to");

		//Get Center point of the area where the Comp should be drawn
		int Cx, Cy;
		pUI->GetPointClicked(Cx, Cy);

		//Clear Status Bar
		pUI->ClearStatusBar();


		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;

		if (pManager->GetIsCut())
		{
			Component* CPD = pManager->GetCPDComp();
			CPD->SetGfx(pGInfo);
			CPD->SetTerm1_conn_count(0);
			CPD->SetTerm2_conn_count(0);
			pManager->AddComponent(CPD);
			pManager->SetCPDComp(nullptr);
		}
		else
		{
			Component* CPD = pManager->GetCPDComp();
			int ID = pManager->GetCompCount() + 1;
			double Value = CPD->GetValue();
			string LBL = CPD->GetLabel();
			string Type = CPD->GetCompType();
			if (Type == "RES")
			{
				Resistor* pPasted = new Resistor(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "BATTERY")
			{
				Battery* pPasted = new Battery(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "BUZ")
			{
				Buzzer* pPasted = new Buzzer(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "FUSE")
			{
				Fuse* pPasted = new Fuse(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "GROUND")
			{
				Ground* pPasted = new Ground(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "LAMP")
			{
				Lamp* pPasted = new Lamp(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "MOD")
			{
				Module* pPasted = new Module(pGInfo, ID, Value, LBL);
				pManager->AddComponent(pPasted);
			}
			else if (Type == "SWITCH")
			{
				Switch* pPasted = new Switch(pGInfo, ID, LBL);
				pManager->AddComponent(pPasted);
			}
			
		}
	}
}


