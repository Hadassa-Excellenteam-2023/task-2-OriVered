#include "Pieces\King.h"

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
