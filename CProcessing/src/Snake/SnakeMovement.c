#ifndef _SNAKE_MOVEMENT_
#define _SNAKE_MOVEMENT_

#include "Snake.h"
void MoveSnake(Snake* m_snake, bool* canMove, float* timer)
{
	if (m_snake->canMove) {
		//increment snake
		if (!m_snake->isDead) {
			if (m_snake->segmentLength > 1) {
				for (int x = m_snake->segmentLength; x > 0; x--)
				{
					m_snake->segments[x].pos.x = m_snake->segments[x - 1].pos.x;
					m_snake->segments[x].pos.y = m_snake->segments[x - 1].pos.y;
				}
			}
			m_snake->segments[0].pos.x += (int)m_snake->movVec.x;
			m_snake->segments[0].pos.y += (int)m_snake->movVec.y;
		}
		m_snake->canMove = false;
	}
}

#endif // !

