#include "Pieces\Bishop.h"

/* Determines if a move is valid for a Bishop piece based on the given new location.
 This function checks if the move is along a diagonal direction and within the board limits.

 Parameters:
 - newLocation: A Location object representing the destination of the move.

 Returns:
 - true if the move is valid for a Bishop piece, false otherwise.*/
bool Bishop::isValidMove(Location newLocation) const noexcept
{
    int rowDiff = newLocation.first[0] - m_location.first[0];
    int colDiff = newLocation.second - m_location.second;

    // check if the move is along a diagonal direction
    if (abs(rowDiff) != abs(colDiff)) {
        return false;
    }

    // check if the move is within the board limits
    if (newLocation.first[0] < 'A' || newLocation.first[0] > 'H' ||
        newLocation.second < 1 || newLocation.second > 8) {
        return false;
    }

    // the move is valid along a diagonal direction
    return true;
}
