#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, GetCompSelected()); //update to draw resistor

}

void Switch::Operate()
{

}
