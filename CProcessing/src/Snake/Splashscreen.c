#include "cprocessing.h"
#include "Splashscreen.h"
#include "MainMenu.h"

CP_Image digipenLogo;
const int smallScaleFactor = 2;
float logoWidth, logoHeight;
float logoPosX, logoPosY;

CP_Color backgroundColour;

float i = 0.0f;

void Splashscreen_Init(void)
{
	digipenLogo = CP_Image_Load("./Assets/DigiPen_WHITE.png");

	logoWidth = (float)CP_Image_GetWidth(digipenLogo);
	logoHeight = (float)CP_Image_GetHeight(digipenLogo);

	logoPosX = (CP_System_GetWindowWidth()) / 2.0f;
	logoPosY = (CP_System_GetWindowHeight()) / 2.0f;

	backgroundColour = CP_Color_Create(0, 0, 0, 255);
}

void Splashscreen_Update(void)
{
	CP_Settings_Background(backgroundColour);
	
	if (i <= 300)
	{
		i += 100 * CP_System_GetDt();
	}
	else
	{
		CP_Engine_SetNextGameState(MainMenu_Init, MainMenu_Update, MainMenu_Exit);
	}

	CP_Image_Draw(digipenLogo, logoPosX, logoPosY, logoWidth / smallScaleFactor, logoHeight / smallScaleFactor, (int)i);
		
	
}

void Splashscreen_Exit(void)
{
	CP_Image_Free(&digipenLogo);
}