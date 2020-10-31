#ifndef _SNAKE_DRAW_
#define _SNAKE_DRAW_
#include <stdlib.h>
#include "Snake.h"
void DrawSnek(Snake* m_snake, const Grid* m_grid)
{

	for (int i = 0; i < m_snake->segmentLength; i++)
	{
		CP_Settings_Fill(m_snake->color);
		wrapCoordinates(&m_snake->segments[i], m_snake , m_grid);
		CP_Graphics_DrawRect((m_snake->segments[i].pos.x * m_grid->cellWidth) + GRID_PADDING, (m_snake->segments[i].pos.y * m_grid->cellHeight) + GRID_PADDING, m_grid->cellWidth - GRID_PADDING, m_grid->cellHeight - GRID_PADDING);
	}
}

void ScoreTimerUpdate(scoretimer* m_scoretimer)
{
	m_scoretimer->time += CP_System_GetDt();

	if (m_scoretimer->time > m_scoretimer->maxtime)
	{
		m_scoretimer->time_count++;
		m_scoretimer->time = 0.0f;
	}
	_itoa_s(m_scoretimer->time_count, m_scoretimer->text_timer, 100, 10); //display timer
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	CP_Font_DrawText(m_scoretimer->text_timer, m_scoretimer->pos.x, m_scoretimer->pos.y);

	_itoa_s(m_scoretimer->score, m_scoretimer->text_timer, 100, 10); //display scoresheet
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	CP_Font_DrawText(m_scoretimer->text_timer, m_scoretimer->pos.x / 2.0f , m_scoretimer->pos.y / 2.0f);

}
#endif // !


