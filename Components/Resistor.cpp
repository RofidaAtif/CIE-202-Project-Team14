#include "Resistor.h"

Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, GetCompSelected()); //update to draw resistor

}

void Resistor::Operate()
{

}
