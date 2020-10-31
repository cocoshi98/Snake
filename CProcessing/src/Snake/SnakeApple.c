#ifndef _SNAKE_APPLE_
#define _SNAKE_APPLE_

#include <stdlib.h>
#include "Snake.h"
void spawnApple(Snake* m_snake, Apple* m_apple)
{
	//find random coordinates for apple and set their x,y values
	m_apple->pos.x = (rand() % (MAX_ROW-2) +1);
	m_apple->pos.y = (rand() % (MAX_COL-2) +1);

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
	//m_snake->speed *= SPEED_MULTIPLIER_PER_APPLE ;
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
