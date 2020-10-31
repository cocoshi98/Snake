#ifndef SNAKE_COLLISION_
#define SNAKE_COLLISION_

#include "Snake.h"
void CheckNextCell(const Grid* grid, Snake* m_snake, Apple* m_apple)
{
	//if snake head
	if (m_snake->segments[0].pos.x + m_snake->movVec.x == m_apple->pos.x && m_snake->segments[0].pos.y + m_snake->movVec.y == m_apple->pos.y)
	{
		snakeGrow(m_snake);
		spawnApple(m_snake, m_apple);
	}

	for (int i = 1; i < m_snake->segmentLength; i++)
	{
		if (m_snake->segments[0].pos.x + m_snake->movVec.x == m_snake->segments[i].pos.x && m_snake->segments[0].pos.y + m_snake->movVec.y == m_snake->segments[i].pos.y)
		{
			m_snake->isDead = true;
			CP_Engine_SetNextGameState(GameOver_Init, GameOver_Update, GameOver_Exit);
		}
			
	}

}

#endif // !

