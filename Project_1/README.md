# CSCI 404 Programming Project 1: Uninformed Search
Name: Peter Kohler\
CWID: 10429312\
Language: C++14\
OS: Linux\
Kernel: 5.15

## Code Structure
The code is structured around 3 separate functions and a main function that prints the results. The "cities" in the problem statement are represented using
a C++ class called a "node" which is instantiated in the "node.h" file in the include folder. This class includes the state, the parent, a list of actions and associated costs, and finally a total cost to travel from the node back to the origin city.

The first function is called "create_graph" which creates the collection of class objects called "nodes" that represent the cities in the problem statement. This function returns a standard C++ object called a map which contains all of the city nodes with all possible actions as defined by the input text file.

The second function is called "pathCost" and it calculates the total cost required to travel from the node in question back to the origin city and stores that in the node's associated member variable.

The third function is called "explore" which implements Uniform-cost search using the origin city as the top of the search tree and finishes when the input destination city is found and explored. It returns a pointer to the destination city node which is later used to determine the route and milage from the origin city to the destination city.

## Build and Usage Instructions
To build the code cmake is required. The code has been built successfully with cmake version 3.22.1, but it should probably(?) compile on an earlier version such as 3.16.

To build the code, extract the code from the zip file into a new folder. Then enter the newly created folder with the extracted code in your terminal and generate the build files using cmake:
```
$ cmake -S . -B build
```
This will place all of the build files in a new folder called "build".\
Next build the project using the cmake-generated build files:
```
$ cmake --build build
```
This creates the executable "find_route" in the folder "build" that you will use to run the code.

Navigate to the newly created "build" folder.
```
$ cd build
```

As directed in the problem statement, the program has 3 CLI arguments:
```
$ ./find_route [input_filename] [origin_city] [destination_city]
```
The "./" is required for a local executable!\
The input test files are stored in the folder "test_files" which you will need to include in your filename call for each test file. 

An example program usage would be:
```
$./find_route test_files/input1.txt Munich Berlin
```

## Test Cases
input1.txt is the provided state graph containing the cities of Europe and England.\
input1_testcases.txt is the list of test cases for input1 and the expected outputs.

input3.txt is the new state graph as directed by the Project prompt.\
input3_testcases.txt is the list of test cases for input3 and the expected outputs.\
input3_visualization.pdf is a visualization of the state graph.