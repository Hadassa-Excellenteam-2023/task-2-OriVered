#include "Pieces\Queen.h"

bool Queen::isValidMove(Location newLocation) const noexcept
{
    // A queen's move is valid if it's a valid move for a rook or a bishop
    return Rook::isValidMove(newLocation) || Bishop::isValidMove(newLocation);
}