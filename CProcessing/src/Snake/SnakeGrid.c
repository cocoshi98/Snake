#ifndef _SNAKE_WALLS_
#define _SNAKE_WALLS_

#include "snek.h"
void wrapCoordinates(SnakeSegment* snek)
{
	//can add isDead here to bang the walls
	if (snek->pos.x >= MAX_COL) {
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
	}
}

void DrawGrid(const Grid* m_Grid)
{
	CP_Settings_Fill(m_Grid->color);
	for (int x = 0; x < m_Grid->sizeUnits.x; x++)
	{
		for (int y = 0; y < m_Grid->sizeUnits.y; y++)
		{
			//draw grid
			CP_Graphics_DrawRect(m_Grid->cellPadding + (x * m_Grid->cellWidth), m_Grid->cellPadding + (y * m_Grid->cellHeight),
				m_Grid->cellWidth - m_Grid->cellPadding, m_Grid->cellHeight - m_Grid->cellPadding);

		}
	}
}

#endif // !

