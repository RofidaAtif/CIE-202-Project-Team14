#pragma once
#include "../UI/UI.h"
#include <iostream>
#include<fstream>



class Component;	//forward class declaration

class Connection 
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
	bool ConnSelected;
	string LBL;

public:
	Connection(GraphicsInfo* r_GfxInfo, string lbl= "Label", Component* cmp1 = nullptr, Component* cmp2 = nullptr);

	virtual void Draw(UI* );	//for connection to Draw itself
	Connection* ConnSelect(int Sx, int Sy);
	void SaveFile(fstream& f, int id1, int id2);
	void SetLabel(string lbl);
	string GetLabel();
	Component* GetComp1();
	Component* GetComp2();
	void SetComp1(Component* c1);
	void SetComp2(Component* c2);
	GraphicsInfo* GetGFX();
	void SetGFx(GraphicsInfo* pGfx);

	
};
