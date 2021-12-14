#pragma once

#include "action.h"


//Class responsible for adding a new resistor action
class SwitchToSIM : public Action
{
private:

public:
	SwitchToSIM(ApplicationManager* pApp);

	virtual ~SwitchToSIM(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

