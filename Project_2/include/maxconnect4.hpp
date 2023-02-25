//==============================================
/// @author Peter Kohler (pmkohler@mines.edu)
/// @brief  Implements an agent that plays
/// Max-Connect4
//==============================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef std::vector< std::vector<int>> Matrix;

Matrix createBoard(std::fstream& file);

std::pair<int,int> calcScore(const Matrix& board);

bool playMove(Matrix& board, int move, int& next);

bool terminalCheck(const Matrix& board);

void printBoard(const Matrix& board);