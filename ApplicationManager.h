#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <sstream>
#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Components\Connection.h"


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components
	enum { MaxConnCount = 200 };   //Max no of Connectors

private:
	bool IsValid;
	string Comp1ClckTerm, Comp2ClckTerm;
	int CompCount;		//Actual number of Components
	int ConnCount;	    //Actual number of Connections
	int SLCompIndex, SLConnIndex;
	bool IsCut;
	int CutID;
	Component* SLComp;
	Connection* SLConn;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];	//List of all Connections (Array of pointers)
	Component* CPDComp;

	UI* pUI; //pointer to the UI


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	
	void SetComp1ClckTerm(string clcked);
	string GetComp1ClckTerm();

	void SetComp2ClckTerm(string clcked);
	string GetComp2ClckTerm();

	bool GetIsValid();
	void SetIsValid(bool valid);

	Component * GetCompList(int i);
	void SetCompList(int TBSindex, Component* SetValue);
	Connection* GetConnList(int i);
	void SetConnList(int TBSindex, Connection* SetValue); //To be set index

	int GetCompCount();
	int GetConnCount();
	void AddConnection(Connection* pConn);
	Component* GetComponentByCordinates(int x, int y, int Num=0); //returns pointer to the component if (x,y) is in the component region
	
	Component* GetCompSEL();
	Component* GetCPDComp();
	void SetCPDComp(Component* CPD);
	void SetCompSEL(Component* SEL);
	void SetCompSELIndex(int i);
	int GetCompSELIndex();

	Connection* GetConnSEL();
	void SetConnSEL(Connection* SEL);
	void SetConnSELIndex(int i);
	int GetConnSELIndex();
	int GetCutID();
	void SetCutID(int id);
	
	bool GetIsCut();
	void SetIsCut(bool iscut);
	
	void ClearCompList(int i);
	void ClearConnList(int i);

	void DelCompList(int i);
	void DelConnList(int i);
	
	

	void savefile(fstream& f);

	//destructor
	~ApplicationManager();
};

#endif
