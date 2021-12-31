#pragma once

#include "action.h"
#include "..\Components\Module.h"

//Class responsible for adding a new module action
class ActionAddModule : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	string LBL; //Label of the module
	double ResTotal; //The value of the total resistance of the module
	double Res1; //The value of the resistor1
	double Res2; //The value of the resistor2
	double Res3; //The value of the resistor3
	double Res4; //The value of the resistor4
	double Res5; //The value of the resistor5

public:
	ActionAddModule(ApplicationManager *pApp);
	virtual ~ActionAddModule(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	double getResValue();

	virtual void Undo();
	virtual void Redo();

};

