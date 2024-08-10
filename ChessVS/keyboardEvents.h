#include "redCell_structure.h"
#include "board.h"
#include "KingThreat.h"
#include "LostFigures.h"
#include <iostream>

bool* keyStates = new bool[256];

void keyPressed(unsigned char key, int x, int y)
{
    keyStates[key] = 1;

    if (key == ESC)
    {
        exit(0);
    }

    if (spacePressed == 0)
    {
        if ((key == 'W' || key == 'w') && redCell.Y + 1 < 8)
        {
            redCell.Y++;
        }

        if ((key == 'A' || key == 'a') && redCell.X - 1 > -1)
        {
            redCell.X--;
        }

        if ((key == 'S' || key == 's') && redCell.Y - 1 > -1)
        {
            redCell.Y--;
        }

        if ((key == 'D' || key == 'd') && redCell.X + 1 < 8)
        {
            redCell.X++;
        }
    }


    if (spacePressed == 1)
    {
        if ((key == 'W' || key == 'w') && chooseCell.Y + 1 < 8)
        {
            chooseCell.Y++;
        }

        if ((key == 'A' || key == 'a') && chooseCell.X - 1 > -1)
        {
            chooseCell.X--;
        }

        if ((key == 'S' || key == 's') && chooseCell.Y - 1 > -1)
        {
            chooseCell.Y--;
        }

        if ((key == 'D' || key == 'd') && chooseCell.X + 1 < 8)
        {
            chooseCell.X++;
        }
    }

    if (key == ' ' && board[redCell.Y][redCell.X] != 0 && sgn(currTurn) == sgn(board[redCell.Y][redCell.X]) && canMove())
    {
        spacePressed++;
    }

    if (spacePressed == 1)
    {
        if (!spaceFirstTimePressed)
        {
            chooseCell.X = redCell.X;
            chooseCell.Y = redCell.Y;
            spaceFirstTimePressed = 1;
        }
    }

    if (spacePressed == 2)
    {
        if (chooseCell.Y == redCell.Y && chooseCell.X == redCell.X)
        {
            spacePressed = 0;
            spaceFirstTimePressed = 0;
            chooseCell.X = chooseCell.Y = -1;
        }
        else if (choiceOptions[chooseCell.Y][chooseCell.X] == 2)
        {
            /* If eat someone */
            int destFig = board[chooseCell.Y][chooseCell.X];
            if (destFig > 0)
            {
                lostWhite[destFig]++;
            }
            else if (destFig < 0)
            {
                lostBlack[-destFig]++;
            }


            /* Move */
            board[chooseCell.Y][chooseCell.X] = board[redCell.Y][redCell.X];
            board[redCell.Y][redCell.X] = 0;


            /* If a pawn reaches the board`s end, you can replace it with one of the lost figures */
            if ((chooseCell.Y == 0 && board[chooseCell.Y][chooseCell.X] == BLACK * PAWN) ||
                (chooseCell.Y == 7 && board[chooseCell.Y][chooseCell.X] == WHITE * PAWN))
            {
                ChooseLostFigure(chooseCell.X, chooseCell.Y);
            }

            redCell.X = chooseCell.X;
            redCell.Y = chooseCell.Y;

            chooseCell.X = chooseCell.Y = -1;
            spaceFirstTimePressed = 0;
            spacePressed = 0;
            currTurn = -currTurn;

            /* If the game can be continued */
            if (Check(currTurn))
            {
                if (currTurn == WHITE)
                    cout << "White";
                else
                    cout << "Black";

                cout << " King under the threat!\n\n";
            }
        }
        else
        {
            spacePressed = 1;
        }
    }
}

void keyUp(unsigned char key, int x, int y)
{
    keyStates[key] = 0;
}
#pragma once
