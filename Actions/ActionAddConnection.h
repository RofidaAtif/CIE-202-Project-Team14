#pragma once
#include "Action.h"
#include"..\Components\Connection.h"
//Class responsible for adding a new resistor action
class ActionAddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	string LBL; //Label of the connection
public:
	ActionAddConnection(ApplicationManager* pApp);
	virtual ~ActionAddConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

	
};