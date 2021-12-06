#include "Connection.h"
#include <iostream>


Connection::Connection( GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	ConnSelected = false;

}

void Connection::Draw(UI* pUI)
{
	
	pUI->DrawConnection(*pGfxInfo,ConnSelected);
}


void Connection::ConnSelect(int Sx, int Sy)
{

	double x1 = pGfxInfo->PointsList[0].x;
	double y1 = pGfxInfo->PointsList[0].y;
	double x2 = pGfxInfo->PointsList[1].x;
	double y2 = pGfxInfo->PointsList[1].y;
	double m = abs((y2 - y1) / (x2 - x1));
	double n =abs( (Sy - y1) / (Sx - x1) );

	if (  n >= (m - 0.09) && n <= (m + 0.09) && ( (Sx <= x2 && Sx >= x1 && ( (Sy <= y2 && Sy >= y1) || (Sy <= y1 && Sy >= y2))) ) )
	{
		ConnSelected = !ConnSelected;
	}
	else
	{
		ConnSelected = false;
	}

}


