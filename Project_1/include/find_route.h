//==============================================
/// @author Peter Kohler (pmkohler@mines.edu)
/// @brief  Parses the input test file and then determines the optimal route 
///         to the desired goal city
//==============================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include "node.h"

using actionCostPair = std::pair<node*, int>;

std::pair<int, bool> pathCost(node* ptr, node* ptrOrigin);

bool compare(node* a, node* b);

std::map<std::string, node*> create_graph(std::string filename);

node* explore(std::map<std::string, node*> map, std::string origin_city, std::string destination_city);