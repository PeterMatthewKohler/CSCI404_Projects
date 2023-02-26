#pragma once

#include <vector>
#include <memory>

// Definition of node data structure which will represent each possible position on the board
class node{
public:
    // New board
    using Matrix = std::vector< std::vector<int>>;

    node(){};     // Default constructor
    ~node(){};    // Default destructor
    
    // Only board input
    node(Matrix board_input)
    {
        board = board_input;
        eval = 0;
        move = 0;
        bestChoice = 0;
    }
    // Copy constructor
    node(const node& input)
    {
        board = input.board;
        eval = input.eval;
        move = input.move;
        bestChoice = input.bestChoice;
    }

    Matrix board;               // State of the board of the connect4 game
    node* parent;
    int eval;                   // Evaluation using a heuristic function
    int move;                   // Integer signifying most recently played move
    int bestChoice;             // Number that gets updated running miniMax algorithm with choice to be taken



};