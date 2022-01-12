#pragma once
#include "action.h"
#include "ActionAddConnection.h"
#include "..\Components\Lamp.h"
#include "..\Components\Resistor.h"
#include "..\Components\Switch.h"
#include "..\Components\Ground.h"
#include "..\Components\Battery.h"
#include "..\Components\Buzzer.h"
#include "..\Components\Fuse.h"
#include "..\Components\Module.h"

class ActionValidation : public Action
{
private:
	bool validate;

public:
	ActionValidation(ApplicationManager* pApp);
	bool IsSeriesLoop();
	bool IsConnected();
	bool Isground();

	virtual ~ActionValidation(void);
	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};

