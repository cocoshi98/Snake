/*
#ifndef _SNAKE_APPLE_
#define _SNAKE_APPLE_

#include <stdlib.h>
#include "snek.h"
void spawnApple(Snake* m_snake, Apple* m_apple)
{
	//find random coordinates for apple and set their x,y values
	m_apple->pos.x = (rand() % MAX_ROW);
	m_apple->pos.y = (rand() % MAX_COL);

	//check if we are trying to spawn m_apple in the snake
	for (int i = 0; i < m_snake->segmentLength; i++)
	{
		if (m_apple->pos.x == m_snake->segments[i].pos.x && m_apple->pos.y == m_snake->segments[i].pos.y)
		{
			//if we are placing the apple inside the snake, recursively call and place the apple somewhere else
			spawnApple(m_snake, m_apple);
			return;
		}
	}
}

void snakeGrow(Snake* m_snake)
{
	//m_snake->speed *= SPEED_MULTIPLIER_PER_APPLE ; // ????
	m_snake->segments[m_snake->segmentLength].pos.x = m_snake->segments[m_snake->segmentLength - 1].pos.x;
	m_snake->segments[m_snake->segmentLength].pos.y = m_snake->segments[m_snake->segmentLength - 1].pos.y;
	++m_snake->segmentLength;
}

void DrawApple(const Grid* m_grid, Apple* m_apple)
{
	CP_Settings_Fill(m_apple->color);
	CP_Graphics_DrawRect(GRID_PADDING + m_apple->pos.x * m_grid->cellWidth, GRID_PADDING + m_apple->pos.y * m_grid->cellHeight, m_grid->cellWidth - GRID_PADDING, m_grid->cellHeight - GRID_PADDING);
}

#endif // !
*/
#include <stdlib.h>
#include "SnakeApple.h"
#include <stdio.h>
#define FOOD 1
#define GRID_HEIGHT 12
#define GRID_WIDTH 24
int grid[GRID_HEIGHT][GRID_WIDTH];
int foodx, foody = 0;
int coorX = 1;
int coorY = 1;

void create_food(void)
{
	foodx = rand() % (GRID_WIDTH - 2) + 1;
	foody = rand() % (GRID_HEIGHT - 2) + 1;

	grid[foodx][foody] = FOOD;
	//CP_Image img1 = CP_Image_Load("./Assets/DigiPen_WHITE.png");
	// Display the image at the mouse position
	//CP_Image_Draw(img1, (float)foodx , (float)foody , 40, 40, 255);
}
void food_draw(void)
{
	for (int x = 1; x < GRID_WIDTH; x++)
	{
		for (int y = 1; y < GRID_HEIGHT; y++)
		{
			if (grid[x][y] == FOOD)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255)); //red color
				CP_Graphics_DrawRect((float)x * 30, (float)y * 30, 30, 30);
			}
		}
	}
}
void eat_food(void)
{
	if (grid[coorX][coorY] == FOOD) //when snake eat food
	{
		grid[coorX][coorY] = 0; //clear food
		//score = score + 10 ;
		//snake++;
		create_food(); //create new food
	}
}