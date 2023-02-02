//==============================================
/// @author Peter Kohler (pmkohler@mines.edu)
/// @brief  Parses the input test file and then determines the route
///         to the desired goal city from the origin city
//==============================================

#include "find_route.h"

std::map<std::string, node*> create_graph(std::string filename){
    std::string str;
    std::fstream file;
    file.open(filename); 
    // Map to check if a city has been instantiated already
    std::map<std::string, node*> map;

    // Files come in 3 pieces per line
    // 1 -> Source City, 2 -> Destination City, 3 -> Path Cost
    std::vector<std::string> line;
    int index = 0;

    while (file >> str) {
        if (str == "END"){  // EOF
            break;
        }
        line.push_back(str);
        if (index == 2) {   // We have a full line, now we need to process
            if (map.find(line[0]) == map.end()) {
                // Source city is not in the map yet, create a new node and add city to map
                node* sourceCity = new node(line[0]);
                map.insert(std::make_pair(line[0], sourceCity));
            }
            // Check if destination city is in map yet
            if (map.find(line[1]) == map.end()){
                // Destination city is not in map yet, create new node and add city to map
                node* destCity = new node(line[1]);
                map.insert(std::make_pair(line[1], destCity));
            }
            // Both the Source and Destination cities exist in memory, now we can define the connection from 
            // the Source city to Destination city.
            actionCostPair pair;
            pair.first = map.find(line[1])->second;
            pair.second = std::stoi(line[2]);

            node* ptr = map.find(line[0])->second;
            ptr->actionList.push_back(pair);

            // Also define the connection from the Destination city to the Source city.
            pair.first = map.find(line[0])->second;
            pair.second = std::stoi(line[2]);

            ptr = map.find(line[1])->second;
            ptr->actionList.push_back(pair);

            // Reset
            index = 0;
            line.clear();
            continue;
        }
        index++;
    }
    return map;
}

node* explore(std::map<std::string, node*> map, std::string origin_city, std::string destination_city){
    // Create a standard FIFO queue for exploration
    std::queue<node*> queue;

    // Boolean to signal if we've found the destination city
    bool goal_found = false;

    // Get the node of the origin city
    node* ptr = map.find(origin_city)->second;
    // Check to see if we've passed the realistic # of nodes explored to find the goal node
    int explore_count = 0;

    while (!goal_found){
        // Add all nodes newly added to the fringe to the queue to be explored
        std::vector<actionCostPair> actions = ptr->actionList;
        for (auto i : actions){
            // Set the preceding node as the parent, only if it hasn't already been assigned!
            if (i.first->parent == nullptr){
                i.first->parent = ptr;
            }
            // Check and see if the new node on the fringe is the goal node
            if (i.first->state == destination_city){
                ptr = i.first;
                goal_found = true;
                break;
            }
            queue.push(i.first);
        }
        // Now explore the next node in the queue assuming we haven't found the goal node
        if (!goal_found){
            ptr = queue.front();
            queue.pop();
            explore_count++;
        }
        if (explore_count > 10*map.size()){ // Quit after we've explored 10*(Total # of Nodes in Graph)
            // Can't find the city node. Assume it's not reachable.
            return nullptr;
        }
    }
    return ptr;
}


int main(int argc, char** argv){
    // Error check for incorrect number of input args
    if (argc != 4){
        std::cout << "FATAL ERROR: Incorrect number of input arguments.\nPlease refer to the README for the correct program usage.\n";
        return 1;
    }
    std::map<std::string, node*> map;
    map = create_graph(argv[1]);

    // Check to ensure origin and destination cities are spelled correctly
    if (map.find(argv[2]) == map.end() ) {
        std::cout << "FATAL ERROR: Origin City not found.\n";
        return 2;
    }
    if (map.find(argv[3]) == map.end() ) {
        std::cout << "FATAL ERROR: Destination City not found.\n";
        return 3;
    }

    // Hard coded result of the two input cities are the same
    if (!std::strcmp(argv[2],argv[3])){
        std::cout << "distance: 0 km\nroute:\n" << argv[2] << " to " << argv[3] << ", 0 km\n";
        return 0;
    }

    node* ptr = explore(map, argv[2], argv[3]);

    // If we can't find the destination city assume route is impossible and cities are not connected
    if (ptr == nullptr){
        std::cout << "distance: infinity\nroute:\nnone\n";
        return 0;
    }

    // At this point we've found the goal node (assuming its possible to reach)
    // Now we need to go backwards and determine the route and it's mileage cost
    std::vector<std::string> route;
    std::vector<int> mileage;

    while (ptr->state != argv[2]){
        route.push_back(ptr->state);
        // Find the associated milage
        for (auto i : ptr->actionList){
            if (i.first->state == ptr->parent->state){
                mileage.push_back(i.second);
                break;
            }
        }
        ptr = ptr->parent;
    }
    // Add the origin city to the route
    route.push_back(ptr->state);

    // Calculate total distance traveled
    int sum = 0;
    for (auto i : mileage){
        sum += i;
    }

    // Print out the resultant distance and route
    // Route vector should always be 1 element larger than mileage vector
    std::cout << "distance: " << sum << " km\n";
    std::cout << "route:\n";
    for (int index = mileage.size()-1; index >= 0; index--){
        std::cout << route[index+1] << " to " << route[index] << ", " << mileage[index] << " km\n";
    }
    return 0;
}