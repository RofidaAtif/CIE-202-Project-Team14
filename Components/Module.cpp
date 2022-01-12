#include "Module.h"
Module::Module(GraphicsInfo* r_GfxInfo, int id, double ResTotal, string lbl,string type) :Component(r_GfxInfo, id, ResTotal, lbl,type)
{

}

void Module::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawModule(*m_pGfxInfo, GetCompSelected()); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo, GetLabel());

}

void Module::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;

	f << "Mod" << "       " << to_string(GetID()) << "       " << GetLabel() << "       " << GetValue() << "       " << to_string(Gfx.PointsList[0].x) << "       " << to_string(Gfx.PointsList[0].y) << endl;
//here
}
void Module::Operate()
{

}