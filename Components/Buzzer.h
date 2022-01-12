#pragma once
#include "Component.h"

class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo *r_GfxInfo,int id, double res = 0, string lbl = "BUZ", string type = "BUZ");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void SaveFile(fstream& f);
};
