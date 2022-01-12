#include "Resistor.h"

Resistor::Resistor(GraphicsInfo* r_GfxInfo, int id, double res, string lbl, string type) :Component(r_GfxInfo, id, res, lbl, type)
{
	
}


void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,GetCompSelected()); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo, GetLabel());
	
}

void Resistor::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;

	f << "RES" << "       " << to_string(GetID()) << "       " << GetLabel() << "       " << GetValue() << "       " << to_string(Gfx.PointsList[0].x) << "       " << to_string(Gfx.PointsList[0].y) << endl;
}
void Resistor::Operate()
{

}


