//==============================================
/// @author Peter Kohler (pmkohler@mines.edu)
/// @brief  Implements an agent that plays
/// Max-Connect4
//==============================================

#include "maxconnect4.hpp"

Matrix createBoard(std::fstream& file) {
    Matrix board(6, std::vector<int> (7)); // Board is size 6x7
    std::string str;

    int row = 0;
    int col = 0;
    while (file >> str) {
        for (auto i : str) {
            board[row][col] = int(i - '0'); // Converts char to int
            col++;
        }
        row++;
        col = 0;
        if (row > 5) {break;}
    }
    return board;
}

std::pair<int,int> calcScore(const Matrix& board) {
    std::pair<int, int> score;
    for (int i = 0; i < 6; i++){     // First traverse all rows
        int sequence = 0, tile = 0, prevTile = 0;
        for (int j = 0; j < 7; j++){
            prevTile = tile;
            tile = board[i][j];
            if (tile == 0){
                if (sequence >= 4){ // Check if we had a sequence of 4
                    if (prevTile == 1){score.first += sequence - 3;}
                    if (prevTile == 2){score.second += sequence - 3;}
                }
                sequence = 0;
            }
            else {  // tile is a 1 or 2
                if (tile != prevTile) {
                    if (sequence >= 4){ // Check if we had a sequence of 4
                        if (prevTile == 1){score.first += sequence - 3;}
                        if (prevTile == 2){score.second += sequence - 3;}
                    }
                    sequence = 1;   // reset
                }
                else if (j == 6){ // We are at end of row, check if we have sequence of 4 or greater
                    if (tile == prevTile && sequence >= 3){
                        sequence++;
                        if (tile == 1){score.first += sequence - 3;}
                        if (tile == 2){score.second += sequence - 3;}
                    }
                }
                else {  // Tiles are equal
                    sequence++;
                }
            }
        }
    }
    for (int i = 0; i < 7; i++){        // Now traverse the columns
        int sequence = 0, tile = 0, prevTile = 0;
        for (int j = 0; j < 6; j++){
            prevTile = tile;
            tile = board[j][i];
            if (tile == 0){
                if (sequence >= 4){ // Check if we had a sequence of 4
                    if (prevTile == 1){score.first += sequence - 3;}
                    if (prevTile == 2){score.second += sequence - 3;}
                }
                sequence = 0;
            }
            else {  // tile is a 1 or 2
                if (tile != prevTile) {
                    if (sequence >= 4){ // Check if we had a sequence of 4
                        if (prevTile == 1){score.first += sequence - 3;}
                        if (prevTile == 2){score.second += sequence - 3;}
                    }
                    sequence = 1;   // reset
                }
                else if (j == 5){ // We are at end of column, check if we have sequence of 4 or greater
                    if (tile == prevTile && sequence >= 3){
                        sequence++;
                        if (tile == 1){score.first += sequence - 3;}
                        if (tile == 2){score.second += sequence - 3;}
                    }
                }
                else {  // Tiles are equal
                    sequence++;
                }
            }
        }
    }
    return score;
}

bool playMove(Matrix& board, int move, int& next) {    //returns true if move is valid, false if invalid
    if (move > 7 || move < 1) {
        std::cout << "ERROR: Please enter a move between 1 and 7." << std::endl;
        return false;
        }

    for (int i = 5; i >= 0; i--){   // Traverse column in reverse to find first available open space
        if (board[i][move-1] == 0){
            board[i][move-1] = next;
            if (next == 1){next++;}
            else {next--;}
            return true;
        }
    }
    std::cout << "This column is full. Please pick a different move." << std::endl;
    return false;
}

bool terminalCheck(const Matrix& board) {   // returns true if no more moves can be made on the board, false if not
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (board[i][j] == 0){return false;}
        }
    }
    return true;
}

void printBoard(const Matrix& board) {  // Just prints the state of the board
    std::cout << "\nBoard:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {
    std::string str = "test_files/input2.txt";
    std::fstream file;
    file.open(str);
    Matrix board = createBoard(file);
    file >> str;
    file.close();
    int next = int(str[0] - '0');

    // --------- DEBUGGING
    printBoard(board);
    std::cout << "next: " << next << "\n\n";
    // ---------

    std::pair<int,int> score = calcScore(board);
    std::cout << "Score: " << score.first << " - " << score.second << std::endl;

    bool terminal = false;
    int move;
    while (!terminal) {
        bool valid = false;
        while (!valid){
            std::cout << "Please enter a move." << std::endl;
            std::cin >> move;
            valid = playMove(board, move, next);
        }
        // Check for terminal state of board being full
        terminal = terminalCheck(board);
        // --------- DEBUGGING
        printBoard(board);
        std::cout << "next: " << next << "\n\n";
        std::pair<int,int> score = calcScore(board);
        std::cout << "Score: " << score.first << " - " << score.second << std::endl;
        // ---------
    }

    return 0;
}