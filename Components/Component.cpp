#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
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



bool Component::GetSelected() {
	return Selected;
}
void Component::Select(int Sx, int Sy)
{

	int x1 = m_pGfxInfo->PointsList[0].x;
	int y1 = m_pGfxInfo->PointsList[0].y;
	int x2 = m_pGfxInfo->PointsList[1].x;
	int y2 = m_pGfxInfo->PointsList[1].y;
	
	if (Sx <= x2 && Sx >= x1 && Sy <= y2 && Sy >= y1)
	{
		Selected = !Selected;
	}
	else
	{
		Selected = false;
	}
	
}

Component::~Component()
{}

