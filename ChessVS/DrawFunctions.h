#ifndef DRAWFUNCTIONS_H_INCLUDED
#define DRAWFUNCTIONS_H_INCLUDED

#include <iostream>
#include "redCell_structure.h"
#include "constants.h"
#include "DrawCells.h"
#include "Textures.h"
#include "DrawFigures.h"

void ShowFigure(int figure, int x, int y)
{
    if (figure == 0)
        return;

    char color = (figure > 0) ? 'y' : 'b';

    switch (abs(figure))
    {
    case 1:
    {
        DrawPawn(color, x, y);
        break;
    }
    case 2:
    {
        DrawBishop(color, x, y);
        break;
    }
    case 3:
    {
        DrawKnight(color, x, y);
        break;
    }
    case 4:
    {
        DrawCastle(color, x, y);
        break;
    }
    case 5:
    {
        DrawQueen(color, x, y);
        break;
    }
    case 6:
    {
        DrawKing(color, x, y);
        break;
    }
    }
}

void DrawChessboard()
{
    int color = 0;

    for (int x = 0; x <= 8; x++)
    {
        for (int y = 0; y <= 8; y++)
        {
            possibleMoves[y][x] = color;
            color = (color + 1) % 2;
        }
    }

    ShowPossibleMoves(board[redCell.Y][redCell.X], redCell.X, redCell.Y);

    for (int x = 0; x <= 8; x++)
    {
        for (int y = 0; y <= 8; y++)
        {
            int dx = x * step;
            int dy = y * step;

            ShowFigure(board[y][x], x, y);

            if (x == chooseCell.X && y == chooseCell.Y)
            {
                glColor3f((float)245 / 255, (float)152 / 255, (float)62 / 255);
            }
            else if (y == redCell.Y && x == redCell.X)
            {
                glColor3f((float)252 / 255, (float)61 / 255, (float)14 / 255);
            }
            else if (possibleMoves[y][x] != 2)
            {
                float col = (possibleMoves[y][x] == 1) ? 1 : 0.5;
                glColor3f(col, col, col);
            }
            else if (possibleMoves[y][x] == 2)
            {
                glColor3f((float)75 / 255, (float)210 / 255, (float)64 / 255);
            }

            glBegin(GL_QUADS);
            glVertex2i(dx, dy);
            glVertex2i(dx + step, dy);
            glVertex2i(dx + step, dy + step);
            glVertex2i(dx, dy + step);
            glEnd();

            glLineWidth(1.5);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2i(dx, dy);
            glVertex2i(dx + step, dy);
            glVertex2i(dx + step, dy + step);
            glVertex2i(dx, dy + step);
            glEnd();

            glFlush();

            //glutPostRedisplay();
        }
    }
    CopyToOptions();
    ClearPossibleMoves();
}

#endif // DRAWFUNCTIONS_H_INCLUDED
#pragma once
