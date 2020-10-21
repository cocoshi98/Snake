#include "cprocessing.h"
#include "MainMenu.h"
#include "Game.h"


static float centerX_Play, centerY_Play;
static float buttonLeft_Play, buttonRight_Play, buttonTop_Play, buttonBottom_Play;

static float centerX_Quit, centerY_Quit;
static float buttonLeft_Quit, buttonRight_Quit, buttonTop_Quit, buttonBottom_Quit;

static const float buttonHalfsize_x= 150.0f;
static const float buttonHalfsize_Y = 50.0f;

static CP_Color bgColour, fontColour, buttonColour;

static float fontsize = 70.0f;

void MainMenu_Init(void)
{

	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));


	// Button for PLAY 
	centerX_Play = CP_System_GetWindowWidth() / 2.0f;
	centerY_Play = CP_System_GetWindowHeight() / 4.0f;

	buttonLeft_Play = centerX_Play - buttonHalfsize_x;
	buttonRight_Play = centerX_Play + buttonHalfsize_x;
	buttonTop_Play = centerY_Play - buttonHalfsize_Y;
	buttonBottom_Play = centerY_Play + buttonHalfsize_Y;

	// Button for QUIT
	centerX_Quit = CP_System_GetWindowWidth() / 2.0f;
	centerY_Quit = CP_System_GetWindowHeight() / 1.5f;

	buttonLeft_Quit = centerX_Play - buttonHalfsize_x;
	buttonRight_Quit = centerX_Play + buttonHalfsize_x;
	buttonTop_Quit = centerY_Play - buttonHalfsize_Y;
	buttonBottom_Quit = centerY_Play + buttonHalfsize_Y;

	bgColour = CP_Color_Create(0, 0, 0, 255);
	fontColour = CP_Color_Create(255, 0, 0, 255);
	buttonColour = CP_Color_Create(255, 255, 255, 255);

	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

}



void MainMenu_Update(void)
{

	CP_Settings_Background(bgColour);

	// Draw PLAY Button
	CP_Settings_Fill(buttonColour);
	CP_Graphics_DrawRect(centerX_Play, centerY_Play, buttonHalfsize_x * 2, buttonHalfsize_Y * 2);
	
	CP_Settings_TextSize(fontsize);
	CP_Settings_Fill(fontColour);
	CP_Font_DrawText("PLAY", centerX_Play, centerY_Play);

	// Draw QUIT Button
	CP_Settings_Fill(buttonColour);
	CP_Graphics_DrawRect(centerX_Quit, centerY_Quit, buttonHalfsize_x * 2, buttonHalfsize_Y * 2);

	CP_Settings_TextSize(fontsize);
	CP_Settings_Fill(fontColour);
	CP_Font_DrawText("QUIT", centerX_Quit, centerY_Quit);

	if (CP_Input_MouseClicked())
	{
		 float mouseX = CP_Input_GetMouseX();
		 float mouseY = CP_Input_GetMouseY();

		if (mouseX >= buttonLeft_Play &&
			mouseX <= buttonRight_Play &&
			mouseY >= buttonTop_Play &&
			mouseY <= buttonBottom_Play)
		{
			
			CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Exit);
		}
	}

	if (CP_Input_MouseClicked())
	{
		float mouseX = CP_Input_GetMouseX();
		float mouseY = CP_Input_GetMouseY();

		if (mouseX >= buttonLeft_Quit &&
			mouseX <= buttonRight_Quit &&
			mouseY >= buttonTop_Quit &&
			mouseY <= buttonBottom_Quit)
		{
			// do something when quit button is clicked
		}
	}

}
void MainMenu_Exit(void)
{

}