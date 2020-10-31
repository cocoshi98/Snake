#ifndef _SNAKE_DRAW_
#define _SNAKE_DRAW_

#include "Snake.h"
void DrawSnek(Snake* m_snake, const Grid* m_grid)
{

	for (int i = 0; i < m_snake->segmentLength; i++)
	{
		CP_Settings_Fill(m_snake->color);
		wrapCoordinates(&m_snake->segments[i]);
		CP_Graphics_DrawRect((m_snake->segments[i].pos.x * m_grid->cellWidth) + GRID_PADDING, (m_snake->segments[i].pos.y * m_grid->cellHeight) + GRID_PADDING, m_grid->cellWidth - GRID_PADDING, m_grid->cellHeight - GRID_PADDING);
	}

}

#endif // !

//#include <stdio.h>
//#include <stdlib.h>
//#include "cprocessing.h"
//#include "SnakeDraw.h"
//
//#define FOOD 1
//#define GRID_HEIGHT 12
//#define GRID_WIDTH 24
//#define MAXARRAY 50
//
//CP_Vector snakeBody[MAXARRAY];
//int coorX = 1;
//int coorY = 1;
//int vecX = 1;
//int vecY = 0;
//int snake = 5;
//
//void snake_draw(void)
//{
//	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255)); //black
//
//	for (int i = snake - 1; i > 0; i--)
//	{
//		snakeBody[i] = snakeBody[i - 1]; //follow snake body
//	}
//	snakeBody[0] = CP_Vector_Set((float)coorX, (float)coorY);
//
//	coorX += vecX;
//	coorY += vecY;
//
//	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255)); //green color
//	CP_Graphics_DrawRect((float)coorX * 30, (float)coorY * 30, 30, 30);
//	for (int i = 0; i < snake; i++)
//	{
//		CP_Graphics_DrawRect(snakeBody[i].x * 30, snakeBody[i].y * 30, 30, 30); //draw snake body
//	}
//}

