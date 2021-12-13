#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo,int id, string lbl) :Component(r_GfxInfo,id, lbl)
{

}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo,GetCompSelected()); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo, GetLabel());

}
void Switch::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;

	f << "SWT" << "       " << to_string(GetID()) << "       " << GetLabel() << "       " << GetValue() << "       " << to_string(Gfx.PointsList[0].x) << "       " << to_string(Gfx.PointsList[0].y) << endl;
}

void Switch::Operate()
{

}
