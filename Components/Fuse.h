#pragma once
#include "Component.h"

class Fuse :public Component
{
public:
	Fuse(GraphicsInfo *r_GfxInfo,int id, double res = 0, string lbl = "FUSE", string type = "FUSE");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};
