//==============================================
/// @author Peter Kohler (pmkohler@mines.edu)
/// @brief  Implements an agent that plays
/// Max-Connect4
//==============================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <node.h>

typedef std::vector< std::vector<int>> Matrix;

Matrix createBoard(std::fstream& file);

std::pair<int,int> calcScore(const Matrix& board);

bool playMove(Matrix& board, int move, int next);

bool terminalCheck(const Matrix& board);

void printBoard(const Matrix& board);

int miniMax(node& input, int depth, int alpha, int beta, bool maximizingPlayer);

int evalBoard(Matrix board);