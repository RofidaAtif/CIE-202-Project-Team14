#pragma once
#include "action.h"
#include <iostream>
#include<fstream>
using namespace std;


class ActionSave : public Action
{
private:
	fstream file;  //write to a file

public:
	ActionSave(ApplicationManager* pApp);

	virtual ~ActionSave(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};