#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "Connection.h"
#include <iostream>
#include<fstream>
#include "..\ApplicationManager.h"

//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label,CompType;
	bool CompSelected;
	double m_Value;
	int m_ID;
	double b_voltage;

protected:
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2

	//Each terminal is connected to set of connections
	Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection *term2_connections[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;


	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component

public:
	Component(GraphicsInfo *r_GfxInfo, int id, double val = 0, string lbl = "",string type ="");
	Component(GraphicsInfo* r_GfxInfo, int id, string lbl = "", string type = "");
	
	
	int getCompCenterX(UI*);
	int getCompCenterY(UI*);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2

	virtual void Operate() = 0;	//Calculates the output voltage according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	virtual void SaveFile(fstream& f) = 0;
	
	bool GetCompSelected(); 
	//virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	//virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	//virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	
	Component();
	void SetLabel(string lbl);
	string GetLabel();
	void SetValue(double val);
	double GetValue();
	int GetID();
	void SetID(int id);
	void SetGfx(GraphicsInfo* r_GfxInfo);
	int GetTerm1_conn_count();
	int GetTerm2_conn_count();
	void SetTerm1_conn_count(int);
	void SetTerm2_conn_count(int);
	GraphicsInfo* GetGfx();

	string GetCompType();
	
	Component* CompSelect(int Sx,int Sy);
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
