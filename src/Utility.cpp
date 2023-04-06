#include "Utility.h"

/* Converts an integer number to a corresponding Location object.
 This function is useful for creating a Location object based on
 the position of a character in a string representing the initial board state.

 Parameters:
 - num: An integer representing the position of a character in the initial board string.

 Returns:
 - A Location object corresponding to the given number.*/
Location convertToLocation(int num) {
    // Convert number to file (column) and rank (row)
    int file = (num) / 8 + 1;  // Columns go from 1 (a) to 8 (h)
    int rank = (num) % 8 + 1;  // Rows go from 1 to 8
    // Convert file to string
    string fileString;
    switch (file) {
    case 1: fileString = "A"; break;
    case 2: fileString = "B"; break;
    case 3: fileString = "C"; break;
    case 4: fileString = "D"; break;
    case 5: fileString = "E"; break;
    case 6: fileString = "F"; break;
    case 7: fileString = "G"; break;
    case 8: fileString = "H"; break;
    default: fileString = ""; break; // Invalid column number
    }
    // Return Location object
    return make_pair(fileString, rank);
}

/* Converts a string representation of a location(e.g., "A1") to a corresponding Location object.

 Parameters:
 - locationStr: A string representing a location on the board (e.g., "A1").

 Returns:
 - A Location object corresponding to the given string.*/
Location convertToLocationFromStr(const std::string& locationStr) {
    int file = locationStr[0] - 'a';  // Columns go from 1 (a) to 8 (h)
    int rank = locationStr[1] - '0';      // Rows go from 1 to 8
    int num = file * 8 + rank - 1;

    return convertToLocation(num);
}

/* Calculates the path between two locations on the board.
 This function generates a vector of intermediate locations between
 the source and destination locations, excluding the source and destination.

 Parameters:
 - src: The source location as a Location object.
 - dest: The destination location as a Location object.

 Returns:
 - A vector of intermediate Location objects between the source and destination.*/

std::vector<Location> getPath(const Location& src, const Location& dest) {
    std::vector<Location> path;

    int srcCol = src.first[0] - 'A';
    int destCol = dest.first[0] - 'A';

    int dRow = dest.second - src.second;
    int dCol = destCol - srcCol;

    int maxSteps = std::max(std::abs(dRow), std::abs(dCol));

    for (int step = 1; step < maxSteps; ++step) {
        int newRow = src.second + dRow * step / maxSteps;
        int newCol = srcCol + dCol * step / maxSteps;
        char newFile = 'A' + newCol;
        path.emplace_back(string(1, newFile), newRow);
    }

    return path;
}