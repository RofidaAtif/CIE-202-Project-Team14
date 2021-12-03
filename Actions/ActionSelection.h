#pragma once

#include "action.h"

//Class responsible for adding a new resistor action
class ActionSelection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Sx, Sy;	//Center point of the comp
public:
	ActionSelection(ApplicationManager* pApp);
	virtual ~ActionSelection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo() {};
	virtual void Redo() {};


};

