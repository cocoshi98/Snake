
#include <stdio.h>
#include "cprocessing.h"
#include <math.h>
#include <stdbool.h>
#include "snake.h"

SnakeGame myGame;

void GameVariablesInit(SnakeGame *game)
{
    game->m_grid.color = CP_Color_Create(0, 0, 0, 255);
    game->m_grid.sizeUnits.x = MAX_ROW;
    game->m_grid.sizeUnits.y = MAX_COL;
    game->m_grid.cellPadding = GRID_PADDING;
    game->m_grid.cellWidth = ((float)CP_System_GetWindowWidth() - game->m_grid.cellPadding) / game->m_grid.sizeUnits.x;
    game->m_grid.cellHeight = ((float)CP_System_GetWindowHeight() - game->m_grid.cellPadding) / game->m_grid.sizeUnits.y;

    game->m_snake.color = CP_Color_Create(0, 200, 0, 255);

    game->m_snake.segmentLength = 2;
    game->m_snake.speed = 15.0f;
    game->m_snake.movVec.x = 1;
    game->m_snake.movVec.y = 0;

    //set snake pos and dir to 2,2
    game->m_snake.isDead = false;
    game->m_snake.canMove = false;
    game->m_snake.segments[0].pos.x = game->m_snake.segments[0].pos.y = 2;
    game->m_snake.segments[1].pos.x = game->m_snake.segments[1].pos.y = 0;
    game->m_snake.snakeCurrDir = EAST;

    game->m_apple.color = CP_Color_Create(255, 0, 0, 255);
    spawnApple(&game->m_snake, &game->m_apple);
}

void Snake_Init(void)
{
    GameVariablesInit(&myGame);
}

void Snake_Update(void)
{

    UpdateGameTick(&myGame.updateTimer, &myGame.m_snake);
    PlayerInput(&myGame.m_snake, &myGame.movementBuffer);

    MoveSnake(&myGame.m_snake, &myGame.m_snake.canMove, &myGame.updateTimer);
    CheckNextCell(&myGame.m_grid, &myGame.m_snake, &myGame.m_apple);
    //draw bg
    CP_Settings_Background(CP_Color_Create(120, 120, 120, 255));
    //draw grid
    DrawGrid(&myGame.m_grid);
    //draw our snake at its positions
    DrawSnek(&myGame.m_snake, &myGame.m_grid);
    //draw our apple on the grid
    DrawApple(&myGame.m_grid, &myGame.m_apple);
}

void UpdateGameTick(float *gameTimer, Snake *snake)
{
    *gameTimer -= snake->speed * CP_System_GetDt();
    if (*gameTimer <= 0)
    {
        snake->canMove = true;
        *gameTimer = 2.0f;
    }
}

//@TODO STOP SNAKE FROM NECKING HIMSELF INSIDE HIMSELF
void PlayerInput(Snake *m_snake, eDirections *movementBuffer)
{

    //take snake directions
    switch (m_snake->snakeCurrDir)
    {
        //can move east west
    case NORTH:
    case SOUTH:
        if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
        {
            *movementBuffer = EAST;
        }
        else if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
        {
            *movementBuffer = WEST;
        }
        break;
        //can move north south
    case EAST:
    case WEST:
        if (CP_Input_KeyDown(KEY_W) || CP_Input_KeyDown(KEY_UP))
        {
            *movementBuffer = NORTH;
        }
        else if (CP_Input_KeyDown(KEY_S) || CP_Input_KeyDown(KEY_DOWN))
        {
            *movementBuffer = SOUTH;
        }
        break;
    default:
        break;
    }

    if (CP_Input_KeyDown(KEY_D))
    {
        if (m_snake->movVec.x != -1)
            m_snake->movVec.x = 1;
        m_snake->movVec.y = 0;
    }
    else if (CP_Input_KeyDown(KEY_A))
    {
        if (m_snake->movVec.x != 1)
            m_snake->movVec.x = -1;
        m_snake->movVec.y = 0;
    }

    if (CP_Input_KeyDown(KEY_W))
    {
        if (m_snake->movVec.y != 1)
            m_snake->movVec.y = -1;
        m_snake->movVec.x = 0;
    }
    else if (CP_Input_KeyDown(KEY_S))
    {
        if (m_snake->movVec.y != -1)
            m_snake->movVec.y = 1;
        m_snake->movVec.x = 0;
    }
}

void Snake_Exit(void)
{
}