#ifndef KINGTHREAT_H_INCLUDED
#define KINGTHREAT_H_INCLUDED

#include "board.h"
#include "constants.h"
using namespace std;

int KingX;
int KingY;

void ShowPawnCoverage(int x, int y, int color)
{
    int nextY = y + color;

    if (isInside(x + 1, nextY))
        enemyCoverage[nextY][x + 1] = 1;

    if (isInside(x - 1, nextY))
        enemyCoverage[nextY][x - 1] = 1;
}

void ShowBishopCoverage(int x, int y, int color)
{
    int cX = x + 1;
    int cY = y + 1;
    while (cX < 8 && cY < 8)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX++;
        cY++;
    }

    cX = x - 1;
    cY = y - 1;
    while (cX > -1 && cY > -1)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX--;
        cY--;
    }

    cX = x + 1;
    cY = y - 1;
    while (cY > -1 && cX < 8)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX++;
        cY--;
    }

    cX = x - 1;
    cY = y + 1;
    while (cX > -1 && cY < 8)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX--;
        cY++;
    }
}

void ShowKnightCoverage(int x, int y, int color)
{
    if (isInside(x - 1, y + 2))
        enemyCoverage[y + 2][x - 1] = 1;

    if (isInside(x + 1, y + 2))
        enemyCoverage[y + 2][x + 1] = 1;

    if (isInside(x + 2, y + 1))
        enemyCoverage[y + 1][x + 2] = 1;

    if (isInside(x + 2, y - 1))
        enemyCoverage[y - 1][x + 2] = 1;

    if (isInside(x + 1, y - 2))
        enemyCoverage[y - 2][x + 1] = 1;

    if (isInside(x - 1, y - 2))
        enemyCoverage[y - 2][x - 1] = 1;

    if (isInside(x - 2, y - 1))
        enemyCoverage[y - 1][x - 2] = 1;

    if (isInside(x - 2, y + 1))
        enemyCoverage[y + 1][x - 2] = 1;
}

void ShowCastleCoverage(int x, int y, int color)
{
    int cX = x + 1;
    while (cX < 8)
    {
        enemyCoverage[y][cX] = 1;

        //if (board[y][cX] != 0) break;

        cX++;
    }

    cX = x - 1;
    while (cX > -1)
    {
        enemyCoverage[y][cX] = 1;

        if (board[y][cX] != 0) break;

        cX--;
    }

    int cY = y - 1;
    while (cY > -1)
    {
        enemyCoverage[cY][x] = 1;

        if (board[cY][x] != 0) break;

        cY--;
    }

    cY = y + 1;
    while (cY < 8)
    {
        enemyCoverage[cY][x] = 1;

        if (board[cY][x] != 0) break;

        cY++;
    }
}

void ShowQueenCoverage(int x, int y, int color)
{
    int cX, cY;

    cX = x + 1;
    cY = y + 1;
    while (cX < 8 && cY < 8)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX++;
        cY++;
    }

    cX = x - 1;
    cY = y - 1;
    while (cX > -1 && cY > -1)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX--;
        cY--;
    }

    cX = x + 1;
    cY = y - 1;
    while (cY > -1 && cX < 8)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX++;
        cY--;
    }

    cX = x - 1;
    cY = y + 1;
    while (cX > -1 && cY < 8)
    {
        enemyCoverage[cY][cX] = 1;

        if (board[cY][cX] != 0) break;

        cX--;
        cY++;
    }

    cX = x + 1;
    while (cX < 8)
    {
        enemyCoverage[y][cX] = 1;

        if (board[y][cX] != 0) break;

        cX++;
    }

    cX = x - 1;
    while (cX > -1)
    {
        enemyCoverage[y][cX] = 1;

        if (board[y][cX] != 0) break;

        cX--;
    }

    cY = y - 1;
    while (cY > -1)
    {
        enemyCoverage[cY][x] = 1;

        if (board[cY][x] != 0) break;

        cY--;
    }

    cY = y + 1;
    while (cY < 8)
    {
        enemyCoverage[cY][x] = 1;

        if (board[cY][x] != 0) break;

        cY++;
    }
}

void ShowKingCoverage(int x, int y, int color)
{
    for (int j = x - 1; j <= x + 1; j++)
    {
        for (int i = y - 1; i <= y + 1; i++)
        {
            if (i == y && j == x)
                continue;

            if (isInside(i, j))
            {
                enemyCoverage[i][j] = 1;
            }
        }
    }
}

void FindKing(int color)
{
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            if (sgn(board[y][x]) == color && abs(board[y][x]) == KING)
            {
                KingX = x;
                KingY = y;
                break;
            }
}

void ShowFigureCoverage(int x, int y, int figure)
{
    int color = sgn(figure);
    switch (abs(figure))
    {
    case 1:
    {
        ShowPawnCoverage(x, y, color);
        break;
    }
    case 2:
    {
        ShowBishopCoverage(x, y, color);
        break;
    }
    case 3:
    {
        ShowKnightCoverage(x, y, color);
        break;
    }
    case 4:
    {
        ShowCastleCoverage(x, y, color);
        break;
    }
    case 5:
    {
        ShowQueenCoverage(x, y, color);
        break;
    }
    case 6:
    {
        ShowKingCoverage(x, y, color);
        break;
    }
    }
}

void FormateCoverage(int enemyColor)
{
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (sgn(board[y][x]) == enemyColor)
                ShowFigureCoverage(x, y, board[y][x]);
        }
    }
}

bool Check(int color)
{
    ClearCoverage();
    FindKing(color);
    FormateCoverage(-color);

    return enemyCoverage[KingY][KingX];
}

#endif // KINGTHREAT_H_INCLUDED
#pragma once
