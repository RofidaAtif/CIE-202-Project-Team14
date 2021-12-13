#include "Ground.h"

Ground::Ground(GraphicsInfo *r_GfxInfo, int id, double res, string lbl):Component(r_GfxInfo, id,res, lbl)
{}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo, GetLabel());
}
oid Ground::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;

	f << "GROUND" << "       " << to_string(GetID()) << "       " << GetLabel() << "       " << GetValue() << "       " << to_string(Gfx.PointsList[0].x) << "       " << to_string(Gfx.PointsList[0].y) << endl;
}
void Ground::Operate()
{

}
