# CSCI 404 Programming Project 2: Adversarial Search
Name: Peter Kohler\
CWID: 10429312\
Language: C++14\
OS: Linux\
Kernel: 5.15

## Code Structure
The code uses a class definition called "node" which contains the state of the board called "board", the score of the current board state called "eval", the most recent move called "move", and the best choice determined by the recursive miniMax algorithm called "bestChoice".

There are many different functions that were used to implement this game:\
`createBoard` is a utility function that creates the 2D array that contains all the connect 4 tiles.\
`calcScore` determines the score of the current board state\
`playMove` plays a move on the input board state and update's the current board state with that move\
`terminalCheck` checks whether the game is over or not\
`printBoard` displays the board state in the terminal\
`miniMax` is an implementation of the miniMax algorithm with alpha beta pruning, it returns the best move given the provided board state for the agent to take\
`evalBoard` is a heuristic function to assign a numerical value to the input board state\
`saveBoard` saves the input board state to an output text file\
`main` just runs everything


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
This creates the executable "maxconnect" in the folder "build" that you will use to run the code.

Navigate to the newly created "build" folder.
```
$ cd build
```

To run the game in interactive mode the code uses the following input argument scheme:\

`maxconnect4 interactive [input_file] [computer-next/human-next] [depth]`

An example terminal command would be:
```
$ ./build/maxconnect4 interactive test_files/input1.txt computer-next 5
```
To run the game in one-move mode the code uses the following input argument scheme:\

`maxconnect4 one-move [input_file] [output_file] [depth]`

An example terminal command would be:
An example input would be:
```
$ ./build/maxconnect4 one-move build/test_files/input1.txt human-next.txt 5
```
This will create a text file called `human-next.txt` in the terminal's working directory.

Don't forget the "./" is required for a local executable!\
The input test files are stored in the folder "test_files" which you will need to include in your filename call for each test file. 

## Test Cases
In the folder test_files there are 5 test cases.\
`testcase1.txt`\
Input command: 
```
./build/maxconnect4 interactive test_files/testcase1.txt computer-next 5
```
Expected Output: Computer makes a move in the 4th column to score a point.

`testcase2.txt`\
Input command: 
```
./build/maxconnect4 interactive test_files/testcase2.txt computer-next 5
```
Expected Output: Computer makes a move in the 3rd column to score a point.

`testcase3.txt`\
Input command: 
```
./build/maxconnect4 interactive test_files/testcase3.txt computer-next 5
```
Expected Output: Computer makes a move in the 1st column to score a point.

`testcase4.txt`\
Input command: 
```
./build/maxconnect4 interactive test_files/testcase4.txt computer-next 5
```
Expected Output: Computer makes a move in the 3rd column to block the other player from scoring a point.

`testcase5.txt`\
Input command: 
```
./build/maxconnect4 interactive test_files/testcase5.txt computer-next 5
```
Expected Output: Computer makes a move in the 6th column to block the other player from scoring a point.