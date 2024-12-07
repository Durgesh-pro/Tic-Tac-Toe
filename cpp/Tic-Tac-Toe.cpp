#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        cout << "\nTic-Tac-Toe Game\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool parseInput(const string& input, int& row, int& col) {
        if (input.length() != 2) return false;
        
        char rowChar = input[0];
        char colChar = input[1];

        if (rowChar < 'A' || rowChar > 'C') return false;
        if (colChar < '1' || colChar > '3') return false;

        row = rowChar - 'A';
        col = colChar - '1';

        return true;
    }

    void play() {
        int row, col;
        string input;

        for (int turn = 0; turn < 9; turn++) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (e.g., A1, B2, C3): ";
            cin >> input;

            if (parseInput(input, row, col)) {
                if (makeMove(row, col)) {
                    if (checkWin()) {
                        printBoard();
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        return;
                    }
                    switchPlayer();
                } else {
                    cout << "Invalid move. That spot is already taken. Try again!" << endl;
                    turn--;
                }
            } else {
                cout << "Invalid input. Please enter a valid move (e.g., A1, B2, C3)." << endl;
                turn--;
            }
        }

        printBoard();
        cout << "It's a draw!" << endl;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
