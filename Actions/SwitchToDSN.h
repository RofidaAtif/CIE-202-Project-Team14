#pragma once

#include "action.h"


//Class responsible for adding a new resistor action
class SwitchToDSN : public Action
{
private:

public:
	SwitchToDSN(ApplicationManager* pApp);

	virtual ~SwitchToDSN(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};