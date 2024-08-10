#ifndef LOSTFIGURES_H_INCLUDED
#define LOSTFIGURES_H_INCLUDED

#include "constants.h"
#include <map>
#include <iostream>
#include "board.h"
using namespace std;

map <int, int> lostWhite = {
                             {BISHOP, 0},
                             {KNIGHT, 0},
                             {CASTLE, 0},
                             { QUEEN, 1},
};


map <int, int> lostBlack = {
                             {BISHOP, 0},
                             {KNIGHT, 0},
                             {CASTLE, 0},
                             { QUEEN, 1},
};

bool AbleToChoose(map <int, int>& m)
{
    for (int i = BISHOP; i <= QUEEN; i++)
        if (m[i] > 0)
            return 1;

    return 0;
}


void ChooseLostFigure(int x, int y)
{
    if (sgn(board[y][x]) == WHITE && AbleToChoose(lostWhite))
    {
        cout << "Bishop == " << BISHOP << " | You have: " << lostWhite[BISHOP] << endl;
        cout << "Knight == " << KNIGHT << " | You have: " << lostWhite[KNIGHT] << endl;
        cout << "Castle == " << CASTLE << " | You have: " << lostWhite[CASTLE] << endl;
        cout << "Queen  == " << QUEEN << " | You have: " << lostWhite[QUEEN] << endl;
        cout << endl;
        cout << "Input a number of the figure you want: ";

        string req;
        int num;
        while (1)
        {
            cin >> req;
            char figure = req[0];
            if (req.size() == 1 && (BISHOP <= figure - '0' && figure <= QUEEN - '0'))
            {
                num = figure - '0';
                break; 
            }
            
        }

        board[y][x] = currTurn * num;
    }
    else if (sgn(board[y][x]) == BLACK && AbleToChoose(lostBlack))
    {
        cout << "Bishop == " << BISHOP << " | You have: " << lostBlack[BISHOP] << endl;
        cout << "Knight == " << KNIGHT << " | You have: " << lostBlack[KNIGHT] << endl;
        cout << "Castle == " << CASTLE << " | You have: " << lostBlack[CASTLE] << endl;
        cout << "Queen  == " << QUEEN << " | You have: " << lostBlack[QUEEN] << endl;
        cout << endl;
        cout << "Input a number of the figure you want: ";

        int num;
        while (1)
        {
            cin >> num;
            if (BISHOP <= num && num <= QUEEN)
                break;
        }

        board[y][x] = BLACK * num;
    }
}

#endif // LOSTFIGURES_H_INCLUDED
#pragma once
