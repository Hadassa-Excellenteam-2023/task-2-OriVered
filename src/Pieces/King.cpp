#include "Pieces\King.h"

/* Determines if a move is valid for a King piece based on the given new location.
This function checks if the move is a single step in any direction (horizontal, vertical, or diagonal)
and within the board limits.

Parameters:
    newLocation: A Location object representing the destination of the move.
Returns: 
    true if the move is valid for a King piece, false otherwise.*/
bool King::isValidMove(Location newLocation) const noexcept
{
    int rowDiff = newLocation.first[0] - m_location.first[0];
    int colDiff = newLocation.second - m_location.second;
    int rowDiffAbs = abs(rowDiff);
    int colDiffAbs = abs(colDiff);

    // Check if the move is a single step in any direction (horizontal, vertical, or diagonal)
    bool validMove = (rowDiffAbs <= 1 && colDiffAbs <= 1) && !(rowDiffAbs == 0 && colDiffAbs == 0);

    // Check if the move is within the board limits and if it's a valid king move
    return (newLocation.first[0] >= 'A' && newLocation.first[0] <= 'H' &&
        newLocation.second >= 1 && newLocation.second <= 8) && validMove;
}
