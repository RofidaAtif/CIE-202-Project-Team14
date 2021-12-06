#include "Connection.h"

Connection::Connection(int length,GraphicsInfo *r_GfxInfo, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	connLength = length;
	ConnSelected = false;

}

void Connection::Draw(UI* pUI)
{
	
	pUI->DrawConnection(*pGfxInfo, connLength,ConnSelected);
}

void Connection::ConnSelect(int Sx, int Sy)
{

	int x1 = pGfxInfo->PointsList[0].x;
	int y1 = pGfxInfo->PointsList[0].y;
	int x2 = pGfxInfo->PointsList[1].x;
	int y2 = pGfxInfo->PointsList[1].y;

	if (Sx <= x2 && Sx >= x1 && Sy <= y2 && Sy >= y1)
	{
		ConnSelected = !ConnSelected;
	}
	else
	{
		ConnSelected = false;
	}

}


