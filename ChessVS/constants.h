#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int step = 90;
char ESC = 27;
const int IMAGE_SIZE = 64;

const int WHITE = 1;
const int BLACK = -1;

const int WHITE_KING = 6;
const int BLACK_KING = -6;
const int KING = 6;
const int QUEEN = 5;
const int CASTLE = 4;
const int KNIGHT = 3;
const int BISHOP = 2;
const int PAWN = 1;


int sgn(int num)
{
    if (num < 0)
        return BLACK;
    else if (num > 0)
        return WHITE;
    else
        return 0;
}

void swap(int& a, int& b)
{
    int t = b;
    b = a;
    a = t;
}

bool isInside(int x, int y)
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

#endif // CONSTANTS_H_INCLUDED
