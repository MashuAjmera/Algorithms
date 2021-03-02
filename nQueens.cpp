#include <iostream>
using namespace std;

bool isSafe(int board[], int row, int col, int N)
{
    for (int i = 0; i < col; i++)
        if (board[i] == row || row + col == i + board[i] || row - col == board[i] - i) // matching row/left diogonal/right diagonal
            return false;
    return true;
}

bool solveNQ(int board[], int col, int N)
{
    if (col >= N)
    {
        cout << "\nThe rows in the respective columns of this solution are:";
        for (int i = 0; i < N; i++)
            cout << " " << board[i];
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
        if (isSafe(board, i, col, N))
        {
            board[col] = i;
            res = solveNQ(board, col + 1, N) || res;
            board[col] = -1;
        }

    return res;
}

int main()
{
    int N = 4; // please specify the size of the board required
    int board[N] = {-1};
    if (!solveNQ(board, 0, N))
        cout << "Solution doesn't exist.";
}