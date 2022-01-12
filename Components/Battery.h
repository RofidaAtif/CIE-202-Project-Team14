#pragma once
#include "Component.h"

class Battery :public Component
{
private:
	const double ires = 0.9;
public:
	Battery(GraphicsInfo *r_GfxInfo,int id, double res = 0, string lbl = "BATTERY" , string type = "BATTERY");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);

};
