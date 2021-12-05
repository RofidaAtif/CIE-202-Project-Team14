#include "Connection.h"

Connection::Connection(int length,GraphicsInfo *r_GfxInfo, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	connLength = length;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, connLength);
}


