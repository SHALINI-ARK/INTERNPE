#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}

void printTabulation(const vector<int>& playerMoves, char playerSymbol) {
    cout << "Player " << playerSymbol << " Moves: ";
    for (int move : playerMoves) {
        cout << move + 1 << " ";
    }
    cout << endl;
}

bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

void makeMove(vector<vector<char>>& board, int col, char player, vector<int>& playerMoves) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            playerMoves.push_back(col);
            break;
        }
    }
}

bool checkWinner(const vector<vector<char>>& board, char playerSymbol) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == playerSymbol && board[i][j + 1] == playerSymbol &&
                board[i][j + 2] == playerSymbol && board[i][j + 3] == playerSymbol) {
                return true;
            }
        }
    }

    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == playerSymbol && board[i + 1][j] == playerSymbol &&
                board[i + 2][j] == playerSymbol && board[i + 3][j] == playerSymbol) {
                return true;
            }
        }
    }

    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == playerSymbol && board[i + 1][j + 1] == playerSymbol &&
                board[i + 2][j + 2] == playerSymbol && board[i + 3][j + 3] == playerSymbol) {
                return true;
            }
        }
    }

    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == playerSymbol && board[i - 1][j + 1] == playerSymbol &&
                board[i - 2][j + 2] == playerSymbol && board[i - 3][j + 3] == playerSymbol) {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

int getUserMove() {
    int userMove;
    cout << "Enter your move (column 1-7): ";
    cin >> userMove;
    return userMove - 1; // Convert to 0-based indexing
}

int getComputerMove() {
    return rand() % COLS;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));
    vector<int> player1Moves;
    vector<int> player2Moves;
    bool player1Turn = true;

    cout << "Welcome to Connect 4!\n";

    while (true) {
        printBoard(board);

        char currentPlayerSymbol = (player1Turn) ? PLAYER1 : PLAYER2;
        char opponentPlayerSymbol = (player1Turn) ? PLAYER2 : PLAYER1;
        vector<int>& currentPlayerMoves = (player1Turn) ? player1Moves : player2Moves;

        if (currentPlayerSymbol == PLAYER1) {
            // User's turn
            int userMove = getUserMove();

            if (isValidMove(board, userMove)) {
                makeMove(board, userMove, currentPlayerSymbol, currentPlayerMoves);
                printTabulation(currentPlayerMoves, currentPlayerSymbol);

                if (checkWinner(board, currentPlayerSymbol)) {
                    printBoard(board);
                    cout << "Congratulations! Player " << currentPlayerSymbol << " wins!\n";
                    return 0;
                }

                if (isBoardFull(board)) {
                    printBoard(board);
                    cout << "It's a tie!\n";
                    return 0;
                }
            } else {
                cout << "Invalid move. Try again.\n";
                continue;
            }
        } else {
            int computerMove;
            do {
                computerMove = getComputerMove();
            } while (!isValidMove(board, computerMove));

            makeMove(board, computerMove, currentPlayerSymbol, currentPlayerMoves);
            printTabulation(currentPlayerMoves, currentPlayerSymbol);

            if (checkWinner(board, currentPlayerSymbol)) {
                printBoard(board);
                cout << "Sorry, Player " << currentPlayerSymbol << " lost. The computer wins!\n";
                return 0;
            }

            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!\n";
                return 0;
            }
        }

        player1Turn = !player1Turn;
    }

    return 0;
}
