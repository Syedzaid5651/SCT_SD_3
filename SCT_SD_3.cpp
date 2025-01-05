#include <iostream>
#define N 9
using namespace std;

bool Safe(int board[N][N], int r, int c, int num) {
   
    for (int x = 0; x < N; x++)
        if (board[r][x] == num)
            return false;

    for (int x = 0; x < N; x++)
        if (board[x][c] == num)
            return false;

    int startRow = r - r % 3, startCol = c - c % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool solveSudoku(int board[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (Safe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
                return true;
        }
        board[row][col] = 0;
    }

    return false;
}

void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << grid[r][d] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N];
    cout << "Enter the Sudoku puzzle (0 for empty cells):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        cout << "No solution exists" << endl;

    return 0;
}