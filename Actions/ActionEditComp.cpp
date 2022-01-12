#include "ActionEditComp.h"
#include "..\ApplicationManager.h"

ActionEditComp::ActionEditComp(ApplicationManager* pApp, string type):Action(pApp)
{
	Type = type;
}

ActionEditComp::~ActionEditComp(void)
{
}

void ActionEditComp::Execute()
{
	UI* pUI = pManager->GetUI();

	if (Type == "el")
	{
		pUI->PrintMsg("enter new label");
		string lbl = pUI->GetSrting();
		pUI->ClearStatusBar();
		Component* SEL = pManager->GetCompSEL();
		SEL->SetLabel(lbl);
		pUI->ClearDrawingArea();
	}
	else if (Type == "ev")
	{
		int RES = 0;
		pUI->PrintMsg("enter new value");
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

		Component* SEL = pManager->GetCompSEL();
		SEL->SetValue(RES);
		pUI->ClearDrawingArea();
	}

}


