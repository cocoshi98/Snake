#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdbool.h>
#include "cprocessing.h"

#define MAX_ROW 20
#define MAX_COL 20
#define GRID_PADDING 5.0f
#define SPEED_MULTIPLIER_PER_APPLE 1.10f

typedef enum eDirections
{
	NORTH,
	SOUTH,
	EAST,
	WEST
} eDirections;

typedef enum eCellFlag
{
	NOTHING,
	WALL,
	APPLE,
	SNAKE
} eCellFlag;

typedef union INT_Vector
{
	int v[2];
	struct
	{
		int x, y;
	};
} INT_Vector;

typedef struct Cell
{
	INT_Vector pos;
	eCellFlag contents;
} Cell;

typedef struct Grid
{
	float cellWidth;
	float cellHeight;
	float cellPadding;
	INT_Vector sizeUnits;
	Cell cells[MAX_ROW][MAX_COL];
	CP_Color color;
} Grid;

typedef struct SnakeSegment
{
	CP_Vector pos;
} SnakeSegment;

typedef struct Snake
{
	//max amount of snake segments is whole screen
	SnakeSegment segments[MAX_ROW * MAX_COL];
	int segmentLength;
	CP_Color color;
	eDirections snakeCurrDir;
	INT_Vector movVec;
	float speed;
	bool canMove;
	bool isDead;
} Snake;

typedef struct Apple
{
	INT_Vector pos;
	CP_Color color;
} Apple;

typedef struct SnakeGame
{
	Snake m_snake;
	Grid m_grid;
	float updateTimer;
	Apple m_apple;
	eDirections movementBuffer;
} SnakeGame;


void Snake_Init(void);
void Snake_Update(void);
void DrawApple(const Grid *m_grid, Apple *m_apple);
void Snake_Exit(void);
void UpdateGameTick(float *gameTimer, Snake *snake);
void CheckNextCell(const Grid *grid, Snake *m_snake, Apple *m_apple);
void DrawSnek(Snake *m_snake, const Grid *m_grid);
void MoveSnake(Snake *m_snake, bool *canMove, float *timer);
void wrapCoordinates(SnakeSegment *snake);
void spawnApple(Snake *m_snake, Apple *m_apple);
void PlayerInput(Snake *m_snake, eDirections *movementBuffer);
void DrawGrid(const Grid *m_Grid);
void snakeGrow(Snake *m_snake);

#endif // !_SNAKE_H_
