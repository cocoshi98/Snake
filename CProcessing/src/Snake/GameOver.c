#ifndef GAME_OVER_
#define GAME_OVER_

#include "Snake.h"

void GameOver_Init(void)
{
	CP_Settings_Background(CP_Color_Create(199, 14, 23, 255));

	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
}

void GameOver_Update(void)
{
	CP_Settings_Background(CP_Color_Create(199, 14, 23, 255));

	float fontsize = 100.0f;
	float posX = CP_System_GetWindowWidth() / 2.0f;
	float posY = CP_System_GetWindowHeight() / 3.5f;
	CP_Settings_TextSize(fontsize);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("GAME OVER", posX, posY);
}

void GameOver_Exit(void)
{

}
#endif // !