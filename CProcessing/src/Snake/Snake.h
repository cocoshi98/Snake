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

typedef struct scoretimer
{
	char text_timer[100];
	int time_count , score , total;
	float time, maxtime, fontsize;
	CP_Vector pos;

} scoretimer;

typedef struct SnakeGame
{
	Snake m_snake;
	Grid m_grid;
	float updateTimer;
	Apple m_apple;
	eDirections movementBuffer; 
	scoretimer m_scoretimer;

} SnakeGame;

//MIN YI------------------------------------
typedef struct Button {
	CP_Color colour;
	CP_Color fontColour;
	CP_Color hoverColour;
	CP_Color fontHoverColour;
	CP_Vector pos;
	float left, right, top, bottom;
	float buttonHalfsize_x;
	float buttonHalfsize_y;
	float fontsize;

} Button;


//------------------------------------
void Snake_Init(void);
void Snake_Update(void);
void DrawApple(const Grid *m_grid, Apple *m_apple);
void Snake_Exit(void);
void UpdateGameTick(float *gameTimer, Snake *snake);
void CheckNextCell(const Grid *grid, Snake *m_snake, Apple *m_apple, scoretimer* m_scoretimer);
void DrawSnek(Snake *m_snake, const Grid *m_grid);
void MoveSnake(Snake *m_snake, bool *canMove, float *timer);
void wrapCoordinates(SnakeSegment *snake, Snake* m_snake, Grid* m_grid);
void spawnApple(Snake *m_snake, Apple *m_apple);
void PlayerInput(Snake *m_snake, eDirections *movementBuffer);
void DrawGrid(Grid *m_Grid);
void snakeGrow(Snake *m_snake);
void ScoreTimerUpdate(scoretimer* m_scoretimer);
void display_score(scoretimer* m_scoretimer);

//
void MainMenu_Init(void);
void MainMenu_Update(void);
void MainMenu_Exit(void);
void DrawSnakeTitle(void);
void DrawPlayButton(void);
void DrawQuitButton(void);
void CheckHoverPlayButton(void);
void CheckHoverQuitButton(void);
void GameOver_Init(void);
void GameOver_Update(void);
void GameOver_Exit(void);


#endif // !_SNAKE_H_
