#include "Pieces\Pawn.h"

bool Pawn::isValidMove(Location newLocation) const noexcept
{
    int rowDiff = (m_color == PieceColor::WHITE) ? newLocation.first[0] - m_location.first[0]
        : m_location.first[0] - newLocation.first[0];
    int colDiff = newLocation.second - m_location.second;

    // Check if it's the pawn's initial move (two steps forward)
    bool isInitialMove = (m_color == PieceColor::WHITE && m_location.first[0] == 'B') ||
        (m_color == PieceColor::BLACK && m_location.first[0] == 'G');
    bool validInitialMove = isInitialMove && rowDiff == 2 && colDiff == 0;

    // Regular pawn move (one step forward)
    bool validRegularMove = rowDiff == 1 && colDiff == 0;

    // TODO: Implement capturing and en passant moves for pawns

    // Check if the move is within the board limits and if it's a valid pawn move
    return (newLocation.first[0] >= 'A' && newLocation.first[0] <= 'H' &&
        newLocation.second >= 1 && newLocation.second <= 8) && (validInitialMove || validRegularMove);
}
