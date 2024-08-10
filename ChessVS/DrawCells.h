#ifndef DRAWCELLS_H_INCLUDED
#define DRAWCELLS_H_INCLUDED

#include "board.h"
#include "constants.h"

void DrawPawnMoves(int redX, int redY, int figure)
{
    if (sgn(figure) != sgn(currTurn))
        return;

    int nextY = redY + sgn(figure);

    if (isInside(redX, nextY) && board[nextY][redX] == 0)
    {
        possibleMoves[nextY][redX] = 2;

        if (redY == 1 && figure > 0 && board[redY + 2][redX] == 0)
        {
            possibleMoves[redY + 2][redX] = 2;
        }
        else if (redY == 6 && figure < 0 && board[redY - 2][redX] == 0)
        {
            possibleMoves[redY - 2][redX] = 2;
        }
    }

    if (isInside(redX - 1, nextY) && sgn(board[nextY][redX - 1]) == -sgn(figure))
        possibleMoves[nextY][redX - 1] = 2;

    if (isInside(redX + 1, nextY) && sgn(board[nextY][redX + 1]) == -sgn(figure))
        possibleMoves[nextY][redX + 1] = 2;
}

void DrawBishopMoves(int redX, int redY, int figure)
{
    if (sgn(figure) != sgn(currTurn))
        return;

    for (int i = redX + 1, j = redY + 1; i <= 7 && j <= 7; i++, j++)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int i = redX - 1, j = redY - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int i = redX - 1, j = redY + 1; i >= 0 && j <= 7; i--, j++)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int i = redX + 1, j = redY - 1; i <= 7 && j >= 0; i++, j--)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }
}

void DrawKnightMoves(int redX, int redY, int figure)
{
    if (sgn(figure) != sgn(currTurn))
        return;

    int posX = redX - 1;
    int posY = redY + 2;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        //std::cout << "redX+1 = " << redX + 1 << " | redY+2 = " << redY + 2 << "\n";
        possibleMoves[posY][posX] = 2;
    }

    posX += 2;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;

    posX += 1;
    posY -= 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;

    posY -= 2;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;

    posX -= 1;
    posY -= 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;

    posX -= 2;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;

    posX -= 1;
    posY += 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;

    posY += 2;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
        possibleMoves[posY][posX] = 2;
}

void DrawCastleMoves(int redX, int redY, int figure)
{
    if (sgn(figure) != sgn(currTurn))
        return;

    for (int x = redX + 1; x <= 7; x++)
    {
        if (board[redY][x] == 0)
            possibleMoves[redY][x] = 2;
        else if (sgn(board[redY][x]) == -sgn(figure))
        {
            possibleMoves[redY][x] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int x = redX - 1; x >= 0; x--)
    {
        if (board[redY][x] == 0)
            possibleMoves[redY][x] = 2;
        else if (sgn(board[redY][x]) == -sgn(figure))
        {
            possibleMoves[redY][x] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int y = redY + 1; y <= 7; y++)
    {
        if (board[y][redX] == 0)
            possibleMoves[y][redX] = 2;
        else if (sgn(board[y][redX]) == -sgn(figure))
        {
            possibleMoves[y][redX] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int y = redY - 1; y >= 0; y--)
    {
        if (board[y][redX] == 0)
            possibleMoves[y][redX] = 2;
        else if (sgn(board[y][redX]) == -sgn(figure))
        {
            possibleMoves[y][redX] = 2;
            break;
        }
        else
        {
            break;
        }
    }
}

void DrawQueenMoves(int redX, int redY, int figure)
{
    if (sgn(figure) != sgn(currTurn))
        return;

    for (int i = redX + 1, j = redY + 1; i <= 7 && j <= 7; i++, j++)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int i = redX - 1, j = redY - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int i = redX - 1, j = redY + 1; i >= 0 && j <= 7; i--, j++)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int i = redX + 1, j = redY - 1; i <= 7 && j >= 0; i++, j--)
    {
        if (board[j][i] == 0)
            possibleMoves[j][i] = 2;
        else if (sgn(board[j][i]) == -sgn(figure))
        {
            possibleMoves[j][i] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int x = redX + 1; x <= 7; x++)
    {
        if (board[redY][x] == 0)
            possibleMoves[redY][x] = 2;
        else if (sgn(board[redY][x]) == -sgn(figure))
        {
            possibleMoves[redY][x] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int x = redX - 1; x >= 0; x--)
    {
        if (board[redY][x] == 0)
            possibleMoves[redY][x] = 2;
        else if (sgn(board[redY][x]) == -sgn(figure))
        {
            possibleMoves[redY][x] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int y = redY + 1; y <= 7; y++)
    {
        if (board[y][redX] == 0)
            possibleMoves[y][redX] = 2;
        else if (sgn(board[y][redX]) == -sgn(figure))
        {
            possibleMoves[y][redX] = 2;
            break;
        }
        else
        {
            break;
        }
    }

    for (int y = redY - 1; y >= 0; y--)
    {
        if (board[y][redX] == 0)
            possibleMoves[y][redX] = 2;
        else if (sgn(board[y][redX]) == -sgn(figure))
        {
            possibleMoves[y][redX] = 2;
            break;
        }
        else
        {
            break;
        }
    }
}

void DrawKingMoves(int redX, int redY, int figure)
{
    if (sgn(figure) != sgn(currTurn))
        return;

    int posX = redX + 1;
    int posY = redY + 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posY -= 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posY -= 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posX -= 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posX -= 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posY += 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posY += 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }

    posX += 1;
    if (isInside(posX, posY) && (board[posY][posX] == 0 || sgn(board[posY][posX]) == -sgn(figure)))
    {
        possibleMoves[posY][posX] = 2;
    }
}

void ShowPossibleMoves(int figure, int redX, int redY)
{
    switch (abs(figure))
    {
    case 1:
    {
        DrawPawnMoves(redX, redY, figure);
        break;
    }
    case 2:
    {
        DrawBishopMoves(redX, redY, figure);
        break;
    }
    case 3:
    {
        DrawKnightMoves(redX, redY, figure);
        break;
    }
    case 4:
    {
        DrawCastleMoves(redX, redY, figure);
        break;
    }
    case 5:
    {
        DrawQueenMoves(redX, redY, figure);
        break;
    }
    case 6:
    {
        DrawKingMoves(redX, redY, figure);
        break;
    }
    }
}

#endif // DRAWCELLS_H_INCLUDED
#pragma once
