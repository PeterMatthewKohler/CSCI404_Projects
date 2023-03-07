//==============================================
/// @author Peter Kohler (pmkohler@mines.edu)
/// @brief  Implements an agent that plays
/// Max-Connect4
//==============================================

#include "maxconnect4.hpp"

Matrix createBoard(std::fstream& file) {            // Creates the board to be used from an input text file
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

std::pair<int,int> calcScore(const Matrix& board) { // returns a pair which contains the score of the input board state
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
    // Diagonals top left to bottom right
    for (int i = 2; i >= 0; i--){
        int row = i;
        int sequence = 0, tile = 0, prevTile = 0;
        for (int col = 0; row < 6 && col < 7;){
            prevTile = tile;
            tile = board[row][col];
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
                else if (row == 5 || col == 6){ // We are at end of the diagonal, check if we have sequence of 4 or greater
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
            row++;
            col++;
        }
    }
    for (int i = 1; i <= 4; i++){
        int col = i;
        int sequence = 0, tile = 0, prevTile = 0;
        for (int row = 0; row < 6 && col < 7;){
            prevTile = tile;
            tile = board[row][col];
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
                else if (row == 5 || col == 6){ // We are at end of the diagonal, check if we have sequence of 4 or greater
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
            row++;
            col++;
        }
    }
    // Now diagonals top right to bottom left
    for (int i = 2; i >= 0; i--){
        int row = i;
        int sequence = 0, tile = 0, prevTile = 0;
        for (int col = 6; row < 6 && col >= 0;){
            prevTile = tile;
            tile = board[row][col];
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
                else if (row == 5 || col == 0){ // We are at end of the diagonal, check if we have sequence of 4 or greater
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
            row++;
            col--;
        }
    }
    for (int i = 5; i >= 3; i--){
        int col = i;
        int sequence = 0, tile = 0, prevTile = 0;
        for (int row = 0; row < 6 && col >= 0;){
            prevTile = tile;
            tile = board[row][col];
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
                else if (row == 5 || col == 0){ // We are at end of the diagonal, check if we have sequence of 4 or greater
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
            row++;
            col--;
        }
    }
    return score;
}

bool playMove(Matrix& board, int move, int next) {  //returns true if move is valid, false if invalid
    if (move > 7 || move < 1) {                       //Valid input is between 1 and 7 inclusive
        return false;
        }

    for (int i = 5; i >= 0; i--){   // Traverse column in reverse to find first available open space
        if (board[i][move-1] == 0){
            board[i][move-1] = next;
            return true;
        }
    }
    return false;
}

bool terminalCheck(const Matrix& board) {           // returns true if no more moves can be made on the board, false if not
    // Only need to check top row
    for (auto i : board[0]){
        if (i == 0){return false;}
    }
    return true;
}

void printBoard(const Matrix& board) {              // Just prints the state of the board
    std::cout << "\nBoard:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Returns the best/worst heuristic value of all of the node input's children nodes
// At the top level we don't care about the return heuristic value and simply want the best move
// added to the input node's member variable "bestChoice"
int miniMax(node& input, int depth, int alpha, int beta, bool maximizingPlayer) {
    if (depth == 0 || terminalCheck(input.board)){return evalBoard(input.board);}
    // Create the children nodes
    std::vector<node> vect;
    for (int i = 0; i < 7; i++){
        node child = node(input.board);
        child.parent = &input;
        int turn;
        if (maximizingPlayer){turn = 1;}
        else{turn = 2;}
        if (playMove(child.board, i + 1, turn)){   // If the move is valid, assign it a value from heuristic function
            child.eval = evalBoard(child.board);   // and add it to the children of the input node
            child.move = i;
            vect.push_back(child);
        }
    }
    if (maximizingPlayer) {
        int maxEval = INT_MIN;  // Negative infinity
        for (auto i : vect){
            auto nodeEval = miniMax(i, depth - 1, alpha, beta, false);
            //Pick the higher of the two evaluations
            if (maxEval < nodeEval){
                maxEval = nodeEval;
                // Set the new best move in the parent node's member variable
                input.bestChoice = i.move;
            }
            alpha = std::max(alpha, nodeEval);
            if (beta <= alpha){break;}  // Pruning
        }
        return maxEval;
    }
    else {
        int minEval = INT_MAX;    // Positive infinity
        for (auto i : vect){
            auto nodeEval = miniMax(i, depth - 1, alpha, beta, true);
            // Pick the lower of the two evaluations
            if (minEval > nodeEval){
                minEval = nodeEval;
                // Set the best choice in the parent node's member variable
                input.bestChoice = i.move;
            }
            beta = std::min(beta, nodeEval);
            if (beta <= alpha){break;}  // Pruning
        }
        return minEval;
    }
}

int evalBoard(Matrix board) {    // Heuristic used for evaluating board states
    // Simply (p1 score) - (p2 score)
    auto score = calcScore(board);
    return score.first - score.second;
}

void saveBoard(Matrix board, std::fstream& file, std::string outputName, const int next) {  // Saves board in a designated file
    file.open(outputName, std::fstream::out | std::fstream::trunc);     // We don't care what's currently in the output file
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            file << board[i][j];
        }
        file << "\n";
    }
    file << next;
    file.close();
}

int main(int argc, char** argv) {
    // Check Input Args
    if (argc < 5){
        std::cout << "ERROR: Usage error. Please consult the README for the correct input arguments.\n";
        return -1;
    }
    // Determine Game Mode
    bool gameMode = false;  // If false, one-move. If true, interactive;
    bool playerNext = false; // If true, it is human player's turn
    std::string str1 = "interactive";
    std::string str2 = "one-move";
    if (std::strcmp(str1.c_str(),argv[1]) && std::strcmp(str2.c_str(),argv[1])){  // Check determing input arg for game mode is bad/wrong
        std::cout << "ERROR: Please input a correct game mode.\n";
        return -1;
    }
    if (!std::strcmp(str1.c_str(),argv[1])){
        gameMode = true;
        // In interactive mode, determine who plays next
        str1 = "computer-next";
        str2 = "human-next";
        if (!std::strcmp(str2.c_str(),argv[3])){playerNext = true;}
        if (std::strcmp(str1.c_str(),argv[3]) && std::strcmp(str2.c_str(),argv[3])){    // Check determing input arg for next turn is bad/wrong
            std::cout << "ERROR: Please input a correct input arg for who's turn is next.\n";
            return -1;
        }
    }

    // Check and Parse the input file
    std::string str;
    std::fstream file;
    file.open(argv[2]);
    if(!file.is_open()){
        std::cout << "ERROR: Please input a valid filename.\n";
        return -1;
    }
    Matrix board = createBoard(file);
    node game(board);
    file >> str;
    file.close();
    int next = int(str[0] - '0');

    // Get the depth
    int depth;
    if (!std::isdigit(*argv[4])) {  // If it's not a number
        std::cout << "ERROR: Please enter a valid number for the depth.\n";
        return -1;
    }
    else{                           // If it is a number
        depth = std::atoi(argv[4]);
        if (depth <= 0) {
            std::cout << "ERROR: Please enter a valid number for the depth.\n";
            return -1;
        }
    }
    // Start playing
    std::fstream output;
    // --------- Print initial board state and score
    printBoard(game.board);
    std::cout << "next: " << next << "\n\n";
    auto score = calcScore(game.board);
    std::cout << "Score: " << score.first << " - " << score.second << "\n";
    // ---------

    bool terminal = false;
    int move;

    if (gameMode){  // interactive mode
        str1 = "computer.txt";
        str2 = "human.txt";
        while (!terminal) {
            if (playerNext){
                // Player's turn
                bool valid = false;
                while (!valid){
                    std::cout << "Please enter a move." << "\n";
                    std::cin >> move;
                    valid = playMove(game.board, move, next);
                    if (!valid){std::cout << "Please enter a valid move" << "\n";}
                }
                if (next == 1){next++;}
                else{next--;}
                // --------- Print current board state and score
                printBoard(game.board);
                std::cout << "next: " << next << "\n\n";
                score = calcScore(game.board);
                std::cout << "Score: " << score.first << " - " << score.second << "\n";
                // ---------
                // Save board state in a text file human.txt
                saveBoard(game.board, output, str2, next);
                // It is now the computer player's turn
                playerNext = false;
                // Check for terminal state of board being full
                terminal = terminalCheck(game.board);
                if (terminal){break;}
            }
            else{
                // Computer's turn
                miniMax(game, depth, INT_MIN, INT_MAX, true);
                std::cout << "\nComputer's decision: " << game.bestChoice + 1 << "\n";
                // Play algorithm's choice
                playMove(game.board, game.bestChoice+1, next);
                if (next == 1){next++;}
                else{next--;}
                // --------- Print current board state and score
                printBoard(game.board);
                std::cout << "next: " << next << "\n\n";
                score = calcScore(game.board);
                std::cout << "Score: " << score.first << " - " << score.second << "\n";
                // ---------
                // Save board state in a text file computer.txt
                saveBoard(game.board, output, str1, next);
                // It is now the human player's turn
                playerNext = true;
                // Check for terminal state of board being full
                terminal = terminalCheck(game.board);
                if (terminal){break;}
            }
        }
    }
    else{   // One-move mode
        std::string outputName = argv[3];
        std::cout << "Outputname is : " << outputName << std::endl;
        terminal = terminalCheck(game.board);
        if (terminal){
            std::cout << "\nBoard is full. End.\n";
            return 0;
        }
        miniMax(game, depth, INT_MIN, INT_MAX, true);
        std::cout << "\nComputer's decision: " << game.bestChoice + 1 << "\n";
        // Play algorithm's choice
        playMove(game.board, game.bestChoice+1, next);
        if (next == 1){next++;}
        else{next--;}
        // --------- Print current board state and score
        printBoard(game.board);
        std::cout << "next: " << next << "\n\n";
        score = calcScore(game.board);
        std::cout << "Score: " << score.first << " - " << score.second << "\n";
        // ---------
        // Save board state in a text file designated by the input argument
        saveBoard(game.board, output, outputName, next);
    }
    // --------- Print final board state and score
    std::cout << "=========FINAL BOARD STATE==========\n";
    printBoard(game.board);
    std::cout << "next: " << next << "\n\n";
    score = calcScore(game.board);
    std::cout << "Score: " << score.first << " - " << score.second << "\n";
    //---------

    return 0;
}