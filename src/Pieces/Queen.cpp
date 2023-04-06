#include "Pieces\Queen.h"

/* Determines if a move is valid for a Queen piece based on the given new location.
This function checks if the move is a valid move for a Rook or a Bishop piece.

Parameters:
    newLocation: A Location object representing the destination of the move.
Returns:
    true if the move is valid for a Queen piece, false otherwise.*/
bool Queen::isValidMove(Location newLocation) const noexcept
{
    // A queen's move is valid if it's a valid move for a rook or a bishop
    return Rook::isValidMove(newLocation) || Bishop::isValidMove(newLocation);
}