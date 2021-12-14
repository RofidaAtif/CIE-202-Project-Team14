#pragma once
#include "Component.h"

class Lamp :public Component
{
private:
	double IRES; //The value of the resistance of the lamp

public:
	Lamp(GraphicsInfo* r_GfxInfo,int id, double ires = 0, string lbl = "Lamp");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};
