#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "constants.h"
#include <map>
#include "GL/freeglut.h"
using namespace std;

int spacePressed = 0;
bool spaceFirstTimePressed = 0;
int currTurn = 1;

int board[8][8]
{
    4, 3, 2, 5, 6, 2, 3, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -4, -3, -2, -5, -6, -2, -3, -4,
};

std::map <int, unsigned int> textures;

int possibleMoves[9][9]
{
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int choiceOptions[9][9]
{
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void ClearPossibleMoves()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            possibleMoves[i][j] = 0;
}

void CopyToOptions()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            choiceOptions[i][j] = possibleMoves[i][j];
}

bool canMove()
{
    bool can = 0;
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            if (choiceOptions[y][x] == 2)
            {
                can = 1;
                break;
            }
    return can;
}

bool enemyCoverage[8][8]
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void ClearCoverage()
{
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
        {
            enemyCoverage[y][x] = 0;
        }
}



#endif // BOARD_H_INCLUDED
#pragma once
