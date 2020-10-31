#ifndef _SNAKE_WALLS_
#define _SNAKE_WALLS_

#include "Snake.h"


void wrapCoordinates(SnakeSegment* snek, Snake* m_snake, Grid* m_grid)
{
	if (m_grid->cells[(int)m_snake->segments[0].pos.x + m_snake->movVec.x][(int)m_snake->segments[0].pos.y + m_snake->movVec.y].contents == WALL)
	{
		m_snake->isDead = true;
		CP_Engine_SetNextGameState(GameOver_Init, GameOver_Update, GameOver_Exit);
	}
	/*else if (snek->pos.x >= MAX_COL)
	{
		snek->pos.x = 0;
	}
	else if (snek->pos.x < 0)
	{
		snek->pos.x = MAX_ROW - 1;
	}
	if (snek->pos.y >= MAX_ROW) {
		snek->pos.y = 0;
	}
	else if (snek->pos.y < 0)
	{
		snek->pos.y = MAX_COL - 1;
	}*/
}

void DrawGrid(Grid* m_Grid)
{
	for (int x = 0; x < MAX_ROW; x++)
	{
		m_Grid->cells[x][0].contents = WALL;
		m_Grid->cells[x][MAX_COL - 1].contents = WALL;
	}
	for (int y = 0; y < MAX_COL; y++)
	{
		m_Grid->cells[0][y].contents = WALL;
		m_Grid->cells[MAX_ROW - 1][y].contents = WALL;
	}
	CP_Settings_Fill(m_Grid->color);
	for (int x = 0; x < m_Grid->sizeUnits.x; x++)
	{
		for (int y = 0; y < m_Grid->sizeUnits.y; y++)
		{
			//draw grid
			
			if (m_Grid->cells[x][y].contents == WALL)
			{
			CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255)); //blue color
			CP_Graphics_DrawRect(m_Grid->cellPadding + (x * m_Grid->cellWidth), m_Grid->cellPadding + (y * m_Grid->cellHeight),
				m_Grid->cellWidth - m_Grid->cellPadding, m_Grid->cellHeight - m_Grid->cellPadding);
            }
		
		}
	}
}

#endif // !

