#include "ActionAddModule.h"
#include "..\ApplicationManager.h"

ActionAddModule::ActionAddModule(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddModule::~ActionAddModule(void)
{
}

void ActionAddModule::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new module: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
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


	//get the value of the resistance from the user as a string
	
	pUI->PrintMsg("enter the value of R1");
	Res1 = getResValue();
	pUI->PrintMsg("enter the value of R2");
	Res2 = getResValue();
	pUI->PrintMsg("enter the value of R3");
	Res3 = getResValue();
	pUI->PrintMsg("enter the value of R4");
	Res4 = getResValue();
	pUI->PrintMsg("enter the value of R5");
	Res5 = getResValue();

	ResTotal = (1 / ((1 / Res1) + (1 / Res2))) + (1 / Res3) + (1 / ((1 / Res4) + (1 / Res5)));

	//get the label name from the user
	pUI->PrintMsg("enter a Label of the Module");
	LBL = pUI->GetSrting();
	pUI->ClearStatusBar();

	int ID = (pManager->GetCompCount()) + 1;
	Module* pR = new Module(pGInfo, ID, ResTotal, LBL);
	pManager->AddComponent(pR);

}


double ActionAddModule::getResValue()
{
	double Res = 0;
	UI* pUI = pManager->GetUI();
	string res = pUI->GetSrting();
	pUI->ClearStatusBar();
	stringstream Dres(res); //convert the string to a double 
	int CHKRes = 0;
	Dres >> CHKRes; //set the value of the resistance

	while (Res == 0)
	{

		if (CHKRes)
		{
			Res = CHKRes;
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

	return Res;
}

void ActionAddModule::Undo()
{}

void ActionAddModule::Redo()
{}

