#include "Fuse.h"

Fuse::Fuse(GraphicsInfo *r_GfxInfo, int id, double res, string lbl):Component(r_GfxInfo, id,res, lbl)
{
}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, GetCompSelected()); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo, GetLabel());
}
void Fuse::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;

	f << "FUSE" << "       " << to_string(GetID()) << "       " << GetLabel() << "       " << GetValue() << "       " << to_string(Gfx.PointsList[0].x) << "       " << to_string(Gfx.PointsList[0].y) << endl;
}
void Fuse::Operate()
{

}
