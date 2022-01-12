#include "ActionEditConn.h"
#include "..\ApplicationManager.h"

ActionEditConn::ActionEditConn(ApplicationManager* pApp, string type) :Action(pApp)
{
	Type = type;
}

ActionEditConn::~ActionEditConn(void)
{
}

void ActionEditConn::Execute()
{
	UI* pUI = pManager->GetUI();

	if (Type == "el")
	{
		pUI->PrintMsg("enter new label");
		string lbl = pUI->GetSrting();
		pUI->ClearStatusBar();
		Connection* SEL = pManager->GetConnSEL();
		SEL->SetLabel(lbl);
		pUI->ClearDrawingArea();
	}
	else if (Type == "ev")
	{
		int  Cx, Cy;
		pUI->PrintMsg("Select new 1st Component");
		pUI->GetPointClicked(Cx, Cy);
		Component* comp1 = pManager->GetComponentByCordinates(Cx, Cy);

		while ((comp1 == nullptr) && (pManager->GetCompCount() >= 2)) {
			pUI->GetPointClicked(Cx, Cy);
			comp1 = pManager->GetComponentByCordinates(Cx, Cy);
		}
		pUI->ClearStatusBar();
		pUI->PrintMsg("Select new 2nd Component");
		pUI->GetPointClicked(Cx, Cy);
		Component* comp2 = pManager->GetComponentByCordinates(Cx, Cy);
		while ((comp2 == nullptr) && (pManager->GetCompCount() >= 2)) {
			pUI->GetPointClicked(Cx, Cy);
			comp2 = pManager->GetComponentByCordinates(Cx, Cy);
		}
		pUI->ClearStatusBar();
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
			
		}
		Connection* SEL = pManager->GetConnSEL();
		SEL->SetComp1(comp1);
		SEL->SetComp2(comp2);
		SEL->SetGFx(pGInfo);
		pUI->ClearDrawingArea();

		

	}
	
}




