#pragma once
#include "../UI/UI.h"



class Component;	//forward class declaration

class Connection 
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
	int connLength;
	bool ConnSelected;

public:
	Connection(int length, GraphicsInfo *r_GfxInfo, Component *cmp1=nullptr, Component *cmp2=nullptr);

	virtual void Draw(UI* );	//for connection to Draw itself
	void ConnSelect(int Sx, int Sy);
	
};
