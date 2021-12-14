#pragma once
#include "Component.h"

class Resistor:public Component
{

public:
	Resistor(GraphicsInfo *r_GfxInfo,int id, double res = 0, string lbl = "RES");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};
