#include "ActionAddRes.h"
#include "..\ApplicationManager.h"

ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();	
	
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	
	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth/2;
	pGInfo->PointsList[0].y = Cy - compHeight/2;
	pGInfo->PointsList[1].x = Cx + compWidth/2;
	pGInfo->PointsList[1].y = Cy + compHeight/2;
	 
	//get the value of the resistance from the user as a string
	RES = 0;
	pUI->PrintMsg("enter the value of the resistance");
	string res = pUI->GetSrting();
	pUI->ClearStatusBar();
	stringstream Dres(res); //convert the string to a double 
	int CHKRes = 0;
	Dres >> CHKRes; //set the value of the resistance

	while (RES == 0)
	{
		
		if (CHKRes)
		{
			RES = CHKRes;
		}
		else
		{
			pUI->PrintMsg("Invalid value please enter another value");
			string res = pUI->GetSrting();
			pUI->ClearStatusBar();
			stringstream Dres(res); //convert the string to a double 
			Dres >> CHKRes;
		}
	}

	//get the label name from the user
	pUI->PrintMsg("enter the Name of the label");
	LBL = pUI->GetSrting();
	pUI->ClearStatusBar();

	int ID = (pManager->GetCompCount()) + 1;
	Resistor* pR = new Resistor(pGInfo, ID, RES, LBL);
	pManager->AddComponent(pR);
}

void ActionAddRes::Undo()
{}

void ActionAddRes::Redo()
{}

