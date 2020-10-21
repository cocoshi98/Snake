#pragma once
#include "cprocessing.h"

//********************    CONTROL USER INPUT    *****************************************

int velX = 1;
int velY = 0;
int snakeX = 1;
int snakeY = 1;

void updateUserInput(void)
{
	// If snake is moving horizontally
	if (velX != 0)
	{
		if (CP_Input_KeyTriggered(KEY_DOWN))
		{
			velX = 0;
			velY = 1;
		}
		if (CP_Input_KeyTriggered(KEY_UP))
		{
			velX = 0;
			velY = -1;
		}
	}

	// If snake is moving vertically
	if (velY != 0)
	{
		if (CP_Input_KeyTriggered(KEY_RIGHT))
		{
			velX = 1;
			velY = 0;
		}
		if (CP_Input_KeyTriggered(KEY_LEFT))
		{
			velX = -1;
			velY = 0;
		}
	}

	snakeX += velX;
	snakeY += velY;
}



//******************    DRAW  WALL    *****************************************

#define GRID_WIDTH 80
#define GRID_HEIGHT 40
int grid[GRID_WIDTH][GRID_HEIGHT];

float gridUnitX = 40;
float gridUnitY = 40;

#define WALL 1

void setBoundary(void)
{
	// Set grid fot top and bottom Wall
	for (int x = 0; x < GRID_WIDTH; x++)
	{
		grid[x][0] = WALL;
		grid[x][GRID_HEIGHT - 1] = WALL;
	}
	//Set grid for left and right Wall
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		grid[0][y] = WALL;
		grid[GRID_WIDTH - 1][y] = WALL;
	}

}



void draw_Wall(void)
{
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));

	for (int x = 0; x < GRID_WIDTH; x++)
	{
		for (int y = 0; y < GRID_HEIGHT; y++)
		{
			if (grid[x][y] == WALL)
				CP_Graphics_DrawRect((float)x * gridUnitX, (float)y * gridUnitY, gridUnitX, gridUnitY);
		}
	}
}



//******************    DRAW SNAKE    *****************************************

#define MAXTRAIL 100
CP_Vector snakeTrail[MAXTRAIL];
int snakeLength = 50;

void draw_Snake(void)
{
	// Set trail for snake
	for (int i = snakeLength - 1; i > 0; i--)
	{
		snakeTrail[i] = snakeTrail[i - 1];
	}
	snakeTrail[0] = CP_Vector_Set((float)snakeX, (float)snakeY);

	updateUserInput();

	// Draw Snake
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	CP_Graphics_DrawRect((float)snakeX * gridUnitX, (float)snakeY * gridUnitY, gridUnitX, gridUnitY);
	for (int i = 0; i < snakeLength; i++)
	{
		CP_Graphics_DrawRect(snakeTrail[i].x * gridUnitX, snakeTrail[i].y * gridUnitY, gridUnitX, gridUnitY);
	}
}


//******************    CHECK COLLISION W WALL    *****************************************

void check_collision_wall(void)
{
	if (grid[snakeX][snakeY] == WALL)
		CP_Engine_Terminate();
}


//******************    CHECK COLLISION W SNAKE    *****************************************

void check_collision_snake(void)
{
	for (int i = 0; i < snakeLength; i++)
	{
		if (snakeX == (int)snakeTrail[i].x && snakeY == (int)snakeTrail[i].y)
			CP_Engine_Terminate();
	}
}

//******************    DRAW TIMER    *****************************************

#define CHARACTER_BUFFER_SIZE 40
#define FONT_SIZE 80.0f
int secondsElapsed;
char characterBuffer[CHARACTER_BUFFER_SIZE];
float cornerX, cornerY;
CP_Color fontColour;

void setFont(void)
{
	memset(characterBuffer, 0, CHARACTER_BUFFER_SIZE * sizeof(char));
	cornerX = CP_System_GetWindowWidth() * (9.3f / 10);
	cornerY = CP_System_GetWindowHeight() * (1.0f / 10);
	CP_Settings_TextSize(FONT_SIZE);
	fontColour = CP_Color_Create(255, 38, 143, 255);
}

void drawTimer(void)
{
	secondsElapsed = (int)CP_System_GetSeconds();
	_itoa_s(secondsElapsed, characterBuffer, CHARACTER_BUFFER_SIZE, 10);
	CP_Settings_Fill(fontColour);
	CP_Font_DrawText(characterBuffer, cornerX, cornerY);
}