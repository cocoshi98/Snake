#include "cprocessing.h"
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include "Snake.h"

#define FOOD 2

float timer;
int foodEaten;


void Game_Init(void) 
{
	CP_System_SetWindowSize((int)(GRID_WIDTH * gridUnitX), (int)(GRID_HEIGHT * gridUnitY));
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	setBoundary();
	setFont();
	

}

void Game_Update(void)
{

	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	

	drawTimer();
	draw_Wall();
	draw_Snake();
	

	// Collision with the food	
	if (grid[snakeX][snakeY] == FOOD)
	{
		foodEaten++;
		snakeLength++;
	}
	/*else
	{
		//Draw Food
		int randomX = rand() % (GRID_WIDTH - 1) + 1;
		int randomY = rand() % (GRID_HEIGHT - 1) + 1;
		grid[randomX][randomY] = FOOD;
		CP_Settings_Fill(CP_Color_Create(234, 131, 13, 255));
		CP_Graphics_DrawRect(randomX * gridUnitX, randomY * gridUnitY, gridUnitX, gridUnitY);
	}*/


	check_collision_wall();
	check_collision_snake();


}


void Game_Exit(void)
{

}



