#pragma once
#include"Component.h"
class Module: public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo, int id, double ResTotal, string lbl = "Mod");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};

