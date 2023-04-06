#include "Pieces\Knight.h"


/* Determines if a move is valid for a Knight piece based on the given new location.
This function checks if the move is a L-shaped pattern (two steps in one direction and one step in another)
and within the board limits.

Parameters:
    newLocation: A Location object representing the destination of the move.
Returns:
    true if the move is valid for a Knight piece, false otherwise.*/
bool Knight::isValidMove(Location newLocation) const noexcept
{
    int rowDiff = newLocation.first[0] - m_location.first[0];
    int colDiff = newLocation.second - m_location.second;
    int rowDiffAbs = abs(rowDiff);
    int colDiffAbs = abs(colDiff);

    bool validMove = (rowDiffAbs == 1 && colDiffAbs == 2) || (rowDiffAbs == 2 && colDiffAbs == 1);

    // Check if the move is within the board limits and if it's a valid knight move
    return (newLocation.first[0] >= 'A' && newLocation.first[0] <= 'H' &&
        newLocation.second >= 1 && newLocation.second <= 8) && validMove;
}
