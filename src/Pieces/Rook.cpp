#include "Pieces\Rook.h"

/* Determines if a move is valid for a Rook piece based on the given new location.
This function checks if the move is along a straight line (horizontally or vertically).

Parameters:
	newLocation: A Location object representing the destination of the move.
Returns:
	true if the move is valid for a Rook piece, false otherwise.*/
bool Rook::isValidMove(Location newLocation) const noexcept
{
	return (m_location.first == newLocation.first || m_location.second == newLocation.second);
}
