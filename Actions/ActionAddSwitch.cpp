#include "ActionAddSwitch.h"
#include "..\ApplicationManager.h"

ActionAddSwitch::ActionAddSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddSwitch::~ActionAddSwitch(void)
{
}

void ActionAddSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Switch: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
		
	int WindowHeight = pUI->getWidowHeight();
	int WindowWidth = pUI->getWidowWidth();

	int StatusBarHeight = pUI->getStatusBarHeight();
	int ToolBarHeight = pUI->getToolBarHeight();


	while ( (Cy - (compWidth /2) < ToolBarHeight) || (Cy + (compWidth / 2) > (WindowHeight - StatusBarHeight)))
	{
		pUI->PrintMsg("Click anywhere in the design area Only");
		pUI->GetPointClicked(Cx, Cy);
		pUI->ClearStatusBar();
	}

	while ((Cx - (compWidth / 2) < 0) || (Cx + (compWidth / 2) > WindowWidth))
	{
		pUI->PrintMsg("Click anywhere in the design area Only");
		pUI->GetPointClicked(Cx, Cy);
		pUI->ClearStatusBar();
	}

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	LBL = pUI->GetSrting(); //Get the name of the label of the switch
	int ID = (pManager->GetCompCount()) + 1;
	Switch* pR = new Switch(pGInfo, ID, LBL);
	pManager->AddComponent(pR);
}

void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}

