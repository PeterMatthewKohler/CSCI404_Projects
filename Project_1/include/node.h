#pragma once

#include <string>
#include <memory>
#include <vector>

// Definition of the node data structure which represents each individual city

class node{
using actionCostPair = std::pair<node*, int>;
public:
    // New city 
    node(std::string state_input) 
    {
        state = state_input;
        parent = nullptr;
        
    }

    std::string state;  // Gets set during instantiation
    node* parent;       // Gets set when during exploration

    // Vector used to store all possible actions to take from a given city
    std::vector<actionCostPair> actionList; 
};
