#ifndef GAME_OVER_
#define GAME_OVER_

#include "Snake.h"
#include <stdlib.h>

SnakeGame myGame;

void display_score(scoretimer* m_scoretimer)
{
	m_scoretimer->total = m_scoretimer->time_count + m_scoretimer->score;

	_itoa_s(m_scoretimer->total, m_scoretimer->text_timer, 100, 10); //display scoresheet
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	CP_Font_DrawText(m_scoretimer->text_timer, m_scoretimer->pos.x / 2.0f, m_scoretimer->pos.y / 0.2f);
}
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

	display_score(&myGame.m_scoretimer);

	CP_Settings_TextSize(fontsize);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("YOUR TOTAL SCORE IS:", posX, posY + 150.0f);


	CP_Settings_TextSize(fontsize);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("[Press space bar to return]", posX, posY + 450.0f);

	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		CP_Engine_SetNextGameState(MainMenu_Init, MainMenu_Update, MainMenu_Exit);
	}
}

void GameOver_Exit(void)
{

}
#endif // !