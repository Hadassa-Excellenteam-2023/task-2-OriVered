#include "Pieces\Bishop.h"

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
