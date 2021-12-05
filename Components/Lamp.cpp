#include "Lamp.h"

Lamp::Lamp(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Lamp::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawLamp(*m_pGfxInfo); //update to draw resistor

}

void Lamp::Operate()
{

}