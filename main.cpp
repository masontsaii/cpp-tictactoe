#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
    //
    //    PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {

        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);

        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
} 

bool isWon(char player, char board[][3]) {

    // Check rows
    for (int i=0; i < 3; i++) {
        bool won = true;
        for (int j=0; j < 3; j++) {
            if(board[i][j] != player) {
                won = false;
            }
        }
        if (won) {
            return true;
        }
    }

    // Check Columns
    for(int i=0; i < 3; i++) {
        bool won = true;
        for(int j=0; j < 3; j++) {
            if(board[j][i] != player) {
                won = false;
            }
        }
        if(won) {
            return true;
        }
    }

    // Check diagonal 1
    bool won = true;
    for(int i=0; i < 3; i++) {
        if(board[i][i] != player) {
            won = false;
        }
    }
    if (won) {
        return true;
    }

    // Check diagonal 2 
    won = true;
    for (int i=0; i < 3; i++) {
            if (board[i][2 - i] != player) {
                won = false;
            }
    }
    return won;
}

bool isDraw(char board[][3]) {
    
    bool boardFilled = true;
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void displayBoard (char board[][3]) {

    cout << endl;
    for (int i=0; i < 3; i++) {
        cout << "-------------" << endl;
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << endl;
    }
    cout << "-------------" << endl;
}

void makeAMove(char board[][3], char player) {

    int row, col;
    while (true) {
        cout << "Enter a row (0, 1, 2) for player " << player << ": ";
        cin >> row;
        cout << "Enter a column (0, 1, 2) for player " << player << ": ";
        cin >> col;

        if(board[row][col] != ' ') {
            cout << "This cell is already occupied. Try a different cell" << endl;
        }
        else {
            board[row][col] = player;
            return;
        }
    }
}