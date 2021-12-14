#pragma once
#include "action.h"
#include <iostream>
#include<fstream>
#include "..\Components\Lamp.h"
#include "..\Components\Resistor.h"
#include "..\Components\Switch.h"
#include "..\Components\Ground.h"
#include "..\Components\Battery.h"
#include "..\Components\Buzzer.h"
#include "..\Components\Fuse.h"
using namespace std;


class ActionLoad : public Action
{
private:
	fstream file;  //write to a file

public:
	ActionLoad(ApplicationManager* pApp);

	virtual ~ActionLoad(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};