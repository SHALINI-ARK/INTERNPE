#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
char currentPlayer = 'X';
void printBoard();
void userMove();
void computerMove();
bool isValidMove(int row, int col);
bool checkWinner();
bool isBoardFull();
void switchPlayer();

int main() {
    cout << "Welcome to Tic Tac Toe Game ❌ ⭕" << endl;

    printBoard();

    while (true) {
        if (currentPlayer == 'X') {
            userMove();
        } else {
            computerMove();
        }

        printBoard();

        if (checkWinner()) {
            cout << endl << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull()) {
            cout << "It's a draw!" << endl;
            break;
        }

        switchPlayer();
    }

    return 0;
}
void printBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "  -----" << endl;
        }
    }
}
void userMove() {
    int row, col;
    do {
        cout << endl << "Enter your move (row and column): ";
        cin >> row >> col;
    } while (!isValidMove(row, col));

    board[row][col] = 'X';
}
void computerMove() {
    srand(static_cast<unsigned int>(time(0)));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    }while (!isValidMove(row, col));
    cout << endl << "Computer chooses: " << row << " " << col << endl;
    board[row][col] = 'O';
}
bool isValidMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Invalid move. Try again." << endl;
        return false;
    }
    return true;
}
bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer ||
            board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer ||
        board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}
bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
