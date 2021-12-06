#include "ActionAddConnection.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddConnection::~ActionAddConnection(void)
{
}
void ActionAddConnection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new connection: Select 1st Component");
	pUI->GetPointClicked(Cx, Cy);
	Component* comp1 = pManager->GetComponentByCordinates(Cx, Cy);
	
	while ((comp1 == nullptr)&&(pManager->GetCompCount()>=2) ) {
		pUI->GetPointClicked(Cx, Cy);
		comp1 = pManager->GetComponentByCordinates(Cx, Cy);
	}
	pUI->ClearStatusBar();
	pUI->PrintMsg("Adding a new connection: Select 2nd Component");
	pUI->GetPointClicked(Cx, Cy);
	Component* comp2 = pManager->GetComponentByCordinates(Cx, Cy);
	while ((comp2 == nullptr)&&(pManager->GetCompCount() >= 2)) {
		pUI->GetPointClicked(Cx, Cy);
		comp2 = pManager->GetComponentByCordinates(Cx, Cy);
	}
	pUI->ClearStatusBar();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
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
			pGInfo->PointsList[0].y = y2 - (compHeight / 2);
			pGInfo->PointsList[1].x = x1 - (compWidth / 2);
			pGInfo->PointsList[1].y = y1 + (compHeight / 2);
		}
		else if (x2 > x1) {
			pGInfo->PointsList[0].x = x1 + compWidth / 2;
			pGInfo->PointsList[0].y = y1 - compHeight / 2;
			pGInfo->PointsList[1].x = x2 - compWidth / 2;
			pGInfo->PointsList[1].y = y2 + compHeight / 2;
		}

		int length = abs(x1 - x2) - compWidth;
		Connection* pC = new Connection(length, pGInfo, comp1, comp2);

		pManager->AddConnection(pC);
	}
}


void ActionAddConnection::Undo()
{}

void ActionAddConnection::Redo()
{}
