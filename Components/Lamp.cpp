#include "Lamp.h"

Lamp::Lamp(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Lamp::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawLamp(*m_pGfxInfo, GetCompSelected()); //update to draw resistor
	pUI->DrawLabel(*m_pGfxInfo,GetLabel());
}
void Lamp::SaveFile(fstream& f) {
	GraphicsInfo& Gfx = *m_pGfxInfo;
	
	f <<"BLB"<<"       "<<to_string(GetID()) << "       " << GetLabel() << "       " << GetValue()  << "       " << to_string( Gfx.PointsList[0].x)<< "       " << to_string(Gfx.PointsList[0].y)<<endl;
}
void Lamp::Operate()
{

}
