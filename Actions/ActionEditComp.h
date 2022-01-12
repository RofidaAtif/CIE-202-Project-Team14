#pragma once

#include "action.h"
#include <string>
using namespace std;

//Class responsible for adding a new resistor action
class ActionEditComp : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Sx, Sy;	//Center point of the comp
	string Type;
	

public:
	ActionEditComp(ApplicationManager* pApp, string type="");
	virtual ~ActionEditComp(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
	


};


