# README for Chess Game

This is a command line chess game. The game uses ASCII art for the board and pieces.

## Getting Started

To run the game, follow these steps:

1. Clone the repository to your local machine
2. Open the terminal and navigate to the directory where the repository is located
3. Compile the code using the following command:

g++ main.cpp Board.cpp Chess.cpp -o chess

4. Run the game using the following command:

./chess

## How to Play

The game is played through the terminal and uses ASCII art to represent the board and pieces. The game is played in turns, with the white player moving first.

To make a move, enter the source and destination squares (e.g., "A2A4"). The game will return the result of the move and update the board accordingly. The game continues until one player resigns or the game ends in a draw.

## Implementation Details

### The game is implemented in C++ and uses the following files:

- Board.h: Contains the Board class, which represents the chess board and manages the pieces and moves.
- Board.cpp: Implements the functions of the Board class.
- Chess.h: Contains the Chess class, which represents the chess game and manages the game loop.
- Chess.cpp: Implements the functions of the Chess class.
- main.cpp: The main function that runs the game.
- Pieces/BasicPiece.cpp: Implements the functions of the BasicPiece class.
- Pieces/Bishop.cpp: Implements the functions of the Bishop class.
- Pieces/King.cpp: Implements the functions of the King class.
- Pieces/Knight.cpp: Implements the functions of the Knight class.
- Pieces/Pawn.cpp: Implements the functions of the Pawn class.
- Pieces/Queen.cpp: Implements the functions of the Queen class.
- Pieces/Rook.cpp: Implements the functions of the Rook class.
- Utility.cpp: Implements the utility functions for converting between locations and generating the path between two locations.
