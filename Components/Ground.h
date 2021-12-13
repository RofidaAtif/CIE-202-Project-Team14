#pragma once
#include "Component.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo *r_GfxInfo,int id, double res = 0, string lbl = "GROUND");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};
