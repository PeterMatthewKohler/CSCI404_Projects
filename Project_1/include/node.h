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
    // Copy constructor
    node(const node* ptr)
    {
        state = ptr->state;
        parent = ptr->parent;
        actionList = ptr->actionList;
        pathCost = 0;   // Do not copy the path cost
    }

    std::string state;  // Gets set during instantiation
    node* parent;       // Gets set during exploration
    int pathCost;       // The total path cost from the node back to the Origin city

    // Vector used to store all possible actions to take from a given city
    std::vector<actionCostPair> actionList; 
};
