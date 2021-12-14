#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}


int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction()
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	SetX(x);SetY(y);

	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_LAMP:  return ADD_LAMP;
			case ITM_SWITCH:  return  ADD_SWITCH;
			case ITM_CONN:  return ADD_CONNECTION;
			case ITM_BATTERY: return  ADD_BATTERY;
			case ITM_GROUND:  return  ADD_GROUND;
			case ITM_BUZZER:  return  ADD_BUZZER;
			case ITM_FUSE:  return  ADD_FUSE;
			case ITM_EXIT:	return EXIT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ACT_DEL:	return DEL;
			case ACT_MOVE:	return MOVE;
			case ACT_COPY:	return COPY;
			case ACT_CUT:	return CUT;
			case ACT_UNDO: return UNDO;
			case ACT_REDO: return REDO;
			case SIM: return SIM_MODE;
				
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case AMMETER:	return Ammeter;
			case VOLTAMETER:  return Voltameter;
			case VALIDATE: return Validate;
			case DSN:  return DSN_MODE;
			case ITM_EXIT1:	return EXIT;
			default: return SIM_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	}
}

void UI::SetX(int x)
{
	xcl = x;

}
void UI::SetY(int y)
{
	ycl = y;

}
int UI::GetX()
{
	return xcl;
}
int UI::GetY()
{
	return ycl;
}


//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_LAMP] = "images\\Menu\\Menu_Lamp.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_BATTERY] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_GROUND] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_BUZZER] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_FUSE] = "images\\Menu\\Menu_Fuse.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ACT_MOVE] = "images\\Menu\\Menu_MOVE.jpg";
	MenuItemImages[ACT_COPY] = "images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ACT_CUT] = "images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ACT_PASTE] = "images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ACT_DEL] = "images\\Menu\\Menu_DEL.jpg";
	MenuItemImages[ACT_UNDO] = "images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ACT_REDO] = "images\\Menu\\Menu_REDO.jpg";
	MenuItemImages[SIM] = "images\\Menu\\Menu_SIM.jpg";
	MenuItemImages[ITM_CONN] = "images\\Menu\\Menu_Connection.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_Load.jpg";
	

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[AMMETER] = "images\\Menu\\Menu_AMMETER.jpg";
	MenuItemImages[VOLTAMETER] = "images\\Menu\\Menu_VOLTAMETER.jpg";
	MenuItemImages[VALIDATE] = "images\\Menu\\Menu_Validate.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[DSN] = "images\\Menu\\Menu_DSN.jpg";
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string ResImage;
	if(selected)	
		ResImage ="Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else  
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	if (selected)
	{
		pWind->SetPen(RED, 10);
	}
	else
	{
		pWind->SetPen(BLACK, 10);
	}
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}
void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string SwitchImage;
	if (selected)
		SwitchImage = "Images\\Comp\\Switch_HI.jpg";	//use image of highlighted resistor
	else
		SwitchImage = "Images\\Comp\\Switch.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawLamp(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string LampImage;
	if (selected)
		LampImage = "Images\\Comp\\Lamp_HI.jpg";	//use image of highlighted resistor
	else
		LampImage = "Images\\Comp\\Lamp.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(LampImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawLabel(const GraphicsInfo& r_GfxInfo, string lbl, bool selected) const
{
	pWind->SetFont(15, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + COMP_WIDTH/4, lbl);
}

void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BatteryImage;
	if (selected)
		BatteryImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted Battery
	else
		BatteryImage = "Images\\Comp\\Battery.jpg";	//use image of the normal Battery

	//Draw battery at Gfx_Info (1st corner)
	pWind->DrawImage(BatteryImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawGround(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GroundImage;
	if (selected)
		GroundImage = "Images\\Comp\\Ground_HI.jpg";	//use image of highlighted Battery
	else
		GroundImage = "Images\\Comp\\Ground.jpg";	//use image of the normal Battery

	//Draw ground at Gfx_Info (1st corner)
	pWind->DrawImage(GroundImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BuzzerImage;
	if (selected)
		BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";	//use image of highlighted Battery
	else
		BuzzerImage = "Images\\Comp\\Buzzer.jpg";	//use image of the normal Battery

	//Draw buzzer at Gfx_Info (1st corner)
	pWind->DrawImage(BuzzerImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawFuse(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string FuseImage;
	if (selected)
		FuseImage = "Images\\Comp\\Fuse_HI.jpg";	//use image of highlighted Battery
	else
		FuseImage = "Images\\Comp\\Fuse.jpg";	//use image of the normal Battery

	//Draw fuse at Gfx_Info (1st corner)
	pWind->DrawImage(FuseImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}


void UI::switchtosim()
{
	AppMode = SIMULATION;
};


void UI::switchtodsn()
{
	AppMode = DESIGN;
};

void UI::ClearWindow() {

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, width, height - StatusBarHeight);


}


UI::~UI()
{
	delete pWind;
}
