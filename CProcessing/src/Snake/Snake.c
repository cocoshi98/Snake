#include "cprocessing.h"
#include <string.h>

#define SNAKE 1
#define FOOD 2
#define WALL 3

#define GRID_WIDTH 16
#define GRID_HEIGHT 16

int snakeX, snakeY;
int grid[10][8];

float gridUnitWidth;
float gridUnitHeight;


void Snake_Init(void)
{
	gridUnitWidth = 64;
	gridUnitHeight = 64;
}

void Snake_Update(void)
{
	CP_Graphics_DrawRect((float)snakeX, (float)snakeY, gridUnitWidth, gridUnitHeight);
}

void Snake_Exit(void)
{

}