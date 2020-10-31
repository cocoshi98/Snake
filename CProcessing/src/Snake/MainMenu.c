#ifndef SNAKE_COLLISION_
#define SNAKE_COLLISION_

#include "Snake.h"

Button playButton;
Button quitButton;

void PlayButton_VariablesInit(void)
{
	playButton.colour = CP_Color_Create(255, 255, 255, 255);
	playButton.fontColour = CP_Color_Create(255, 0, 0, 255);
	playButton.hoverColour = CP_Color_Create(43, 224, 49, 255);
	playButton.pos.x = CP_System_GetWindowWidth() / 2.0f;
	playButton.pos.y = CP_System_GetWindowHeight() / 1.6f;

	playButton.buttonHalfsize_x = 150.0f;
	playButton.buttonHalfsize_y = 50.0f;
	playButton.fontsize = 70.0f;

	playButton.left = playButton.pos.x - playButton.buttonHalfsize_x;
	playButton.right = playButton.pos.x + playButton.buttonHalfsize_x;
	playButton.top = playButton.pos.y - playButton.buttonHalfsize_y;
	playButton.bottom = playButton.pos.y + playButton.buttonHalfsize_y;
}

void QuitButton_VariablesInit(void)
{
	quitButton.colour = CP_Color_Create(255, 255, 255, 255);
	quitButton.fontColour = CP_Color_Create(255, 0, 0, 255);
	quitButton.hoverColour = CP_Color_Create(43, 224, 49, 255);
	quitButton.pos.x = CP_System_GetWindowWidth() / 2.0f;
	quitButton.pos.y = CP_System_GetWindowHeight() / 1.3f;

	quitButton.buttonHalfsize_x = 150.0f;
	quitButton.buttonHalfsize_y = 50.0f;
	quitButton.fontsize = 70.0f;

	quitButton.left = quitButton.pos.x - quitButton.buttonHalfsize_x;
	quitButton.right = quitButton.pos.x + quitButton.buttonHalfsize_x;
	quitButton.top = quitButton.pos.y - quitButton.buttonHalfsize_y;
	quitButton.bottom = quitButton.pos.y + quitButton.buttonHalfsize_y;
}

void MainMenu_Init(void)
{
	PlayButton_VariablesInit();
	QuitButton_VariablesInit();

	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
}

void MainMenu_Update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));

	DrawSnakeTitle();
	DrawPlayButton();
	DrawQuitButton();

	CheckHoverPlayButton();
	CheckHoverQuitButton();
}

void MainMenu_Exit(void)
{

}


void DrawSnakeTitle(void)
{
	float fontsize_title = 100.0f;
	float x = CP_System_GetWindowWidth() / 2.0f;
	float y = CP_System_GetWindowHeight() / 3.0f;

	CP_Settings_TextSize(fontsize_title);
	CP_Settings_Fill(CP_Color_Create(43, 224, 49, 255));
	CP_Font_DrawText("SNAKE GAME", x, y);
}

void DrawPlayButton(void)
{
	CP_Settings_Fill(playButton.colour);
	CP_Graphics_DrawRect(playButton.pos.x, playButton.pos.y, playButton.buttonHalfsize_x * 2, playButton.buttonHalfsize_y * 2);

	CP_Settings_TextSize(playButton.fontsize);
	CP_Settings_Fill(playButton.fontColour);
	CP_Font_DrawText("PLAY", playButton.pos.x, playButton.pos.y);
}

void DrawQuitButton(void)
{
	CP_Settings_Fill(quitButton.colour);
	CP_Graphics_DrawRect(quitButton.pos.x, quitButton.pos.y, quitButton.buttonHalfsize_x * 2, quitButton.buttonHalfsize_y * 2);

	CP_Settings_TextSize(quitButton.fontsize);
	CP_Settings_Fill(quitButton.fontColour);
	CP_Font_DrawText("QUIT", quitButton.pos.x, quitButton.pos.y);
}

void CheckHoverPlayButton(void)
{
	// check cursor position
	float mouseX = CP_Input_GetMouseX();
	float mouseY = CP_Input_GetMouseY();

	// check if cursor hover PLAY button
	if (mouseX >= playButton.left &&
		mouseX <= playButton.right &&
		mouseY >= playButton.top &&
		mouseY <= playButton.bottom)
	{

		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameState(Snake_Init, Snake_Update, Snake_Exit);
		}

		else
		{
			// Change font and button colour when cursor hover START button
			CP_Settings_Fill(playButton.hoverColour);
			CP_Graphics_DrawRect(playButton.pos.x, playButton.pos.y, playButton.buttonHalfsize_x * 2, playButton.buttonHalfsize_y * 2);

			CP_Settings_TextSize(playButton.fontsize);
			CP_Settings_Fill(playButton.colour);
			CP_Font_DrawText("PLAY", playButton.pos.x, playButton.pos.y);
		}
	}
}

void CheckHoverQuitButton(void)
{
	// check cursor position
	float mouseX = CP_Input_GetMouseX();
	float mouseY = CP_Input_GetMouseY();

	// check if cursor hover QUIT button
	if (mouseX >= quitButton.left &&
		mouseX <= quitButton.right &&
		mouseY >= quitButton.top &&
		mouseY <= quitButton.bottom)
	{

		if (CP_Input_MouseClicked())
		{
			CP_Engine_Terminate();
		}
		else
		{
			// Change font and button colour when cursor hover QUIT button
			CP_Settings_Fill(quitButton.hoverColour);
			CP_Graphics_DrawRect(quitButton.pos.x, quitButton.pos.y, quitButton.buttonHalfsize_x * 2, quitButton.buttonHalfsize_y * 2);

			CP_Settings_TextSize(quitButton.fontsize);
			CP_Settings_Fill(quitButton.colour);
			CP_Font_DrawText("QUIT", quitButton.pos.x, quitButton.pos.y);
		}
	}
}
#endif // !