#include "Connection.h"



Connection::Connection( GraphicsInfo* r_GfxInfo, string lbl, Component* cmp1, Component* cmp2)
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


Connection* Connection::ConnSelect(int Sx, int Sy)
{

	double x1 = pGfxInfo->PointsList[0].x;
	double y1 = pGfxInfo->PointsList[0].y;
	double x2 = pGfxInfo->PointsList[1].x;
	double y2 = pGfxInfo->PointsList[1].y;
	double m = (Sy - y1) * (x2 - x1);
	double n = (y2 - y1) * (Sx - x1);
	

	if (  n >= (m - 500) && n <= (m + 500) && ( ( (Sx <= x2 && Sx >= x1) || (Sx <= x1 && Sx >= x2) ) && ( (Sy <= y2 && Sy >= y1) || (Sy <= y1 && Sy >= y2) )) )
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
void Connection::SetLabel(string lbl)
{
	LBL = lbl;
}

string Connection::GetLabel()
{
	return LBL;
}


Component* Connection::GetComp1()
{
	return Cmpnt1;
}

Component* Connection::GetComp2()
{
	return Cmpnt2;
}


void Connection::SetComp1(Component* c1)
{
	Cmpnt1 = c1;
}

void Connection::SetComp2(Component* c2)
{
	Cmpnt2 = c2;
}

GraphicsInfo* Connection::GetGFX()
{
	return pGfxInfo;
}


void Connection::SetGFx(GraphicsInfo* pGfx)
{
	pGfxInfo = pGfx;
}

void Connection::SaveFile(fstream& f,int id1,int id2) 
{
	GraphicsInfo& Gfx = *pGfxInfo;
	f << to_string(id1) << "       "  <<to_string(id2) << endl;
}



