#include <vector>
#include <iostream>
using namespace std;

class ParishiTicTacToe {
    
private:
    vector<vector<char>> board;
    char currentPlayer;
    int moves;

public:
    ParishiTicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        moves = 0;
    }

    bool makeMove(int i, int j) {
        if (i < 0 || i >= 3 || j < 0 || j >= 3)
            return false;

        if (board[i][j] != ' ')
            return false;

        board[i][j] = currentPlayer;
        moves++;
        return true;
    }

    void changePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool decideWinner() {
       
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2])
                return true;
        }

        for (int j = 0; j < 3; j++) {
            if (board[0][j] != ' ' &&
                board[0][j] == board[1][j] &&
                board[1][j] == board[2][j])
                return true;
        }

        if (board[0][0] != ' ' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return true;

        if (board[0][2] != ' ' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return true;

        return false;
    }

    bool isDraw() {
        return moves == 9 && !decideWinner();
    }

    void printBoard() {
        for (auto &row : board) {
            for (auto &cell : row)
                cout << cell << " ";
            cout << endl;
        }
        cout << endl;
    }
};
