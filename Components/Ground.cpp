#include "Ground.h"

Ground::Ground(GraphicsInfo* r_GfxInfo, int id, double res, string lbl, string type) :Component(r_GfxInfo, id, res, lbl, type)
{}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, GetCompSelected()); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo, GetLabel());
}
void Ground::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;

	f << "GROUND" << "       " << to_string(GetID()) << "       " << GetLabel() << "       " << GetValue() << "       " << to_string(Gfx.PointsList[0].x) << "       " << to_string(Gfx.PointsList[0].y) << endl;
}
void Ground::Operate()
{

}
