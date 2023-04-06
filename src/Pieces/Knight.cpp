#include "Pieces\Knight.h"


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
