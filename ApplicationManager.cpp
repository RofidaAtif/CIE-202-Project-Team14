#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddSwitch.h"
#include "Actions\ActionAddLamp.h"
#include "Actions\ActionAddGround.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddBuzzer.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionSelection.h"
#include "Actions\ActionAddConnection.h"
#include "Actions\ActionEditComp.h"
#include "Actions\ActionEditConn.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionLoad.h"
#include "Actions\SwitchToSIM.h"
#include "Actions\SwitchToDSN.h"
#include "Actions\ActionAddModule.h"

using namespace std;
#include <iostream>

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;
	SLComp = nullptr;
	SLConn = nullptr;
	
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for(int i=0; i<MaxConnCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddConnection(Connection* pConn) 
{
	ConnList[ConnCount++] = pConn;
}

////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetComponentByCordinates(int x, int y) {
	UI* pUI = GetUI();
	int  IsLocated = 0;
	int  DiffX, DiffY;
	int compheight = pUI->getCompHeight();
	int compwidth = pUI->getCompWidth();
	for (int i = 0; i < CompCount; i++) {
		
		DiffX = abs(x - CompList[i]->getCompCenterX(pUI));
		DiffY = abs(y - CompList[i]->getCompCenterY(pUI));
		
		if ((DiffY <= compheight / 2) && (DiffX <= compwidth / 2))
		{
			IsLocated = 1;
			return CompList[i];

			break;
		}


	}
	if (IsLocated == 0)
		return nullptr;
}


////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_LAMP:
			pAct = new ActionAddLamp(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;

		case ADD_BATTERY:
			pAct = new ActionAddBattery(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuzzer(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFuse(this);
			break;
		case SIM_MODE:
			pAct = new SwitchToSIM(this);
			break;
		case DSN_MODE:
			pAct = new SwitchToDSN(this);
			break;

		case SELECT:
			pAct = new ActionSelection(this);
			break;

		case DEL:
			pAct = new ActionDelete(this);
			break;
			
		case ADD_CONNECTION:
			pAct= new ActionAddConnection(this);
			break;
			
		case EDIT_CompLabel:
			pAct = new ActionEditComp(this,"el");
			break;
		case EDIT_CompValue:
			pAct = new ActionEditComp(this, "ev");
			break;
		case EDIT_ConnLabel:
			pAct = new ActionEditConn(this, "el");
			break;
		case EDIT_ConnTerm:
			pAct = new ActionEditConn(this, "ev");
			break;
		case SAVE:
			pAct = new ActionSave(this);
			break;
		case LOAD:
			pAct = new ActionLoad(this);
			break;
		case ADD_MOD:
			pAct = new ActionAddModule(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetCompList(int i)
{
	return CompList[i];
}
void ApplicationManager::SetCompList(int TBSindex, Component* SetValue)
{
	CompList[TBSindex] = SetValue;
}

void ApplicationManager::ClearCompList(int i)
{
	CompList[i] = nullptr;
	CompCount--;
}
////////////////////////////////////////////////////////////////////

Connection* ApplicationManager::GetConnList(int i)
{
	return ConnList[i];
}
void ApplicationManager::SetConnList(int TBSindex, Connection* SetValue)
{
	ConnList[TBSindex] = SetValue;
}
void ApplicationManager::ClearConnList(int i)
{
	ConnList[i] = nullptr;
	ConnCount--;
}

////////////////////////////////////////////////////////////////////
int ApplicationManager::GetCompCount()
{
	return CompCount;
}


////////////////////////////////////////////////////////////////////
int ApplicationManager::GetConnCount()
{
	return ConnCount;

}


////////////////////////////////////////////////////////////////////	
void ApplicationManager::UpdateInterface()
{
	for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);
	for(int i=0; i<ConnCount; i++)
			ConnList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}


Component* ApplicationManager::GetCompSEL()
{
	return SLComp;
}

void ApplicationManager::SetCompSEL(Component* SEL)
{
	SLComp = SEL;
}


int ApplicationManager::GetCompSELIndex()
{
	return SLCompIndex;
}
void ApplicationManager::SetCompSELIndex(int i)
{
	SLCompIndex = i;
}

Connection* ApplicationManager::GetConnSEL()
{
	return SLConn;
}

void ApplicationManager::SetConnSEL(Connection* SEL)
{
	SLConn = SEL;
}

int ApplicationManager::GetConnSELIndex()
{
	return SLConnIndex;
}

void ApplicationManager::SetConnSELIndex(int i)
{
	SLConnIndex = i;
}
////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	for(int i=0; i<ConnCount; i++)
		delete ConnList[i];
	delete pUI;
	
}
