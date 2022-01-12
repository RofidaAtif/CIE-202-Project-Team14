#include "Component.h"


Component::Component(GraphicsInfo *r_GfxInfo, int id, double val, string lbl,string type)
{
	m_pGfxInfo = r_GfxInfo;
	m_Label = lbl;
	m_Value = val;
	m_ID = id;
	CompType = type;
}
Component::Component(GraphicsInfo* r_GfxInfo, int id, string lbl, string type)
{
	m_pGfxInfo = r_GfxInfo;
	m_Label = lbl;
	m_Value = 0;
	m_ID = id;
	CompType = type;
}



Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}

int Component::getCompCenterX(UI* pUI) {
	return m_pGfxInfo->PointsList[0].x + pUI->getCompWidth() / 2;
}
int Component::getCompCenterY(UI* pUI) {
	return m_pGfxInfo->PointsList[0].y + pUI->getCompHeight() / 2;
}



bool Component::GetCompSelected() {
	return CompSelected;
}
Component* Component::CompSelect(int Sx, int Sy)
{

	int x1 = m_pGfxInfo->PointsList[0].x;
	int y1 = m_pGfxInfo->PointsList[0].y;
	int x2 = m_pGfxInfo->PointsList[1].x;
	int y2 = m_pGfxInfo->PointsList[1].y;
	
	if (Sx <= x2 && Sx >= x1 && Sy <= y2 && Sy >= y1)
	{
		CompSelected = !CompSelected;
	}
	else
	{
		CompSelected = false;
	}

	if (CompSelected == true)
	{

		return this;
	}
	else
	{
		return nullptr;
	}
	
}

void Component::SetLabel(string lbl)
{
	m_Label = lbl;
}




string Component::GetLabel()
{
	return m_Label;
}


void Component::SetValue(double val)
{
	m_Value = val;
}




double Component::GetValue()
{
	return m_Value;
}
int Component::GetID()
{
	return m_ID;
}

void Component::SetID(int id)
{
	m_ID = id;
}

void Component::SetGfx(GraphicsInfo* r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;
}

int Component::GetTerm1_conn_count()
{
	return term1_conn_count;
}
int Component::GetTerm2_conn_count()
{
	return term2_conn_count;
}

void Component::SetTerm1_conn_count(int t1)
{
	term1_conn_count = t1;
}
void Component::SetTerm2_conn_count(int t2)
{
	term2_conn_count = t2;

}
GraphicsInfo* Component::GetGfx()
{
	return m_pGfxInfo;
}
string Component:: GetCompType()
{
	return CompType;
}

Component::~Component()
{}

