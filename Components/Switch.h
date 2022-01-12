#pragma once
#include "Component.h"

class Switch :public Component
{
private:
	string LBL;
public:
	Switch(GraphicsInfo* r_GfxInfo,int id, string lbl = "SWITCH", string type = "SWITCH");

	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};
