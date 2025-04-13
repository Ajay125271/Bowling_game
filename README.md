# Bowling Game 

-This application calculates the scores of a Bowling game for multiple players and prints them.


## Features
- Support for multiple players
- Input using bowling notation (`X` for strike, `/` for spare)
- Calculates final score per player

### Prerequisites
- CMake
- C++17 compiler
- Git

### BUILD Instructions:
- cd bowling_game
- mkdir build
- cd build
- cmake ..
- cmake --build .

###USAGE:
-Run the executable from the main application filder.
- ".\bin\Debug\BowlingGame.exe"

###INPUT:
-The input is provided through tests/input_test.txt file.

  sample-
    Alice 10 7 3 9 0 10 10 10 2 3 6 4 7 2 10 10 10
    Bob 9 1 10 10 6 2 5 5 10 0 10 9 0 10 10 10 10

###OUTPUT:
   sample-
    Alice: 176 points
    Bob: 200 points
