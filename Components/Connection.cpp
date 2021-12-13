#include "Connection.h"
#include <iostream>


Connection::Connection( GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	ConnSelected = false;
	LBL = lbl;
}

void Connection::Draw(UI* pUI)
{
	
	pUI->DrawConnection(*pGfxInfo,ConnSelected);
	pUI->DrawLabel(*pGfxInfo, LBL);
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
bool sel = ConnSelected;

	if (ConnSelected == true)
	{

		return this;
	}
	else
	{
		return nullptr;
	}
	
}

Component* Connection::GetComp1()
{
	return Cmpnt1;
}

Component* Connection::GetComp2()
{
	return Cmpnt2;
}
void Connection::SaveFile(fstream& f,int id1,int id2) 
{
	GraphicsInfo& Gfx = *pGfxInfo;
	f << to_string(id1) << "       "  <<to_string(id2) << endl;
}



