#include <bits/stdc++.h>
using namespace std;

bool esValido(int board[4][4], int fila, int columna)
{
    int i, j;

    for (i = 0; i < columna; i++)
        if (board[fila][i] == 1)
            return false;

    for (i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (i = fila, j = columna; j >= 0 && i < 4; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

void dibujarTabler(int board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool solve8Queens(int board[4][4], int total)
{
    if (total == 4){
        return true;
        dibujarTabler(board);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (esValido(board, i, j))
            {
                board[i][j] = 1;
                if (solve8Queens(board, total + 1))
                {
                    return true;
                }
                board[i][j] = 0;
            }
        }
    }
    return false;
}
